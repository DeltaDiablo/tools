#include <string>
#include <array>
#include <cmath>

namespace dfi3018 {
//repeated components for DFI 3018
std::string GetNumberOfDesignators(const std::array<int, 8>& binary)
{
    int decimalValue = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        decimalValue += binary[i] * std::pow(2, binary.size() - 1 - i);
    }

    std::string binaryString = "";
    for (std::size_t i = 0; i < binary.size(); i++)
    {
        binaryString.append(std::to_string(binary[i]));
    }
    std::string output = "";
    if (decimalValue == 0)
    {
        output = "No statement ///-> " + binaryString;
    }
    else
    {
        output = std::to_string(decimalValue) + " designators ///-> " + binaryString;
    }
    return output;
}
//end repeated components for DFI 3018

/* DFI 3018 DUI 001 NUMBER OF DESIGNATORS SUPPORTED*/
std::string Dui001(const std::array<int, 8>& numberOfDesignatorsSupported)
{
    return GetNumberOfDesignators(numberOfDesignatorsSupported);
}   
/* DFI 3018 DUI 002 TOTAL NUMBER OF ACTIVE DESIGNATORS*/
std::string Dui002(const std::array<int, 8>& totalNumberOfActiveDesignators)
{
    return GetNumberOfDesignators(totalNumberOfActiveDesignators);
}
}
