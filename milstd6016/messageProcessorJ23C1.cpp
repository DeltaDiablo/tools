#include "messageProcessorJ23C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ23C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.3C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J2.3C1."},
		{"SPARE (SP)", 756, 1, 7, 7, "Spare bit."},
		{"MODE I CODE", 293, 3, 8, 12, "Mode I code."},
		{"MODE II CODE", 294, 2, 13, 24, "Mode II code."},
		{"MODE III CODE", 295, 2, 25, 36, "Mode III code."},
		{"SURFACE PLATFORM", 1797, 2, 37, 42, "Surface platform."},
		{"SURFACE ACTIVITY", 1798, 2, 43, 49, "Surface activity."},
		{"SPARE", 756, 20, 50, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.3C1", "SURFACE PPLI - AMPLIFICATION CONTINUATION WORD", fields);
}

}

J23C1Message ParseJ23C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J23C1Message message;
		message.error = "Invalid J2.3C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ23C1WordBitsInternal(bits);
}

J23C1Message ParseJ23C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J23C1Message message;
		message.error = "Invalid J2.3C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J23C1Message message;
		message.error = "Invalid J2.3C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ23C1WordBitsInternal(bits.substr(0, 70));
}

J23C1Message ParseJ23C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ23C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ23C1MessageBytes(bytes);
	}

	J23C1Message message;
	message.error = "Invalid J2.3C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ23C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ23C1MessageBits(wordBits));
}

std::string ProcessJ23C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ23C1MessageBytes(bytes));
}

std::string ProcessJ23C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ23C1Message(input));
}

}
