#ifndef MILSTD6016_MESSAGEPROCESSORJ24C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ24C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J24C1FieldValue = WordFieldValue;
using J24C1Message = WordMessage;

J24C1Message ParseJ24C1MessageBits(const std::string& wordBits);
J24C1Message ParseJ24C1MessageBytes(const std::vector<int>& bytes);
J24C1Message ParseJ24C1Message(const std::string& input);

std::string ProcessJ24C1MessageBits(const std::string& wordBits);
std::string ProcessJ24C1MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ24C1Message(const std::string& input);

}

#endif
