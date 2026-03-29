#ifndef MILSTD6016_MESSAGEPROCESSORJ03C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ03C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J03C1FieldValue = WordFieldValue;
using J03C1Message = WordMessage;

J03C1Message ParseJ03C1MessageBits(const std::string& wordBits);

J03C1Message ParseJ03C1MessageBytes(const std::vector<int>& bytes);

J03C1Message ParseJ03C1Message(const std::string& input);

std::string ProcessJ03C1MessageBits(const std::string& wordBits);

std::string ProcessJ03C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ03C1Message(const std::string& input);

}

#endif
