#include "messageProcessorJ22C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.2C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J2.2C2."},
		{"MISSION ASSIGNMENT", 391, 3, 7, 11, "Mission assignment."},
		{"SIDE", 1420, 1, 12, 16, "Side."},
		{"SPARE", 756, 8, 17, 24, "Spare bits."},
		{"PRIMARY TARGET IDENTIFICATION", 1703, 1, 25, 48, "Primary target identification."},
		{"SECONDARY TARGET IDENTIFICATION", 1704, 1, 49, 62, "Secondary target identification."},
		{"SPARE", 756, 20, 63, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2C2", "AIR PPLI - ASSIGNMENT CONTINUATION WORD", fields);
}

}

J22C2Message ParseJ22C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22C2Message message;
		message.error = "Invalid J2.2C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C2WordBitsInternal(bits);
}

J22C2Message ParseJ22C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22C2Message message;
		message.error = "Invalid J2.2C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22C2Message message;
		message.error = "Invalid J2.2C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C2WordBitsInternal(bits.substr(0, 70));
}

J22C2Message ParseJ22C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22C2MessageBytes(bytes);
	}

	J22C2Message message;
	message.error = "Invalid J2.2C2 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22C2MessageBits(wordBits));
}

std::string ProcessJ22C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22C2MessageBytes(bytes));
}

std::string ProcessJ22C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22C2Message(input));
}

}
