#ifndef MILSTD6016_MESSAGEPROCESSORJ12E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ12E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J12E0FieldValue = WordFieldValue;
using J12E0Message = WordMessage;

J12E0Message ParseJ12E0MessageBits(const std::string& wordBits);

J12E0Message ParseJ12E0MessageBytes(const std::vector<int>& bytes);

J12E0Message ParseJ12E0Message(const std::string& input);

std::string ProcessJ12E0MessageBits(const std::string& wordBits);

std::string ProcessJ12E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ12E0Message(const std::string& input);

}

#endif
