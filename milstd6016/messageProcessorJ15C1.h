#ifndef MILSTD6016_MESSAGEPROCESSORJ15C1_H_
#define MILSTD6016_MESSAGEPROCESSORJ15C1_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J15C1FieldValue = WordFieldValue;
using J15C1Message = WordMessage;

J15C1Message ParseJ15C1MessageBits(const std::string& wordBits);

J15C1Message ParseJ15C1MessageBytes(const std::vector<int>& bytes);

J15C1Message ParseJ15C1Message(const std::string& input);

std::string ProcessJ15C1MessageBits(const std::string& wordBits);

std::string ProcessJ15C1MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ15C1Message(const std::string& input);

}

#endif
