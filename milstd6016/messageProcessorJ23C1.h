#ifndef MILSTD6016_MESSAGEPROCESSORJ23C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ23C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J23C1FieldValue = WordFieldValue;
using J23C1Message = WordMessage;

J23C1Message ParseJ23C1MessageBits(const std::string& wordBits);
J23C1Message ParseJ23C1MessageBytes(const std::vector<int>& bytes);
J23C1Message ParseJ23C1Message(const std::string& input);

std::string ProcessJ23C1MessageBits(const std::string& wordBits);
std::string ProcessJ23C1MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ23C1Message(const std::string& input);

}

#endif
