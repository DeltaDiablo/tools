#include "messageProcessorJ15E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ15E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.5E0."},
		{"SPARE", 756, 7, 2, 8, "Spare bits."},
		{"RECURRENCE RATE, NET STATUS PARTICIPATION GROUP (RRN NSN)", 444, 22, 9, 12, "Recurrence rate, net status participation group."},
		{"TIME SLOT SET, NET STATUS PARTICIPATION GROUP (TSS NSN)", 847, 1, 13, 14, "Time slot set, net status participation group."},
		{"TIME SLOT NUMBER, NET STATUS PARTICIPATION GROUP", 441, 3, 15, 29, "Time slot number, net status participation group."},
		{"NET NUMBER, NET STATUS PARTICIPATION GROUP", 348, 11, 30, 36, "Net number, net status participation group."},
		{"OVERALL RECURRENCE RATE, NET STATUS PARTICIPATION GROUP (RRN ONS)", 444, 23, 37, 40, "Same coding as for bits 9-12."},
		{"RELAY LEVEL, OWN NET CONTROL STATION (RLO NCS)", 1775, 2, 41, 44, "Relay level, own net control station."},
		{"COMMUNICANT STATUS UPDATE INDICATOR (CS UI)", 1780, 1, 45, 46, "Communicant status update indicator."},
		{"TIME SLOT OFFSET, CONTROL NET ENTRY", 348, 19, 47, 53, "Time slot offset, control net entry."},
		{"NET NUMBER, CONTROL NET ENTRY", 348, 20, 54, 60, "Net number, control net entry."},
		{"PARTICIPANT INDEX NUMBER", 1782, 1, 61, 68, "Participant index number."},
		{"SPARE (SP)", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.5E0", "NET CONTROL INITIALIZATION EXTENSION WORD", fields);
}

}

J15E0Message ParseJ15E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J15E0Message message;
		message.error = "Invalid J1.5E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15E0WordBitsInternal(bits);
}

J15E0Message ParseJ15E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J15E0Message message;
		message.error = "Invalid J1.5E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J15E0Message message;
		message.error = "Invalid J1.5E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15E0WordBitsInternal(bits.substr(0, 70));
}

J15E0Message ParseJ15E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ15E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ15E0MessageBytes(bytes);
	}

	J15E0Message message;
	message.error = "Invalid J1.5E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ15E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ15E0MessageBits(wordBits));
}

std::string ProcessJ15E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ15E0MessageBytes(bytes));
}

std::string ProcessJ15E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ15E0Message(input));
}

}
