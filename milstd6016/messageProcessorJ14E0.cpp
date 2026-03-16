#include "messageProcessorJ14E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ14E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = []() {
		std::vector<internal::FieldSpec> generated;
		generated.reserve(131);

		generated.push_back({"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.4E0."});
		generated.push_back({"REPORT FORMAT INDICATOR (RFI)", 1543, 1, 2, 3, "Report format indicator."});

		for (int cqIndex = 1; cqIndex <= 128; ++cqIndex)
		{
			const int dfiDui = 12 + cqIndex;
			const int repetition = (cqIndex - 1) / 32;
			const int withinRepetition = (cqIndex - 1) % 32;
			const int lowBit = 4 + (withinRepetition * 2);
			const int highBit = lowBit + 1;

			std::string repetitionTag;
			if (repetition == 0)
			{
				repetitionTag = " [base word]";
			}
			else if (repetition == 1)
			{
				repetitionTag = " [first repetition]";
			}
			else if (repetition == 2)
			{
				repetitionTag = " [second repetition]";
			}
			else
			{
				repetitionTag = " [third repetition]";
			}

			std::string name = "CONNECTIVITY QUALITY, INTRA-COMMUNITY COMMUNICANT " +
				std::to_string(cqIndex) + " (CQ, " + std::to_string(cqIndex) + ")" + repetitionTag;

			std::string notes;
			if (repetition == 0)
			{
				notes = "Transmitted in the base J1.4E0 word in the J1.4 message. Same coding as for bits 4-5.";
			}
			else if (repetition == 1)
			{
				notes = "Transmitted in the first repetition of the J1.4E0 word in the J1.4 message. Same coding as for bits 4-5.";
			}
			else if (repetition == 2)
			{
				notes = "Transmitted in the second repetition of the J1.4E0 word in the J1.4 message. Same coding as for bits 4-5.";
			}
			else
			{
				notes = "Transmitted in the third repetition of the J1.4E0 word in the J1.4 message. Same coding as for bits 4-5.";
			}

			generated.push_back({name, 1725, dfiDui, lowBit, highBit, notes});
		}

		generated.push_back({"SPARE (SP)", 756, 2, 68, 69, "Spare bits."});
		return generated;
	}();

	return internal::BuildWordMessage(msbToLsbBits, "J1.4E0", "COMMUNICANT STATUS EXTENSION WORD", fields);
}

}

J14E0Message ParseJ14E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J14E0Message message;
		message.error = "Invalid J1.4E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ14E0WordBitsInternal(bits);
}

J14E0Message ParseJ14E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J14E0Message message;
		message.error = "Invalid J1.4E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J14E0Message message;
		message.error = "Invalid J1.4E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ14E0WordBitsInternal(bits.substr(0, 70));
}

J14E0Message ParseJ14E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ14E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ14E0MessageBytes(bytes);
	}

	J14E0Message message;
	message.error = "Invalid J1.4E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ14E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ14E0MessageBits(wordBits));
}

std::string ProcessJ14E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ14E0MessageBytes(bytes));
}

std::string ProcessJ14E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ14E0Message(input));
}

}
