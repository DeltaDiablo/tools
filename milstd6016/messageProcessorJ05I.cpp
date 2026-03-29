#include "messageProcessorJ05I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ05IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.5I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.5I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 101 for J0.5I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"RECURRENCE RATE INDICATOR", 444, 13, 13, 16, "Recurrence rate indicator."},
		{"SPARE", 756, 10, 17, 26, "Spare bits."},
		{"REPROMULGATION COUNTER", 1668, 1, 27, 30, "Repromulgation counter."},
		{"REPROMULGATION COUNTER, ORIGINAL VALUE", 1668, 2, 31, 34, "Repromulgation counter, original value."},
		{"ROUTE NUMBER, 2", 1727, 2, 35, 38, "Route number, 2."},
		{"SPARE", 756, 31, 39, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.5I", "REPROMULGATION RELAY INITIAL WORD", fields);
}

}

J05IMessage ParseJ05IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J05IMessage message;
		message.error = "Invalid J0.5I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ05IWordBitsInternal(bits);
}

J05IMessage ParseJ05IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J05IMessage message;
		message.error = "Invalid J0.5I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J05IMessage message;
		message.error = "Invalid J0.5I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ05IWordBitsInternal(bits.substr(0, 70));
}

J05IMessage ParseJ05IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ05IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ05IMessageBytes(bytes);
	}

	J05IMessage message;
	message.error = "Unable to parse J0.5I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ05IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ05IMessageBits(wordBits));
}

std::string ProcessJ05IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ05IMessageBytes(bytes));
}

std::string ProcessJ05IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ05IMessage(input));
}

}
