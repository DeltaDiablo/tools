#ifndef MILSTD6016_MESSAGEPROCESSORJ25C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ25C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J25C3FieldValue = WordFieldValue;
using J25C3Message = WordMessage;

J25C3Message ParseJ25C3MessageBits(const std::string& wordBits);
J25C3Message ParseJ25C3MessageBytes(const std::vector<int>& bytes);
J25C3Message ParseJ25C3Message(const std::string& input);

std::string ProcessJ25C3MessageBits(const std::string& wordBits);
std::string ProcessJ25C3MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ25C3Message(const std::string& input);

}

#endif
