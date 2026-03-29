#include "messageProcessorJ25C3.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ25C3WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.5C3."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00011 for J2.5C3."},
		{"SPARE (SP)", 756, 1, 7, 7, "Spare bit."},
		{"U COORDINATE", 276, 1, 8, 27, "U coordinate."},
		{"V COORDINATE", 277, 1, 28, 47, "V coordinate."},
		{"BETA ANGLE", 284, 1, 48, 62, "Beta angle."},
		{"RELATIVE POSITION QUALITY", 278, 1, 63, 66, "Relative position quality."},
		{"RELATIVE AZIMUTH QUALITY", 285, 1, 67, 69, "Relative azimuth quality."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.5C3", "LAND POINT PPLI - RELATIVE NAVIGATION CONTINUATION WORD", fields);
}

}

J25C3Message ParseJ25C3MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J25C3Message message;
		message.error = "Invalid J2.5C3 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25C3WordBitsInternal(bits);
}

J25C3Message ParseJ25C3MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J25C3Message message;
		message.error = "Invalid J2.5C3 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J25C3Message message;
		message.error = "Invalid J2.5C3 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25C3WordBitsInternal(bits.substr(0, 70));
}

J25C3Message ParseJ25C3Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ25C3MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ25C3MessageBytes(bytes);
	}

	J25C3Message message;
	message.error = "Invalid J2.5C3 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ25C3MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ25C3MessageBits(wordBits));
}

std::string ProcessJ25C3MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ25C3MessageBytes(bytes));
}

std::string ProcessJ25C3Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ25C3Message(input));
}

}
