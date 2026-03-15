#include "messageLibrary.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <tuple>

namespace milstd6016 {

namespace {

struct CatalogData
{
	std::vector<ValueMeaning> values;
	std::vector<DfiDuiCombo> combos;
	std::string sourcePath;
};

std::string Trim(const std::string& value)
{
	std::size_t start = 0;
	while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start])))
	{
		++start;
	}

	std::size_t end = value.size();
	while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])))
	{
		--end;
	}

	return value.substr(start, end - start);
}

std::string Normalize(const std::string& input)
{
	std::stringstream stream(input);
	std::string token;
	std::string output;

	while (stream >> token)
	{
		if (!output.empty())
		{
			output += ' ';
		}
		output += token;
	}

	return output;
}

std::vector<std::string> ParseCsvLine(const std::string& line)
{
	std::vector<std::string> columns;
	std::string builder;
	bool inQuotes = false;

	for (std::size_t index = 0; index < line.size(); ++index)
	{
		const char current = line[index];

		if (current == '"')
		{
			if (inQuotes && index + 1 < line.size() && line[index + 1] == '"')
			{
				builder += '"';
				++index;
				continue;
			}

			inQuotes = !inQuotes;
			continue;
		}

		if (current == ',' && !inQuotes)
		{
			columns.push_back(builder);
			builder.clear();
			continue;
		}

		builder += current;
	}

	columns.push_back(builder);
	return columns;
}

bool TryParseInt(const std::string& value, int& result)
{
	const std::string trimmed = Trim(value);
	if (trimmed.empty())
	{
		return false;
	}

	std::size_t processed = 0;
	try
	{
		result = std::stoi(trimmed, &processed, 10);
	}
	catch (...)
	{
		return false;
	}

	return processed == trimmed.size();
}

bool TryParseWithBase(const std::string& digits, int numberBase, int& value)
{
	try
	{
		std::size_t processed = 0;
		value = std::stoi(digits, &processed, numberBase);
		return processed == digits.size();
	}
	catch (...)
	{
		value = 0;
		return false;
	}
}

std::set<int> ParseRequestedValues(const std::string& raw)
{
	std::set<int> values;
	const std::string normalized = Normalize(raw);
	if (normalized.empty())
	{
		return values;
	}

	int parsedValue = 0;
	if (TryParseInt(normalized, parsedValue))
	{
		values.insert(parsedValue);
	}

	if (normalized.size() > 2 && normalized[0] == '0' && (normalized[1] == 'x' || normalized[1] == 'X'))
	{
		if (TryParseWithBase(normalized.substr(2), 16, parsedValue))
		{
			values.insert(parsedValue);
		}
	}

	if (normalized.size() > 2 && normalized[0] == '0' && (normalized[1] == 'o' || normalized[1] == 'O'))
	{
		if (TryParseWithBase(normalized.substr(2), 8, parsedValue))
		{
			values.insert(parsedValue);
		}
	}

	if (normalized.size() > 2 && normalized[0] == '0' && (normalized[1] == 'b' || normalized[1] == 'B'))
	{
		if (TryParseWithBase(normalized.substr(2), 2, parsedValue))
		{
			values.insert(parsedValue);
		}
	}

	const bool digitsOnly = !normalized.empty() &&
		std::all_of(normalized.begin(), normalized.end(), [](char c) { return std::isdigit(static_cast<unsigned char>(c)) != 0; });
	if (digitsOnly && normalized.size() > 1)
	{
		const bool octalDigitsOnly = std::all_of(normalized.begin(), normalized.end(), [](char c) { return c >= '0' && c <= '7'; });
		const bool binaryDigitsOnly = std::all_of(normalized.begin(), normalized.end(), [](char c) { return c == '0' || c == '1'; });

		if (octalDigitsOnly && TryParseWithBase(normalized, 8, parsedValue))
		{
			values.insert(parsedValue);
		}

		if (binaryDigitsOnly && TryParseWithBase(normalized, 2, parsedValue))
		{
			values.insert(parsedValue);
		}
	}

	const std::regex octalSuffixPattern("^(\\d+)\\s*\\(\\s*OCTAL\\s*\\)$", std::regex_constants::icase);
	std::smatch octalSuffixMatch;
	if (std::regex_match(normalized, octalSuffixMatch, octalSuffixPattern) && octalSuffixMatch.size() > 1)
	{
		if (TryParseWithBase(octalSuffixMatch[1].str(), 8, parsedValue))
		{
			values.insert(parsedValue);
		}
	}

	return values;
}

bool TryParseBitCodeCondition(const std::string& bitCode, int& minValue, int& maxValue)
{
	minValue = 0;
	maxValue = 0;

	const std::string normalized = Normalize(bitCode);
	if (normalized.empty())
	{
		return false;
	}

	const bool hasOctalSuffix = normalized.find("(OCTAL)") != std::string::npos ||
								normalized.find("(octal)") != std::string::npos ||
								normalized.find("(Octal)") != std::string::npos;

	const std::regex throughPattern("^(\\d+)\\s+THROUGH\\s+(\\d+)$", std::regex_constants::icase);
	std::smatch throughMatch;
	if (std::regex_match(normalized, throughMatch, throughPattern) && throughMatch.size() > 2)
	{
		const int numberBase = hasOctalSuffix ? 8 : 10;
		int start = 0;
		int end = 0;
		if (!TryParseWithBase(throughMatch[1].str(), numberBase, start) ||
			!TryParseWithBase(throughMatch[2].str(), numberBase, end))
		{
			return false;
		}

		minValue = std::min(start, end);
		maxValue = std::max(start, end);
		return true;
	}

	const std::regex octalPattern("^(\\d+)\\s*\\(\\s*OCTAL\\s*\\)$", std::regex_constants::icase);
	std::smatch octalMatch;
	if (std::regex_match(normalized, octalMatch, octalPattern) && octalMatch.size() > 1)
	{
		int octalValue = 0;
		if (!TryParseWithBase(octalMatch[1].str(), 8, octalValue))
		{
			return false;
		}

		minValue = octalValue;
		maxValue = octalValue;
		return true;
	}

	int decimalValue = 0;
	if (!TryParseInt(normalized, decimalValue))
	{
		return false;
	}

	minValue = decimalValue;
	maxValue = decimalValue;
	return true;
}

std::vector<std::string> GetCandidatePaths()
{
	return {
		"milstd6016/dfi_dui_di.csv",
		"csharpproject/output/dfi_dui_di.csv",
		"csharpproject/src/MilStd6016Library/Data/milstd6016_dfi_dui_di.csv"
	};
}

CatalogData LoadCatalog()
{
	CatalogData catalog;

	std::ifstream stream;
	for (const std::string& candidate : GetCandidatePaths())
	{
		stream.open(candidate.c_str(), std::ios::in | std::ios::binary);
		if (stream.is_open())
		{
			catalog.sourcePath = candidate;
			break;
		}
		stream.clear();
	}

	if (!stream.is_open())
	{
		return catalog;
	}

	std::set<std::tuple<int, int, std::string, std::string> > seen;
	std::string line;
	bool firstRow = true;

	while (std::getline(stream, line))
	{
		if (!line.empty() && line.back() == '\r')
		{
			line.pop_back();
		}

		if (Trim(line).empty())
		{
			continue;
		}

		if (firstRow)
		{
			firstRow = false;
			continue;
		}

		const std::vector<std::string> columns = ParseCsvLine(line);
		if (columns.size() < 10)
		{
			continue;
		}

		int dfi = 0;
		int dui = 0;
		if (!TryParseInt(columns[0], dfi) || !TryParseInt(columns[2], dui))
		{
			continue;
		}

		ValueMeaning value;
		value.dfi = dfi;
		value.dui = dui;
		value.duiName = columns[3];
		value.bitCode = columns[8];
		value.dataItem = columns[7];
		value.explanation = columns[9];
		value.applicability = columns[6];

		if (Normalize(value.bitCode).empty() || Normalize(value.dataItem).empty())
		{
			continue;
		}

		const std::tuple<int, int, std::string, std::string> key(
			value.dfi,
			value.dui,
			Normalize(value.bitCode),
			Normalize(value.dataItem));

		if (!seen.insert(key).second)
		{
			continue;
		}

		catalog.values.push_back(value);
	}

	std::sort(catalog.values.begin(), catalog.values.end(), [](const ValueMeaning& left, const ValueMeaning& right)
	{
		if (left.dfi != right.dfi)
		{
			return left.dfi < right.dfi;
		}
		if (left.dui != right.dui)
		{
			return left.dui < right.dui;
		}
		return left.bitCode < right.bitCode;
	});

	std::map<std::pair<int, int>, DfiDuiCombo> combosByKey;
	for (const ValueMeaning& value : catalog.values)
	{
		const std::pair<int, int> key(value.dfi, value.dui);
		if (combosByKey.find(key) == combosByKey.end())
		{
			DfiDuiCombo combo;
			combo.dfi = value.dfi;
			combo.dui = value.dui;
			combo.duiName = value.duiName;
			combosByKey[key] = combo;
		}
	}

	for (const std::map<std::pair<int, int>, DfiDuiCombo>::value_type& entry : combosByKey)
	{
		catalog.combos.push_back(entry.second);
	}

	return catalog;
}

const CatalogData& GetCatalog()
{
	static const CatalogData catalog = LoadCatalog();
	return catalog;
}

}

std::vector<DfiDuiCombo> GetDfiDuiCombos()
{
	return GetCatalog().combos;
}

std::vector<ValueMeaning> GetValueMeanings(int dfi, int dui)
{
	std::vector<ValueMeaning> matches;
	for (const ValueMeaning& value : GetCatalog().values)
	{
		if (value.dfi == dfi && value.dui == dui)
		{
			matches.push_back(value);
		}
	}

	return matches;
}

bool TryGetValueMeaning(int dfi, int dui, const std::string& bitCode, ValueMeaning& result)
{
	const std::string normalized = Normalize(bitCode);
	for (const ValueMeaning& value : GetCatalog().values)
	{
		if (value.dfi == dfi && value.dui == dui && Normalize(value.bitCode) == normalized)
		{
			result = value;
			return true;
		}
	}

	return false;
}

bool TryResolveValueMeaning(int dfi, int dui, const std::string& bitCode, ValueMeaning& result)
{
	if (TryGetValueMeaning(dfi, dui, bitCode, result))
	{
		return true;
	}

	const std::set<int> requestedValues = ParseRequestedValues(bitCode);
	if (requestedValues.empty())
	{
		return false;
	}

	bool found = false;
	int bestSpan = 0;
	std::string bestBitCode;

	for (const ValueMeaning& value : GetCatalog().values)
	{
		if (value.dfi != dfi || value.dui != dui)
		{
			continue;
		}

		int minValue = 0;
		int maxValue = 0;
		if (!TryParseBitCodeCondition(value.bitCode, minValue, maxValue))
		{
			continue;
		}

		bool matched = false;
		for (int requested : requestedValues)
		{
			if (requested >= minValue && requested <= maxValue)
			{
				matched = true;
				break;
			}
		}

		if (!matched)
		{
			continue;
		}

		const int span = maxValue - minValue;
		if (!found || span < bestSpan || (span == bestSpan && value.bitCode < bestBitCode))
		{
			found = true;
			bestSpan = span;
			bestBitCode = value.bitCode;
			result = value;
		}
	}

	return found;
}

std::string GetCatalogSourcePath()
{
	return GetCatalog().sourcePath;
}

}
