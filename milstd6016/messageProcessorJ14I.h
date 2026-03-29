#ifndef MILSTD6016_MESSAGEPROCESSORJ14I_H_
#define MILSTD6016_MESSAGEPROCESSORJ14I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J14IFieldValue = WordFieldValue;
using J14IMessage = WordMessage;

J14IMessage ParseJ14IMessageBits(const std::string& wordBits);

J14IMessage ParseJ14IMessageBytes(const std::vector<int>& bytes);

J14IMessage ParseJ14IMessage(const std::string& input);

std::string ProcessJ14IMessageBits(const std::string& wordBits);

std::string ProcessJ14IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ14IMessage(const std::string& input);

}

#endif
