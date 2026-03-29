#include "messageProcessorJ07I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ07IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.7I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.7I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 111 for J0.7I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"REALLOCATION POOL NUMBER (POOL NUMBER)", 1616, 1, 13, 15, "Reallocation pool number."},
		{"DISSEMINATION MODE INDICATOR, OWN (MIO)", 1936, 1, 16, 16, "Dissemination mode indicator, own unit."},
		{"TABLE POSITION NUMBER, OWN", 1946, 1, 17, 23, "Table position number, own unit."},
		{"DEMAND, OWN", 1956, 1, 24, 28, "Demand value, own unit."},
		{"RECEIVE COUNT, OWN", 1966, 1, 29, 31, "Receive count, own unit."},
		{"DISSEMINATION MODE INDICATOR, A (MIA)", 1936, 2, 32, 32, "Dissemination mode indicator, participant A."},
		{"SPARE", 756, 1, 33, 33, "Spare bit."},
		{"HOP COUNT, A", 1976, 1, 34, 36, "Hop count, participant A."},
		{"TIME TAG, A", 1986, 1, 37, 39, "Time tag, participant A."},
		{"DEMAND, A", 1956, 2, 40, 44, "Demand value, participant A."},
		{"RECEIVE COUNT, A", 1966, 2, 45, 47, "Receive count, participant A."},
		{"TRACK NUMBER, DEMAND ORIGINATOR A / TABLE POSITION NUMBER, A", 769, 1, 48, 54, "Track number demand originator A or table position number A (bits 48-54)."},
		{"SPARE", 756, 8, 55, 62, "Spare bits (bits 55-62)."},
		{"SPARE", 756, 7, 63, 69, "Spare bits (bits 63-69)."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.7I", "TIME SLOT REALLOCATION INITIAL WORD", fields);
}

}

J07IMessage ParseJ07IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J07IMessage message;
		message.error = "Invalid J0.7I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ07IWordBitsInternal(bits);
}

J07IMessage ParseJ07IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J07IMessage message;
		message.error = "Invalid J0.7I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J07IMessage message;
		message.error = "Invalid J0.7I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ07IWordBitsInternal(bits.substr(0, 70));
}

J07IMessage ParseJ07IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ07IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ07IMessageBytes(bytes);
	}

	J07IMessage message;
	message.error = "Invalid J0.7I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ07IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ07IMessageBits(wordBits));
}

std::string ProcessJ07IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ07IMessageBytes(bytes));
}

std::string ProcessJ07IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ07IMessage(input));
}

}
