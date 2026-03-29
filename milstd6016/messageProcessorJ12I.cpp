#include "messageProcessorJ12I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ12IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.2I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.2I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 010 for J1.2I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"ACTION/INFORMATION INDICATOR, 4 (AII 4)", 1740, 4, 13, 14, "Action/information indicator 4 code."},
		{"TRACK NUMBER, ORIGINATOR", 769, 63, 15, 29, "Track number, originator."},
		{"TRACK NUMBER, DESTINATION", 769, 64, 30, 44, "Track number, destination."},
		{"MINIMUM CONNECTIVITY QUALITY REQUESTED (CQ MIN)", 1725, 141, 45, 46, "Minimum connectivity quality requested."},
		{"ALLOCATED PG INDEX NUMBER", 1783, 1, 47, 55, "Allocated PG index number."},
		{"ROUTE NUMBER, RELAY (RN REL)", 1784, 1, 56, 59, "Route number, relay."},
		{"MAXIMUM CONNECTIVITY QUALITY PROVIDED (CQ MAX)", 1725, 142, 60, 61, "Maximum connectivity quality provided."},
		{"SPARE", 756, 8, 62, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.2I", "ROUTE ESTABLISHMENT INITIAL WORD", fields);
}

}

J12IMessage ParseJ12IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J12IMessage message;
		message.error = "Invalid J1.2I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12IWordBitsInternal(bits);
}

J12IMessage ParseJ12IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J12IMessage message;
		message.error = "Invalid J1.2I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J12IMessage message;
		message.error = "Invalid J1.2I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ12IWordBitsInternal(bits.substr(0, 70));
}

J12IMessage ParseJ12IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ12IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ12IMessageBytes(bytes);
	}

	J12IMessage message;
	message.error = "Invalid J1.2I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ12IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ12IMessageBits(wordBits));
}

std::string ProcessJ12IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ12IMessageBytes(bytes));
}

std::string ProcessJ12IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ12IMessage(input));
}

}
