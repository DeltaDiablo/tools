#include <array>
#include <string>
#include <cmath>

/* DFI 3009 DUI 001 GEO FILTER SUBTYPE 3 bits*/
std::string GeoFilterSubtype(const std::array<int, 3>& geoFilterSubtype)
{
    int geoFilterSubtypeInt = 0;
    for (int i = 0; i < 3; i++)
    {
        geoFilterSubtypeInt += geoFilterSubtype[i] * std::pow(2, 2 - i);
    }
    std::string output = "";
    switch (geoFilterSubtypeInt)
    {
    case 0:
        output = "Category/Identity, Exception to Filter ///-> 000";
        break;
    case 1:
        output = "Category/Identity, Filter ///-> 001";
        break;
    case 2:
        output = "Point Type/Point, Amplification, Exception to Filter ///-> 010";
        break;
    case 3:
        output = "Point Type/Point, Amplification, Filter ///-> 011";
        break;
    case 4 ... 7:
        output = "Undefined ///-> 100 through 111";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}