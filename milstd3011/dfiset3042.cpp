#include <array>
#include <string>
#include <cmath>

namespace dfi3042 {
//repeated code for DFI 3042
//proccess 13 bits for altitude limits in 25 ft increments, 0-8190 feet, 8191 alt unknown
std::string AltitudeLimit(const std::array<int, 13>& bitsForAltitudeLimit){
    //convert the of 0s and 1s  to an integer
    int altitudeLimitInt = 0;
    for (size_t i = 0; i < bitsForAltitudeLimit.size(); ++i) {
        altitudeLimitInt <<= 1; // Shift left to make room for the next bit
        altitudeLimitInt |= bitsForAltitudeLimit[i]; // Add the current bit
    }
    //check if the altitude limit is unknown
    if (altitudeLimitInt == 8191) {
        return "ALTITUDE UNKNOWN //-> " + std::to_string(altitudeLimitInt);
    }
    //convert the altitude limit to feet by multiplying by 25
    int altitudeLimitFeet = altitudeLimitInt * 25;
    return std::to_string(altitudeLimitFeet) + " FEET //-> " + std::to_string(altitudeLimitInt);
}
//end repeated code for DFI 3042

/* DFI 3042 DUI 001 LOWER ALTITUDE LIMIT 13 bits */
std::string Dui001(const std::array<int, 13>& bitsForLowerAltitudeLimit)
{
    return AltitudeLimit(bitsForLowerAltitudeLimit);
}
/* DFI 3042 DUI 002 UPPER ALTITUDE LIMIT 13 bits */
std::string Dui002(const std::array<int, 13>& bitsForUpperAltitudeLimit)
{
    return AltitudeLimit(bitsForUpperAltitudeLimit);
}
}
