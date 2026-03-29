#ifndef MILSTD6016_MESSAGEPROCESSORJ06C4_H_
#define MILSTD6016_MESSAGEPROCESSORJ06C4_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J06C4FieldValue = WordFieldValue;
using J06C4Message = WordMessage;

J06C4Message ParseJ06C4MessageBits(const std::string& wordBits);

J06C4Message ParseJ06C4MessageBytes(const std::vector<int>& bytes);

J06C4Message ParseJ06C4Message(const std::string& input);

std::string ProcessJ06C4MessageBits(const std::string& wordBits);

std::string ProcessJ06C4MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ06C4Message(const std::string& input);

}

#endif
