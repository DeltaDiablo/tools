#ifndef MILSTD6016_MESSAGEPROCESSORJ04C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ04C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J04C2FieldValue = WordFieldValue;
using J04C2Message = WordMessage;

J04C2Message ParseJ04C2MessageBits(const std::string& wordBits);

J04C2Message ParseJ04C2MessageBytes(const std::vector<int>& bytes);

J04C2Message ParseJ04C2Message(const std::string& input);

std::string ProcessJ04C2MessageBits(const std::string& wordBits);

std::string ProcessJ04C2MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ04C2Message(const std::string& input);

}

#endif
