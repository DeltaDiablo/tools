#ifndef MILSTD6016_MESSAGEPROCESSORJ25E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ25E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J25E0FieldValue = WordFieldValue;
using J25E0Message = WordMessage;

J25E0Message ParseJ25E0MessageBits(const std::string& wordBits);
J25E0Message ParseJ25E0MessageBytes(const std::vector<int>& bytes);
J25E0Message ParseJ25E0Message(const std::string& input);

std::string ProcessJ25E0MessageBits(const std::string& wordBits);
std::string ProcessJ25E0MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ25E0Message(const std::string& input);

}

#endif
