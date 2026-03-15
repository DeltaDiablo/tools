#ifndef MILSTD6016_MESSAGEPROCESSORJ00I_H_
#define MILSTD6016_MESSAGEPROCESSORJ00I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J00IFieldValue = WordFieldValue;
using J00IMessage = WordMessage;

J00IMessage ParseJ00IMessageBits(const std::string& wordBits);

J00IMessage ParseJ00IMessageBytes(const std::vector<int>& bytes);

J00IMessage ParseJ00IMessage(const std::string& input);

std::string ProcessJ00IMessageBits(const std::string& wordBits);

std::string ProcessJ00IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ00IMessage(const std::string& input);

}

#endif
