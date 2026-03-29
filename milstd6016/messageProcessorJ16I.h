#ifndef MILSTD6016_MESSAGEPROCESSORJ16I_H_
#define MILSTD6016_MESSAGEPROCESSORJ16I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J16IFieldValue = WordFieldValue;
using J16IMessage = WordMessage;

J16IMessage ParseJ16IMessageBits(const std::string& wordBits);

J16IMessage ParseJ16IMessageBytes(const std::vector<int>& bytes);

J16IMessage ParseJ16IMessage(const std::string& input);

std::string ProcessJ16IMessageBits(const std::string& wordBits);

std::string ProcessJ16IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ16IMessage(const std::string& input);

}

#endif
