#ifndef MILSTD6016_MESSAGEPROCESSORJ25I_H_
#define MILSTD6016_MESSAGEPROCESSORJ25I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J25IFieldValue = WordFieldValue;
using J25IMessage = WordMessage;

J25IMessage ParseJ25IMessageBits(const std::string& wordBits);
J25IMessage ParseJ25IMessageBytes(const std::vector<int>& bytes);
J25IMessage ParseJ25IMessage(const std::string& input);

std::string ProcessJ25IMessageBits(const std::string& wordBits);
std::string ProcessJ25IMessageBytes(const std::vector<int>& bytes);
std::string ProcessJ25IMessage(const std::string& input);

}

#endif
