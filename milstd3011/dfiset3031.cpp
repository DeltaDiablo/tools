#include <array>
#include <string>
#include <cmath>

namespace dfi3031 {
//repeated function for Dfi 3031

//end of repeated functions

/* DFI 3031 DUI 001 GEOGRAPHIC FILTER INDEX 5 bits*/
std::string Dui001(const std::array<int, 5>& geographicFilterIndex)
{
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        index += geographicFilterIndex[i] * std::pow(2, 4 - i);
    }
    std::string output = std::to_string(index) + " ///-> ";
    std::string binaryset = "";
    for (std::size_t i = 0; i < geographicFilterIndex.size(); i++)
    {
        binaryset.append(std::to_string(geographicFilterIndex[i]));
    }
    // Valid range is 0-31
    if (index >= 0 && index <= 31) {
        output = "Geographic Filter Index ///-> " + output;
    } else {
        output = "Illegal Geographic Filter Index ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
}
