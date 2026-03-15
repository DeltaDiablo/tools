#ifndef MILSTD6016_MESSAGEPROCESSORVALUEMEANING_H_
#define MILSTD6016_MESSAGEPROCESSORVALUEMEANING_H_

#include <string>

namespace milstd6016 {

std::string DescribeValueMeaning(int dfi, int dui, const std::string& bitCode, bool resolveRanges = true);

std::string DescribeAllValueMeanings(int dfi, int dui);

}

#endif
