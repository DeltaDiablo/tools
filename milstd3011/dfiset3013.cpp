#include <array>
#include <string>
#include <cmath>

//repeated components for DFI 3013

/* AXIS LENGTH 12 bits
 * Length (in data miles) of the major axis of a geographic message filter.
 * Range: 0 (illegal) or 1-4095 data miles in one data mile increments.
 */
std::string GetAxisLength(const std::array<int, 12>& binary)
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
        output = "Illegal";
    }
    else
    {
        output = std::to_string(decimalValue) + " data miles";
    }
    output = output + " ///-> " + binaryString;
    return output;
}

//end repeated components for DFI 3013

/* DFI 3013 DUI 001 MAJOR AXIS LENGTH 12 bits*/
std::string Dui001(const std::array<int, 12>& majorAxisLength)
{
    return GetAxisLength(majorAxisLength);
}
/* DFI 3013 DUI 002 MINOR AXIS LENGTH 12 bits*/
std::string Dui002(const std::array<int, 12>& minorAxisLength)
{
    return GetAxisLength(minorAxisLength);
}