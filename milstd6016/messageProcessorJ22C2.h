#ifndef MILSTD6016_MESSAGEPROCESSORJ22C2_H_
#define MILSTD6016_MESSAGEPROCESSORJ22C2_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22C2FieldValue = WordFieldValue;
using J22C2Message = WordMessage;

J22C2Message ParseJ22C2MessageBits(const std::string& wordBits);
J22C2Message ParseJ22C2MessageBytes(const std::vector<int>& bytes);
J22C2Message ParseJ22C2Message(const std::string& input);

std::string ProcessJ22C2MessageBits(const std::string& wordBits);
std::string ProcessJ22C2MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22C2Message(const std::string& input);

}

#endif
