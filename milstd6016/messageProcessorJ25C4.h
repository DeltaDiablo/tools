#ifndef MILSTD6016_MESSAGEPROCESSORJ25C4_H_
#define MILSTD6016_MESSAGEPROCESSORJ25C4_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J25C4FieldValue = WordFieldValue;
using J25C4Message = WordMessage;

J25C4Message ParseJ25C4MessageBits(const std::string& wordBits);
J25C4Message ParseJ25C4MessageBytes(const std::vector<int>& bytes);
J25C4Message ParseJ25C4Message(const std::string& input);

std::string ProcessJ25C4MessageBits(const std::string& wordBits);
std::string ProcessJ25C4MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ25C4Message(const std::string& input);

}

#endif
