#ifndef MILSTD6016_MESSAGEPROCESSORJ01E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ01E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J01E0FieldValue = WordFieldValue;
using J01E0Message = WordMessage;

J01E0Message ParseJ01E0MessageBits(const std::string& wordBits);

J01E0Message ParseJ01E0MessageBytes(const std::vector<int>& bytes);

J01E0Message ParseJ01E0Message(const std::string& input);

std::string ProcessJ01E0MessageBits(const std::string& wordBits);

std::string ProcessJ01E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ01E0Message(const std::string& input);

}

#endif
