#ifndef MILSTD6016_MESSAGEPROCESSORJ20C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ20C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J20C1FieldValue = WordFieldValue;
using J20C1Message = WordMessage;

J20C1Message ParseJ20C1MessageBits(const std::string& wordBits);

J20C1Message ParseJ20C1MessageBytes(const std::vector<int>& bytes);

J20C1Message ParseJ20C1Message(const std::string& input);

std::string ProcessJ20C1MessageBits(const std::string& wordBits);

std::string ProcessJ20C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ20C1Message(const std::string& input);

}

#endif
