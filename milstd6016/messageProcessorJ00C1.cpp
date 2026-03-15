#include "messageProcessorJ00C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ00C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.0C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J0.0C1."},
		{"SPARE", 756, 10, 7, 16, "Spare bits."},
		{"TIME SLOT SET, CURRENT (TSS CUR)", 847, 12, 17, 18, "Time slot set, current."},
		{"TIME SLOT NUMBER, CURRENT", 441, 10, 19, 33, "Time slot number, current."},
		{"EPOCH COUNT CURRENT", 448, 2, 34, 40, "Epoch count current."},
		{"SPARE", 756, 29, 41, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.0C1", "MODE 4 CONTINUATION WORD", fields);
}

}

J00C1Message ParseJ00C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00C1WordBitsInternal(bits);
}

J00C1Message ParseJ00C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J00C1Message message;
		message.error = "Invalid J0.0C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00C1WordBitsInternal(bits.substr(0, 70));
}

J00C1Message ParseJ00C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ00C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ00C1MessageBytes(bytes);
	}

	J00C1Message message;
	message.error = "Unable to parse J0.0C1 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ00C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ00C1MessageBits(wordBits));
}

std::string ProcessJ00C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ00C1MessageBytes(bytes));
}

std::string ProcessJ00C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ00C1Message(input));
}

}
