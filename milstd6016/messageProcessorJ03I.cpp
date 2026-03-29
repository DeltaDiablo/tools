#include "messageProcessorJ03I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ03IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.3I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.3I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 011 for J0.3I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"TRACK NUMBER, ADDRESSEE", 769, 6, 13, 27, "Track number, addressee."},
		{"SPARE", 756, 3, 28, 30, "Spare bits."},
		{"DELTA EPOCH", 1615, 6, 31, 33, "Delta epoch."},
		{"EPOCH SUBDIVISION", 755, 1, 34, 39, "Epoch subdivision."},
		{"ACTION CODE, TIME SLOT ASSIGNMENT (ACT CDE)", 803, 1, 40, 42, "Action code, time slot assignment."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 43, 51, "Participation group."},
		{"SPARE", 756, 9, 52, 60, "Spare bits."},
		{"RECEIPT/COMPLIANCE", 392, 8, 61, 65, "Receipt/compliance."},
		{"RECURRENCE RATE, RECEIPT/COMPLIANCE (RRN R/C)", 444, 25, 66, 69, "Recurrence rate, receipt/compliance."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.3I", "TIME SLOT ASSIGNMENT INITIAL WORD", fields);
}

}

J03IMessage ParseJ03IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J03IMessage message;
		message.error = "Invalid J0.3I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03IWordBitsInternal(bits);
}

J03IMessage ParseJ03IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J03IMessage message;
		message.error = "Invalid J0.3I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J03IMessage message;
		message.error = "Invalid J0.3I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ03IWordBitsInternal(bits.substr(0, 70));
}

J03IMessage ParseJ03IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ03IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ03IMessageBytes(bytes);
	}

	J03IMessage message;
	message.error = "Unable to parse J0.3I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ03IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ03IMessageBits(wordBits));
}

std::string ProcessJ03IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ03IMessageBytes(bytes));
}

std::string ProcessJ03IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ03IMessage(input));
}

}
