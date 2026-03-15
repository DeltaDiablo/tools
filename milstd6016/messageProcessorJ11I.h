#ifndef MILSTD6016_MESSAGEPROCESSORJ11I_H_
#define MILSTD6016_MESSAGEPROCESSORJ11I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J11IFieldValue = WordFieldValue;
using J11IMessage = WordMessage;

J11IMessage ParseJ11IMessageBits(const std::string& wordBits);

J11IMessage ParseJ11IMessageBytes(const std::vector<int>& bytes);

J11IMessage ParseJ11IMessage(const std::string& input);

std::string ProcessJ11IMessageBits(const std::string& wordBits);

std::string ProcessJ11IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ11IMessage(const std::string& input);

}

#endif
