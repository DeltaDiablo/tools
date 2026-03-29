#ifndef MILSTD6016_MESSAGEPROCESSORJ26E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ26E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J26E0FieldValue = WordFieldValue;
using J26E0Message = WordMessage;

J26E0Message ParseJ26E0MessageBits(const std::string& wordBits);
J26E0Message ParseJ26E0MessageBytes(const std::vector<int>& bytes);
J26E0Message ParseJ26E0Message(const std::string& input);

std::string ProcessJ26E0MessageBits(const std::string& wordBits);
std::string ProcessJ26E0MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ26E0Message(const std::string& input);

}

#endif
