#include <array>
#include <string>
#include <cmath>

namespace dfi3010 {
//processor functions for DFI 3010
std::string lat8ftPrecision(const std::array<int, 23>& latitude)
{
    /*
     * 0 DEGREES                                0
     * +90/4,194,303 THROUGH +90 DEGREES NORTH  1 THROUGH 4194303
     * NO STATEMENT                             4194304
     * -90 THROUGH -90/4,194,303 DEGREES SOUTH  4194305 THROUGH 8388607
     */
    //IN 90/4,194,303 DEGREE INCREMENTS.
    // Convert the array of bits to an integer
    int value = 0;
    for (size_t i = 0; i < latitude.size(); ++i) {
        value <<= 1; // Shift left to make room for the next bit
        value |= latitude[i]; // Add the current bit
    }
    // Calculate the latitude in degrees
    double latitudeDegrees = (static_cast<double>(value) / 4194303.0) * 90.0;
    //evaluate the latitude and return the appropriate string
    switch (value) {
        case 0:
            return "0 degrees";
        case 4194304:
            return "No statement";
        case 8388607:
            return "90 degrees south";
        default:
            if (value > 0 && value < 4194304) {
                return std::to_string(latitudeDegrees) + " degrees north";
            } else if (value > 4194304 && value < 8388607) {
                return std::to_string(90.0 - latitudeDegrees) + " degrees south";
            } else {
                return "Invalid latitude value";
            }
    }
}

/* DFI 3010 DUI 015 LATITUDE, 0.0013 MINUTE 23 bits*/
std::string Dui015(const std::array<int, 23>& latitude)
{
    return lat8ftPrecision(latitude);
}
/* DFI 3010 DUI 018 LATITUDE, CENTER 0.0013 MINUTE 23 bits*/
std::string Dui018(const std::array<int, 23>& latitudeCenter)
{
    //use the dfiset3010 Dui018 function to process the latitudeCenter array and return the output
    return lat8ftPrecision(latitudeCenter);
}
}
