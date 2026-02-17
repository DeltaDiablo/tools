#include <string>
#include <array>
#include <cmath>

//repeated components for DFI 3014

/*  *
 * DUI 001, DUI 002, DUI 003, DUI 004: Number of 16-bit words in one data word increments:
 *   - 0: No statement
 *   - 1 through 255: Number of 16-bit words in one data word increments
 */
std::string GetTransmissionBlockHeaderLength(const std::array<int, 8>& binary)
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
        output = "No statement ///-> 0";
    }
    else
    {
        output = std::to_string(decimalValue) + " words";
    }
    output = output + " ///-> " + binaryString;
    return output;
}
//end repeated components for DFI 3014 



/* DFI 3014 DUI 001 TRANSMISSION BLOCK HEADER LENGTH 8 bits*/
std::string Dui001(const std::array<int, 8>& transmissionBlockHeaderLength)
{
    return GetTransmissionBlockHeaderLength(transmissionBlockHeaderLength);
}
/* DFI 3014 DUI 002 TRANSMISSION BLOCK HEADER LENGTH, 1 8 bits*/
std::string Dui002(const std::array<int, 8>& transmissionBlockHeaderLength1)
{
    return GetTransmissionBlockHeaderLength(transmissionBlockHeaderLength1);
}
/* DFI 3014 DUI 003 TRANSMISSION BLOCK HEADER LENGTH, 2 8 bits*/
std::string Dui003(const std::array<int, 8>& transmissionBlockHeaderLength2)
{
    return GetTransmissionBlockHeaderLength(transmissionBlockHeaderLength2);
}

/* DFI 3014 DUI 004 TRANSMISSION BLOCK HEADER LENGTH, 3 8 bits*/
std::string Dui004(const std::array<int, 8>& transmissionBlockHeaderLength3)
{
    return GetTransmissionBlockHeaderLength(transmissionBlockHeaderLength3);
}
