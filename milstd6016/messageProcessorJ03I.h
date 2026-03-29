#ifndef MILSTD6016_MESSAGEPROCESSORJ03I_H_
#define MILSTD6016_MESSAGEPROCESSORJ03I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J03IFieldValue = WordFieldValue;
using J03IMessage = WordMessage;

J03IMessage ParseJ03IMessageBits(const std::string& wordBits);

J03IMessage ParseJ03IMessageBytes(const std::vector<int>& bytes);

J03IMessage ParseJ03IMessage(const std::string& input);

std::string ProcessJ03IMessageBits(const std::string& wordBits);

std::string ProcessJ03IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ03IMessage(const std::string& input);

}

#endif
