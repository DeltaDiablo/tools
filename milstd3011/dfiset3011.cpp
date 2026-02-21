#include <array>
#include <string>
#include <cmath>

namespace dfi3011 {
/* DATA ITEM                                           BIT CODE VALUE 
   0 DEGREES                                           0
   +180/8,388,607 THROUGH +180 DEGREES EAST            1 THROUGH 8388607
   NO STATEMENT                                        8388608
   -180 THROUGH -180/8,388,607 DEGREES WEST            8388609 THROUGH 16777215
*/
//repeated components for DFI 3011
std::string GetLongitude(const std::array<int, 24>& binary)
{
    // Convert the binary array to a decimal value
    int decimalValue = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        decimalValue += binary[i] * std::pow(2, binary.size() - 1 - i);
    }

    // Calculate the longitude based on the decimal value
    double longitude;
    switch (decimalValue) {
        case 0:
            return "0 degrees";
        case 8388608:
            return "No Statement";
        default:
            if (decimalValue < 8388608) {
                longitude = (static_cast<double>(decimalValue) / 8388607.0) * 180.0;
                return std::to_string(longitude) + " degrees East";
            } else {
                longitude = ((static_cast<double>(decimalValue) - 8388608.0) / 8388607.0) * -180.0;
                return std::to_string(longitude) + " degrees West";
            }
    }
}

/* DFI 3011 DUI 015 LONGITUDE, 0.0013 MINUTE 24 bits*/
std::string Dui015(const std::array<int, 24>& longitude)
{
    return GetLongitude(longitude);
}
/* DFI 3011 DUI 016 LONGITUDE, CENTER 0.0013 MINUTE 24 bits*/
std::string Dui016(const std::array<int, 24>& longitudeCenter)
{
    return GetLongitude(longitudeCenter);
}
}
