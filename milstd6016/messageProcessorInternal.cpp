#include "messageProcessorInternal.h"

#include <cctype>
#include <sstream>

#include "messageLibrary.h"

namespace milstd6016 {
namespace internal {

std::string Trim(const std::string& value)
{
	std::size_t start = 0;
	while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start])) != 0)
	{
		++start;
	}

	std::size_t end = value.size();
	while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])) != 0)
	{
		--end;
	}

	return value.substr(start, end - start);
}

bool IsBinaryLike(const std::string& input)
{
	bool hasBinaryDigit = false;
	for (char c : input)
	{
		if (c == '0' || c == '1')
		{
			hasBinaryDigit = true;
			continue;
		}

		if (std::isspace(static_cast<unsigned char>(c)) != 0 || c == '_' || c == '-')
		{
			continue;
		}

		return false;
	}

	return hasBinaryDigit;
}

std::string SanitizeBinaryBits(const std::string& input)
{
	std::string bits;
	for (char c : input)
	{
		if (c == '0' || c == '1')
		{
			bits += c;
		}
	}
	return bits;
}

bool TryParseCsvBytes(const std::string& input, std::vector<int>& bytes)
{
	bytes.clear();
	std::stringstream stream(input);
	std::string token;

	while (std::getline(stream, token, ','))
	{
		const std::string trimmed = Trim(token);
		if (trimmed.empty())
		{
			continue;
		}

		std::size_t processed = 0;
		int value = 0;
		try
		{
			value = std::stoi(trimmed, &processed, 10);
		}
		catch (...)
		{
			bytes.clear();
			return false;
		}

		if (processed != trimmed.size())
		{
			bytes.clear();
			return false;
		}

		if (value < 0)
		{
			value = 0;
		}
		if (value > 255)
		{
			value = 255;
		}

		bytes.push_back(value);
	}

	return !bytes.empty();
}

std::string BytesToBitString(const std::vector<int>& bytes)
{
	std::string bits;
	bits.reserve(bytes.size() * 8);
	for (int byteValue : bytes)
	{
		for (int bit = 7; bit >= 0; --bit)
		{
			bits += (((byteValue >> bit) & 0x01) != 0) ? '1' : '0';
		}
	}
	return bits;
}

int BitsToUInt(const std::string& bits)
{
	int value = 0;
	for (char c : bits)
	{
		value = (value << 1) | ((c == '1') ? 1 : 0);
	}
	return value;
}

std::string ReverseBitOrderBySpecPosition(const std::string& msbToLsbBits)
{
	return std::string(msbToLsbBits.rbegin(), msbToLsbBits.rend());
}

std::string ExtractFieldBits(const std::string& msbToLsbBits, int lowBit, int highBit)
{
	const int wordWidth = static_cast<int>(msbToLsbBits.size());
	const int startIndex = (wordWidth - 1) - highBit;
	const int endIndex = (wordWidth - 1) - lowBit;
	if (startIndex < 0 || endIndex >= wordWidth || startIndex > endIndex)
	{
		return std::string();
	}

	return msbToLsbBits.substr(static_cast<std::size_t>(startIndex), static_cast<std::size_t>(endIndex - startIndex + 1));
}

std::string LookupMeaningText(int dfi, int dui, int numericValue)
{
	ValueMeaning meaning;
	if (!TryResolveValueMeaning(dfi, dui, std::to_string(numericValue), meaning))
	{
		return std::string();
	}

	std::ostringstream builder;
	if (!meaning.dataItem.empty())
	{
		builder << meaning.dataItem;
	}
	if (!meaning.explanation.empty())
	{
		if (builder.tellp() > 0)
		{
			builder << " - ";
		}
		builder << meaning.explanation;
	}
	if (!meaning.applicability.empty())
	{
		if (builder.tellp() > 0)
		{
			builder << " [" << meaning.applicability << "]";
		}
		else
		{
			builder << meaning.applicability;
		}
	}

	return builder.str();
}

WordFieldValue BuildFieldValue(const std::string& wordBits, const FieldSpec& field)
{
	WordFieldValue result;
	result.name = field.name;
	result.dfi = field.dfi;
	result.dui = field.dui;
	result.lowBit = field.lowBit;
	result.highBit = field.highBit;
	result.fallbackText = field.fallback;
	result.bitString = ExtractFieldBits(wordBits, field.lowBit, field.highBit);
	result.numericValue = BitsToUInt(result.bitString);
	if (field.dfi > 0 && field.dui > 0)
	{
		result.resolvedText = LookupMeaningText(field.dfi, field.dui, result.numericValue);
	}
	return result;
}

WordMessage BuildWordMessage(const std::string& msbToLsbBits,
	const char* wordNumber,
	const char* wordTitle,
	const std::vector<FieldSpec>& fields)
{
	WordMessage message;
	message.isValid = true;
	message.wordNumber = wordNumber;
	message.wordTitle = wordTitle;
	message.inputBitOrder = "transmitted order (bit 69 on the left through bit 0 on the right)";
	message.transmittedBits = msbToLsbBits;
	message.specOrderBits = ReverseBitOrderBySpecPosition(msbToLsbBits);

	const std::size_t fieldCount = fields.size();
	if (fieldCount > 256)
	{
		message.isValid = false;
		message.error = "Internal parser state error: invalid field specification count (" + std::to_string(fieldCount) + "). Perform a clean rebuild to refresh stale object files.";
		return message;
	}

	message.fields.reserve(fieldCount);

	for (std::size_t index = 0; index < fieldCount; ++index)
	{
		message.fields.push_back(BuildFieldValue(msbToLsbBits, fields[index]));
	}

	return message;
}

std::string FormatWordMessage(const WordMessage& message)
{
	if (!message.isValid)
	{
		return message.error;
	}

	std::ostringstream out;
	out << message.wordNumber << " decode\n";
	out << "WORD TITLE: " << message.wordTitle << "\n";
	out << "Bit order supplied: " << message.inputBitOrder << ".\n";
	out << "Word bits [69:0]: " << message.transmittedBits << "\n";
	out << "Word bits [0:69]:  " << message.specOrderBits << "\n\n";

	for (std::size_t index = 0; index < message.fields.size(); ++index)
	{
		const WordFieldValue& field = message.fields[index];
		out << field.name
			<< " [" << field.highBit << ':' << field.lowBit << "]"
			<< " = " << field.bitString
			<< " (" << field.numericValue << ")";

		if (!field.resolvedText.empty())
		{
			out << " -> " << field.resolvedText;
		}
		else if (!field.fallbackText.empty())
		{
			out << " -> " << field.fallbackText;
		}

		if (field.dfi > 0 && field.dui > 0)
		{
			out << " [DFI " << field.dfi << ", DUI " << field.dui << "]";
		}

		if (index + 1 < message.fields.size())
		{
			out << "\n";
		}
	}

	return out.str();
}

}
}
