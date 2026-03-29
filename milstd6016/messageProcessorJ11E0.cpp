#include "messageProcessorJ11E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ11E0WordBitsInternal(const std::string& msbToLsbBits)
{
	// Primary layout (first J1.1E0 occurrence): CQ4-7 at bits 2-9, JU4-7 at bits 10-69.
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.1E0."},
		{"CONNECTIVITY QUALITY, 4 (CQ, 4)", 1725, 4, 2, 3, "First J1.1E0 in message."},
		{"CONNECTIVITY QUALITY, 5 (CQ, 5)", 1725, 5, 4, 5, "Same coding as for bits 2-3."},
		{"CONNECTIVITY QUALITY, 6 (CQ, 6)", 1725, 6, 6, 7, "Same coding as for bits 2-3."},
		{"CONNECTIVITY QUALITY, 7 (CQ, 7)", 1725, 7, 8, 9, "Same coding as for bits 2-3."},
		{"TRACK NUMBER, JU 4", 769, 35, 10, 24, "First J1.1E0 in message."},
		{"TRACK NUMBER, JU 5", 769, 36, 25, 39, "Same coding as for bits 10-24."},
		{"TRACK NUMBER, JU 6", 769, 37, 40, 54, "Same coding as for bits 10-24."},
		{"TRACK NUMBER, JU 7", 769, 38, 55, 69, "Same coding as for bits 10-24."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.1E0", "CONNECTIVITY STATUS EXTENSION WORD", fields);
}

}

J11E0Message ParseJ11E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J11E0Message message;
		message.error = "Invalid J1.1E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11E0WordBitsInternal(bits);
}

J11E0Message ParseJ11E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J11E0Message message;
		message.error = "Invalid J1.1E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J11E0Message message;
		message.error = "Invalid J1.1E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ11E0WordBitsInternal(bits.substr(0, 70));
}

J11E0Message ParseJ11E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ11E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ11E0MessageBytes(bytes);
	}

	J11E0Message message;
	message.error = "Invalid J1.1E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ11E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ11E0MessageBits(wordBits));
}

std::string ProcessJ11E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ11E0MessageBytes(bytes));
}

std::string ProcessJ11E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ11E0Message(input));
}

}
