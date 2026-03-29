#ifndef MILSTD6016_MESSAGEPROCESSORJ10E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ10E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J10E0FieldValue = WordFieldValue;
using J10E0Message = WordMessage;

J10E0Message ParseJ10E0MessageBits(const std::string& wordBits);

J10E0Message ParseJ10E0MessageBytes(const std::vector<int>& bytes);

J10E0Message ParseJ10E0Message(const std::string& input);

std::string ProcessJ10E0MessageBits(const std::string& wordBits);

std::string ProcessJ10E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ10E0Message(const std::string& input);

}

#endif
