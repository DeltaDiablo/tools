#ifndef MILSTD6016_MESSAGEPROCESSORJ10I_H_
#define MILSTD6016_MESSAGEPROCESSORJ10I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J10IFieldValue = WordFieldValue;
using J10IMessage = WordMessage;

J10IMessage ParseJ10IMessageBits(const std::string& wordBits);

J10IMessage ParseJ10IMessageBytes(const std::vector<int>& bytes);

J10IMessage ParseJ10IMessage(const std::string& input);

std::string ProcessJ10IMessageBits(const std::string& wordBits);

std::string ProcessJ10IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ10IMessage(const std::string& input);

}

#endif
