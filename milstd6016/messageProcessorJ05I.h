#ifndef MILSTD6016_MESSAGEPROCESSORJ05I_H_
#define MILSTD6016_MESSAGEPROCESSORJ05I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J05IFieldValue = WordFieldValue;
using J05IMessage = WordMessage;

J05IMessage ParseJ05IMessageBits(const std::string& wordBits);

J05IMessage ParseJ05IMessageBytes(const std::vector<int>& bytes);

J05IMessage ParseJ05IMessage(const std::string& input);

std::string ProcessJ05IMessageBits(const std::string& wordBits);

std::string ProcessJ05IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ05IMessage(const std::string& input);

}

#endif
