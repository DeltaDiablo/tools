#ifndef MILSTD6016_MESSAGEPROCESSORJ14E0_H_
#define MILSTD6016_MESSAGEPROCESSORJ14E0_H_

#include <string>
#include <vector>

#include "messageProcessorCore.h"

namespace milstd6016 {

using J14E0FieldValue = WordFieldValue;
using J14E0Message = WordMessage;

J14E0Message ParseJ14E0MessageBits(const std::string& wordBits);

J14E0Message ParseJ14E0MessageBytes(const std::vector<int>& bytes);

J14E0Message ParseJ14E0Message(const std::string& input);

std::string ProcessJ14E0MessageBits(const std::string& wordBits);

std::string ProcessJ14E0MessageBytes(const std::vector<int>& bytes);

std::string ProcessJ14E0Message(const std::string& input);

}

#endif
