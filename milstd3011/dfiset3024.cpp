#include <string>
#include <array>
#include <cmath>

namespace dfi3024 {
//repeaded functions for DFI 3024
/*ASCII 8-BIT CHARACTER SET          0 THROUGH 255 */
//end of repeated functions

/* DFI 3024 DUI 001 ASCII*/
std::string Dui001(const std::array<int, 8>& asciiCharacters)
{
    int asciiCharactersInt = 0;
    for (int i = 0; i < 8; i++)
    {
        asciiCharactersInt += asciiCharacters[i] * std::pow(2, 7 - i);
    }
    std::string output = "";
    if (asciiCharactersInt >= 0 && asciiCharactersInt <= 255)
    {
        output = std::to_string(asciiCharactersInt);
    }
    else
    {
        output = "Illegal //-> " + std::to_string(asciiCharactersInt);
    }
    return output;
}
}
