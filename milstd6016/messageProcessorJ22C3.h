#ifndef MILSTD6016_MESSAGEPROCESSORJ22C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ22C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22C3FieldValue = WordFieldValue;
using J22C3Message = WordMessage;

J22C3Message ParseJ22C3MessageBits(const std::string& wordBits);
J22C3Message ParseJ22C3MessageBytes(const std::vector<int>& bytes);
J22C3Message ParseJ22C3Message(const std::string& input);

std::string ProcessJ22C3MessageBits(const std::string& wordBits);
std::string ProcessJ22C3MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22C3Message(const std::string& input);

}

#endif
