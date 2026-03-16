#include "messageProcessorJ24C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ24C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.4C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J2.4C1."},
		{"SPARE (SP)", 756, 1, 7, 7, "Spare bit."},
		{"MODE I CODE", 293, 3, 8, 12, "Mode I code."},
		{"MODE II CODE", 294, 2, 13, 24, "Mode II code."},
		{"MODE III CODE", 295, 2, 25, 36, "Mode III code."},
		{"SUBSURFACE PLATFORM", 1797, 3, 37, 42, "Subsurface platform."},
		{"SUBSURFACE ACTIVITY", 1798, 3, 43, 49, "Subsurface activity."},
		{"SPARE", 756, 20, 50, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.4C1", "SUBSURFACE PPLI - AMPLIFICATION CONTINUATION WORD", fields);
}

}

J24C1Message ParseJ24C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J24C1Message message;
		message.error = "Invalid J2.4C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24C1WordBitsInternal(bits);
}

J24C1Message ParseJ24C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J24C1Message message;
		message.error = "Invalid J2.4C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J24C1Message message;
		message.error = "Invalid J2.4C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24C1WordBitsInternal(bits.substr(0, 70));
}

J24C1Message ParseJ24C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ24C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ24C1MessageBytes(bytes);
	}

	J24C1Message message;
	message.error = "Invalid J2.4C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ24C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ24C1MessageBits(wordBits));
}

std::string ProcessJ24C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ24C1MessageBytes(bytes));
}

std::string ProcessJ24C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ24C1Message(input));
}

}
