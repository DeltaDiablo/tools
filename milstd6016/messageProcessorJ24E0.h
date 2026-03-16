#ifndef MILSTD6016_MESSAGEPROCESSORJ24E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ24E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J24E0FieldValue = WordFieldValue;
using J24E0Message = WordMessage;

J24E0Message ParseJ24E0MessageBits(const std::string& wordBits);
J24E0Message ParseJ24E0MessageBytes(const std::vector<int>& bytes);
J24E0Message ParseJ24E0Message(const std::string& input);

std::string ProcessJ24E0MessageBits(const std::string& wordBits);
std::string ProcessJ24E0MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ24E0Message(const std::string& input);

}

#endif
