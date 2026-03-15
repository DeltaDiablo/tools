#include "messageProcessorJ06C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ06C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.6C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J0.6C2."},
		{"NEEDLINE PARTICIPATION GROUP STATUS, 1 (NPG ST1)", 1789, 1, 7, 10, "Needline participation group status 1."},
		{"NEEDLINE PARTICIPATION GROUP STATUS AMPLIFY, 1 (NPG SA1)", 1790, 1, 11, 13, "Needline participation group status amplify 1."},
		{"TEST DURATION COUNT, 1", 1791, 1, 14, 21, "Test duration count 1."},
		{"PARTICIPATION GROUP, 1", 838, 2, 22, 30, "Participation group 1."},
		{"NEEDLINE PARTICIPATION GROUP STATUS, 2 (NPG ST2)", 1789, 2, 31, 34, "Same coding as for bits 7-10."},
		{"NEEDLINE PARTICIPATION GROUP STATUS AMPLIFY, 2 (NPG SA2)", 1790, 2, 35, 37, "Same coding as for bits 11-13."},
		{"TEST DURATION COUNT, 2", 1791, 2, 38, 45, "Same coding as for bits 14-21."},
		{"PARTICIPATION GROUP, 2", 838, 3, 46, 54, "Same coding as for bits 22-30."},
		{"SPARE", 756, 15, 55, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.6C2", "NET STATUS NEEDLINE PARTICIPATION GROUP STATUS CONTINUATION WORD", fields);
}

}

J06C2Message ParseJ06C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J06C2Message message;
		message.error = "Invalid J0.6C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C2WordBitsInternal(bits);
}

J06C2Message ParseJ06C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J06C2Message message;
		message.error = "Invalid J0.6C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J06C2Message message;
		message.error = "Invalid J0.6C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C2WordBitsInternal(bits.substr(0, 70));
}

J06C2Message ParseJ06C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ06C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ06C2MessageBytes(bytes);
	}

	J06C2Message message;
	message.error = "Invalid J0.6C2 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ06C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ06C2MessageBits(wordBits));
}

std::string ProcessJ06C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ06C2MessageBytes(bytes));
}

std::string ProcessJ06C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ06C2Message(input));
}

}
