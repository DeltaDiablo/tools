#include <array>
#include <string>
#include <cmath>

namespace dfi3039 {
//repeated function for Dfi 3039
int calculateCrc(const std::array<int, 16>& data)
{
    int output = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        output = (output << 1) + data[i];
    }
    return output;
}
//end of repeated functions

/* DFI 3039 DUI 001 MESSAGE GROUP HEADER CRC*/
std::string Dui001(const std::array<int, 16>& messageGroupHeaderCrc)
{
    int crcValue = calculateCrc(messageGroupHeaderCrc);
    return "MESSAGE GROUP HEADER CRC ///-> " + std::to_string(crcValue);
}
/* DFI 3039 DUI 002 TRANSMISSION BLOCK HEADER CRC*/
std::string Dui002(const std::array<int, 16>& transmissionBlockHeaderCrc)
{
    int crcValue = calculateCrc(transmissionBlockHeaderCrc);
    return "TRANSMISSION BLOCK HEADER CRC ///-> " + std::to_string(crcValue);
}
}
