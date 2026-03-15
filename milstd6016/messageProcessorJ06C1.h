#ifndef MILSTD6016_MESSAGEPROCESSORJ06C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ06C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J06C1FieldValue = WordFieldValue;
using J06C1Message = WordMessage;

J06C1Message ParseJ06C1MessageBits(const std::string& wordBits);

J06C1Message ParseJ06C1MessageBytes(const std::vector<int>& bytes);

J06C1Message ParseJ06C1Message(const std::string& input);

std::string ProcessJ06C1MessageBits(const std::string& wordBits);

std::string ProcessJ06C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ06C1Message(const std::string& input);

}

#endif
