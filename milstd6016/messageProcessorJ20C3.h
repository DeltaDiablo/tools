#ifndef MILSTD6016_MESSAGEPROCESSORJ20C3_H_
#define MILSTD6016_MESSAGEPROCESSORJ20C3_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J20C3FieldValue = WordFieldValue;
using J20C3Message = WordMessage;

J20C3Message ParseJ20C3MessageBits(const std::string& wordBits);

J20C3Message ParseJ20C3MessageBytes(const std::vector<int>& bytes);

J20C3Message ParseJ20C3Message(const std::string& input);

std::string ProcessJ20C3MessageBits(const std::string& wordBits);

std::string ProcessJ20C3MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ20C3Message(const std::string& input);

}

#endif
