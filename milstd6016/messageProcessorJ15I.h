#ifndef MILSTD6016_MESSAGEPROCESSORJ15I_H_
#define MILSTD6016_MESSAGEPROCESSORJ15I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J15IFieldValue = WordFieldValue;
using J15IMessage = WordMessage;

J15IMessage ParseJ15IMessageBits(const std::string& wordBits);

J15IMessage ParseJ15IMessageBytes(const std::vector<int>& bytes);

J15IMessage ParseJ15IMessage(const std::string& input);

std::string ProcessJ15IMessageBits(const std::string& wordBits);

std::string ProcessJ15IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ15IMessage(const std::string& input);

}

#endif
