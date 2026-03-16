#ifndef MILSTD6016_MESSAGEPROCESSORJ20C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ20C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J20C2FieldValue = WordFieldValue;
using J20C2Message = WordMessage;

J20C2Message ParseJ20C2MessageBits(const std::string& wordBits);

J20C2Message ParseJ20C2MessageBytes(const std::vector<int>& bytes);

J20C2Message ParseJ20C2Message(const std::string& input);

std::string ProcessJ20C2MessageBits(const std::string& wordBits);

std::string ProcessJ20C2MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ20C2Message(const std::string& input);

}

#endif
