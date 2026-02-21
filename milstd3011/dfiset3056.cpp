#include <array>
#include <string>

namespace dfi3056 {
//repeated code for 3056
//return filtered or not filtered for a 1 bit input array
std:: string FilteredOrNotFiltered(const std::array<int, 1>& inputArray)
{
    if (inputArray[0] == 0)
    {
        return "Not Filtered ///-> 0";
    }
    else if (inputArray[0] == 1)
    {
        return "Filtered ///-> 1";
    }
    else
    {
        return "Invalid input, must be 0 or 1";
    }
}
//end repeated code for 3056

/* DFI 3056 DUI 001 NO STATEMENT*/
std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
/* DFI 3056 DUI 002 DANGER*/
std::string Dui002(const std::array<int, 1>& danger)
{
    return FilteredOrNotFiltered(danger);
}
/* DFI 3056 DUI 003 CONTAMINATED*/
std::string Dui003(const std::array<int, 1>& contaminated)
{
    return FilteredOrNotFiltered(contaminated);
}
/* DFI 3056 DUI 004 MISSILE ENGAGEMENT ZONE*/
std::string Dui004(const std::array<int, 1>& missileEngagementZone)
{
    return FilteredOrNotFiltered(missileEngagementZone);
}
/* DFI 3056 DUI 005 DISUSED*/
std::string Dui005(const std::array<int, 1>& disused)
{
    return FilteredOrNotFiltered(disused);
}
/* DFI 3056 DUI 006 HOSTILE WEAPON ZONE*/
std::string Dui006(const std::array<int, 1>& hostileWeaponZone)
{
    return FilteredOrNotFiltered(hostileWeaponZone);
}
/* DFI 3056 DUI 007 HOSTILE TACTICAL ZONE*/
std::string Dui007(const std::array<int, 1>& hostileTacticalZone)
{
    return FilteredOrNotFiltered(hostileTacticalZone);
}
/* DFI 3056 DUI 008 SHORAD*/
std::string Dui008(const std::array<int, 1>& shorad)
{
    return FilteredOrNotFiltered(shorad);
}
/* DFI 3056 DUI 009 KILL ZONE*/
std::string Dui009(const std::array<int, 1>& killZone)
{
    return FilteredOrNotFiltered(killZone);
}
/* DFI 3056 DUI 010 TARGET AREA OF INTEREST*/
std::string Dui010(const std::array<int, 1>& targetAreaOfInterest)
{
    return FilteredOrNotFiltered(targetAreaOfInterest);
}
/* DFI 3056 DUI 011 NAMED AREA OF INTEREST*/
std::string Dui011(const std::array<int, 1>& namedAreaOfInterest)
{
    return FilteredOrNotFiltered(namedAreaOfInterest);
}
/* DFI 3056 DUI 012 PT6, AMP11*/
std::string Dui012(const std::array<int, 1>& pt6Amp11)
{
    return FilteredOrNotFiltered(pt6Amp11);
}
/* DFI 3056 DUI 013 PT6, AMP12*/
std::string Dui013(const std::array<int, 1>& pt6Amp12)
{
    return FilteredOrNotFiltered(pt6Amp12);
}
/* DFI 3056 DUI 014 PT6, AMP13*/
std::string Dui014(const std::array<int, 1>& pt6Amp13)
{
    return FilteredOrNotFiltered(pt6Amp13);
}
/* DFI 3056 DUI 015 PT6, AMP14*/
std::string Dui015(const std::array<int, 1>& pt6Amp14)
{
    return FilteredOrNotFiltered(pt6Amp14);
}
/* DFI 3056 DUI 016 PT6, AMP15*/
std::string Dui016(const std::array<int, 1>& pt6Amp15)
{
    return FilteredOrNotFiltered(pt6Amp15);
}
}
