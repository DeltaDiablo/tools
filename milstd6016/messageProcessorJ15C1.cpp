#include "messageProcessorJ15C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ15C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J1.5C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J1.5C1."},
		{"ADD/DELETE INDICATOR (A/D IND)", 777, 1, 7, 7, "Add/delete indicator."},
		{"TRACK NUMBER, SECONDARY 1", 769, 57, 8, 22, "Track number, secondary 1."},
		{"TRACK NUMBER, SECONDARY 2", 769, 58, 23, 37, "Same coding as for bits 8-22."},
		{"TRACK NUMBER, SECONDARY 3", 769, 59, 38, 52, "Same coding as for bits 8-22."},
		{"TRACK NUMBER, SECONDARY 4", 769, 60, 53, 67, "Same coding as for bits 8-22."},
		{"SPARE (SP)", 756, 2, 68, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.5C1", "NET CONTROL INITIALIZATION CONTINUATION WORD", fields);
}

}

J15C1Message ParseJ15C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J15C1Message message;
		message.error = "Invalid J1.5C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15C1WordBitsInternal(bits);
}

J15C1Message ParseJ15C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J15C1Message message;
		message.error = "Invalid J1.5C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J15C1Message message;
		message.error = "Invalid J1.5C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15C1WordBitsInternal(bits.substr(0, 70));
}

J15C1Message ParseJ15C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ15C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ15C1MessageBytes(bytes);
	}

	J15C1Message message;
	message.error = "Invalid J1.5C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ15C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ15C1MessageBits(wordBits));
}

std::string ProcessJ15C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ15C1MessageBytes(bytes));
}

std::string ProcessJ15C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ15C1Message(input));
}

}
