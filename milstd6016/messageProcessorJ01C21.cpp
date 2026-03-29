#include "messageProcessorJ01C21.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ01C21WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.1C21."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 10101 (21) for J0.1C21."},
		{"TEST PATTERN, 1", 445, 5, 7, 69, "Test pattern, 1."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.1C21", "TEST CONTINUATION WORD", fields);
}

}

J01C21Message ParseJ01C21MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J01C21Message message;
		message.error = "Invalid J0.1C21 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01C21WordBitsInternal(bits);
}

J01C21Message ParseJ01C21MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J01C21Message message;
		message.error = "Invalid J0.1C21 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J01C21Message message;
		message.error = "Invalid J0.1C21 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01C21WordBitsInternal(bits.substr(0, 70));
}

J01C21Message ParseJ01C21Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ01C21MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ01C21MessageBytes(bytes);
	}

	J01C21Message message;
	message.error = "Unable to parse J0.1C21 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ01C21MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ01C21MessageBits(wordBits));
}

std::string ProcessJ01C21MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ01C21MessageBytes(bytes));
}

std::string ProcessJ01C21Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ01C21Message(input));
}

}
