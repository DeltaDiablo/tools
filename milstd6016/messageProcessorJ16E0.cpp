#include "messageProcessorJ16E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ16E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.6E0."},
		{"PARTICIPATION GROUP, 1 [base word]", 838, 2, 2, 10, "Transmitted in the base J1.6E0 word in the J1.6 message."},
		{"PARTICIPATION GROUP, 2 [first repetition]", 838, 3, 2, 10, "Transmitted in the first repetition of J1.6E0. Same coding as for bits 2-10."},
		{"RESPONSE TIME", 1787, 1, 11, 19, "Response time."},
		{"ASSIGN/DEASSIGN INDICATOR (A/D IND)", 1788, 1, 20, 21, "Assign/deassign indicator."},
		{"TRACK NUMBER, ADDRESSEE 1 [base word]", 769, 17, 22, 36, "Transmitted in the base J1.6E0 word in the J1.6 message."},
		{"TRACK NUMBER, ADDRESSEE 2 [base word]", 769, 19, 37, 51, "Transmitted in the base J1.6E0 word in the J1.6 message. Same coding as for bits 22-36."},
		{"TRACK NUMBER, ADDRESSEE 3 [base word]", 769, 20, 52, 66, "Transmitted in the base J1.6E0 word in the J1.6 message. Same coding as for bits 22-36."},
		{"TRACK NUMBER, ADDRESSEE 4 [first repetition]", 769, 21, 22, 36, "Transmitted in the first repetition of J1.6E0. Same coding as for bits 22-36."},
		{"TRACK NUMBER, ADDRESSEE 5 [first repetition]", 769, 22, 37, 51, "Transmitted in the first repetition of J1.6E0. Same coding as for bits 22-36."},
		{"TRACK NUMBER, ADDRESSEE 6 [first repetition]", 769, 16, 52, 66, "Transmitted in the first repetition of J1.6E0. Same coding as for bits 22-36."},
		{"SPARE", 756, 3, 67, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.6E0", "NEEDLINE PARTICIPATION GROUP ASSIGNMENT EXTENSION WORD", fields);
}

}

J16E0Message ParseJ16E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J16E0Message message;
		message.error = "Invalid J1.6E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ16E0WordBitsInternal(bits);
}

J16E0Message ParseJ16E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J16E0Message message;
		message.error = "Invalid J1.6E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J16E0Message message;
		message.error = "Invalid J1.6E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ16E0WordBitsInternal(bits.substr(0, 70));
}

J16E0Message ParseJ16E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ16E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ16E0MessageBytes(bytes);
	}

	J16E0Message message;
	message.error = "Invalid J1.6E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ16E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ16E0MessageBits(wordBits));
}

std::string ProcessJ16E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ16E0MessageBytes(bytes));
}

std::string ProcessJ16E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ16E0Message(input));
}

}
