#include "messageProcessorJ00E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ00E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J0.0E0."},
		{"RECURRENCE RATE, PPLI A", 444, 16, 2, 5, "Recurrence rate, PPLI A."},
		{"TIME SLOT SET, PPLI A (TSS PA)", 847, 18, 6, 7, "Time slot set, PPLI A."},
		{"TIME SLOT NUMBER, PPLI A", 441, 33, 8, 14, "Time slot number, PPLI A."},
		{"RELAY DELAY, PPLI A", 843, 6, 15, 19, "Relay delay, PPLI A."},
		{"RECURRENCE RATE, PPLI B 1", 444, 17, 20, 23, "Same coding family as recurrence rate, PPLI A."},
		{"TIME SLOT SET, PPLI B 1 (TSS PB1)", 847, 19, 24, 25, "Same coding family as time slot set, PPLI A."},
		{"TIME SLOT NUMBER, PPLI B 1", 441, 34, 26, 32, "Same coding family as time slot number, PPLI A."},
		{"RECURRENCE RATE, PPLI B 2", 444, 18, 33, 36, "Same coding family as recurrence rate, PPLI A."},
		{"TIME SLOT SET, PPLI B 2 (TSS PB2)", 847, 20, 37, 38, "Same coding family as time slot set, PPLI A."},
		{"TIME SLOT NUMBER, PPLI B 2", 441, 35, 39, 45, "Same coding family as time slot number, PPLI A."},
		{"RECURRENCE RATE, CONTROL", 444, 19, 46, 49, "Same coding family as recurrence rate, PPLI A."},
		{"TIME SLOT SET, CONTROL (TSS CNT)", 847, 21, 50, 51, "Same coding family as time slot set, PPLI A."},
		{"TIME SLOT NUMBER, CONTROL", 441, 36, 52, 58, "Same coding family as time slot number, PPLI A."},
		{"RELAY DELAY, CONTROL", 843, 7, 59, 63, "Same coding family as relay delay, PPLI A."},
		{"ACCESS RATE, PPLI A", 1772, 3, 64, 67, "Access rate, PPLI A."},
		{"SPARE", 756, 2, 68, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.0E0", "INITIAL ENTRY EXTENSION WORD", fields);
}

}

J00E0Message ParseJ00E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J00E0Message message;
		message.error = "Invalid J0.0E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00E0WordBitsInternal(bits);
}

J00E0Message ParseJ00E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J00E0Message message;
		message.error = "Invalid J0.0E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J00E0Message message;
		message.error = "Invalid J0.0E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00E0WordBitsInternal(bits.substr(0, 70));
}

J00E0Message ParseJ00E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ00E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ00E0MessageBytes(bytes);
	}

	J00E0Message message;
	message.error = "Unable to parse J0.0E0 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ00E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ00E0MessageBits(wordBits));
}

std::string ProcessJ00E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ00E0MessageBytes(bytes));
}

std::string ProcessJ00E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ00E0Message(input));
}

}
