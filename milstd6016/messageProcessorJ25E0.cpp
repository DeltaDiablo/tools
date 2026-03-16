#include "messageProcessorJ25E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ25E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J2.5E0."},
		{"LATITUDE, 0.0013 MINUTE", 281, 15, 2, 24, "Latitude."},
		{"LONGITUDE, 0.0013 MINUTE", 282, 15, 25, 48, "Longitude."},
		{"SPARE", 756, 21, 49, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.5E0", "LAND POINT PPLI EXTENSION WORD", fields);
}

}

J25E0Message ParseJ25E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J25E0Message message;
		message.error = "Invalid J2.5E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25E0WordBitsInternal(bits);
}

J25E0Message ParseJ25E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J25E0Message message;
		message.error = "Invalid J2.5E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J25E0Message message;
		message.error = "Invalid J2.5E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25E0WordBitsInternal(bits.substr(0, 70));
}

J25E0Message ParseJ25E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ25E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ25E0MessageBytes(bytes);
	}

	J25E0Message message;
	message.error = "Invalid J2.5E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ25E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ25E0MessageBits(wordBits));
}

std::string ProcessJ25E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ25E0MessageBytes(bytes));
}

std::string ProcessJ25E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ25E0Message(input));
}

}
