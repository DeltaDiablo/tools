#include <array>
#include <string>
#include <cmath>

namespace dfi3044 {
//repeated code for DFI 3044
//convet 4 bits to an integer and return the integer
int Convert4BitsToInt(const std::array<int, 4>& bitarray) {
    int versionInt = 0;
    for (size_t i = 0; i < bitarray.size(); ++i) {
        versionInt <<= 1; // Shift left to make room for the next bit
        versionInt |= bitarray[i]; // Add the current bit
    }
    return versionInt;
}
//end repeated code for DFI 3044

/* DFI 3044 DUI 001 MANAGEMENT VERSION 4 bits*/
std::string Dfi3044Dui001(const std::array<int, 4>& managementVersion)
{
    int versionInt = Convert4BitsToInt(managementVersion);
    return "MANAGEMENT VERSION " + std::to_string(versionInt) + " //-> " + std::to_string(versionInt);
}
}
