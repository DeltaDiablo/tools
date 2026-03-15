#ifndef MILSTD6016_MESSAGEPROCESSORJ03E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ03E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J03E0FieldValue = WordFieldValue;
using J03E0Message = WordMessage;

J03E0Message ParseJ03E0MessageBits(const std::string& wordBits);

J03E0Message ParseJ03E0MessageBytes(const std::vector<int>& bytes);

J03E0Message ParseJ03E0Message(const std::string& input);

std::string ProcessJ03E0MessageBits(const std::string& wordBits);

std::string ProcessJ03E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ03E0Message(const std::string& input);

}

#endif
