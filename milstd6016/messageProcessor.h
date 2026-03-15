#ifndef MILSTD6016_MESSAGEPROCESSOR_H_
#define MILSTD6016_MESSAGEPROCESSOR_H_

#include <string>
#include <vector>

namespace milstd6016 {

struct WordFieldValue
{
	std::string name;
	int dfi = 0;
	int dui = 0;
	int lowBit = 0;
	int highBit = 0;
	std::string bitString;
	int numericValue = 0;
	std::string resolvedText;
	std::string fallbackText;
};

struct WordMessage
{
	bool isValid = false;
	std::string error;
	std::string wordNumber;
	std::string wordTitle;
	std::string inputBitOrder;
	std::string transmittedBits;
	std::string specOrderBits;
	std::vector<WordFieldValue> fields;
};

using J00IFieldValue = WordFieldValue;
using J00IMessage = WordMessage;
using J00C1FieldValue = WordFieldValue;
using J00C1Message = WordMessage;

std::string DescribeValueMeaning(int dfi, int dui, const std::string& bitCode, bool resolveRanges = true);

std::string DescribeAllValueMeanings(int dfi, int dui);

J00IMessage ParseJ00IMessageBits(const std::string& wordBits);

J00IMessage ParseJ00IMessageBytes(const std::vector<int>& bytes);

J00IMessage ParseJ00IMessage(const std::string& input);

J00C1Message ParseJ00C1MessageBits(const std::string& wordBits);

J00C1Message ParseJ00C1MessageBytes(const std::vector<int>& bytes);

J00C1Message ParseJ00C1Message(const std::string& input);

std::string ProcessJ00IMessageBits(const std::string& wordBits);

std::string ProcessJ00IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ00IMessage(const std::string& input);

std::string ProcessJ00C1MessageBits(const std::string& wordBits);

std::string ProcessJ00C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ00C1Message(const std::string& input);

}

#endif
