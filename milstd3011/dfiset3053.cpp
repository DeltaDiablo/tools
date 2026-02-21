#include <array>
#include <string>

namespace dfi3053 {
//repeated code for 3053
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
//end repeated code for 3053

std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
// 002 COMBAT AIR PATROL (CAP)
std::string Dui002(const std::array<int, 1>& combatAirPatrol)
{
    return FilteredOrNotFiltered(combatAirPatrol);
}
// 003 AIRBORNE EARLY WARNING (AEW)
std::string Dui003(const std::array<int, 1>& airborneEarlyWarning)
{
    return FilteredOrNotFiltered(airborneEarlyWarning);
}
// 004 ANTISUBMARINE WARFARE FIXED WING (ASW FW)
std::string Dui004(const std::array<int, 1>& antisubmarineWarfareFixedWing)
{
    return FilteredOrNotFiltered(antisubmarineWarfareFixedWing);
}
// 005 ANTISUBMARINE WARFARE HELICOPTER (ASW HEL)
std::string Dui005(const std::array<int, 1>& antisubmarineWarfareHelicopter)
{
    return FilteredOrNotFiltered(antisubmarineWarfareHelicopter);
}
// 006 REPLENISHMENT (RPL)
std::string Dui006(const std::array<int, 1>& replenishment)
{
    return FilteredOrNotFiltered(replenishment);
}
// 007 STRIKE INITIAL POINT (STK IP)
std::string Dui007(const std::array<int, 1>& strikeInitialPoint)
{
    return FilteredOrNotFiltered(strikeInitialPoint);
}
// 008 TACAN (TAC)
std::string Dui008(const std::array<int, 1>& tacan)
{
    return FilteredOrNotFiltered(tacan);
}
// 009 TANKER (TKR)
std::string Dui009(const std::array<int, 1>& tanker)
{
    return FilteredOrNotFiltered(tanker);
}
// 010 ORBIT, RACE TRACK (ORB RT)
std::string Dui010(const std::array<int, 1>& orbitRaceTrack)
{
    return FilteredOrNotFiltered(orbitRaceTrack);
}
// 011 ORBIT, FIGURE EIGHT (ORB F8)
std::string Dui011(const std::array<int, 1>& orbitFigureEight)
{
    return FilteredOrNotFiltered(orbitFigureEight);
}
// 012 ORBIT, RANDOM CLOSED (ORB RC)
std::string Dui012(const std::array<int, 1>& orbitRandomClosed)
{
    return FilteredOrNotFiltered(orbitRandomClosed);
}
// 013 ORBIT POINT (ORB PT)
std::string Dui013(const std::array<int, 1>& orbitPoint)
{
    return FilteredOrNotFiltered(orbitPoint);
}
// 014 PT3, AMP13 (PT3 A13)
std::string Dui014(const std::array<int, 1>& pt3Amp13)
{
    return FilteredOrNotFiltered(pt3Amp13);
}
// 015 PT3, AMP14 (PT3 A14)
std::string Dui015(const std::array<int, 1>& pt3Amp14)
{
    return FilteredOrNotFiltered(pt3Amp14);
}
// 016 PT3, AMP15 (PT3 A15)
std::string Dui016(const std::array<int, 1>& pt3Amp15)
{
    return FilteredOrNotFiltered(pt3Amp15);
}
}
