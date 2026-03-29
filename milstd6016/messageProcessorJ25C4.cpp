#include "messageProcessorJ25C4.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ25C4WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.5C4."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00100 for J2.5C4."},
		{"SPARE", 756, 3, 7, 9, "Spare bits."},
		{"LATITUDE, 0.0103 MINUTE", 281, 17, 10, 29, "Latitude, 0.0103 minute resolution."},
		{"SPARE", 756, 3, 30, 32, "Spare bits."},
		{"LONGITUDE, 0.0103 MINUTE", 282, 13, 33, 53, "Longitude, 0.0103 minute resolution."},
		{"SPARE", 756, 16, 54, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.5C4", "LAND POINT PPLI - DISPLACED POSITION CONTINUATION WORD", fields);
}

}

J25C4Message ParseJ25C4MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J25C4Message message;
		message.error = "Invalid J2.5C4 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25C4WordBitsInternal(bits);
}

J25C4Message ParseJ25C4MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J25C4Message message;
		message.error = "Invalid J2.5C4 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J25C4Message message;
		message.error = "Invalid J2.5C4 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25C4WordBitsInternal(bits.substr(0, 70));
}

J25C4Message ParseJ25C4Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ25C4MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ25C4MessageBytes(bytes);
	}

	J25C4Message message;
	message.error = "Invalid J2.5C4 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ25C4MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ25C4MessageBits(wordBits));
}

std::string ProcessJ25C4MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ25C4MessageBytes(bytes));
}

std::string ProcessJ25C4Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ25C4Message(input));
}

}
