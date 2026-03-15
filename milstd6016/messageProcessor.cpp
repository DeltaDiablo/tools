#include "messageProcessor.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <sstream>
#include <vector>

#include "messageLibrary.h"

namespace milstd6016 {

namespace {

struct J00IFieldSpec
{
	const char* name;
	int dfi;
	int dui;
	int lowBit;
	int highBit;
	const char* fallback;
};

std::string ExtractFieldBits(const std::string& msbToLsbBits, int lowBit, int highBit);
int BitsToUInt(const std::string& bits);
std::string LookupMeaningText(int dfi, int dui, int numericValue);

J00IFieldValue BuildJ00IFieldValue(const std::string& wordBits, const J00IFieldSpec& field)
{
	J00IFieldValue result;
	result.name = field.name;
	result.dfi = field.dfi;
	result.dui = field.dui;
	result.lowBit = field.lowBit;
	result.highBit = field.highBit;
	result.fallbackText = (field.fallback != 0) ? field.fallback : "";
	result.bitString = ExtractFieldBits(wordBits, field.lowBit, field.highBit);
	result.numericValue = BitsToUInt(result.bitString);
	if (field.dfi > 0 && field.dui > 0)
	{
		result.resolvedText = LookupMeaningText(field.dfi, field.dui, result.numericValue);
	}
	return result;
}

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

J00IMessage ParseJ00IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::array<J00IFieldSpec, 17> fields = {{
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.0I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.0I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 000 for J0.0I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"SPARE", 756, 3, 13, 15, "Spare bits."},
		{"DISUSED", 758, 7, 16, 22, "Disused field."},
		{"RTT REPLY STATUS INDICATOR (RRS)", 274, 1, 23, 23, "RTT reply status indicator."},
		{"SLOT ASSIGN INDEX NUMBER (SAI NUM)", 1552, 1, 24, 27, "Slot assign index number."},
		{"TIME QUALITY", 279, 1, 28, 31, "Time quality."},
		{"RECURRENCE RATE, VOICE A", 444, 15, 32, 35, "Recurrence rate for Voice A."},
		{"TIME SLOT SET, VOICE A (TSS V-A)", 847, 17, 36, 37, "Time slot set for Voice A."},
		{"TIME SLOT NUMBER, VOICE A", 441, 32, 38, 41, "Time slot number for Voice A."},
		{"OFFSET, VOICE B", 843, 5, 42, 46, "Offset for Voice B."},
		{"RECURRENCE RATE, RTT-B", 444, 14, 47, 50, "Same coding family as recurrence rate for Voice A."},
		{"TIME SLOT SET, RTT-B (TSS RTT)", 847, 16, 51, 52, "Same coding family as time slot set for Voice A."},
		{"TIME SLOT NUMBER, RTT-B", 441, 31, 53, 57, "Time slot number for RTT-B."},
		{"ACCESS RATE, RTT-B", 1772, 2, 58, 61, "Access rate for RTT-B."}
	}};

	static const std::array<J00IFieldSpec, 2> trailingFields = {{
		{"ACCESS RATE, PPLI B", 1772, 4, 62, 65, "Same coding family as access rate for RTT-B."},
		{"SPARE", 756, 4, 66, 69, "Spare bits."}
	}};

	J00IMessage message;
	message.isValid = true;
	message.wordNumber = "J0.0I";
	message.wordTitle = "INITIAL ENTRY INITIAL WORD";
	message.inputBitOrder = "transmitted order (bit 69 on the left through bit 0 on the right)";
	message.transmittedBits = msbToLsbBits;
	message.specOrderBits = ReverseBitOrderBySpecPosition(msbToLsbBits);
	message.fields.reserve(fields.size() + trailingFields.size());

	for (std::size_t index = 0; index < fields.size(); ++index)
	{
		message.fields.push_back(BuildJ00IFieldValue(msbToLsbBits, fields[index]));
	}

	for (std::size_t index = 0; index < trailingFields.size(); ++index)
	{
		message.fields.push_back(BuildJ00IFieldValue(msbToLsbBits, trailingFields[index]));
	}

	return message;
}

J00C1Message ParseJ00C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::array<J00IFieldSpec, 6> fields = {{
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.0C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J0.0C1."},
		{"SPARE", 756, 10, 7, 16, "Spare bits."},
		{"TIME SLOT SET, CURRENT (TSS CUR)", 847, 12, 17, 18, "Time slot set, current."},
		{"TIME SLOT NUMBER, CURRENT", 441, 10, 19, 33, "Time slot number, current."},
		{"EPOCH COUNT CURRENT", 448, 2, 34, 40, "Epoch count current."}
	}};

	static const std::array<J00IFieldSpec, 1> trailingFields = {{
		{"SPARE", 756, 29, 41, 69, "Spare bits."}
	}};

	J00C1Message message;
	message.isValid = true;
	message.wordNumber = "J0.0C1";
	message.wordTitle = "MODE 4 CONTINUATION WORD";
	message.inputBitOrder = "transmitted order (bit 69 on the left through bit 0 on the right)";
	message.transmittedBits = msbToLsbBits;
	message.specOrderBits = ReverseBitOrderBySpecPosition(msbToLsbBits);
	message.fields.reserve(fields.size() + trailingFields.size());

	for (std::size_t index = 0; index < fields.size(); ++index)
	{
		message.fields.push_back(BuildJ00IFieldValue(msbToLsbBits, fields[index]));
	}

	for (std::size_t index = 0; index < trailingFields.size(); ++index)
	{
		message.fields.push_back(BuildJ00IFieldValue(msbToLsbBits, trailingFields[index]));
	}

	return message;
}

std::string FormatJ00IMessage(const J00IMessage& message)
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
		const J00IFieldValue& field = message.fields[index];
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

std::string FormatJ00C1Message(const J00C1Message& message)
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
		const J00C1FieldValue& field = message.fields[index];
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

std::string FormatValueMeaning(const ValueMeaning& value)
{
	std::ostringstream builder;
	builder << "DFI " << value.dfi << ", DUI " << value.dui;
	if (!value.duiName.empty())
	{
		builder << " (" << value.duiName << ")";
	}
	builder << '\n';
	builder << "BIT_CODE: " << value.bitCode << '\n';
	builder << "DATA_ITEM: " << value.dataItem;
	if (!value.applicability.empty())
	{
		builder << '\n' << "APPLICABILITY: " << value.applicability;
	}
	if (!value.explanation.empty())
	{
		builder << '\n' << "EXPLANATION: " << value.explanation;
	}
	return builder.str();
}

}

std::string DescribeValueMeaning(int dfi, int dui, const std::string& bitCode, bool resolveRanges)
{
	ValueMeaning value;
	const bool found = resolveRanges
		? TryResolveValueMeaning(dfi, dui, bitCode, value)
		: TryGetValueMeaning(dfi, dui, bitCode, value);

	if (!found)
	{
		std::ostringstream builder;
		builder << "No MIL-STD-6016 value meaning found for DFI " << dfi
				<< ", DUI " << dui
				<< ", BIT_CODE '" << bitCode << "'.";

		const std::string sourcePath = GetCatalogSourcePath();
		if (sourcePath.empty())
		{
			builder << " Catalog file was not found.";
		}
		return builder.str();
	}

	return FormatValueMeaning(value);
}

std::string DescribeAllValueMeanings(int dfi, int dui)
{
	const std::vector<ValueMeaning> values = GetValueMeanings(dfi, dui);
	if (values.empty())
	{
		std::ostringstream builder;
		builder << "No MIL-STD-6016 entries found for DFI " << dfi << ", DUI " << dui << ".";
		const std::string sourcePath = GetCatalogSourcePath();
		if (sourcePath.empty())
		{
			builder << " Catalog file was not found.";
		}
		return builder.str();
	}

	std::ostringstream builder;
	for (std::size_t index = 0; index < values.size(); ++index)
	{
		if (index != 0)
		{
			builder << "\n\n";
		}
		builder << FormatValueMeaning(values[index]);
	}

	return builder.str();
}

J00IMessage ParseJ00IMessageBits(const std::string& wordBits)
{
	const std::string bits = SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J00IMessage message;
		message.error = "Invalid J0.0I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00IWordBitsInternal(bits);
}

J00IMessage ParseJ00IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J00IMessage message;
		message.error = "Invalid J0.0I input: no bytes were provided.";
		return message;
	}

	const std::string bits = BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J00IMessage message;
		message.error = "Invalid J0.0I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00IWordBitsInternal(bits.substr(0, 70));
}

J00IMessage ParseJ00IMessage(const std::string& input)
{
	if (IsBinaryLike(input))
	{
		return ParseJ00IMessageBits(input);
	}

	std::vector<int> bytes;
	if (TryParseCsvBytes(input, bytes))
	{
		return ParseJ00IMessageBytes(bytes);
	}

	J00IMessage message;
	message.error = "Unable to parse J0.0I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

J00C1Message ParseJ00C1MessageBits(const std::string& wordBits)
{
	const std::string bits = SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00C1WordBitsInternal(bits);
}

J00C1Message ParseJ00C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00C1WordBitsInternal(bits.substr(0, 70));
}

J00C1Message ParseJ00C1Message(const std::string& input)
{
	if (IsBinaryLike(input))
	{
		return ParseJ00C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (TryParseCsvBytes(input, bytes))
	{
		return ParseJ00C1MessageBytes(bytes);
	}

	J00C1Message message;
	message.error = "Unable to parse J0.0C1 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ00IMessageBits(const std::string& wordBits)
{
	return FormatJ00IMessage(ParseJ00IMessageBits(wordBits));
}

std::string ProcessJ00IMessageBytes(const std::vector<int>& bytes)
{
	return FormatJ00IMessage(ParseJ00IMessageBytes(bytes));
}

std::string ProcessJ00IMessage(const std::string& input)
{
	return FormatJ00IMessage(ParseJ00IMessage(input));
}

std::string ProcessJ00C1MessageBits(const std::string& wordBits)
{
	return FormatJ00C1Message(ParseJ00C1MessageBits(wordBits));
}

std::string ProcessJ00C1MessageBytes(const std::vector<int>& bytes)
{
	return FormatJ00C1Message(ParseJ00C1MessageBytes(bytes));
}

std::string ProcessJ00C1Message(const std::string& input)
{
	return FormatJ00C1Message(ParseJ00C1Message(input));
}

}
