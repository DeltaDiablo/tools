#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

namespace dfi3000 {
std::string dui001(const std::array<int, 7>& percentExceedingLatency) 
{
    int percentExceedingLatencyInt = 0;
    // copy the bits from the array into an integer
    for (int i = 0; i < 7; i++)
    {
        percentExceedingLatencyInt += percentExceedingLatency[i] * std::pow(2, 6 - i);
    }
    std::string output = "";
    switch (percentExceedingLatencyInt)
    {
    case 0 ... 100:
        output = std::to_string(percentExceedingLatencyInt) + "% ///-> ";
        for (std::size_t i = 0; i < percentExceedingLatency.size(); i++)
        {
            output += std::to_string(percentExceedingLatency[i]);
        }
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
}
