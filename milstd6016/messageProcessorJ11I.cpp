#include "messageProcessorJ11I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ11IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.1I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.1I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 001 for J1.1I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"CONNECTIVITY STATUS INSTRUCTION (CSI)", 1728, 1, 13, 14, "Connectivity status instruction code."},
		{"CONNECTIVITY STATUS LEVEL (CON STS)", 1729, 1, 15, 17, "Connectivity status level."},
		{"SPARE", 756, 1, 18, 18, "Spare bit."},
		{"CONNECTIVITY QUALITY, 1 (CQ, 1)", 1725, 1, 19, 20, "Connectivity quality, JU 1."},
		{"CONNECTIVITY QUALITY, 2 (CQ, 2)", 1725, 2, 21, 22, "Same coding as for bits 19-20."},
		{"CONNECTIVITY QUALITY, 3 (CQ, 3)", 1725, 3, 23, 24, "Same coding as for bits 19-20."},
		{"TRACK NUMBER, JU 1", 769, 32, 25, 39, "Track number, JU 1."},
		{"TRACK NUMBER, JU 2", 769, 33, 40, 54, "Same coding as for bits 25-39."},
		{"TRACK NUMBER, JU 3", 769, 34, 55, 69, "Same coding as for bits 25-39."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.1I", "CONNECTIVITY STATUS INITIAL WORD", fields);
}

}

J11IMessage ParseJ11IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J11IMessage message;
		message.error = "Invalid J1.1I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11IWordBitsInternal(bits);
}

J11IMessage ParseJ11IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J11IMessage message;
		message.error = "Invalid J1.1I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J11IMessage message;
		message.error = "Invalid J1.1I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11IWordBitsInternal(bits.substr(0, 70));
}

J11IMessage ParseJ11IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ11IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ11IMessageBytes(bytes);
	}

	J11IMessage message;
	message.error = "Invalid J1.1I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ11IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ11IMessageBits(wordBits));
}

std::string ProcessJ11IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ11IMessageBytes(bytes));
}

std::string ProcessJ11IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ11IMessage(input));
}

}
