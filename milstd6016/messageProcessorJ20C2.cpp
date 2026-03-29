#include "messageProcessorJ20C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ20C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Word format for continuation word."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Continuation word label."},
		{"VOICE FREQUENCY/CHANNEL", 417, 16, 7, 19, "Voice frequency/channel."},
		{"VOICE CALL SIGN INDICATOR (VCS IND)", 1717, 1, 20, 20, "Voice call sign indicator."},
		{"VOICE CALL SIGN", 264, 1, 21, 44, "Voice call sign."},
		{"TRACK NUMBER, FLIGHT LEAD", 769, 39, 45, 59, "Track number, flight lead."},
		{"CONTROL CHANNEL", 348, 6, 60, 66, "Control channel."},
		{"SPARE", 756, 3, 67, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.0C2", "INDIRECT INTERFACE UNIT PPLI CONTINUATION WORD 2", fields);
}

}

J20C2Message ParseJ20C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J20C2Message message;
		message.error = "Invalid J2.0C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C2WordBitsInternal(bits);
}

J20C2Message ParseJ20C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J20C2Message message;
		message.error = "Invalid J2.0C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J20C2Message message;
		message.error = "Invalid J2.0C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C2WordBitsInternal(bits.substr(0, 70));
}

J20C2Message ParseJ20C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ20C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ20C2MessageBytes(bytes);
	}

	J20C2Message message;
	message.error = "Invalid J2.0C2 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ20C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ20C2MessageBits(wordBits));
}

std::string ProcessJ20C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ20C2MessageBytes(bytes));
}

std::string ProcessJ20C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ20C2Message(input));
}

}
