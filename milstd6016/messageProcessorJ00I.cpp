#include "messageProcessorJ00I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ00IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.0I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.0I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 000 for J0.0I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"SPARE", 756, 3, 13, 15, "Spare bits."},
		{"DISUSED", 758, 7, 16, 22, "Disused field."},
		{"RTT REPLY STATUS INDICATOR (RRS)", 274, 1, 23, 23, "RTT reply status indicator."},
		{"SLOT ASSIGN INDEX NUMBER (SAI NUM)", 1552, 1, 24, 27, "Slot assign index number."},
		{"TIME QUALITY", 279, 1, 28, 31, "Time quality."},
		{"RECURRENCE RATE, VOICE A", 444, 15, 32, 35, "Recurrence rate for Voice A."},
		{"TIME SLOT SET, VOICE A (TSS V-A)", 847, 17, 36, 37, "Time slot set for Voice A."},
		{"TIME SLOT NUMBER, VOICE A", 441, 32, 38, 41, "Time slot number for Voice A."},
		{"OFFSET, VOICE B", 843, 5, 42, 46, "Offset for Voice B."},
		{"RECURRENCE RATE, RTT-B", 444, 14, 47, 50, "Same coding family as recurrence rate for Voice A."},
		{"TIME SLOT SET, RTT-B (TSS RTT)", 847, 16, 51, 52, "Same coding family as time slot set for Voice A."},
		{"TIME SLOT NUMBER, RTT-B", 441, 31, 53, 57, "Time slot number for RTT-B."},
		{"ACCESS RATE, RTT-B", 1772, 2, 58, 61, "Access rate for RTT-B."},
		{"ACCESS RATE, PPLI B", 1772, 4, 62, 65, "Same coding family as access rate for RTT-B."},
		{"SPARE", 756, 4, 66, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.0I", "INITIAL ENTRY INITIAL WORD", fields);
}

}

J00IMessage ParseJ00IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J00IMessage message;
		message.error = "Invalid J0.0I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00IWordBitsInternal(bits);
}

J00IMessage ParseJ00IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J00IMessage message;
		message.error = "Invalid J0.0I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J00IMessage message;
		message.error = "Invalid J0.0I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ00IWordBitsInternal(bits.substr(0, 70));
}

J00IMessage ParseJ00IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ00IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ00IMessageBytes(bytes);
	}

	J00IMessage message;
	message.error = "Unable to parse J0.0I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ00IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ00IMessageBits(wordBits));
}

std::string ProcessJ00IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ00IMessageBytes(bytes));
}

std::string ProcessJ00IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ00IMessage(input));
}

}
