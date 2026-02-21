#include <array>
#include <string>
#include <cmath>

namespace dfi3050 {
//repeated code for DFI 3050
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
//end of repeated code

/* DFI 3050 DUI 001 NO STATEMENT 1 bit*/
std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
/* DFI 3050 DUI 002 NAVIGATION 1 bit*/
std::string Dui002(const std::array<int, 1>& navigation)
{
    return FilteredOrNotFiltered(navigation);
}
/* DFI 3050 DUI 003 MINE 1 bit*/
std::string Dui003(const std::array<int, 1>& mine)
{
    return FilteredOrNotFiltered(mine);
}
/* DFI 3050 DUI 004 IMPACT POINT 1 bit*/
std::string Dui004(const std::array<int, 1>& impactPoint)
{
    return FilteredOrNotFiltered(impactPoint);
}
/* DFI 3050 DUI 005 GROUND ZERO 1 bit*/
std::string Dui005(const std::array<int, 1>& groundZero)
{
    return FilteredOrNotFiltered(groundZero);
}
/* DFI 3050 DUI 006 AIM/WEAPON ENTRY POINT 1 bit*/
std::string Dui006(const std::array<int, 1>& aimWeaponEntryPoint)
{
    return FilteredOrNotFiltered(aimWeaponEntryPoint);
}
/* DFI 3050 DUI 007 MISSILE LAUNCH POINT 1 bit*/
std::string Dui007(const std::array<int, 1>& missileLaunchPoint)
{
    return FilteredOrNotFiltered(missileLaunchPoint);
}
/* DFI 3050 DUI 008 ELECTRONIC ATTACK (EA) DECOY 1 bit*/
std::string Dui008(const std::array<int, 1>& electronicAttackDecoy)
{
    return FilteredOrNotFiltered(electronicAttackDecoy);
}
/* DFI 3050 DUI 009 ENGAGEMENT POINT 1 bit*/
std::string Dui009(const std::array<int, 1>& engagementPoint)
{
    return FilteredOrNotFiltered(engagementPoint);
}
/* DFI 3050 DUI 010 OIL RIG 1 bit*/
std::string Dui010(const std::array<int, 1>& oilRig)
{
    return FilteredOrNotFiltered(oilRig);
}
/* DFI 3050 DUI 011 PT0, AMP10 1 bit*/
std::string Dui011(const std::array<int, 1>& pt0Amp10)
{
    return FilteredOrNotFiltered(pt0Amp10);
}
/* DFI 3050 DUI 012 PT0, AMP11 1 bit*/
std::string Dui012(const std::array<int, 1>& pt0Amp11)
{
    return FilteredOrNotFiltered(pt0Amp11);
}
/* DFI 3050 DUI 013 PT0, AMP12 1 bit*/
std::string Dui013(const std::array<int, 1>& pt0Amp12)
{
    return FilteredOrNotFiltered(pt0Amp12);
}
/* DFI 3050 DUI 014 PT0, AMP13 1 bit*/
std::string Dui014(const std::array<int, 1>& pt0Amp13)
{
    return FilteredOrNotFiltered(pt0Amp13);
}
/* DFI 3050 DUI 015 PT0, AMP14 1 bit*/
std::string Dui015(const std::array<int, 1>& pt0Amp14)
{
    return FilteredOrNotFiltered(pt0Amp14);
}
/* DFI 3050 DUI 016 PT0, AMP15 1 bit*/
std::string Dui016(const std::array<int, 1>& pt0Amp15)
{
    return FilteredOrNotFiltered(pt0Amp15);
}
}
