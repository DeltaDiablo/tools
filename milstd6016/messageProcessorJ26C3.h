#ifndef MILSTD6016_MESSAGEPROCESSORJ26C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ26C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J26C3FieldValue = WordFieldValue;
using J26C3Message = WordMessage;

J26C3Message ParseJ26C3MessageBits(const std::string& wordBits);
J26C3Message ParseJ26C3MessageBytes(const std::vector<int>& bytes);
J26C3Message ParseJ26C3Message(const std::string& input);

std::string ProcessJ26C3MessageBits(const std::string& wordBits);
std::string ProcessJ26C3MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ26C3Message(const std::string& input);

}

#endif
