#include "messageProcessorJ04C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ04C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J0.4C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J0.4C2."},
		{"RRIP, ROUTE 1 (RRI 1)", 1734, 1, 7, 7, "RRIP, route 1."},
		{"RRIP, ROUTE 2 (RRI 2)", 1734, 2, 8, 8, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 3 (RRI 3)", 1734, 3, 9, 9, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 4 (RRI 4)", 1734, 4, 10, 10, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 5 (RRI 5)", 1734, 5, 11, 11, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 6 (RRI 6)", 1734, 6, 12, 12, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 7 (RRI 7)", 1734, 7, 13, 13, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 8 (RRI 8)", 1734, 8, 14, 14, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 9 (RRI 9)", 1734, 9, 15, 15, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 10 (RRI 10)", 1734, 10, 16, 16, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 11 (RRI 11)", 1734, 11, 17, 17, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 12 (RRI 12)", 1734, 12, 18, 18, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 13 (RRI 13)", 1734, 13, 19, 19, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 14 (RRI 14)", 1734, 14, 20, 20, "Same coding as RRIP, ROUTE 1."},
		{"RRIP, ROUTE 15 (RRI 15)", 1734, 15, 21, 21, "Same coding as RRIP, ROUTE 1."},
		{"IRIP, ROUTE 1 (IRI 1)", 1735, 1, 22, 22, "IRIP, route 1."},
		{"IRIP, ROUTE 2 (IRI 2)", 1735, 2, 23, 23, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 3 (IRI 3)", 1735, 3, 24, 24, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 4 (IRI 4)", 1735, 4, 25, 25, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 5 (IRI 5)", 1735, 5, 26, 26, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 6 (IRI 6)", 1735, 6, 27, 27, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 7 (IRI 7)", 1735, 7, 28, 28, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 8 (IRI 8)", 1735, 8, 29, 29, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 9 (IRI 9)", 1735, 9, 30, 30, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 10 (IRI 10)", 1735, 10, 31, 31, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 11 (IRI 11)", 1735, 11, 32, 32, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 12 (IRI 12)", 1735, 12, 33, 33, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 13 (IRI 13)", 1735, 13, 34, 34, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 14 (IRI 14)", 1735, 14, 35, 35, "Same coding as IRIP, ROUTE 1."},
		{"IRIP, ROUTE 15 (IRI 15)", 1735, 15, 36, 36, "Same coding as IRIP, ROUTE 1."},
		{"SPARE", 756, 33, 37, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.4C2", "RADIO RELAY CONTROL CONTINUATION WORD 2", fields);
}

}

J04C2Message ParseJ04C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J04C2Message message;
		message.error = "Invalid J0.4C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04C2WordBitsInternal(bits);
}

J04C2Message ParseJ04C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J04C2Message message;
		message.error = "Invalid J0.4C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J04C2Message message;
		message.error = "Invalid J0.4C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04C2WordBitsInternal(bits.substr(0, 70));
}

J04C2Message ParseJ04C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ04C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ04C2MessageBytes(bytes);
	}

	J04C2Message message;
	message.error = "Unable to parse J0.4C2 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ04C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ04C2MessageBits(wordBits));
}

std::string ProcessJ04C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ04C2MessageBytes(bytes));
}

std::string ProcessJ04C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ04C2Message(input));
}

}
