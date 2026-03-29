#ifndef MILSTD6016_MESSAGEPROCESSORJ12E1_H_
#define MILSTD6016_MESSAGEPROCESSORJ12E1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J12E1FieldValue = WordFieldValue;
using J12E1Message = WordMessage;

J12E1Message ParseJ12E1MessageBits(const std::string& wordBits);

J12E1Message ParseJ12E1MessageBytes(const std::vector<int>& bytes);

J12E1Message ParseJ12E1Message(const std::string& input);

std::string ProcessJ12E1MessageBits(const std::string& wordBits);

std::string ProcessJ12E1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ12E1Message(const std::string& input);

}

#endif
