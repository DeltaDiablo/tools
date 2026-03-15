#include "messageProcessorJ01I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ01IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.1I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.1I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 001 for J0.1I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"SPARE", 756, 57, 13, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.1I", "TEST INITIAL WORD", fields);
}

}

J01IMessage ParseJ01IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J01IMessage message;
		message.error = "Invalid J0.1I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01IWordBitsInternal(bits);
}

J01IMessage ParseJ01IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J01IMessage message;
		message.error = "Invalid J0.1I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J01IMessage message;
		message.error = "Invalid J0.1I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ01IWordBitsInternal(bits.substr(0, 70));
}

J01IMessage ParseJ01IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ01IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ01IMessageBytes(bytes);
	}

	J01IMessage message;
	message.error = "Unable to parse J0.1I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ01IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ01IMessageBits(wordBits));
}

std::string ProcessJ01IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ01IMessageBytes(bytes));
}

std::string ProcessJ01IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ01IMessage(input));
}

}
