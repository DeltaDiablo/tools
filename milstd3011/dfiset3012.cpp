#include <array>
#include <string>
#include <cmath>

//repeated components for DFI 3012
//0 THROUGH 65535 indicated message length in bytes
std::string Get16BitUnsignedInteger(const std::array<int, 16>& binary)
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
    output = std::to_string(decimalValue) + " ///-> " + binaryString;
    return output;
}

/* DFI 3012 DUI 001 APPLICATION BLOCK MESSAGE LENGTH(ABML) 16 bits*/
std::string Dui001(const std::array<int, 16>& applicationBlockMessageLength)
{
    return Get16BitUnsignedInteger(applicationBlockMessageLength);
}
/* DFI 3012 DUI 002 LENGTH OF MESSAGE 16 bits*/
std::string Dui002(const std::array<int, 16>& lengthOfMessage)
{
    return Get16BitUnsignedInteger(lengthOfMessage);
}
/* DFI 3012 DUI 003 MANAGEMENT MESSAGE LENGTH 16 bits*/
std::string Dui003(const std::array<int, 16>& managementMessageLength)
{
    return Get16BitUnsignedInteger(managementMessageLength);
}