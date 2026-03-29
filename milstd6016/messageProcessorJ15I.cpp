#include "messageProcessorJ15I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ15IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.5I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.5I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 101 for J1.5I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"TRACK NUMBER, ADDRESSEE", 769, 6, 13, 27, "Track number, addressee."},
		{"NET NUMBER, DEFAULT", 348, 10, 28, 34, "Net number, default."},
		{"REPROMULGATION RELAY STATE (RR STE)", 1776, 1, 35, 35, "Repromulgation relay state."},
		{"REPROMULGATION COUNTER", 1668, 1, 36, 39, "Repromulgation counter."},
		{"CONNECTIVITY MONITOR, ENABLE (CON MON)", 1777, 1, 40, 40, "Connectivity monitor enable."},
		{"COMMUNITY DESIGNATOR", 1774, 1, 41, 44, "Community designator."},
		{"REPROMULGATION ORIGINATION CONTROL (RPR OC)", 1778, 1, 45, 45, "Repromulgation origination control."},
		{"INITIAL ENTRY INDICATOR (IE IND)", 1779, 1, 46, 46, "Initial entry indicator."},
		{"TIMEOUT INTERVAL", 1544, 1, 47, 51, "Timeout interval."},
		{"SPARE", 756, 9, 52, 60, "Spare bits."},
		{"RECEIPT/COMPLIANCE", 392, 8, 61, 65, "Receipt/compliance."},
		{"RECURRENCE RATE, RECEIPT/COMPLIANCE (RRN R/C)", 444, 25, 66, 69, "Recurrence rate, receipt/compliance."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.5I", "NET CONTROL INITIALIZATION INITIAL WORD", fields);
}

}

J15IMessage ParseJ15IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J15IMessage message;
		message.error = "Invalid J1.5I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15IWordBitsInternal(bits);
}

J15IMessage ParseJ15IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J15IMessage message;
		message.error = "Invalid J1.5I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J15IMessage message;
		message.error = "Invalid J1.5I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ15IWordBitsInternal(bits.substr(0, 70));
}

J15IMessage ParseJ15IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ15IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ15IMessageBytes(bytes);
	}

	J15IMessage message;
	message.error = "Invalid J1.5I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ15IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ15IMessageBits(wordBits));
}

std::string ProcessJ15IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ15IMessageBytes(bytes));
}

std::string ProcessJ15IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ15IMessage(input));
}

}
