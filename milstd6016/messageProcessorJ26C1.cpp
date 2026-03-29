#include "messageProcessorJ26C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ26C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.6C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J2.6C1."},
		{"VOICE CALL SIGN INDICATOR (VCS IND)", 1717, 1, 7, 7, "Voice call sign indicator."},
		{"SPARE (SP)", 756, 1, 8, 8, "Spare bit."},
		{"VOICE CALL SIGN", 264, 1, 9, 32, "Voice call sign."},
		{"LAND PLATFORM", 1797, 4, 33, 38, "Land platform."},
		{"LAND ACTIVITY", 1798, 4, 39, 45, "Land activity."},
		{"VOICE FREQUENCY/CHANNEL", 417, 16, 46, 58, "Voice frequency/channel."},
		{"CONTROL CHANNEL", 348, 6, 59, 65, "Control channel."},
		{"ACTIVE RELAY INDICATOR, VOICE CHANNEL (ARI VC)", 1571, 3, 66, 66, "Active relay indicator, voice channel."},
		{"ACTIVE RELAY INDICATOR, CONTROL CHANNEL (ARI CC)", 1571, 4, 67, 67, "Active relay indicator, control channel."},
		{"DISUSED (DUD)", 758, 1, 68, 68, "Disused field."},
		{"SPARE (SP)", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.6C1", "LAND TRACK PPLI - AMPLIFICATION/MISSION INFORMATION CONTINUATION WORD", fields);
}

}

J26C1Message ParseJ26C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J26C1Message message;
		message.error = "Invalid J2.6C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ26C1WordBitsInternal(bits);
}

J26C1Message ParseJ26C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J26C1Message message;
		message.error = "Invalid J2.6C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J26C1Message message;
		message.error = "Invalid J2.6C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ26C1WordBitsInternal(bits.substr(0, 70));
}

J26C1Message ParseJ26C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ26C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ26C1MessageBytes(bytes);
	}

	J26C1Message message;
	message.error = "Invalid J2.6C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ26C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ26C1MessageBits(wordBits));
}

std::string ProcessJ26C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ26C1MessageBytes(bytes));
}

std::string ProcessJ26C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ26C1Message(input));
}

}
