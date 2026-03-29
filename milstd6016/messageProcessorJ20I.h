#ifndef MILSTD6016_MESSAGEPROCESSORJ20I_H_
#define MILSTD6016_MESSAGEPROCESSORJ20I_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J20IFieldValue = WordFieldValue;
using J20IMessage = WordMessage;

J20IMessage ParseJ20IMessageBits(const std::string& wordBits);

J20IMessage ParseJ20IMessageBytes(const std::vector<int>& bytes);

J20IMessage ParseJ20IMessage(const std::string& input);

std::string ProcessJ20IMessageBits(const std::string& wordBits);

std::string ProcessJ20IMessageBytes(const std::vector<int>& bytes);

std::string ProcessJ20IMessage(const std::string& input);

}

#endif
