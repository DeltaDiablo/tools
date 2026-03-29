#include "messageProcessorJ03C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ03C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.3C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J0.3C2."},
		{"INDEX NUMBER, SET (INSET)", 1781, 1, 7, 14, "Index number, set."},
		{"ACTION CODE (ACT CD)", 803, 2, 15, 18, "Action code."},
		{"INDEX NUMBER, NEW SET (NEWSET)", 1781, 2, 19, 26, "Index number, new set."},
		{"SPARE", 756, 43, 27, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.3C2", "TIME SLOT ASSIGNMENT CONTINUATION WORD 2", fields);
}

}

J03C2Message ParseJ03C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J03C2Message message;
		message.error = "Invalid J0.3C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03C2WordBitsInternal(bits);
}

J03C2Message ParseJ03C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J03C2Message message;
		message.error = "Invalid J0.3C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J03C2Message message;
		message.error = "Invalid J0.3C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03C2WordBitsInternal(bits.substr(0, 70));
}

J03C2Message ParseJ03C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ03C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ03C2MessageBytes(bytes);
	}

	J03C2Message message;
	message.error = "Unable to parse J0.3C2 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ03C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ03C2MessageBits(wordBits));
}

std::string ProcessJ03C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ03C2MessageBytes(bytes));
}

std::string ProcessJ03C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ03C2Message(input));
}

}
