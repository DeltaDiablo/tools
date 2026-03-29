#include "messageProcessorJ12E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ12E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.2E0."},
		{"TRACK NUMBER, RELAY 1", 769, 65, 2, 16, "Track number, relay 1."},
		{"TRACK NUMBER, RELAY 2", 769, 66, 17, 31, "Same coding as for bits 2-16."},
		{"TRACK NUMBER, RELAY 3", 769, 67, 32, 46, "Same coding as for bits 2-16."},
		{"TRACK NUMBER, RELAY 4", 769, 68, 47, 61, "Same coding as for bits 2-16."},
		{"SPARE", 756, 8, 62, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.2E0", "SET MANAGEMENT EXTENSION WORD 1", fields);
}

}

J12E0Message ParseJ12E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J12E0Message message;
		message.error = "Invalid J1.2E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12E0WordBitsInternal(bits);
}

J12E0Message ParseJ12E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J12E0Message message;
		message.error = "Invalid J1.2E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J12E0Message message;
		message.error = "Invalid J1.2E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12E0WordBitsInternal(bits.substr(0, 70));
}

J12E0Message ParseJ12E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ12E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ12E0MessageBytes(bytes);
	}

	J12E0Message message;
	message.error = "Invalid J1.2E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ12E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ12E0MessageBits(wordBits));
}

std::string ProcessJ12E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ12E0MessageBytes(bytes));
}

std::string ProcessJ12E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ12E0Message(input));
}

}
