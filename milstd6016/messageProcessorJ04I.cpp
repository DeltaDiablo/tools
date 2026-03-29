#include "messageProcessorJ04I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ04IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.4I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.4I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 100 for J0.4I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"TRACK NUMBER, ADDRESSEE", 769, 6, 13, 27, "Track number, addressee."},
		{"SPARE", 756, 3, 28, 30, "Spare bits."},
		{"DELTA EPOCH", 1615, 6, 31, 33, "Delta epoch."},
		{"EPOCH SUBDIVISION", 755, 1, 34, 39, "Epoch subdivision."},
		{"RELAY CONTROL ACTION (RC ACT)", 850, 3, 40, 42, "Relay control action."},
		{"RELAY FUNCTION (REL FTC)", 863, 1, 43, 45, "Relay function."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 46, 54, "Interpret only when relay function is PARTICIPATION GROUP."},
		{"SPARE", 756, 5, 46, 50, "Interpret only when relay function is VOICE RELAY."},
		{"VOICE GROUP (VC GP)", 894, 1, 51, 54, "Interpret only when relay function is VOICE RELAY."},
		{"SPARE", 756, 3, 46, 48, "Interpret only when relay function is DIRECTED RELAY."},
		{"RELAY LABEL, DIRECTED", 865, 1, 49, 54, "Interpret only when relay function is DIRECTED RELAY."},
		{"SPARE (SP)", 756, 2, 46, 47, "Interpret only when relay function is ZOOM RELAY."},
		{"ZOOM RELAY TRANSMIT NET", 348, 18, 48, 54, "Interpret only when relay function is ZOOM RELAY."},
		{"SPARE", 756, 6, 55, 60, "Spare bits."},
		{"RECEIPT/COMPLIANCE", 392, 8, 61, 65, "Receipt/compliance."},
		{"RECURRENCE RATE, RECEIPT/COMPLIANCE (RRN R/C)", 444, 25, 66, 69, "Recurrence rate, receipt/compliance."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.4I", "RADIO RELAY CONTROL INITIAL WORD", fields);
}

}

J04IMessage ParseJ04IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J04IMessage message;
		message.error = "Invalid J0.4I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04IWordBitsInternal(bits);
}

J04IMessage ParseJ04IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J04IMessage message;
		message.error = "Invalid J0.4I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J04IMessage message;
		message.error = "Invalid J0.4I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ04IWordBitsInternal(bits.substr(0, 70));
}

J04IMessage ParseJ04IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ04IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ04IMessageBytes(bytes);
	}

	J04IMessage message;
	message.error = "Unable to parse J0.4I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ04IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ04IMessageBits(wordBits));
}

std::string ProcessJ04IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ04IMessageBytes(bytes));
}

std::string ProcessJ04IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ04IMessage(input));
}

}
