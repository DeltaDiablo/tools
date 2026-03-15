#include "messageProcessorJ03C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ03C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.3C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J0.3C1."},
		{"NET NUMBER, DECRYPTION", 348, 22, 7, 13, "Net number, decryption."},
		{"NET NUMBER, RELAY", 348, 7, 14, 20, "Net number, relay."},
		{"SPARE", 756, 49, 21, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.3C1", "TIME SLOT ASSIGNMENT CONTINUATION WORD", fields);
}

}

J03C1Message ParseJ03C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J03C1Message message;
		message.error = "Invalid J0.3C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03C1WordBitsInternal(bits);
}

J03C1Message ParseJ03C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J03C1Message message;
		message.error = "Invalid J0.3C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J03C1Message message;
		message.error = "Invalid J0.3C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03C1WordBitsInternal(bits.substr(0, 70));
}

J03C1Message ParseJ03C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ03C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ03C1MessageBytes(bytes);
	}

	J03C1Message message;
	message.error = "Unable to parse J0.3C1 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ03C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ03C1MessageBits(wordBits));
}

std::string ProcessJ03C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ03C1MessageBytes(bytes));
}

std::string ProcessJ03C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ03C1Message(input));
}

}
