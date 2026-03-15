#include "messageProcessorJ04C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ04C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.4C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J0.4C1."},
		{"NET NUMBER, ORIGINAL NET", 348, 12, 7, 13, "Net number, original net."},
		{"RELAY DELAY, RECEIVE 2", 843, 11, 14, 20, "Relay delay, receive 2."},
		{"SPARE", 756, 49, 21, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.4C1", "RADIO RELAY CONTROL CONTINUATION WORD", fields);
}

}

J04C1Message ParseJ04C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J04C1Message message;
		message.error = "Invalid J0.4C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04C1WordBitsInternal(bits);
}

J04C1Message ParseJ04C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J04C1Message message;
		message.error = "Invalid J0.4C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J04C1Message message;
		message.error = "Invalid J0.4C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04C1WordBitsInternal(bits.substr(0, 70));
}

J04C1Message ParseJ04C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ04C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ04C1MessageBytes(bytes);
	}

	J04C1Message message;
	message.error = "Unable to parse J0.4C1 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ04C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ04C1MessageBits(wordBits));
}

std::string ProcessJ04C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ04C1MessageBytes(bytes));
}

std::string ProcessJ04C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ04C1Message(input));
}

}
