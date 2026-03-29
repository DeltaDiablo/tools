#ifndef MILSTD6016_MESSAGEPROCESSORJ03C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ03C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J03C2FieldValue = WordFieldValue;
using J03C2Message = WordMessage;

J03C2Message ParseJ03C2MessageBits(const std::string& wordBits);

J03C2Message ParseJ03C2MessageBytes(const std::vector<int>& bytes);

J03C2Message ParseJ03C2Message(const std::string& input);

std::string ProcessJ03C2MessageBits(const std::string& wordBits);

std::string ProcessJ03C2MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ03C2Message(const std::string& input);

}

#endif
