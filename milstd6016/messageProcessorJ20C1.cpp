#include "messageProcessorJ20C1.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ20C1WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J2.0C1."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00001 for J2.0C1."},
		{"SPARE (SP)", 756, 1, 7, 7, "Spare bit."},
		{"MODE I CODE", 293, 3, 8, 12, "Mode I code."},
		{"MODE II CODE", 294, 2, 13, 24, "Mode II code."},
		{"MODE III CODE", 295, 2, 25, 36, "Mode III code."},
		{"ELEVATION, 25 FT", 1612, 1, 37, 47, "Elevation, 25 feet."},
		{"DEPTH, 15 METERS", 366, 8, 37, 43, "Depth, 15 meters (alternate field)."},
		{"DEPTH CATEGORY", 366, 9, 44, 47, "Depth category (alternate field)."},
		{"AIR PLATFORM", 1797, 1, 48, 53, "Air platform."},
		{"SURFACE PLATFORM", 1797, 2, 48, 53, "Surface platform (alternate field)."},
		{"SUBSURFACE PLATFORM", 1797, 3, 48, 53, "Subsurface platform (alternate field)."},
		{"LAND PLATFORM", 1797, 4, 48, 53, "Land platform (alternate field)."},
		{"AIR ACTIVITY", 1798, 1, 54, 60, "Air activity."},
		{"SURFACE ACTIVITY", 1798, 2, 54, 60, "Surface activity (alternate field)."},
		{"SUBSURFACE ACTIVITY", 1798, 3, 54, 60, "Subsurface activity (alternate field)."},
		{"LAND ACTIVITY", 1798, 4, 54, 60, "Land activity (alternate field)."},
		{"MISSION CORRELATOR", 725, 3, 61, 68, "Mission correlator."},
		{"SPARE (SP)", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.0C1", "INDIRECT INTERFACE UNIT PPLI - AMPLIFICATION CONTINUATION WORD", fields);
}

}

J20C1Message ParseJ20C1MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J20C1Message message;
		message.error = "Invalid J2.0C1 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C1WordBitsInternal(bits);
}

J20C1Message ParseJ20C1MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J20C1Message message;
		message.error = "Invalid J2.0C1 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J20C1Message message;
		message.error = "Invalid J2.0C1 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20C1WordBitsInternal(bits.substr(0, 70));
}

J20C1Message ParseJ20C1Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ20C1MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ20C1MessageBytes(bytes);
	}

	J20C1Message message;
	message.error = "Invalid J2.0C1 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ20C1MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ20C1MessageBits(wordBits));
}

std::string ProcessJ20C1MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ20C1MessageBytes(bytes));
}

std::string ProcessJ20C1Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ20C1Message(input));
}

}
