#ifndef MILSTD6016_MESSAGEPROCESSORJ13I_H_
#define MILSTD6016_MESSAGEPROCESSORJ13I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J13IFieldValue = WordFieldValue;
using J13IMessage = WordMessage;

J13IMessage ParseJ13IMessageBits(const std::string& wordBits);

J13IMessage ParseJ13IMessageBytes(const std::vector<int>& bytes);

J13IMessage ParseJ13IMessage(const std::string& input);

std::string ProcessJ13IMessageBits(const std::string& wordBits);

std::string ProcessJ13IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ13IMessage(const std::string& input);

}

#endif
