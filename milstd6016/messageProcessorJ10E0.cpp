#include "messageProcessorJ10E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ10E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.0E0."},
		{"SPARE", 756, 8, 2, 9, "Spare bits."},
		{"TRACK NUMBER, JU 4", 769, 35, 10, 24, "Track number, JU 4."},
		{"TRACK NUMBER, JU 5", 769, 36, 25, 39, "Same coding as for bits 10-24."},
		{"TRACK NUMBER, JU 6", 769, 37, 40, 54, "Same coding as for bits 10-24."},
		{"TRACK NUMBER, JU 7", 769, 38, 55, 69, "Same coding as for bits 10-24."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.0E0", "CONNECTIVITY INTERROGATION EXTENSION WORD", fields);
}

}

J10E0Message ParseJ10E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J10E0Message message;
		message.error = "Invalid J1.0E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ10E0WordBitsInternal(bits);
}

J10E0Message ParseJ10E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J10E0Message message;
		message.error = "Invalid J1.0E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J10E0Message message;
		message.error = "Invalid J1.0E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ10E0WordBitsInternal(bits.substr(0, 70));
}

J10E0Message ParseJ10E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ10E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ10E0MessageBytes(bytes);
	}

	J10E0Message message;
	message.error = "Invalid J1.0E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ10E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ10E0MessageBits(wordBits));
}

std::string ProcessJ10E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ10E0MessageBytes(bytes));
}

std::string ProcessJ10E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ10E0Message(input));
}

}
