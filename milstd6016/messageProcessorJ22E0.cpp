#include "messageProcessorJ22E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J2.2E0."},
		{"LATITUDE, 0.0013 MINUTE", 281, 15, 2, 24, "Latitude."},
		{"LONGITUDE, 0.0013 MINUTE", 282, 15, 25, 48, "Longitude."},
		{"SPARE (SP)", 756, 1, 49, 49, "Spare bit."},
		{"COURSE", 371, 15, 50, 58, "Course."},
		{"SPEED", 367, 18, 59, 69, "Speed."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2E0", "AIR PPLI EXTENSION WORD", fields);
}

}

J22E0Message ParseJ22E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22E0Message message;
		message.error = "Invalid J2.2E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22E0WordBitsInternal(bits);
}

J22E0Message ParseJ22E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22E0Message message;
		message.error = "Invalid J2.2E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22E0Message message;
		message.error = "Invalid J2.2E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22E0WordBitsInternal(bits.substr(0, 70));
}

J22E0Message ParseJ22E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22E0MessageBytes(bytes);
	}

	J22E0Message message;
	message.error = "Invalid J2.2E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22E0MessageBits(wordBits));
}

std::string ProcessJ22E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22E0MessageBytes(bytes));
}

std::string ProcessJ22E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22E0Message(input));
}

}
