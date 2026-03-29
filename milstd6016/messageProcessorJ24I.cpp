#include "messageProcessorJ24I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ24IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J2.4I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00010 for J2.4I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 100 for J2.4I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"EXERCISE INDICATOR (EX IND)", 385, 3, 13, 13, "Exercise indicator."},
		{"DISUSED (DUD)", 758, 1, 14, 14, "Disused field."},
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
		{"SPARE", 756, 7, 35, 41, "Spare bits."},
		{"DEPTH, 15 METERS", 366, 8, 42, 48, "Depth, 15 meters."},
		{"DEPTH CATEGORY", 366, 9, 49, 52, "Depth category."},
		{"MISSION CORRELATOR", 725, 3, 53, 60, "Mission correlator."},
		{"DEPTH QUALITY", 283, 4, 61, 64, "Depth quality."},
		{"SPARE", 756, 5, 65, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J2.4I", "SUBSURFACE PPLI INITIAL WORD", fields);
}

}

J24IMessage ParseJ24IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J24IMessage message;
		message.error = "Invalid J2.4I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24IWordBitsInternal(bits);
}

J24IMessage ParseJ24IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J24IMessage message;
		message.error = "Invalid J2.4I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J24IMessage message;
		message.error = "Invalid J2.4I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ24IWordBitsInternal(bits.substr(0, 70));
}

J24IMessage ParseJ24IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ24IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ24IMessageBytes(bytes);
	}

	J24IMessage message;
	message.error = "Invalid J2.4I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ24IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ24IMessageBits(wordBits));
}

std::string ProcessJ24IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ24IMessageBytes(bytes));
}

std::string ProcessJ24IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ24IMessage(input));
}

}
