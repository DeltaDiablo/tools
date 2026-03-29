#include "messageProcessorJ06C3.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ06C3WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.6C3."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00011 for J0.6C3."},
		{"ACTION CODE, CRYPTOVARIABLE", 897, 1, 7, 10, "Action code for cryptovariable operation."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 11, 19, "Participation group identifier."},
		{"NET NUMBER", 348, 1, 20, 26, "Net number."},
		{"CRYPTOVARIABLE LOGICAL LABEL A, TRANSEC", 801, 7, 27, 33, "Cryptovariable logical label A, TRANSEC."},
		{"CRYPTOVARIABLE LOGICAL LABEL B, TRANSEC", 801, 8, 34, 40, "Same coding as for bits 27-33."},
		{"EFFECTIVE FROM MINUTE", 797, 1, 41, 46, "Effective from minute."},
		{"EFFECTIVE FROM HOUR", 792, 2, 47, 51, "Effective from hour."},
		{"SPARE", 756, 1, 52, 52, "Spare bit."},
		{"CRYPTOVARIABLE LOGICAL LABEL C, MSEC", 801, 9, 53, 59, "Same coding as for bits 27-33."},
		{"CRYPTOVARIABLE LOGICAL LABEL D, MSEC", 801, 10, 60, 66, "Same coding as for bits 27-33."},
		{"SPARE", 756, 3, 67, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.6C3", "CRYPTOVARIABLE LOGICAL LABEL CONTINUATION WORD", fields);
}

}

J06C3Message ParseJ06C3MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J06C3Message message;
		message.error = "Invalid J0.6C3 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C3WordBitsInternal(bits);
}

J06C3Message ParseJ06C3MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J06C3Message message;
		message.error = "Invalid J0.6C3 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J06C3Message message;
		message.error = "Invalid J0.6C3 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C3WordBitsInternal(bits.substr(0, 70));
}

J06C3Message ParseJ06C3Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ06C3MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ06C3MessageBytes(bytes);
	}

	J06C3Message message;
	message.error = "Invalid J0.6C3 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ06C3MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ06C3MessageBits(wordBits));
}

std::string ProcessJ06C3MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ06C3MessageBytes(bytes));
}

std::string ProcessJ06C3Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ06C3Message(input));
}

}
