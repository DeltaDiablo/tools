#include "messageProcessorJ22C3.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22C3WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.2C3."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00011 for J2.2C3."},
		{"NPG MEMBERSHIP STATUS", 1612, 1, 7, 18, "NPG membership status."},
		{"NET ENTRY TYPE", 733, 1, 19, 22, "Net entry type."},
		{"SIGNAL QUALITY METRIC", 748, 1, 23, 27, "Signal quality metric."},
		{"SPARE", 756, 11, 28, 38, "Spare bits."},
		{"DATA LINK REFERENCE POINT", 1885, 1, 39, 62, "Data link reference point."},
		{"SPARE", 756, 12, 63, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2C3", "AIR PPLI - NETWORK MANAGEMENT CONTINUATION WORD", fields);
}

}

J22C3Message ParseJ22C3MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22C3Message message;
		message.error = "Invalid J2.2C3 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C3WordBitsInternal(bits);
}

J22C3Message ParseJ22C3MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22C3Message message;
		message.error = "Invalid J2.2C3 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22C3Message message;
		message.error = "Invalid J2.2C3 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22C3WordBitsInternal(bits.substr(0, 70));
}

J22C3Message ParseJ22C3Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22C3MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22C3MessageBytes(bytes);
	}

	J22C3Message message;
	message.error = "Invalid J2.2C3 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22C3MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22C3MessageBits(wordBits));
}

std::string ProcessJ22C3MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22C3MessageBytes(bytes));
}

std::string ProcessJ22C3Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22C3Message(input));
}

}
