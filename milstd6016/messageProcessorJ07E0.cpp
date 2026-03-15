#include "messageProcessorJ07E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ07E0WordBitsInternal(const std::string& msbToLsbBits)
{
	// Primary layout (sequential bit ordering).
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J0.7E0."},
		{"DISSEMINATION MODE INDICATOR, WORD (MIW)", 1936, 3, 2, 2, "Dissemination mode indicator, word."},
		{"TABLE SEGMENT", 1946, 3, 3, 7, "Table segment identifier."},
		{"DEMAND, B", 1956, 3, 8, 12, "Demand value, participant B."},
		{"RECEIVE COUNT, B", 1966, 3, 13, 15, "Receive count, participant B."},
		{"HOP COUNT, B", 1976, 2, 16, 18, "Hop count, participant B."},
		{"TIME TAG, B", 1986, 2, 19, 21, "Time tag, participant B."},
		{"SPARE", 756, 2, 22, 23, "Spare bits."},
		{"DEMAND, C", 1956, 4, 24, 28, "Same coding as for bits 8-12."},
		{"RECEIVE COUNT, C", 1966, 4, 29, 31, "Same coding as for bits 13-15."},
		{"HOP COUNT, C", 1976, 3, 32, 34, "Same coding as for bits 16-18."},
		{"TIME TAG, C", 1986, 3, 35, 37, "Same coding as for bits 19-21."},
		{"SPARE", 756, 2, 38, 39, "Spare bits."},
		{"DEMAND, D", 1956, 5, 40, 44, "Same coding as for bits 8-12."},
		{"RECEIVE COUNT, D", 1966, 5, 45, 47, "Same coding as for bits 13-15."},
		{"HOP COUNT, D", 1976, 4, 48, 50, "Same coding as for bits 16-18."},
		{"TIME TAG, D", 1986, 4, 51, 53, "Same coding as for bits 19-21."},
		{"SPARE", 756, 2, 54, 55, "Spare bits."},
		{"DEMAND, E", 1956, 6, 56, 60, "Same coding as for bits 8-12."},
		{"RECEIVE COUNT, E", 1966, 6, 61, 63, "Same coding as for bits 13-15."},
		{"HOP COUNT, E", 1976, 5, 64, 66, "Same coding as for bits 16-18."},
		{"TIME TAG, E", 1986, 5, 67, 69, "Same coding as for bits 19-21."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J0.7E0", "TIME SLOT REALLOCATION EXTENSION WORD", fields);
}

}

J07E0Message ParseJ07E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J07E0Message message;
		message.error = "Invalid J0.7E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ07E0WordBitsInternal(bits);
}

J07E0Message ParseJ07E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J07E0Message message;
		message.error = "Invalid J0.7E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J07E0Message message;
		message.error = "Invalid J0.7E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ07E0WordBitsInternal(bits.substr(0, 70));
}

J07E0Message ParseJ07E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ07E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ07E0MessageBytes(bytes);
	}

	J07E0Message message;
	message.error = "Invalid J0.7E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ07E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ07E0MessageBits(wordBits));
}

std::string ProcessJ07E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ07E0MessageBytes(bytes));
}

std::string ProcessJ07E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ07E0Message(input));
}

}
