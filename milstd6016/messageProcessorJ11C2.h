#ifndef MILSTD6016_MESSAGEPROCESSORJ11C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ11C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J11C2FieldValue = WordFieldValue;
using J11C2Message = WordMessage;

J11C2Message ParseJ11C2MessageBits(const std::string& wordBits);

J11C2Message ParseJ11C2MessageBytes(const std::vector<int>& bytes);

J11C2Message ParseJ11C2Message(const std::string& input);

std::string ProcessJ11C2MessageBits(const std::string& wordBits);

std::string ProcessJ11C2MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ11C2Message(const std::string& input);

}

#endif
