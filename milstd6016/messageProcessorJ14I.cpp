#include "messageProcessorJ14I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ14IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.4I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.4I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 100 for J1.4I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"MESSAGE RECEIVED INDICATOR (MRI)", 1541, 1, 13, 13, "Message received indicator."},
		{"NET CONTROL MESSAGE SEQUENCE NUMBER (NC MSN)", 1542, 1, 14, 14, "Net control message sequence number."},
		{"RECEIPT/COMPLIANCE", 392, 8, 15, 19, "Receipt/compliance."},
		{"COMMUNITY DESIGNATOR", 1774, 1, 20, 23, "Community designator."},
		{"RELAY LEVEL, OWN NET CONTROL STATION (RLO NCS)", 1775, 2, 24, 27, "Relay level, own net control station."},
		{"OWN NET CONTROL STATION STATUS (NCS STS)", 1786, 1, 28, 29, "Own net control station status."},
		{"TIME SLOT OFFSET, CONTROL NET ENTRY", 348, 19, 30, 36, "Time slot offset, control net entry."},
		{"NET NUMBER, CONTROL NET ENTRY", 348, 20, 37, 43, "Net number, control net entry."},
		{"CONNECTIVITY QUALITY, INTERCOMMUNITY COMMUNICANT (CQ, IC)", 1725, 12, 44, 45, "Connectivity quality, intercommunity communicant."},
		{"TRACK NUMBER, INTERCOMMUNITY COMMUNICANT", 769, 15, 46, 60, "Track number, intercommunity communicant."},
		{"COMMUNITY DESIGNATOR, INTERCOMMUNITY COMMUNICANT (CD IC)", 1774, 2, 61, 64, "Community designator, intercommunity communicant."},
		{"RELAY LEVEL, INTERCOMMUNITY COMMUNICANT (RL ICC)", 1775, 3, 65, 68, "Relay level, intercommunity communicant."},
		{"SPARE (SP)", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.4I", "COMMUNICANT STATUS INITIAL WORD", fields);
}

}

J14IMessage ParseJ14IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J14IMessage message;
		message.error = "Invalid J1.4I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ14IWordBitsInternal(bits);
}

J14IMessage ParseJ14IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J14IMessage message;
		message.error = "Invalid J1.4I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J14IMessage message;
		message.error = "Invalid J1.4I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ14IWordBitsInternal(bits.substr(0, 70));
}

J14IMessage ParseJ14IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ14IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ14IMessageBytes(bytes);
	}

	J14IMessage message;
	message.error = "Invalid J1.4I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ14IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ14IMessageBits(wordBits));
}

std::string ProcessJ14IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ14IMessageBytes(bytes));
}

std::string ProcessJ14IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ14IMessage(input));
}

}
