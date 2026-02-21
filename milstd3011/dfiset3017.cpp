#include <string>
#include <array>
#include <cmath>

namespace dfi3017 {
//repeated components for DFI 3017

std::string GetNumberOfAddresses(const std::array<int, 8>& binary, bool isDui002 = false)
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
        output = isDui002 ? "0 addresses ///-> " : "Broadcast ///-> " + binaryString;
    }
    else
    {
        output = std::to_string(decimalValue) + " addresses ///-> " + binaryString;
    }
    return output;
}

//end repeated components for DFI 3017

/* DFI 3017 DUI 001 NUMBER DESTINATION ADDRESSES 8 bits*/
std::string Dui001(const std::array<int, 8>& numberDestinationAddresses)
{    return GetNumberOfAddresses(numberDestinationAddresses);
}
/* DFI 3017 DUI 002 NUMBER ADDRESSES THIS DESIGNATOR 8 bits*/
std::string Dui002(const std::array<int, 8>& numberAddressesThisDesignator)
{
    return GetNumberOfAddresses(numberAddressesThisDesignator, true);
}
/* DFI 3017 DUI 003 NUMBER DESTINATION ADDRESSES, NON-ZERO 8 bits*/
std::string Dui003(const std::array<int, 8>& numberDestinationAddressesNonZero)
{
    return GetNumberOfAddresses(numberDestinationAddressesNonZero);
}
}
