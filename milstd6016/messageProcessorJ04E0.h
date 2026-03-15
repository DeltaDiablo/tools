#ifndef MILSTD6016_MESSAGEPROCESSORJ04E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ04E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J04E0FieldValue = WordFieldValue;
using J04E0Message = WordMessage;

J04E0Message ParseJ04E0MessageBits(const std::string& wordBits);

J04E0Message ParseJ04E0MessageBytes(const std::vector<int>& bytes);

J04E0Message ParseJ04E0Message(const std::string& input);

std::string ProcessJ04E0MessageBits(const std::string& wordBits);

std::string ProcessJ04E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ04E0Message(const std::string& input);

}

#endif
