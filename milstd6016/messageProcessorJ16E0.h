#ifndef MILSTD6016_MESSAGEPROCESSORJ16E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ16E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J16E0FieldValue = WordFieldValue;
using J16E0Message = WordMessage;

J16E0Message ParseJ16E0MessageBits(const std::string& wordBits);

J16E0Message ParseJ16E0MessageBytes(const std::vector<int>& bytes);

J16E0Message ParseJ16E0Message(const std::string& input);

std::string ProcessJ16E0MessageBits(const std::string& wordBits);

std::string ProcessJ16E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ16E0Message(const std::string& input);

}

#endif
