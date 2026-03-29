#include "messageProcessorJ25I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ25IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J2.5I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00010 for J2.5I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 101 for J2.5I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"EXERCISE INDICATOR (EX IND)", 385, 3, 13, 13, "Exercise indicator."},
		{"DISPLACED POSITION INDICATOR (DP IND)", 1619, 1, 14, 14, "Displaced position indicator."},
		{"FORCE TELL INDICATOR (FT IND)", 354, 2, 15, 15, "Force tell indicator."},
		{"EMERGENCY INDICATOR (EMG IND)", 355, 2, 16, 16, "Emergency indicator."},
		{"COMMAND AND CONTROL INDICATOR (C2 IND)", 893, 1, 17, 17, "Command and control indicator."},
		{"SIMULATION INDICATOR (SIM IND)", 1604, 1, 18, 18, "Simulation indicator."},
		{"SPARE (SP)", 756, 2, 19, 20, "Spare bits."},
		{"ACTIVE RELAY INDICATOR, WIDE AREA NETWORK (ARI WAN)", 1571, 2, 21, 21, "Active relay indicator, WAN."},
		{"RTT REPLY STATUS INDICATOR (RRS)", 274, 1, 22, 22, "RTT reply status indicator."},
		{"NETWORK PARTICIPATION STATUS INDICATOR (NPS IND)", 1613, 1, 23, 26, "Network participation status indicator."},
		{"TIME QUALITY", 279, 1, 27, 30, "Time quality."},
		{"GEODETIC POSITION QUALITY", 283, 1, 31, 34, "Geodetic position quality."},
		{"STRENGTH", 386, 13, 35, 38, "Strength."},
		{"SPARE (SP)", 756, 1, 39, 39, "Spare bit."},
		{"ELEVATION, 25 FT", 1612, 1, 40, 50, "Elevation, 25 feet."},
		{"SPARE (SP)", 756, 2, 51, 52, "Spare bits."},
		{"MISSION CORRELATOR", 725, 3, 53, 60, "Mission correlator."},
		{"ELEVATION QUALITY", 283, 3, 61, 64, "Elevation quality."},
		{"SPARE", 756, 5, 65, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.5I", "LAND POINT PPLI INITIAL WORD", fields);
}

}

J25IMessage ParseJ25IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J25IMessage message;
		message.error = "Invalid J2.5I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25IWordBitsInternal(bits);
}

J25IMessage ParseJ25IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J25IMessage message;
		message.error = "Invalid J2.5I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J25IMessage message;
		message.error = "Invalid J2.5I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ25IWordBitsInternal(bits.substr(0, 70));
}

J25IMessage ParseJ25IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ25IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ25IMessageBytes(bytes);
	}

	J25IMessage message;
	message.error = "Invalid J2.5I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ25IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ25IMessageBits(wordBits));
}

std::string ProcessJ25IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ25IMessageBytes(bytes));
}

std::string ProcessJ25IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ25IMessage(input));
}

}
