#include "messageProcessorJ22C5.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22C5WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.2C5."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00101 for J2.2C5."},
		{"SPARE", 756, 24, 7, 30, "Spare bits."},
		{"NETWORK ORIGINATOR SET NUMBER", 1614, 1, 31, 35, "Network originator set number."},
		{"NETWORK ORIGINATOR TRACK NUMBER", 1615, 1, 36, 47, "Network originator track number."},
		{"NATIONALITY", 1854, 1, 48, 54, "Nationality."},
		{"PLATFORM AMPLIFICATION", 389, 1, 55, 59, "Platform amplification."},
		{"SPARE", 756, 10, 60, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2C5", "AIR PPLI - SUPPLEMENTAL CONTINUATION WORD", fields);
}

}

J22C5Message ParseJ22C5MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22C5Message message;
		message.error = "Invalid J2.2C5 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C5WordBitsInternal(bits);
}

J22C5Message ParseJ22C5MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22C5Message message;
		message.error = "Invalid J2.2C5 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22C5Message message;
		message.error = "Invalid J2.2C5 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C5WordBitsInternal(bits.substr(0, 70));
}

J22C5Message ParseJ22C5Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22C5MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22C5MessageBytes(bytes);
	}

	J22C5Message message;
	message.error = "Invalid J2.2C5 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22C5MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22C5MessageBits(wordBits));
}

std::string ProcessJ22C5MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22C5MessageBytes(bytes));
}

std::string ProcessJ22C5Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22C5Message(input));
}

}
