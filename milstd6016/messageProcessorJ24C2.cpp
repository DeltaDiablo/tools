#include "messageProcessorJ24C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ24C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.4C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J2.4C2."},
		{"VOICE CALL SIGN INDICATOR (VCS IND)", 1717, 1, 7, 7, "Voice call sign indicator."},
		{"LINK 4A ADDRESS INDICATOR (L4A IND)", 1718, 1, 8, 8, "Link 4A address indicator."},
		{"VOICE CALL SIGN", 264, 1, 9, 32, "Voice call sign."},
		{"LINK 4A ADDRESS", 291, 1, 33, 45, "Link 4A address."},
		{"VOICE FREQUENCY/CHANNEL", 417, 16, 46, 58, "Voice frequency/channel."},
		{"CONTROL CHANNEL", 348, 6, 59, 65, "Control channel."},
		{"ACTIVE RELAY INDICATOR, VOICE CHANNEL (ARI VC)", 1571, 3, 66, 66, "Active relay indicator, voice channel."},
		{"ACTIVE RELAY INDICATOR, CONTROL CHANNEL (ARI CC)", 1571, 4, 67, 67, "Active relay indicator, control channel."},
		{"DISUSED (DUD)", 758, 1, 68, 68, "Disused field."},
		{"SPARE (SP)", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.4C2", "SUBSURFACE PPLI - MISSION INFORMATION CONTINUATION WORD", fields);
}

}

J24C2Message ParseJ24C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J24C2Message message;
		message.error = "Invalid J2.4C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24C2WordBitsInternal(bits);
}

J24C2Message ParseJ24C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J24C2Message message;
		message.error = "Invalid J2.4C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J24C2Message message;
		message.error = "Invalid J2.4C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24C2WordBitsInternal(bits.substr(0, 70));
}

J24C2Message ParseJ24C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ24C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ24C2MessageBytes(bytes);
	}

	J24C2Message message;
	message.error = "Invalid J2.4C2 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ24C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ24C2MessageBits(wordBits));
}

std::string ProcessJ24C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ24C2MessageBytes(bytes));
}

std::string ProcessJ24C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ24C2Message(input));
}

}
