#ifndef MILSTD6016_MESSAGEPROCESSORJ02I_H_
#define MILSTD6016_MESSAGEPROCESSORJ02I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J02IFieldValue = WordFieldValue;
using J02IMessage = WordMessage;

J02IMessage ParseJ02IMessageBits(const std::string& wordBits);

J02IMessage ParseJ02IMessageBytes(const std::vector<int>& bytes);

J02IMessage ParseJ02IMessage(const std::string& input);

std::string ProcessJ02IMessageBits(const std::string& wordBits);

std::string ProcessJ02IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ02IMessage(const std::string& input);

}

#endif
