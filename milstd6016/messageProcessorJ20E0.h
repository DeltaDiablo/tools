#ifndef MILSTD6016_MESSAGEPROCESSORJ20E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ20E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J20E0FieldValue = WordFieldValue;
using J20E0Message = WordMessage;

J20E0Message ParseJ20E0MessageBits(const std::string& wordBits);

J20E0Message ParseJ20E0MessageBytes(const std::vector<int>& bytes);

J20E0Message ParseJ20E0Message(const std::string& input);

std::string ProcessJ20E0MessageBits(const std::string& wordBits);

std::string ProcessJ20E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ20E0Message(const std::string& input);

}

#endif
