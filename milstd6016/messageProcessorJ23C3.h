#ifndef MILSTD6016_MESSAGEPROCESSORJ23C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ23C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J23C3FieldValue = WordFieldValue;
using J23C3Message = WordMessage;

J23C3Message ParseJ23C3MessageBits(const std::string& wordBits);
J23C3Message ParseJ23C3MessageBytes(const std::vector<int>& bytes);
J23C3Message ParseJ23C3Message(const std::string& input);

std::string ProcessJ23C3MessageBits(const std::string& wordBits);
std::string ProcessJ23C3MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ23C3Message(const std::string& input);

}

#endif
