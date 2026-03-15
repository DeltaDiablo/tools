#include "messageProcessorJ11C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ11C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J1.1C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J1.1C1."},
		{"CONNECTIVITY QUALITY, 8 (CQ, 8)", 1725, 8, 7, 8, "Connectivity quality, JU 8."},
		{"CONNECTIVITY QUALITY, 9 (CQ, 9)", 1725, 9, 9, 10, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, 10 (CQ, 10)", 1725, 10, 11, 12, "Same coding as for bits 7-8."},
		{"TRACK NUMBER, JU 8", 769, 23, 13, 27, "Track number, JU 8."},
		{"TRACK NUMBER, JU 9", 769, 11, 28, 42, "Same coding as for bits 13-27."},
		{"TRACK NUMBER, JU 10", 769, 12, 43, 57, "Same coding as for bits 13-27."},
		{"COMMUNITY DESIGNATOR", 1774, 1, 58, 61, "Community designator."},
		{"RELAY LEVEL", 1775, 1, 62, 65, "Relay level."},
		{"SPARE", 756, 4, 66, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.1C1", "CONNECTIVITY STATUS CONTINUATION WORD 1", fields);
}

}

J11C1Message ParseJ11C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J11C1Message message;
		message.error = "Invalid J1.1C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11C1WordBitsInternal(bits);
}

J11C1Message ParseJ11C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J11C1Message message;
		message.error = "Invalid J1.1C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J11C1Message message;
		message.error = "Invalid J1.1C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11C1WordBitsInternal(bits.substr(0, 70));
}

J11C1Message ParseJ11C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ11C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ11C1MessageBytes(bytes);
	}

	J11C1Message message;
	message.error = "Invalid J1.1C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ11C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ11C1MessageBits(wordBits));
}

std::string ProcessJ11C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ11C1MessageBytes(bytes));
}

std::string ProcessJ11C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ11C1Message(input));
}

}
