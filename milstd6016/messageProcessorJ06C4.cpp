#include "messageProcessorJ06C4.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ06C4WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.6C4."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00100 for J0.6C4."},
		{"ACTION CODE, CRYPTOVARIABLE", 897, 1, 7, 10, "Action code for cryptovariable operation."},
		{"CRYPTOVARIABLE LOGICAL LABEL, MSEC INITIALIZATION", 801, 6, 11, 17, "Cryptovariable logical label for MSEC initialization."},
		{"NET NUMBER, 1", 348, 13, 18, 24, "Net number 1."},
		{"NET NUMBER, 2", 348, 14, 25, 31, "Same coding as for bits 18-24."},
		{"NET NUMBER, 3", 348, 8, 32, 38, "Same coding as for bits 18-24."},
		{"NET NUMBER, 4", 348, 15, 39, 45, "Same coding as for bits 18-24."},
		{"NET NUMBER, 5", 348, 16, 46, 52, "Same coding as for bits 18-24."},
		{"NET NUMBER, 6", 348, 17, 53, 59, "Same coding as for bits 18-24."},
		{"NET NUMBER, 7", 348, 23, 60, 66, "Same coding as for bits 18-24."},
		{"SPARE", 756, 3, 67, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.6C4", "NET NUMBER CONTINUATION WORD", fields);
}

}

J06C4Message ParseJ06C4MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J06C4Message message;
		message.error = "Invalid J0.6C4 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C4WordBitsInternal(bits);
}

J06C4Message ParseJ06C4MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J06C4Message message;
		message.error = "Invalid J0.6C4 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J06C4Message message;
		message.error = "Invalid J0.6C4 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C4WordBitsInternal(bits.substr(0, 70));
}

J06C4Message ParseJ06C4Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ06C4MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ06C4MessageBytes(bytes);
	}

	J06C4Message message;
	message.error = "Invalid J0.6C4 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ06C4MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ06C4MessageBits(wordBits));
}

std::string ProcessJ06C4MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ06C4MessageBytes(bytes));
}

std::string ProcessJ06C4Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ06C4Message(input));
}

}
