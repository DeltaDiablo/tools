#include <array>
#include <string>
#include <cmath>

namespace dfi3035 {
//repeated function for Dfi 3035

//end of repeated functions

std::string Dui001(const std::array<int, 4>& jreNPTransmitLimit)
{
    int limit = 0;
    for (int i = 0; i < 4; i++)
    {
        limit += jreNPTransmitLimit[i] * std::pow(2, 3 - i);
    }
    std::string output = std::to_string(limit) + " ///-> ";
    std::string binaryset = "";
    for (std::size_t i = 0; i < jreNPTransmitLimit.size(); i++)
    {
        binaryset.append(std::to_string(jreNPTransmitLimit[i]));
    }
    // Valid range is 1-10
    if (limit >= 1 && limit <= 10) {
        output = "JRE-NP Transmit Limit ///-> " + output;
    }
    else {
        output = "Illegal JRE-NP Transmit Limit ///-> " + output;
    }

    output = output + binaryset;
    return output;
};
}
