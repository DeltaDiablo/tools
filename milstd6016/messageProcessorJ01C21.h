#ifndef MILSTD6016_MESSAGEPROCESSORJ01C21_H_
#define MILSTD6016_MESSAGEPROCESSORJ01C21_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J01C21FieldValue = WordFieldValue;
using J01C21Message = WordMessage;

J01C21Message ParseJ01C21MessageBits(const std::string& wordBits);

J01C21Message ParseJ01C21MessageBytes(const std::vector<int>& bytes);

J01C21Message ParseJ01C21Message(const std::string& input);

std::string ProcessJ01C21MessageBits(const std::string& wordBits);

std::string ProcessJ01C21MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ01C21Message(const std::string& input);

}

#endif
