#include <array>
#include <string>
#include <cmath>

//repeated functions for DFI 3022
//end of repeated functions

std::string Dui001(const std::array<int, 5>& eventType)
{
    int eventTypeInt = 0;
    for (int i = 0; i < 5; i++)
    {
        eventTypeInt += eventType[i] * std::pow(2, 4 - i);
    }
    std::string output = "";
    switch (eventTypeInt)
    {
    case 0:
        output = "EHF Satellite Epoch Strobe";
        break;
    default:
        output = "undefined //-> " + std::to_string(eventTypeInt);
        break;
    }

    return output;

}