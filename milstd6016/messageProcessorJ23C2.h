#ifndef MILSTD6016_MESSAGEPROCESSORJ23C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ23C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J23C2FieldValue = WordFieldValue;
using J23C2Message = WordMessage;

J23C2Message ParseJ23C2MessageBits(const std::string& wordBits);
J23C2Message ParseJ23C2MessageBytes(const std::vector<int>& bytes);
J23C2Message ParseJ23C2Message(const std::string& input);

std::string ProcessJ23C2MessageBits(const std::string& wordBits);
std::string ProcessJ23C2MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ23C2Message(const std::string& input);

}

#endif
