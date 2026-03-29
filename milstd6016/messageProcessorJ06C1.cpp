#include "messageProcessorJ06C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ06C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.6C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J0.6C1."},
		{"ACTION, TIME SLOT REQUEST (ACT TSR)", 1771, 1, 7, 8, "Action code for time slot request."},
		{"SPARE", 756, 1, 9, 9, "Spare bit."},
		{"PARTICIPATION GROUP, 1", 838, 2, 10, 18, "Participation group 1."},
		{"RECURRENCE RATE, 1", 444, 2, 19, 22, "Recurrence rate 1."},
		{"DELTA EPOCH, 1 (DEL EP1)", 1615, 2, 23, 24, "Delta epoch 1."},
		{"PARTICIPATION GROUP, 2", 838, 3, 25, 33, "Same coding as for bits 10-18."},
		{"RECURRENCE RATE, 2", 444, 3, 34, 37, "Same coding as for bits 19-22."},
		{"DELTA EPOCH, 2 (DEL EP2)", 1615, 3, 38, 39, "Same coding as for bits 23-24."},
		{"PARTICIPATION GROUP, 3", 838, 5, 40, 48, "Same coding as for bits 10-18."},
		{"RECURRENCE RATE, 3", 444, 5, 49, 52, "Same coding as for bits 19-22."},
		{"DELTA EPOCH, 3 (DEL EP3)", 1615, 4, 53, 54, "Same coding as for bits 23-24."},
		{"PARTICIPATION GROUP, 4", 838, 6, 55, 63, "Same coding as for bits 10-18."},
		{"RECURRENCE RATE, 4", 444, 4, 64, 67, "Same coding as for bits 19-22."},
		{"DELTA EPOCH, 4 (DEL EP4)", 1615, 5, 68, 69, "Same coding as for bits 23-24."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.6C1", "TIME SLOT BLOCKS ASSIGNMENT/DEASSIGNMENT CONTINUATION WORD", fields);
}

}

J06C1Message ParseJ06C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J06C1Message message;
		message.error = "Invalid J0.6C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C1WordBitsInternal(bits);
}

J06C1Message ParseJ06C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J06C1Message message;
		message.error = "Invalid J0.6C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J06C1Message message;
		message.error = "Invalid J0.6C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06C1WordBitsInternal(bits.substr(0, 70));
}

J06C1Message ParseJ06C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ06C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ06C1MessageBytes(bytes);
	}

	J06C1Message message;
	message.error = "Invalid J0.6C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ06C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ06C1MessageBits(wordBits));
}

std::string ProcessJ06C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ06C1MessageBytes(bytes));
}

std::string ProcessJ06C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ06C1Message(input));
}

}
