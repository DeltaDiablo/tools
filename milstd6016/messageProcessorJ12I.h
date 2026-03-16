#ifndef MILSTD6016_MESSAGEPROCESSORJ12I_H_
#define MILSTD6016_MESSAGEPROCESSORJ12I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J12IFieldValue = WordFieldValue;
using J12IMessage = WordMessage;

J12IMessage ParseJ12IMessageBits(const std::string& wordBits);

J12IMessage ParseJ12IMessageBytes(const std::vector<int>& bytes);

J12IMessage ParseJ12IMessage(const std::string& input);

std::string ProcessJ12IMessageBits(const std::string& wordBits);

std::string ProcessJ12IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ12IMessage(const std::string& input);

}

#endif
