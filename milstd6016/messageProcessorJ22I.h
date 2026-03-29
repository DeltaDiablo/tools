#ifndef MILSTD6016_MESSAGEPROCESSORJ22I_H_
#define MILSTD6016_MESSAGEPROCESSORJ22I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J22IFieldValue = WordFieldValue;
using J22IMessage = WordMessage;

J22IMessage ParseJ22IMessageBits(const std::string& wordBits);
J22IMessage ParseJ22IMessageBytes(const std::vector<int>& bytes);
J22IMessage ParseJ22IMessage(const std::string& input);

std::string ProcessJ22IMessageBits(const std::string& wordBits);
std::string ProcessJ22IMessageBytes(const std::vector<int>& bytes);
std::string ProcessJ22IMessage(const std::string& input);

}

#endif
