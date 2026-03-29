#ifndef MILSTD6016_MESSAGEPROCESSORJ22C5_H_
#define MILSTD6016_MESSAGEPROCESSORJ22C5_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22C5FieldValue = WordFieldValue;
using J22C5Message = WordMessage;

J22C5Message ParseJ22C5MessageBits(const std::string& wordBits);
J22C5Message ParseJ22C5MessageBytes(const std::vector<int>& bytes);
J22C5Message ParseJ22C5Message(const std::string& input);

std::string ProcessJ22C5MessageBits(const std::string& wordBits);
std::string ProcessJ22C5MessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22C5Message(const std::string& input);

}

#endif
