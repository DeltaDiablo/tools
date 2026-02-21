#include <array>
#include <string>
#include <cmath>

namespace dfi3045 {
//repeated code for DFI 3045

//takes in an 8 bit array and converts it to an integer and returns the integer
int Convert8BitsToInt(const std::array<int, 8>& bitarray) {
    int flagInt = 0;
    for (size_t i = 0; i < bitarray.size(); ++i) {
        flagInt <<= 1; // Shift left to make room for the next bit
        flagInt |= bitarray[i]; // Add the current bit
    }
    return flagInt;
}

//end repeated code for DFI 3045

/* DFI 3045 DUI 001 START OF TRANSMISSION FLAG, 1 8 bits*/
std::string Dui001(const std::array<int, 8>& startOfTransmissionFlag1)
{
    int flagInt = Convert8BitsToInt(startOfTransmissionFlag1);
    //if the flag is 0 - 21 its illegal
    if( flagInt >= 0 && flagInt <= 21){
        return "ILLEGAL //-> " + std::to_string(flagInt);
    }
    //if the flag is 22 its start of transmission
    else if (flagInt == 22) {
        return "//-> " + std::to_string(flagInt);
    }
    else if (flagInt >= 23 && flagInt <= 255) {
        return "ILLEGAL //-> " + std::to_string(flagInt);
    }
    else {
        return "INVALID START OF TRANSMISSION FLAG //-> " + std::to_string(flagInt); // Handle invalid cases
    }

}
/* DFI 3045 DUI 002 START OF TRANSMISSION FLAG, 2 8 bits*/
std::string Dui002(const std::array<int, 8>& startOfTransmissionFlag2)
{
    int flagInt = Convert8BitsToInt(startOfTransmissionFlag2);
    //if the flag is 0 - 21 its illegal
    if( flagInt >= 0 && flagInt <= 21){
        return "ILLEGAL //-> " + std::to_string(flagInt);
    }
    //if the flag is 22 its start of transmission
    else if (flagInt == 22) {
        return "//-> " + std::to_string(flagInt);
    }
    else if (flagInt >= 23 && flagInt <= 255) {
        return "ILLEGAL //-> " + std::to_string(flagInt);
    }
    else {
        return "INVALID START OF TRANSMISSION FLAG //-> " + std::to_string(flagInt); // Handle invalid cases
    }
}
}
