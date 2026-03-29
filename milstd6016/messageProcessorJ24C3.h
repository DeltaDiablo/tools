#ifndef MILSTD6016_MESSAGEPROCESSORJ24C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ24C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J24C3FieldValue = WordFieldValue;
using J24C3Message = WordMessage;

J24C3Message ParseJ24C3MessageBits(const std::string& wordBits);
J24C3Message ParseJ24C3MessageBytes(const std::vector<int>& bytes);
J24C3Message ParseJ24C3Message(const std::string& input);

std::string ProcessJ24C3MessageBits(const std::string& wordBits);
std::string ProcessJ24C3MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ24C3Message(const std::string& input);

}

#endif
