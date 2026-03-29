#include "messageProcessorJ10I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ10IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.0I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.0I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 000 for J1.0I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"CONNECTIVITY INTERROGATION INSTRUCTION (CII)", 1726, 1, 13, 14, "Connectivity interrogation instruction code."},
		{"ROUTE NUMBER", 1727, 1, 15, 18, "Route number."},
		{"RECURRENCE RATE, RESPONSE", 444, 20, 19, 22, "Recurrence rate for response."},
		{"RECURRENCE RATE, UPDATE (RRN UPD)", 444, 21, 23, 24, "Recurrence rate for update."},
		{"TRACK NUMBER, JU 1", 769, 32, 25, 39, "Track number, JU 1."},
		{"TRACK NUMBER, JU 2", 769, 33, 40, 54, "Same coding as for bits 25-39."},
		{"TRACK NUMBER, JU 3", 769, 34, 55, 69, "Same coding as for bits 25-39."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.0I", "CONNECTIVITY INTERROGATION INITIAL WORD", fields);
}

}

J10IMessage ParseJ10IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J10IMessage message;
		message.error = "Invalid J1.0I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ10IWordBitsInternal(bits);
}

J10IMessage ParseJ10IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J10IMessage message;
		message.error = "Invalid J1.0I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J10IMessage message;
		message.error = "Invalid J1.0I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ10IWordBitsInternal(bits.substr(0, 70));
}

J10IMessage ParseJ10IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ10IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ10IMessageBytes(bytes);
	}

	J10IMessage message;
	message.error = "Invalid J1.0I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ10IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ10IMessageBits(wordBits));
}

std::string ProcessJ10IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ10IMessageBytes(bytes));
}

std::string ProcessJ10IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ10IMessage(input));
}

}
