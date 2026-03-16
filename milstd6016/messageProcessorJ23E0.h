#ifndef MILSTD6016_MESSAGEPROCESSORJ23E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ23E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J23E0FieldValue = WordFieldValue;
using J23E0Message = WordMessage;

J23E0Message ParseJ23E0MessageBits(const std::string& wordBits);
J23E0Message ParseJ23E0MessageBytes(const std::vector<int>& bytes);
J23E0Message ParseJ23E0Message(const std::string& input);

std::string ProcessJ23E0MessageBits(const std::string& wordBits);
std::string ProcessJ23E0MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ23E0Message(const std::string& input);

}

#endif
