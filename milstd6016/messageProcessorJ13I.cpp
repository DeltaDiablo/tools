#include "messageProcessorJ13I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ13IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J1.3I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00001 for J1.3I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 011 for J1.3I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 no additional words; 1-7 number of additional words."},
		{"ACKNOWLEDGEMENT DATA DESIGNATOR (ACK DD)", 795, 1, 13, 13, "Acknowledgement data designator."},
		{"ACKNOWLEDGEMENT DATA AMPLIFIER (ACK DA)", 796, 1, 14, 14, "Acknowledgement data amplifier."},
		{"TRACK NUMBER, JU", 769, 56, 15, 29, "Track number, JU."},
		{"BLOCK SIZE INDICATOR (BSI)", 798, 1, 30, 30, "Block size indicator."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 1 (SBF F1)", 799, 1, 31, 31, "Sequential block/field flag 1."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 2 (SBF F2)", 799, 2, 32, 32, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 3 (SBF F3)", 799, 3, 33, 33, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 4 (SBF F4)", 799, 4, 34, 34, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 5 (SBF F5)", 799, 5, 35, 35, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 6 (SBF F6)", 799, 6, 36, 36, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 7 (SBF F7)", 799, 7, 37, 37, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 8 (SBF F8)", 799, 8, 38, 38, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 9 (SBF F9)", 799, 9, 39, 39, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 10 (SBF F10)", 799, 10, 40, 40, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 11 (SBF F11)", 799, 11, 41, 41, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 12 (SBF F12)", 799, 12, 42, 42, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 13 (SBF F13)", 799, 13, 43, 43, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 14 (SBF F14)", 799, 14, 44, 44, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 15 (SBF F15)", 799, 15, 45, 45, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 16 (SBF F16)", 799, 16, 46, 46, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 17 (SBF F17)", 799, 17, 47, 47, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 18 (SBF F18)", 799, 18, 48, 48, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 19 (SBF F19)", 799, 19, 49, 49, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 20 (SBF F20)", 799, 20, 50, 50, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 21 (SBF F21)", 799, 21, 51, 51, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 22 (SBF F22)", 799, 22, 52, 52, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 23 (SBF F23)", 799, 23, 53, 53, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 24 (SBF F24)", 799, 24, 54, 54, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 25 (SBF F25)", 799, 25, 55, 55, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 26 (SBF F26)", 799, 26, 56, 56, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 27 (SBF F27)", 799, 27, 57, 57, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 28 (SBF F28)", 799, 28, 58, 58, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 29 (SBF F29)", 799, 29, 59, 59, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 30 (SBF F30)", 799, 30, 60, 60, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 31 (SBF F31)", 799, 31, 61, 61, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 32 (SBF F32)", 799, 32, 62, 62, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 33 (SBF F33)", 799, 33, 63, 63, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 34 (SBF F34)", 799, 34, 64, 64, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 35 (SBF F35)", 799, 35, 65, 65, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 36 (SBF F36)", 799, 36, 66, 66, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 37 (SBF F37)", 799, 37, 67, 67, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 38 (SBF F38)", 799, 38, 68, 68, "Same coding as for bit 31."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 39 (SBF F39)", 799, 39, 69, 69, "Same coding as for bit 31."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.3I", "ACKNOWLEDGEMENT INITIAL WORD", fields);
}

}

J13IMessage ParseJ13IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J13IMessage message;
		message.error = "Invalid J1.3I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ13IWordBitsInternal(bits);
}

J13IMessage ParseJ13IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J13IMessage message;
		message.error = "Invalid J1.3I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J13IMessage message;
		message.error = "Invalid J1.3I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ13IWordBitsInternal(bits.substr(0, 70));
}

J13IMessage ParseJ13IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ13IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ13IMessageBytes(bytes);
	}

	J13IMessage message;
	message.error = "Invalid J1.3I input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ13IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ13IMessageBits(wordBits));
}

std::string ProcessJ13IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ13IMessageBytes(bytes));
}

std::string ProcessJ13IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ13IMessage(input));
}

}
