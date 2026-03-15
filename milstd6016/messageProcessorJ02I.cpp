#include "messageProcessorJ02I.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ02IWordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 00 for J0.2I."},
		{"LABEL, J-SERIES", 270, 4, 2, 6, "Expected fixed coding 00000 for J0.2I."},
		{"SUBLABEL, J-SERIES", 271, 5, 7, 9, "Expected fixed coding 010 for J0.2I."},
		{"MESSAGE LENGTH INDICATOR", 800, 1, 10, 12, "0 means no additional words; 1-7 indicates the number of additional words."},
		{"SPARE", 756, 3, 13, 15, "Spare bits."},
		{"EPOCH NUMBER, EXECUTION", 1539, 1, 16, 22, "Epoch number, execution."},
		{"EPOCH SUBDIVISION, EXECUTION", 755, 2, 23, 28, "Epoch subdivision, execution."},
		{"EPOCH NUMBER, DELTA CHANGE (EPN DCH)", 1615, 7, 29, 30, "Epoch number, delta change."},
		{"TIME SLOT NUMBER, NEW", 441, 40, 31, 45, "Time slot number, new."},
		{"TIME SLOT SET, NEW (TSS NEW)", 847, 2, 46, 47, "Time slot set, new."},
		{"RESIDUAL TIME CHANGE", 442, 2, 48, 65, "Residual time change."},
		{"SPARE", 756, 4, 66, 69, "Spare bits."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.2I", "NETWORK TIME UPDATE INITIAL WORD", fields);
}

}

J02IMessage ParseJ02IMessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J02IMessage message;
		message.error = "Invalid J0.2I word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ02IWordBitsInternal(bits);
}

J02IMessage ParseJ02IMessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J02IMessage message;
		message.error = "Invalid J0.2I input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J02IMessage message;
		message.error = "Invalid J0.2I byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ02IWordBitsInternal(bits.substr(0, 70));
}

J02IMessage ParseJ02IMessage(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ02IMessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ02IMessageBytes(bytes);
	}

	J02IMessage message;
	message.error = "Unable to parse J0.2I input. Provide either a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ02IMessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ02IMessageBits(wordBits));
}

std::string ProcessJ02IMessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ02IMessageBytes(bytes));
}

std::string ProcessJ02IMessage(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ02IMessage(input));
}

}
