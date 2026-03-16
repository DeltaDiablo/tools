#ifndef MILSTD6016_MESSAGEPROCESSORJ13E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ13E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J13E0FieldValue = WordFieldValue;
using J13E0Message = WordMessage;

J13E0Message ParseJ13E0MessageBits(const std::string& wordBits);

J13E0Message ParseJ13E0MessageBytes(const std::vector<int>& bytes);

J13E0Message ParseJ13E0Message(const std::string& input);

std::string ProcessJ13E0MessageBits(const std::string& wordBits);

std::string ProcessJ13E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ13E0Message(const std::string& input);

}

#endif
