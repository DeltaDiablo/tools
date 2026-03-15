#include "messageProcessorJ03E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ03E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J0.3E0."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 2, 10, "Participation group."},
		{"ACCESS DESCRIPTION", 1772, 1, 11, 16, "Access description."},
		{"RECURRENCE RATE", 444, 1, 17, 20, "Recurrence rate."},
		{"TIME SLOT SET", 847, 13, 21, 22, "Time slot set."},
		{"TIME SLOT NUMBER, INDEX", 441, 21, 23, 37, "Time slot number, index."},
		{"TIME SLOT ASSIGNMENT ACTION (TSA ACT)", 446, 1, 38, 38, "Time slot assignment action."},
		{"TIME SLOT ASSIGNMENT TYPE (TSA TYP)", 449, 1, 39, 39, "Time slot assignment type."},
		{"TIME SLOT ASSIGNMENT QUALIFIER (TSA QLA)", 351, 15, 40, 40, "Time slot assignment qualifier."},
		{"NET NUMBER, SPECIFIED", 348, 21, 41, 47, "Net number, specified."},
		{"CRYPTOVARIABLE LOGICAL LABEL NUMBER ONE", 801, 19, 48, 54, "Cryptovariable logical label number one."},
		{"CRYPTOMODE INDICATOR (CYP MDE)", 802, 1, 55, 55, "Cryptomode indicator."},
		{"CRYPTOVARIABLE LOGICAL LABEL NUMBER TWO", 801, 20, 56, 62, "Cryptovariable logical label number two."},
		{"RELAY DELAY, RECEIVE 1", 843, 10, 63, 69, "Relay delay, receive 1."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.3E0", "TIME SLOT ASSIGNMENT EXTENSION WORD", fields);
}

}

J03E0Message ParseJ03E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J03E0Message message;
		message.error = "Invalid J0.3E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03E0WordBitsInternal(bits);
}

J03E0Message ParseJ03E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J03E0Message message;
		message.error = "Invalid J0.3E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J03E0Message message;
		message.error = "Invalid J0.3E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03E0WordBitsInternal(bits.substr(0, 70));
}

J03E0Message ParseJ03E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ03E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ03E0MessageBytes(bytes);
	}

	J03E0Message message;
	message.error = "Unable to parse J0.3E0 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ03E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ03E0MessageBits(wordBits));
}

std::string ProcessJ03E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ03E0MessageBytes(bytes));
}

std::string ProcessJ03E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ03E0Message(input));
}

}
