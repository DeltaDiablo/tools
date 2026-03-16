#ifndef MILSTD6016_MESSAGEPROCESSORJ26I_H_
#define MILSTD6016_MESSAGEPROCESSORJ26I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J26IFieldValue = WordFieldValue;
using J26IMessage = WordMessage;

J26IMessage ParseJ26IMessageBits(const std::string& wordBits);
J26IMessage ParseJ26IMessageBytes(const std::vector<int>& bytes);
J26IMessage ParseJ26IMessage(const std::string& input);

std::string ProcessJ26IMessageBits(const std::string& wordBits);
std::string ProcessJ26IMessageBytes(const std::vector<int>& bytes);
std::string ProcessJ26IMessage(const std::string& input);

}

#endif
