#ifndef MILSTD6016_MESSAGEPROCESSORJ04C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ04C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J04C1FieldValue = WordFieldValue;
using J04C1Message = WordMessage;

J04C1Message ParseJ04C1MessageBits(const std::string& wordBits);

J04C1Message ParseJ04C1MessageBytes(const std::vector<int>& bytes);

J04C1Message ParseJ04C1Message(const std::string& input);

std::string ProcessJ04C1MessageBits(const std::string& wordBits);

std::string ProcessJ04C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ04C1Message(const std::string& input);

}

#endif
