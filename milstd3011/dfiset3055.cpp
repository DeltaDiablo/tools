#include <array>
#include <string>

namespace dfi3055 {
//repeated code for 3055
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
//end repeated code for 3055

/* DFI 3055 DUI 001 NO STATEMENT*/
std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
/* DFI 3055 DUI 002 SEARCH*/
std::string Dui002(const std::array<int, 1>& search)
{
    return FilteredOrNotFiltered(search);
}
/* DFI 3055 DUI 003 RESTRICTED*/
std::string Dui003(const std::array<int, 1>& restricted)
{
    return FilteredOrNotFiltered(restricted);
}
/* DFI 3055 DUI 004 EXERCISE*/
std::string Dui004(const std::array<int, 1>& exercise)
{
    return FilteredOrNotFiltered(exercise);
}
/* DFI 3055 DUI 005 SUBMARINE PATROL AREA*/
std::string Dui005(const std::array<int, 1>& submarinePatrolArea)
{
    return FilteredOrNotFiltered(submarinePatrolArea);
}
/* DFI 3055 DUI 006 FIGHTER ENGAGEMENT ZONE*/
std::string Dui006(const std::array<int, 1>& fighterEngagementZone)
{
    return FilteredOrNotFiltered(fighterEngagementZone);
}
/* DFI 3055 DUI 007 GROUND AREA OF RESPONSIBILITY*/
std::string Dui007(const std::array<int, 1>& groundAreaOfResponsibility)
{
    return FilteredOrNotFiltered(groundAreaOfResponsibility);
}
/* DFI 3055 DUI 008 DEFENDED AREA*/
std::string Dui008(const std::array<int, 1>& defendedArea)
{
    return FilteredOrNotFiltered(defendedArea);
}
/* DFI 3055 DUI 009 PT5, AMP8*/
std::string Dui009(const std::array<int, 1>& pt5Amp8)
{
    return FilteredOrNotFiltered(pt5Amp8);
}
/* DFI 3055 DUI 010 PT5, AMP9*/
std::string Dui010(const std::array<int, 1>& pt5Amp9)
{
    return FilteredOrNotFiltered(pt5Amp9);
}
/* DFI 3055 DUI 011 PT5, AMP10*/
std::string Dui011(const std::array<int, 1>& pt5Amp10)
{
    return FilteredOrNotFiltered(pt5Amp10);
}
/* DFI 3055 DUI 012 PT5, AMP11*/
std::string Dui012(const std::array<int, 1>& pt5Amp11)
{
    return FilteredOrNotFiltered(pt5Amp11);
}
/* DFI 3055 DUI 013 PT5, AMP12*/
std::string Dui013(const std::array<int, 1>& pt5Amp12)  
{
    return FilteredOrNotFiltered(pt5Amp12);
}
/* DFI 3055 DUI 014 PT5, AMP13*/
std::string Dui014(const std::array<int, 1>& pt5Amp13)
{
    return FilteredOrNotFiltered(pt5Amp13);
}
/* DFI 3055 DUI 015 PT5, AMP14*/
std::string Dui015(const std::array<int, 1>& pt5Amp14)
{
    return FilteredOrNotFiltered(pt5Amp14);
}
/* DFI 3055 DUI 016 PT5, AMP15*/
std::string Dui016(const std::array<int, 1>& pt5Amp15)  
{
    return FilteredOrNotFiltered(pt5Amp15);
}
}
