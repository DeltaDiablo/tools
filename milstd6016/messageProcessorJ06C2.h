#ifndef MILSTD6016_MESSAGEPROCESSORJ06C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ06C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J06C2FieldValue = WordFieldValue;
using J06C2Message = WordMessage;

J06C2Message ParseJ06C2MessageBits(const std::string& wordBits);

J06C2Message ParseJ06C2MessageBytes(const std::vector<int>& bytes);

J06C2Message ParseJ06C2Message(const std::string& input);

std::string ProcessJ06C2MessageBits(const std::string& wordBits);

std::string ProcessJ06C2MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ06C2Message(const std::string& input);

}

#endif
