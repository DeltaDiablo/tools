#include <string>
#include <array>
#include <cmath>

namespace dfi3023 {
//repeaded functions for DFI 3023
//end of repeated functions

std::string Dui001(const std::array<int, 4>& applicationProtocolVersion)
{
    int applicationProtocolVersionInt = 0;
    for (int i = 0; i < 4; i++)
    {
        applicationProtocolVersionInt += applicationProtocolVersion[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    if (applicationProtocolVersionInt > 0)
    {
        output = std::to_string(applicationProtocolVersionInt);
    }
    else
    {
        output = "Illegal";
    }
    return output + " ///-> " + std::to_string(applicationProtocolVersionInt);
}
}
