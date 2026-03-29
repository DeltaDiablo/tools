#ifndef MILSTD6016_MESSAGEPROCESSORJ06C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ06C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J06C3FieldValue = WordFieldValue;
using J06C3Message = WordMessage;

J06C3Message ParseJ06C3MessageBits(const std::string& wordBits);

J06C3Message ParseJ06C3MessageBytes(const std::vector<int>& bytes);

J06C3Message ParseJ06C3Message(const std::string& input);

std::string ProcessJ06C3MessageBits(const std::string& wordBits);

std::string ProcessJ06C3MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ06C3Message(const std::string& input);

}

#endif
