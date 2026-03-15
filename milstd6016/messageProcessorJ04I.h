#ifndef MILSTD6016_MESSAGEPROCESSORJ04I_H_
#define MILSTD6016_MESSAGEPROCESSORJ04I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J04IFieldValue = WordFieldValue;
using J04IMessage = WordMessage;

J04IMessage ParseJ04IMessageBits(const std::string& wordBits);

J04IMessage ParseJ04IMessageBytes(const std::vector<int>& bytes);

J04IMessage ParseJ04IMessage(const std::string& input);

std::string ProcessJ04IMessageBits(const std::string& wordBits);

std::string ProcessJ04IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ04IMessage(const std::string& input);

}

#endif
