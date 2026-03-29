#ifndef MILSTD6016_MESSAGEPROCESSORJ07E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ07E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J07E0FieldValue = WordFieldValue;
using J07E0Message = WordMessage;

J07E0Message ParseJ07E0MessageBits(const std::string& wordBits);

J07E0Message ParseJ07E0MessageBytes(const std::vector<int>& bytes);

J07E0Message ParseJ07E0Message(const std::string& input);

std::string ProcessJ07E0MessageBits(const std::string& wordBits);

std::string ProcessJ07E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ07E0Message(const std::string& input);

}

#endif
