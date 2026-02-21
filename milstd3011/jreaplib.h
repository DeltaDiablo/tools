#ifndef JREAPLIB_H_
#define JREAPLIB_H_

#include <string>
#include <vector>

namespace jreap {

std::vector<int> ParseCsvBytes(const std::string& csvBytes);

std::string DecodeApplicationMessage(const std::vector<int>& bytes, bool strictAbml = true);

std::string DecodeApplicationMessageCsv(const std::string& csvBytes, bool strictAbml = true);

}

#endif
