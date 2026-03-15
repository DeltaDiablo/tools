#ifndef MILSTD6016_MESSAGEPROCESSOR_INTERNAL_H_
#define MILSTD6016_MESSAGEPROCESSOR_INTERNAL_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {
namespace internal {

struct FieldSpec
{
	const char* name;
	int dfi;
	int dui;
	int lowBit;
	int highBit;
	const char* fallback;
};

std::string Trim(const std::string& value);

bool IsBinaryLike(const std::string& input);

std::string SanitizeBinaryBits(const std::string& input);

bool TryParseCsvBytes(const std::string& input, std::vector<int>& bytes);

std::string BytesToBitString(const std::vector<int>& bytes);

int BitsToUInt(const std::string& bits);

std::string ReverseBitOrderBySpecPosition(const std::string& msbToLsbBits);

std::string ExtractFieldBits(const std::string& msbToLsbBits, int lowBit, int highBit);

std::string LookupMeaningText(int dfi, int dui, int numericValue);

WordFieldValue BuildFieldValue(const std::string& wordBits, const FieldSpec& field);

WordMessage BuildWordMessage(const std::string& msbToLsbBits,
	const char* wordNumber,
	const char* wordTitle,
	const std::vector<FieldSpec>& fields);

std::string FormatWordMessage(const WordMessage& message);

}
}

#endif
