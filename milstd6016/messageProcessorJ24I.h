#ifndef MILSTD6016_MESSAGEPROCESSORJ24I_H_
#define MILSTD6016_MESSAGEPROCESSORJ24I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J24IFieldValue = WordFieldValue;
using J24IMessage = WordMessage;

J24IMessage ParseJ24IMessageBits(const std::string& wordBits);
J24IMessage ParseJ24IMessageBytes(const std::vector<int>& bytes);
J24IMessage ParseJ24IMessage(const std::string& input);

std::string ProcessJ24IMessageBits(const std::string& wordBits);
std::string ProcessJ24IMessageBytes(const std::vector<int>& bytes);
std::string ProcessJ24IMessage(const std::string& input);

}

#endif
