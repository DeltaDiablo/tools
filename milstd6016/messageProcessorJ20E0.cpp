#include "messageProcessorJ20E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ20E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J2.0E0."},
		{"LATITUDE 1, 0.0013 MINUTE", 281, 18, 2, 24, "Latitude 1."},
		{"LONGITUDE 1, 0.0013 MINUTE", 282, 18, 25, 48, "Longitude 1."},
		{"AIRBORNE INDICATOR (ABN IND)", 732, 2, 49, 49, "Airborne indicator."},
		{"COURSE", 371, 15, 50, 58, "Course."},
		{"SPEED", 367, 18, 59, 69, "Speed."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.0E0", "INDIRECT INTERFACE UNIT PPLI EXTENSION WORD", fields);
}

}

J20E0Message ParseJ20E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J20E0Message message;
		message.error = "Invalid J2.0E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20E0WordBitsInternal(bits);
}

J20E0Message ParseJ20E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J20E0Message message;
		message.error = "Invalid J2.0E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J20E0Message message;
		message.error = "Invalid J2.0E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20E0WordBitsInternal(bits.substr(0, 70));
}

J20E0Message ParseJ20E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ20E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ20E0MessageBytes(bytes);
	}

	J20E0Message message;
	message.error = "Invalid J2.0E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ20E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ20E0MessageBits(wordBits));
}

std::string ProcessJ20E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ20E0MessageBytes(bytes));
}

std::string ProcessJ20E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ20E0Message(input));
}

}
