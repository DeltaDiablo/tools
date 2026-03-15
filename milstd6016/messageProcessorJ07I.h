#ifndef MILSTD6016_MESSAGEPROCESSORJ07I_H_
#define MILSTD6016_MESSAGEPROCESSORJ07I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J07IFieldValue = WordFieldValue;
using J07IMessage = WordMessage;

J07IMessage ParseJ07IMessageBits(const std::string& wordBits);

J07IMessage ParseJ07IMessageBytes(const std::vector<int>& bytes);

J07IMessage ParseJ07IMessage(const std::string& input);

std::string ProcessJ07IMessageBits(const std::string& wordBits);

std::string ProcessJ07IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ07IMessage(const std::string& input);

}

#endif
