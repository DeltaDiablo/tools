#ifndef MILSTD6016_MESSAGEPROCESSORJ25C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ25C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J25C1FieldValue = WordFieldValue;
using J25C1Message = WordMessage;

J25C1Message ParseJ25C1MessageBits(const std::string& wordBits);
J25C1Message ParseJ25C1MessageBytes(const std::vector<int>& bytes);
J25C1Message ParseJ25C1Message(const std::string& input);

std::string ProcessJ25C1MessageBits(const std::string& wordBits);
std::string ProcessJ25C1MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ25C1Message(const std::string& input);

}

#endif
