#include <string>
#include <array>
#include <cmath>

namespace dfi3015 {
 //repeated components for DFI 3015
 std::string GetErrorRate(const std::array<int, 7>& binary)
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
     if (decimalValue == 127)
     {
         output = "Error rate greater than 126 ///-> " + binaryString;
     }
     else
     {
         output = std::to_string(decimalValue) + " ///-> " + binaryString;
     }
     return output;
 }
 //end repeated components for DFI 3015

 /* DFI 3015 DUI 001 CURRENT ERROR RATE 7 bits*/
std::string Dui001(const std::array<int, 7>& currentErrorRate)
    {
        return GetErrorRate(currentErrorRate);
    }
/* DFI 3015 DUI 002 JRE-NP ERROR RATE 7 bits*/
std::string Dui002(const std::array<int, 7>& jreNpErrorRate)
{
    return GetErrorRate(jreNpErrorRate);
}
/* DFI 3015 DUI 017 JRE-NC ERROR RATE 7 bits*/
std::string Dui017(const std::array<int, 7>& jreNcErrorRate)
{
    return GetErrorRate(jreNcErrorRate);
}
/* DFI 3015 DUI 018 ERROR RATE, CURRENT 16 bits*/
std::string Dui018(const std::array<int, 16>& errorRateCurrent)
{
    int decimalValue = 0;
    for (size_t i = 0; i < errorRateCurrent.size(); ++i) {
        decimalValue += errorRateCurrent[i] * std::pow(2, errorRateCurrent.size() - 1 - i);
    }

    std::string binaryString = "";
    for (std::size_t i = 0; i < errorRateCurrent.size(); i++)
    {
        binaryString.append(std::to_string(errorRateCurrent[i]));
    }

    std::string output = "";
    if (decimalValue == 65535)
    {
        output = "Error rate greater than 65534 ///-> " + binaryString;
    }
    else
    {
        output = std::to_string(decimalValue) + " ///-> " + binaryString;
    }
    return output;
}
}
