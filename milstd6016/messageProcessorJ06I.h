#ifndef MILSTD6016_MESSAGEPROCESSORJ06I_H_
#define MILSTD6016_MESSAGEPROCESSORJ06I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J06IFieldValue = WordFieldValue;
using J06IMessage = WordMessage;

J06IMessage ParseJ06IMessageBits(const std::string& wordBits);

J06IMessage ParseJ06IMessageBytes(const std::vector<int>& bytes);

J06IMessage ParseJ06IMessage(const std::string& input);

std::string ProcessJ06IMessageBits(const std::string& wordBits);

std::string ProcessJ06IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ06IMessage(const std::string& input);

}

#endif
