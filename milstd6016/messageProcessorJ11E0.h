#ifndef MILSTD6016_MESSAGEPROCESSORJ11E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ11E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J11E0FieldValue = WordFieldValue;
using J11E0Message = WordMessage;

J11E0Message ParseJ11E0MessageBits(const std::string& wordBits);

J11E0Message ParseJ11E0MessageBytes(const std::vector<int>& bytes);

J11E0Message ParseJ11E0Message(const std::string& input);

std::string ProcessJ11E0MessageBits(const std::string& wordBits);

std::string ProcessJ11E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ11E0Message(const std::string& input);

}

#endif
