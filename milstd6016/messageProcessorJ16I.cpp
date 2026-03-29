#include "messageProcessorJ16I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ16IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.6I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.6I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 110 for J1.6I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"TRACK NUMBER, ADDRESSEE", 769, 6, 13, 27, "Track number, addressee."},
		{"SPARE", 756, 5, 28, 32, "Spare bits."},
		{"PATH QUALITY MONITORING (PQL MON)", 1540, 1, 33, 34, "Path quality monitoring."},
		{"PATH QUALITY THRESHOLD, 1 (PQL TH1)", 1540, 2, 35, 37, "Path quality threshold, 1."},
		{"PATH QUALITY THRESHOLD, 2", 1540, 3, 38, 41, "Path quality threshold, 2."},
		{"SPARE", 756, 19, 42, 60, "Spare bits."},
		{"RECEIPT/COMPLIANCE", 392, 8, 61, 65, "Receipt/compliance."},
		{"RECURRENCE RATE, RECEIPT/COMPLIANCE (RRN R/C)", 444, 25, 66, 69, "Recurrence rate, receipt/compliance."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.6I", "NEEDLINE PARTICIPATION GROUP ASSIGNMENT INITIAL WORD", fields);
}

}

J16IMessage ParseJ16IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J16IMessage message;
		message.error = "Invalid J1.6I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ16IWordBitsInternal(bits);
}

J16IMessage ParseJ16IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J16IMessage message;
		message.error = "Invalid J1.6I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J16IMessage message;
		message.error = "Invalid J1.6I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ16IWordBitsInternal(bits.substr(0, 70));
}

J16IMessage ParseJ16IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ16IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ16IMessageBytes(bytes);
	}

	J16IMessage message;
	message.error = "Invalid J1.6I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ16IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ16IMessageBits(wordBits));
}

std::string ProcessJ16IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ16IMessageBytes(bytes));
}

std::string ProcessJ16IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ16IMessage(input));
}

}
