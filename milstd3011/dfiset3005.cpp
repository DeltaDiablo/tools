
#include <iostream>
#include <array>
#include <cmath>
#include <string>

//constants for DFI 3005
std::string PreferredOrNot(const std::array<int, 1>& jreNcP)
{
    if (jreNcP[0] == 1)
    {
        return "Preferred ///-> 1";
    }
    else
    {
        return "Not Preferred ///-> 0";
    }
}
//end constants for dfi 3005

/* DFI 3005 DUI 001 JRE NC, P 1 bit*/
std::string Dui001(const std::array<int, 1>& jreNcP)
{
    return PreferredOrNot(jreNcP);
}
/* DFI 3005 DUI 002 RTTIME, P 1 bit*/
std::string Dui002(const std::array<int, 1>& rttimeP)
{
    return PreferredOrNot(rttimeP);
}
/* DFI 3005 DUI 003 FIXED DELAY, P 1 bit*/
std::string Dui003(const std::array<int, 1>& fixedDelayP)
{
    return PreferredOrNot(fixedDelayP);
}
/* DFI 3005 DUI 004 EVENT STROBE, P 1 bit*/
std::string Dui004(const std::array<int, 1>& eventStrobeP)
{
    return PreferredOrNot(eventStrobeP);
}
/* DFI 3005 DUI 005 UTC, P 1 bit*/
std::string Dui005(const std::array<int, 1>& utcP)
{
    return PreferredOrNot(utcP);
}
