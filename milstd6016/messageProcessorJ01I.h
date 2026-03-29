#ifndef MILSTD6016_MESSAGEPROCESSORJ01I_H_
#define MILSTD6016_MESSAGEPROCESSORJ01I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J01IFieldValue = WordFieldValue;
using J01IMessage = WordMessage;

J01IMessage ParseJ01IMessageBits(const std::string& wordBits);

J01IMessage ParseJ01IMessageBytes(const std::vector<int>& bytes);

J01IMessage ParseJ01IMessage(const std::string& input);

std::string ProcessJ01IMessageBits(const std::string& wordBits);

std::string ProcessJ01IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ01IMessage(const std::string& input);

}

#endif
