#ifndef MILSTD6016_MESSAGEPROCESSORJ22E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ22E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22E0FieldValue = WordFieldValue;
using J22E0Message = WordMessage;

J22E0Message ParseJ22E0MessageBits(const std::string& wordBits);
J22E0Message ParseJ22E0MessageBytes(const std::vector<int>& bytes);
J22E0Message ParseJ22E0Message(const std::string& input);

std::string ProcessJ22E0MessageBits(const std::string& wordBits);
std::string ProcessJ22E0MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22E0Message(const std::string& input);

}

#endif
