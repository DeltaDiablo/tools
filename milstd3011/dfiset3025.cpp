#include <string>
#include <array>
#include <cmath>

//repeaded functions for DFI 3024
/*ASCII 8-BIT CHARACTER SET          0 THROUGH 255 */
//end of repeated functions

/* DFI 3024 DUI 001 ASCII*/
std::string Dui001(const std::array<int, 2>& controllerModeNP)
{
    int controlInt = 0;
    for (int i = 0; i < 2; i++)
    {
        controlInt += controllerModeNP[i] * std::pow(2, 1 - i);
    }
    std::string output = "";
    switch(controlInt)
    {
        case 0:
            output = "NOT JRE-ANC-CAPABLE ///-> 0";
            break;
        case 1:
            output = "JRE-ANC-CAPABLE ///-> 1";
            break;
        case 2:
            output = "JRE-ANC ///-> 2";
            break;
        case 3:
            output = "undefined ///-> 3";
            break;
        default:
            output = "Illegal ///-> " + std::to_string(controlInt);
            break;


    return output;
}
}
std::string Dui002(const std::array<int, 2>& controllerModeNC)
{
    int controlInt = 0;
    for (int i = 0; i < 2; i++)
    {
        controlInt += controllerModeNC[i] * std::pow(2, 1 - i);
    }
    std::string output = "";
    switch(controlInt)
    {
        case 0:
            output = "UNDEFINED ///-> 0";
            break;
        case 1:
            output = "JRE-ANC-CAPABLE ///-> 1";
            break;
        case 2:
            output = "UNDEFINED ///-> 2";
            break;
        case 3:
            output = "JRE-NCB ///-> 3";
            break;
        default:
            output = "Illegal ///-> " + std::to_string(controlInt);
            break;
    }

    return output;
}   
