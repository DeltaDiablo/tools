#include "messageProcessorJ11C2.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ11C2WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 01 for J1.1C2."},
		{"CONTINUATION WORD LABEL", 1551, 1, 2, 6, "Expected fixed coding 00010 for J1.1C2."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 1 (CQ, 1)", 1725, 13, 7, 8, "Connectivity quality intra-community communicant 1."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 2 (CQ, 2)", 1725, 14, 9, 10, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 3 (CQ, 3)", 1725, 15, 11, 12, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 4 (CQ, 4)", 1725, 16, 13, 14, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 5 (CQ, 5)", 1725, 17, 15, 16, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 6 (CQ, 6)", 1725, 18, 17, 18, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 7 (CQ, 7)", 1725, 19, 19, 20, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 8 (CQ, 8)", 1725, 20, 21, 22, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 9 (CQ, 9)", 1725, 21, 23, 24, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 10 (CQ, 10)", 1725, 22, 25, 26, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 11 (CQ, 11)", 1725, 23, 27, 28, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 12 (CQ, 12)", 1725, 24, 29, 30, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 13 (CQ, 13)", 1725, 25, 31, 32, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 14 (CQ, 14)", 1725, 26, 33, 34, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 15 (CQ, 15)", 1725, 27, 35, 36, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 16 (CQ, 16)", 1725, 28, 37, 38, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 17 (CQ, 17)", 1725, 29, 39, 40, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 18 (CQ, 18)", 1725, 30, 41, 42, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 19 (CQ, 19)", 1725, 31, 43, 44, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 20 (CQ, 20)", 1725, 32, 45, 46, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 21 (CQ, 21)", 1725, 33, 47, 48, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 22 (CQ, 22)", 1725, 34, 49, 50, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 23 (CQ, 23)", 1725, 35, 51, 52, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 24 (CQ, 24)", 1725, 36, 53, 54, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 25 (CQ, 25)", 1725, 37, 55, 56, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 26 (CQ, 26)", 1725, 38, 57, 58, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 27 (CQ, 27)", 1725, 39, 59, 60, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 28 (CQ, 28)", 1725, 40, 61, 62, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 29 (CQ, 29)", 1725, 41, 63, 64, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 30 (CQ, 30)", 1725, 42, 65, 66, "Same coding as for bits 7-8."},
		{"CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT 31 (CQ, 31)", 1725, 43, 67, 68, "Same coding as for bits 7-8."},
		{"SPARE", 756, 1, 69, 69, "Spare bit."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.1C2", "CONNECTIVITY STATUS CONTINUATION WORD 2", fields);
}

}

J11C2Message ParseJ11C2MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J11C2Message message;
		message.error = "Invalid J1.1C2 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11C2WordBitsInternal(bits);
}

J11C2Message ParseJ11C2MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J11C2Message message;
		message.error = "Invalid J1.1C2 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J11C2Message message;
		message.error = "Invalid J1.1C2 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11C2WordBitsInternal(bits.substr(0, 70));
}

J11C2Message ParseJ11C2Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ11C2MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ11C2MessageBytes(bytes);
	}

	J11C2Message message;
	message.error = "Invalid J1.1C2 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ11C2MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ11C2MessageBits(wordBits));
}

std::string ProcessJ11C2MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ11C2MessageBytes(bytes));
}

std::string ProcessJ11C2Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ11C2Message(input));
}

}
