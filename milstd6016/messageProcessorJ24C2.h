#ifndef MILSTD6016_MESSAGEPROCESSORJ24C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ24C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J24C2FieldValue = WordFieldValue;
using J24C2Message = WordMessage;

J24C2Message ParseJ24C2MessageBits(const std::string& wordBits);
J24C2Message ParseJ24C2MessageBytes(const std::vector<int>& bytes);
J24C2Message ParseJ24C2Message(const std::string& input);

std::string ProcessJ24C2MessageBits(const std::string& wordBits);
std::string ProcessJ24C2MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ24C2Message(const std::string& input);

}

#endif
