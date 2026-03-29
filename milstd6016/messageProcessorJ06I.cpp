#include "messageProcessorJ06I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ06IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.6I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.6I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 110 for J0.6I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"TRACK NUMBER, ADDRESSEE", 769, 6, 13, 27, "Track number of the addressee."},
		{"SPARE", 756, 3, 28, 30, "Spare bits."},
		{"LABEL, J-SERIES REQUEST", 270, 7, 31, 35, "Only values allowable are 0 or 2."},
		{"SUBLABEL, J-SERIES REQUEST", 271, 7, 36, 38, "Sublabel of the J-series request."},
		{"ACTION, COMMUNICATION CONTROL (COM CON)", 1769, 1, 39, 40, "Communication control action code."},
		{"SPARE", 756, 2, 41, 42, "Spare bits."},
		{"PARTICIPATION GROUP (PTC GRP)", 838, 4, 43, 51, "Participation group identifier."},
		{"TRANSMISSION TERMINATION DESIGNATOR (TT DES)", 1770, 1, 52, 55, "Transmission termination designator."},
		{"SPARE", 756, 5, 56, 60, "Spare bits."},
		{"RECEIPT/COMPLIANCE", 392, 8, 61, 65, "Receipt/compliance indicator."},
		{"RECURRENCE RATE, RECEIPT/COMPLIANCE (RRN R/C)", 444, 25, 66, 69, "Recurrence rate for receipt/compliance."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.6I", "COMMUNICATIONS CONTROL INITIAL WORD", fields);
}

}

J06IMessage ParseJ06IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J06IMessage message;
		message.error = "Invalid J0.6I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06IWordBitsInternal(bits);
}

J06IMessage ParseJ06IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J06IMessage message;
		message.error = "Invalid J0.6I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J06IMessage message;
		message.error = "Invalid J0.6I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ06IWordBitsInternal(bits.substr(0, 70));
}

J06IMessage ParseJ06IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ06IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ06IMessageBytes(bytes);
	}

	J06IMessage message;
	message.error = "Invalid J0.6I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ06IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ06IMessageBits(wordBits));
}

std::string ProcessJ06IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ06IMessageBytes(bytes));
}

std::string ProcessJ06IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ06IMessage(input));
}

}
