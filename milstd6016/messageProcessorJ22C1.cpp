#include "messageProcessorJ22C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.2C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J2.2C1."},
		{"SPARE (SP)", 756, 1, 7, 7, "Spare bit."},
		{"MODE I CODE", 293, 3, 8, 12, "Mode I code."},
		{"MODE II CODE", 294, 2, 13, 24, "Mode II code."},
		{"MODE III CODE", 295, 2, 25, 36, "Mode III code."},
		{"AIR PLATFORM", 1797, 1, 37, 42, "Air platform."},
		{"AIR ACTIVITY", 1798, 1, 43, 49, "Air activity."},
		{"SPARE", 756, 20, 50, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2C1", "AIR PPLI - AMPLIFICATION CONTINUATION WORD", fields);
}

}

J22C1Message ParseJ22C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22C1Message message;
		message.error = "Invalid J2.2C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C1WordBitsInternal(bits);
}

J22C1Message ParseJ22C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22C1Message message;
		message.error = "Invalid J2.2C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22C1Message message;
		message.error = "Invalid J2.2C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C1WordBitsInternal(bits.substr(0, 70));
}

J22C1Message ParseJ22C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22C1MessageBytes(bytes);
	}

	J22C1Message message;
	message.error = "Invalid J2.2C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22C1MessageBits(wordBits));
}

std::string ProcessJ22C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22C1MessageBytes(bytes));
}

std::string ProcessJ22C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22C1Message(input));
}

}
