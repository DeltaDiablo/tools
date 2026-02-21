#include <array>
#include <string>
#include <cmath>

namespace dfi3043 {
//repeated code for DFI 3043

//end repeated code for DFI 3043

/* DFI 3043 DUI 001 MAJOR AXIS ORIENTATION*/
std::string Dui001(const std::array<int, 8>& majorAxisOrientation){
    /* ----- FOR DUI 001 -----
     * 0 THROUGH 179 DEGREES:        0 THROUGH 179
     * IN ONE DEGREE INCREMENTS.
     * ILLEGAL:                      180 THROUGH 254
     * NO STATEMENT:                 255
     */
    //convert the of 0s and 1s  to an integer
    int majorAxisOrientationInt = 0;
    for (size_t i = 0; i < majorAxisOrientation.size(); ++i) {
        majorAxisOrientationInt <<= 1; // Shift left to make room for the next bit
        majorAxisOrientationInt |= majorAxisOrientation[i]; // Add the current bit
    }
    //check the integer value and return the corresponding string
    if (majorAxisOrientationInt >= 0 && majorAxisOrientationInt <= 179) {
        return std::to_string(majorAxisOrientationInt) + " DEGREES //-> " + std::to_string(majorAxisOrientationInt);
    } else if (majorAxisOrientationInt >= 180 && majorAxisOrientationInt <= 254) {
        return "ILLEGAL //-> " + std::to_string(majorAxisOrientationInt);
    } else if (majorAxisOrientationInt == 255) {
        return "NO STATEMENT //-> " + std::to_string(majorAxisOrientationInt);
    } else {
        return "INVALID MAJOR AXIS ORIENTATION //-> " + std::to_string(majorAxisOrientationInt); // Handle invalid cases
    }
}
}
