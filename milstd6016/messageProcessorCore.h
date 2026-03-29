#ifndef MILSTD6016_MESSAGEPROCESSORCORE_H_
#define MILSTD6016_MESSAGEPROCESSORCORE_H_

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

}

#endif
