#include "messageProcessorJ01E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ01E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J0.1E0."},
		{"TEST PATTERN", 445, 4, 2, 69, "Test pattern."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.1E0", "TEST EXTENSION WORD", fields);
}

}

J01E0Message ParseJ01E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J01E0Message message;
		message.error = "Invalid J0.1E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01E0WordBitsInternal(bits);
}

J01E0Message ParseJ01E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J01E0Message message;
		message.error = "Invalid J0.1E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J01E0Message message;
		message.error = "Invalid J0.1E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01E0WordBitsInternal(bits.substr(0, 70));
}

J01E0Message ParseJ01E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ01E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ01E0MessageBytes(bytes);
	}

	J01E0Message message;
	message.error = "Unable to parse J0.1E0 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ01E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ01E0MessageBits(wordBits));
}

std::string ProcessJ01E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ01E0MessageBytes(bytes));
}

std::string ProcessJ01E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ01E0Message(input));
}

}
