#include <array>
#include <string>

namespace dfi3054 {
//repeated code for 3054
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
//end repeated code for 3054

// 001 NO STATEMENT                                    [1 BIT]  (NS)
std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
// 002 FORWARD EDGE OF THE BATTLE AREA (FEBA)         [1 BIT]  (FEBA)
std::string Dui002(const std::array<int, 1>& forwardEdgeOfTheBattleArea)
{
    return FilteredOrNotFiltered(forwardEdgeOfTheBattleArea);
}
// 003 GUN TARGET LINE                                 [1 BIT]  (GTL)
std::string Dui003(const std::array<int, 1>& gunTargetLine)
{
    return FilteredOrNotFiltered(gunTargetLine);
}
// 004 CORRIDOR                                        [1 BIT]  (CORRDR)
std::string Dui004(const std::array<int, 1>& corridor)
{
    return FilteredOrNotFiltered(corridor);
}
// 005 HOSTILE BOUNDARY                                [1 BIT]  (HOS BND)
std::string Dui005(const std::array<int, 1>& hostileBoundary)
{
    return FilteredOrNotFiltered(hostileBoundary);
}
// 006 BUFFER ZONE BOUNDARY                            [1 BIT]  (BZ BND)
std::string Dui006(const std::array<int, 1>& bufferZoneBoundary)
{
    return FilteredOrNotFiltered(bufferZoneBoundary);
}
// 007 LOW LEVEL TRANSIT ROUTE                         [1 BIT]  (LLTR)
std::string Dui007(const std::array<int, 1>& lowLevelTransitRoute)
{
    return FilteredOrNotFiltered(lowLevelTransitRoute);
}
// 008 TACTICAL ACTION LINE                            [1 BIT]  (TAL)
std::string Dui008(const std::array<int, 1>& tacticalActionLine)
{
    return FilteredOrNotFiltered(tacticalActionLine);
}
// 009 FIRE SUPPORT COORDINATION LINE (FSCL)           [1 BIT]  (FSCL)
std::string Dui009(const std::array<int, 1>& fireSupportCoordinationLine)
{
    return FilteredOrNotFiltered(fireSupportCoordinationLine);
}
// 010 FORWARD LINE OF OWN TROOPS (FLOT)               [1 BIT]  (FLOT)
std::string Dui010(const std::array<int, 1>& forwardLineOfOwnTroops)
{
    return FilteredOrNotFiltered(forwardLineOfOwnTroops);
}
// 011 PT4, AMP10                                      [1 BIT]  (PT4 A10)
std::string Dui011(const std::array<int, 1>& pt4Amp10)
{
    return FilteredOrNotFiltered(pt4Amp10);
}
// 012 PT4, AMP11                                      [1 BIT]  (PT4 A11)
std::string Dui012(const std::array<int, 1>& pt4Amp11)
{
    return FilteredOrNotFiltered(pt4Amp11);
}
// 013 PT4, AMP12                                      [1 BIT]  (PT4 A12)
std::string Dui013(const std::array<int, 1>& pt4Amp12)
{
    return FilteredOrNotFiltered(pt4Amp12);
}
// 014 PT4, AMP13                                      [1 BIT]  (PT4 A13)
std::string Dui014(const std::array<int, 1>& pt4Amp13)
{
    return FilteredOrNotFiltered(pt4Amp13);
}
// 015 PT4, AMP14                                      [1 BIT]  (PT4 A14)
std::string Dui015(const std::array<int, 1>& pt4Amp14)
{
    return FilteredOrNotFiltered(pt4Amp14);
}
// 016 PT4, AMP15                                      [1 BIT]  (PT4 A15)
std::string Dui016(const std::array<int, 1>& pt4Amp15)
{
    return FilteredOrNotFiltered(pt4Amp15);
}
}
