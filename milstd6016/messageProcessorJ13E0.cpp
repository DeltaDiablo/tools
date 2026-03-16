#include "messageProcessorJ13E0.h"

#include <vector>

#include "messageProcessorInternal.h"

namespace milstd6016 {

namespace {

WordMessage ParseJ13E0WordBitsInternal(const std::string& msbToLsbBits)
{
	static const std::vector<internal::FieldSpec> fields = {
		{"WORD FORMAT", 1550, 1, 0, 1, "Expected fixed coding 10 for J1.3E0."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 40 (SBF F40)", 799, 40, 2, 2, "Sequential block/field flag 40."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 41 (SBF F41)", 799, 41, 3, 3, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 42 (SBF F42)", 799, 42, 4, 4, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 43 (SBF F43)", 799, 43, 5, 5, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 44 (SBF F44)", 799, 44, 6, 6, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 45 (SBF F45)", 799, 45, 7, 7, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 46 (SBF F46)", 799, 46, 8, 8, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 47 (SBF F47)", 799, 47, 9, 9, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 48 (SBF F48)", 799, 48, 10, 10, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 49 (SBF F49)", 799, 49, 11, 11, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 50 (SBF F50)", 799, 50, 12, 12, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 51 (SBF F51)", 799, 51, 13, 13, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 52 (SBF F52)", 799, 52, 14, 14, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 53 (SBF F53)", 799, 53, 15, 15, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 54 (SBF F54)", 799, 54, 16, 16, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 55 (SBF F55)", 799, 55, 17, 17, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 56 (SBF F56)", 799, 56, 18, 18, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 57 (SBF F57)", 799, 57, 19, 19, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 58 (SBF F58)", 799, 58, 20, 20, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 59 (SBF F59)", 799, 59, 21, 21, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 60 (SBF F60)", 799, 60, 22, 22, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 61 (SBF F61)", 799, 61, 23, 23, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 62 (SBF F62)", 799, 62, 24, 24, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 63 (SBF F63)", 799, 63, 25, 25, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 64 (SBF F64)", 799, 64, 26, 26, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 65 (SBF F65)", 799, 65, 27, 27, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 66 (SBF F66)", 799, 66, 28, 28, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 67 (SBF F67)", 799, 67, 29, 29, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 68 (SBF F68)", 799, 68, 30, 30, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 69 (SBF F69)", 799, 69, 31, 31, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 70 (SBF F70)", 799, 70, 32, 32, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 71 (SBF F71)", 799, 71, 33, 33, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 72 (SBF F72)", 799, 72, 34, 34, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 73 (SBF F73)", 799, 73, 35, 35, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 74 (SBF F74)", 799, 74, 36, 36, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 75 (SBF F75)", 799, 75, 37, 37, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 76 (SBF F76)", 799, 76, 38, 38, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 77 (SBF F77)", 799, 77, 39, 39, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 78 (SBF F78)", 799, 78, 40, 40, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 79 (SBF F79)", 799, 79, 41, 41, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 80 (SBF F80)", 799, 80, 42, 42, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 81 (SBF F81)", 799, 81, 43, 43, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 82 (SBF F82)", 799, 82, 44, 44, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 83 (SBF F83)", 799, 83, 45, 45, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 84 (SBF F84)", 799, 84, 46, 46, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 85 (SBF F85)", 799, 85, 47, 47, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 86 (SBF F86)", 799, 86, 48, 48, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 87 (SBF F87)", 799, 87, 49, 49, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 88 (SBF F88)", 799, 88, 50, 50, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 89 (SBF F89)", 799, 89, 51, 51, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 90 (SBF F90)", 799, 90, 52, 52, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 91 (SBF F91)", 799, 91, 53, 53, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 92 (SBF F92)", 799, 92, 54, 54, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 93 (SBF F93)", 799, 93, 55, 55, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 94 (SBF F94)", 799, 94, 56, 56, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 95 (SBF F95)", 799, 95, 57, 57, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 96 (SBF F96)", 799, 96, 58, 58, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 97 (SBF F97)", 799, 97, 59, 59, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 98 (SBF F98)", 799, 98, 60, 60, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 99 (SBF F99)", 799, 99, 61, 61, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 100 (SBF 100)", 799, 100, 62, 62, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 101 (SBF 101)", 799, 101, 63, 63, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 102 (SBF 102)", 799, 102, 64, 64, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 103 (SBF 103)", 799, 103, 65, 65, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 104 (SBF 104)", 799, 104, 66, 66, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 105 (SBF 105)", 799, 105, 67, 67, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 106 (SBF 106)", 799, 106, 68, 68, "Same coding as for bit 2."},
		{"SEQUENTIAL BLOCK/FIELD FLAG, 107 (SBF 107)", 799, 107, 69, 69, "Same coding as for bit 2."}
	};

	return internal::BuildWordMessage(msbToLsbBits, "J1.3E0", "ACKNOWLEDGEMENT EXTENSION WORD", fields);
}

}

J13E0Message ParseJ13E0MessageBits(const std::string& wordBits)
{
	const std::string bits = internal::SanitizeBinaryBits(wordBits);
	if (bits.size() != 70)
	{
		J13E0Message message;
		message.error = "Invalid J1.3E0 word length: expected 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ13E0WordBitsInternal(bits);
}

J13E0Message ParseJ13E0MessageBytes(const std::vector<int>& bytes)
{
	if (bytes.empty())
	{
		J13E0Message message;
		message.error = "Invalid J1.3E0 input: no bytes were provided.";
		return message;
	}

	const std::string bits = internal::BytesToBitString(bytes);
	if (bits.size() < 70)
	{
		J13E0Message message;
		message.error = "Invalid J1.3E0 byte input: expected at least 70 bits, received " + std::to_string(bits.size()) + ".";
		return message;
	}

	return ParseJ13E0WordBitsInternal(bits.substr(0, 70));
}

J13E0Message ParseJ13E0Message(const std::string& input)
{
	if (internal::IsBinaryLike(input))
	{
		return ParseJ13E0MessageBits(input);
	}

	std::vector<int> bytes;
	if (internal::TryParseCsvBytes(input, bytes))
	{
		return ParseJ13E0MessageBytes(bytes);
	}

	J13E0Message message;
	message.error = "Invalid J1.3E0 input: expected a 70-bit binary string or comma-separated byte values.";
	return message;
}

std::string ProcessJ13E0MessageBits(const std::string& wordBits)
{
	return internal::FormatWordMessage(ParseJ13E0MessageBits(wordBits));
}

std::string ProcessJ13E0MessageBytes(const std::vector<int>& bytes)
{
	return internal::FormatWordMessage(ParseJ13E0MessageBytes(bytes));
}

std::string ProcessJ13E0Message(const std::string& input)
{
	return internal::FormatWordMessage(ParseJ13E0Message(input));
}

}
