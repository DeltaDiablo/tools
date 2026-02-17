#include <array>
#include <string>
#include <cmath>

// DFI repeated components for DFI 3021

std::string GetLinkDesignator(const std::array<int, 16>& binary)
{
    int decimalValue = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        decimalValue += binary[i] * std::pow(2, binary.size() - 1 - i);
    }
    if(decimalValue == 0)
    {
        return "No statement ///-> " + std::to_string(decimalValue);
    }
    return std::to_string(decimalValue);
}

//end DFI repeated components for DFI 3021
/* DFI 3021 DUI 001 LINK DESIGNATOR TO FILTER 16 bits*/
std::string Dui001(const std::array<int, 16>& linkDesignatorToFilter)
{
    return GetLinkDesignator(linkDesignatorToFilter);
}
/* DFI 3021 DUI 002 LINK DESIGNATOR 16 bits*/
std::string Dui002(const std::array<int, 16>& linkDesignator)
{
    return GetLinkDesignator(linkDesignator);
}
/* DFI 3021 DUI 003 SOURCE LINK DESIGNATOR 16 bits*/
std::string Dui003(const std::array<int, 16>& sourceLinkDesignator)
{
    return GetLinkDesignator(sourceLinkDesignator);
}
/* DFI 3021 DUI 004 TRANSMIT LINK DESIGNATOR 16 bits*/
std::string Dui004(const std::array<int, 16>& transmitLinkDesignator)
{
    return GetLinkDesignator(transmitLinkDesignator);
}