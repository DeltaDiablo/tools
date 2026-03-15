#ifndef MILSTD6016_MESSAGEPROCESSORJ00E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ00E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J00E0FieldValue = WordFieldValue;
using J00E0Message = WordMessage;

J00E0Message ParseJ00E0MessageBits(const std::string& wordBits);

J00E0Message ParseJ00E0MessageBytes(const std::vector<int>& bytes);

J00E0Message ParseJ00E0Message(const std::string& input);

std::string ProcessJ00E0MessageBits(const std::string& wordBits);

std::string ProcessJ00E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ00E0Message(const std::string& input);

}

#endif
