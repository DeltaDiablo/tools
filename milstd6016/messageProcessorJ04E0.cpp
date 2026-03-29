#include "messageProcessorJ04E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ04E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J0.4E0."},
		{"RELAY DELAY", 843, 1, 2, 6, "Relay delay."},
		{"PARTICIPATION GROUP RELAY ASSIGNMENT INDICATOR (PGR IND)", 896, 1, 7, 7, "Participation group relay assignment indicator."},
		{"RELAY CONTROL ACTION (RC ACT)", 850, 3, 8, 10, "Relay control action."},
		{"RECURRENCE RATE", 444, 1, 11, 14, "Recurrence rate."},
		{"TIME SLOT SET", 847, 13, 15, 16, "Time slot set."},
		{"TIME SLOT NUMBER, INDEX", 441, 21, 17, 31, "Time slot number, index."},
		{"NET NUMBER, RECEIVE", 348, 4, 32, 38, "Net number, receive."},
		{"NET NUMBER, TRANSMIT", 348, 5, 39, 45, "Same coding as NET NUMBER, RECEIVE."},
		{"CRYPTOVARIABLE LOGICAL LABEL NUMBER ONE, RELAY (CVL N1R)", 801, 2, 46, 52, "Cryptovariable logical label number one, relay."},
		{"CRYPTOMODE INDICATOR, RELAY (CYP MDE)", 802, 2, 53, 53, "Cryptomode indicator, relay."},
		{"CRYPTOVARIABLE LOGICAL LABEL NUMBER TWO, RELAY", 801, 3, 54, 60, "Same coding as CVL N1R."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 61, 69, "Interpret only when PGR IND is 1."},
		{"RELAY FUNCTION (REL FTC)", 863, 1, 61, 63, "Interpret only when PGR IND is 0."},
		{"VOICE GROUP (VC GP)", 894, 1, 64, 67, "Interpret only when REL FTC is set to VOICE RELAY."},
		{"SPARE (SP)", 756, 2, 68, 69, "Spare bits for VOICE RELAY interpretation."},
		{"RELAY LABEL, DIRECTED", 865, 1, 64, 69, "Interpret only when REL FTC is set to DIRECTED RELAY."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.4E0", "RADIO RELAY CONTROL EXTENSION WORD", fields);
}

}

J04E0Message ParseJ04E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J04E0Message message;
		message.error = "Invalid J0.4E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04E0WordBitsInternal(bits);
}

J04E0Message ParseJ04E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J04E0Message message;
		message.error = "Invalid J0.4E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J04E0Message message;
		message.error = "Invalid J0.4E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04E0WordBitsInternal(bits.substr(0, 70));
}

J04E0Message ParseJ04E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ04E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ04E0MessageBytes(bytes);
	}

	J04E0Message message;
	message.error = "Unable to parse J0.4E0 input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ04E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ04E0MessageBits(wordBits));
}

std::string ProcessJ04E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ04E0MessageBytes(bytes));
}

std::string ProcessJ04E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ04E0Message(input));
}

}
