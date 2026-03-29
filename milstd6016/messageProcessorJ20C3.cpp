#include "messageProcessorJ20C3.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ20C3WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Word format for continuation word."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Continuation word label."},
		{"MINUTE", 797, 4, 7, 12, "Minute."},
		{"SECOND", 380, 1, 13, 18, "Second."},
		{"MILLISECOND", 380, 8, 19, 28, "Millisecond."},
		{"POSITION TIME QUALITY", 283, 7, 29, 32, "Position time quality."},
		{"TIME LATENCY INDICATOR", 308, 1, 33, 33, "Time latency indicator."},
		{"LATITUDE, LSBS 0.0003 MINUTE", 281, 19, 34, 35, "Latitude least-significant bits."},
		{"LONGITUDE, LSBS 0.0003 MINUTE", 282, 19, 36, 37, "Longitude least-significant bits."},
		{"ALTITUDE, LSBS 1.5625 FT", 365, 45, 38, 41, "Altitude least-significant bits."},
		{"HOUR TICK (HT)", 792, 8, 42, 42, "Hour tick."},
		{"AIR SPECIFIC TYPE", 804, 1, 43, 54, "Air specific type."},
		{"SURFACE SPECIFIC TYPE", 808, 1, 43, 54, "Surface specific type (alternate field)."},
		{"SUBSURFACE SPECIFIC TYPE", 809, 1, 43, 54, "Subsurface specific type (alternate field)."},
		{"LAND SPECIFIC TYPE", 810, 1, 43, 54, "Land specific type (alternate field)."},
		{"SPARE", 756, 15, 55, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.0C3", "INDIRECT INTERFACE UNIT PPLI CONTINUATION WORD 3", fields);
}

}

J20C3Message ParseJ20C3MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J20C3Message message;
		message.error = "Invalid J2.0C3 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C3WordBitsInternal(bits);
}

J20C3Message ParseJ20C3MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J20C3Message message;
		message.error = "Invalid J2.0C3 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J20C3Message message;
		message.error = "Invalid J2.0C3 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C3WordBitsInternal(bits.substr(0, 70));
}

J20C3Message ParseJ20C3Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ20C3MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ20C3MessageBytes(bytes);
	}

	J20C3Message message;
	message.error = "Invalid J2.0C3 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ20C3MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ20C3MessageBits(wordBits));
}

std::string ProcessJ20C3MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ20C3MessageBytes(bytes));
}

std::string ProcessJ20C3Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ20C3Message(input));
}

}
