#ifndef MILSTD6016_MESSAGEPROCESSORJ15E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ15E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J15E0FieldValue = WordFieldValue;
using J15E0Message = WordMessage;

J15E0Message ParseJ15E0MessageBits(const std::string& wordBits);

J15E0Message ParseJ15E0MessageBytes(const std::vector<int>& bytes);

J15E0Message ParseJ15E0Message(const std::string& input);

std::string ProcessJ15E0MessageBits(const std::string& wordBits);

std::string ProcessJ15E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ15E0Message(const std::string& input);

}

#endif
