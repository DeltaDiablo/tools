#ifndef MILSTD6016_MESSAGEPROCESSORJ00C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ00C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J00C1FieldValue = WordFieldValue;
using J00C1Message = WordMessage;

J00C1Message ParseJ00C1MessageBits(const std::string& wordBits);

J00C1Message ParseJ00C1MessageBytes(const std::vector<int>& bytes);

J00C1Message ParseJ00C1Message(const std::string& input);

std::string ProcessJ00C1MessageBits(const std::string& wordBits);

std::string ProcessJ00C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ00C1Message(const std::string& input);

}

#endif
