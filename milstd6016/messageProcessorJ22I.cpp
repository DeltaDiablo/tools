#include "messageProcessorJ22I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ22IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J2.2I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00010 for J2.2I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 010 for J2.2I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"EXERCISE INDICATOR (EX IND)", 385, 3, 13, 13, "Exercise indicator."},
		{"MISSION COMMANDER INDICATOR (MC IND)", 1901, 1, 14, 14, "Mission commander indicator."},
		{"FORCE TELL INDICATOR (FT IND)", 354, 2, 15, 15, "Force tell indicator."},
		{"EMERGENCY INDICATOR (EMG IND)", 355, 2, 16, 16, "Emergency indicator."},
		{"COMMAND AND CONTROL INDICATOR (C2 IND)", 893, 1, 17, 17, "Command and control indicator."},
		{"SIMULATION INDICATOR (SIM IND)", 1604, 1, 18, 18, "Simulation indicator."},
		{"AIRBORNE INDICATOR (ABN IND)", 732, 2, 19, 19, "Airborne indicator."},
		{"FLIGHT LEADER INDICATOR (FLT LD)", 730, 1, 20, 20, "Flight leader indicator."},
		{"ACTIVE RELAY INDICATOR, WIDE AREA NETWORK (ARI WAN)", 1571, 2, 21, 21, "Active relay indicator, WAN."},
		{"RTT REPLY STATUS INDICATOR (RRS)", 274, 1, 22, 22, "RTT reply status indicator."},
		{"NETWORK PARTICIPATION STATUS INDICATOR (NPS IND)", 1613, 1, 23, 26, "Network participation status indicator."},
		{"TIME QUALITY", 279, 1, 27, 30, "Time quality."},
		{"GEODETIC POSITION QUALITY", 283, 1, 31, 34, "Geodetic position quality."},
		{"STRENGTH", 386, 13, 35, 38, "Strength."},
		{"BAILOUT INDICATOR (BLT IND)", 1646, 1, 39, 39, "Bailout indicator."},
		{"ALTITUDE, 25 FT", 365, 33, 40, 52, "Altitude, 25-foot resolution."},
		{"NET NUMBER, NONC2 JU-TO-NONC2 JU NPG A", 348, 2, 53, 59, "Net number, NPG A."},
		{"NONC2 JU-TO-NONC2 JU NPG STATUS A (NON STS A)", 1625, 12, 60, 60, "NonC2 JU-to-NonC2 JU NPG status A."},
		{"ALTITUDE QUALITY", 283, 2, 61, 64, "Altitude quality."},
		{"SPARE", 756, 5, 65, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.2I", "AIR PPLI INITIAL WORD", fields);
}

}

J22IMessage ParseJ22IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J22IMessage message;
		message.error = "Invalid J2.2I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22IWordBitsInternal(bits);
}

J22IMessage ParseJ22IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J22IMessage message;
		message.error = "Invalid J2.2I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J22IMessage message;
		message.error = "Invalid J2.2I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ22IWordBitsInternal(bits.substr(0, 70));
}

J22IMessage ParseJ22IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ22IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ22IMessageBytes(bytes);
	}

	J22IMessage message;
	message.error = "Invalid J2.2I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ22IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ22IMessageBits(wordBits));
}

std::string ProcessJ22IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ22IMessageBytes(bytes));
}

std::string ProcessJ22IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ22IMessage(input));
}

}
