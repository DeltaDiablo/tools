#ifndef JREAP_LIBRARY_H
#define JREAP_LIBRARY_H

#include <string>
#include <vector>

namespace jreap {

std::vector<int> ParseCsvBytes(const std::string& csvBytes);

std::string DecodeApplicationMessage(const std::vector<int>& bytes, bool strictAbml = true);

std::string DecodeApplicationMessageCsv(const std::string& csvBytes, bool strictAbml = true);

}

#endif
