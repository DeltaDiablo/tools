#include "messageProcessorJ20I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ20IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J2.0I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00010 for J2.0I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 000 for J2.0I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"EXERCISE INDICATOR (EX IND)", 385, 3, 13, 13, "Field retained against future use."},
		{"BAILOUT INDICATOR (BLT IND)", 1646, 1, 14, 14, "Bailout indicator."},
		{"FORCE TELL INDICATOR (FT IND)", 354, 2, 15, 15, "Force tell indicator."},
		{"EMERGENCY INDICATOR (EMG IND)", 355, 2, 16, 16, "Emergency indicator."},
		{"COMMAND AND CONTROL INDICATOR (C2 IND)", 893, 1, 17, 17, "Command and control indicator."},
		{"SIMULATION INDICATOR (SIM IND)", 1604, 1, 18, 18, "Simulation indicator."},
		{"TRACK NUMBER, SOURCE", 769, 3, 19, 33, "Track number, source."},
		{"FLIGHT LEADER INDICATOR (FLT LD)", 730, 1, 34, 34, "Flight leader indicator."},
		{"MISSION COMMANDER INDICATOR (MC IND)", 1901, 1, 35, 35, "Mission commander indicator."},
		{"GENERIC UNIT TYPE", 1719, 2, 36, 39, "Generic unit type."},
		{"ALTITUDE, 25 FT", 365, 33, 40, 52, "Altitude, 25-foot resolution."},
		{"ALTITUDE QUALITY, GU", 283, 5, 53, 56, "Altitude quality, generic unit."},
		{"POSITION QUALITY, GU", 283, 6, 57, 60, "Position quality, generic unit."},
		{"SITE", 1719, 1, 61, 63, "Site."},
		{"UNIT TYPE", 288, 1, 64, 67, "See J2.0I note 1."},
		{"ORIGINATOR ENVIRONMENT (ENV)", 275, 1, 68, 69, "See J2.0I note 1."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.0I", "INDIRECT INTERFACE UNIT PPLI INITIAL WORD", fields);
}

}

J20IMessage ParseJ20IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J20IMessage message;
		message.error = "Invalid J2.0I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20IWordBitsInternal(bits);
}

J20IMessage ParseJ20IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J20IMessage message;
		message.error = "Invalid J2.0I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J20IMessage message;
		message.error = "Invalid J2.0I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ20IWordBitsInternal(bits.substr(0, 70));
}

J20IMessage ParseJ20IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ20IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ20IMessageBytes(bytes);
	}

	J20IMessage message;
	message.error = "Invalid J2.0I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ20IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ20IMessageBits(wordBits));
}

std::string ProcessJ20IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ20IMessageBytes(bytes));
}

std::string ProcessJ20IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ20IMessage(input));
}

}
