#include "messageProcessorJ12E1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ12E1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.2E1."},
		{"TRACK NUMBER, RELAY 5", 769, 69, 2, 16, "Track number, relay 5."},
		{"TRACK NUMBER, RELAY 6", 769, 70, 17, 31, "Same coding as for bits 2-16."},
		{"TRACK NUMBER, RELAY 7", 769, 71, 32, 46, "Same coding as for bits 2-16."},
		{"SPARE", 756, 23, 47, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.2E1", "SET MANAGEMENT EXTENSION WORD 2", fields);
}

}

J12E1Message ParseJ12E1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J12E1Message message;
		message.error = "Invalid J1.2E1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12E1WordBitsInternal(bits);
}

J12E1Message ParseJ12E1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J12E1Message message;
		message.error = "Invalid J1.2E1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J12E1Message message;
		message.error = "Invalid J1.2E1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12E1WordBitsInternal(bits.substr(0, 70));
}

J12E1Message ParseJ12E1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ12E1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ12E1MessageBytes(bytes);
	}

	J12E1Message message;
	message.error = "Invalid J1.2E1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ12E1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ12E1MessageBits(wordBits));
}

std::string ProcessJ12E1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ12E1MessageBytes(bytes));
}

std::string ProcessJ12E1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ12E1Message(input));
}

}
