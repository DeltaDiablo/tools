#ifndef MILSTD6016_MESSAGEPROCESSORJ22C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ22C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22C1FieldValue = WordFieldValue;
using J22C1Message = WordMessage;

J22C1Message ParseJ22C1MessageBits(const std::string& wordBits);
J22C1Message ParseJ22C1MessageBytes(const std::vector<int>& bytes);
J22C1Message ParseJ22C1Message(const std::string& input);

std::string ProcessJ22C1MessageBits(const std::string& wordBits);
std::string ProcessJ22C1MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22C1Message(const std::string& input);

}

#endif
