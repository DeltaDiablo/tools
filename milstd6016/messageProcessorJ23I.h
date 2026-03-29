#ifndef MILSTD6016_MESSAGEPROCESSORJ23I_H_
#define MILSTD6016_MESSAGEPROCESSORJ23I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J23IFieldValue = WordFieldValue;
using J23IMessage = WordMessage;

J23IMessage ParseJ23IMessageBits(const std::string& wordBits);
J23IMessage ParseJ23IMessageBytes(const std::vector<int>& bytes);
J23IMessage ParseJ23IMessage(const std::string& input);

std::string ProcessJ23IMessageBits(const std::string& wordBits);
std::string ProcessJ23IMessageBytes(const std::vector<int>& bytes);
std::string ProcessJ23IMessage(const std::string& input);

}

#endif
