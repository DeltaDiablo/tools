
#include <iostream>
#include <array>
#include <string>

namespace dfi3004 {
//repeatable code for the JRE capabilities report, since all the DFI 3004 DUIs have the same coding and output just different names, we can use this function to generate the output for all of them
std::string jreCapabilitesReport(std::array<int, 1> jreNcC)
{
    if (jreNcC[0] == 1)
    {
        return "Capable ///-> 1";
    }
    else
    {
        return "Not Capable ///-> 0";
    }
}
//end of repeatable code for the JRE capabilities report

/* DFI 3004 DUI 001 JRE NC, C 1 bit*/
std::string Dui001(const std::array<int, 1>& jreNcC)
{
    return jreCapabilitesReport(jreNcC);
}
/* DFI 3004 DUI 002 RTTIME, C*/
std::string Dui002(const std::array<int, 1>& rttimeC)
{
    return jreCapabilitesReport(rttimeC);
}
/* DFI 3004 DUI 003 FIXED DELAY, C 1 bit*/
std::string Dui003(const std::array<int, 1>& fixedDelayC)
{
    return jreCapabilitesReport(fixedDelayC);
}
/* DFI 3004 DUI 004 EVENT STROBE, C 1 bit*/
std::string Dui004(const std::array<int, 1>& eventStrobeC)
{
    return jreCapabilitesReport(eventStrobeC);
}
/* DFI 3004 DUI 005 UTC, C 1 bit*/
std::string Dui005(const std::array<int, 1>& utcC)
{
    return jreCapabilitesReport(utcC);
}
}
