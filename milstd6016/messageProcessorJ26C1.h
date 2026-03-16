#ifndef MILSTD6016_MESSAGEPROCESSORJ26C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ26C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J26C1FieldValue = WordFieldValue;
using J26C1Message = WordMessage;

J26C1Message ParseJ26C1MessageBits(const std::string& wordBits);
J26C1Message ParseJ26C1MessageBytes(const std::vector<int>& bytes);
J26C1Message ParseJ26C1Message(const std::string& input);

std::string ProcessJ26C1MessageBits(const std::string& wordBits);
std::string ProcessJ26C1MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ26C1Message(const std::string& input);

}

#endif
