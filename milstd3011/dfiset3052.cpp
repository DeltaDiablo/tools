#include <array>
#include <string>

namespace dfi3052 {
//repreated code for 3052
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



// 001 NO STATEMENT
std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}
// 002 TOMCAT
std::string Dui002(const std::array<int, 1>& tomcat)
{
    return FilteredOrNotFiltered(tomcat);
}
// 003 PICKET
std::string Dui003(const std::array<int, 1>& picket)
{
    return FilteredOrNotFiltered(picket);
}
// 004 RENDEZVOUS
std::string Dui004(const std::array<int, 1>& rendezvous)
{
    return FilteredOrNotFiltered(rendezvous);
}
// 005 PT2, AMP4
std::string Dui005(const std::array<int, 1>& pt2Amp4)
{
    return FilteredOrNotFiltered(pt2Amp4);
}
// 006 REPLENISHMENT
std::string Dui006(const std::array<int, 1>& replenishment)
{
    return FilteredOrNotFiltered(replenishment);
}
// 007 RESCUE
std::string Dui007(const std::array<int, 1>& rescue)
{
    return FilteredOrNotFiltered(rescue);
}
// 008 PT2, AMP7
std::string Dui008(const std::array<int, 1>& pt2Amp7)
{
    return FilteredOrNotFiltered(pt2Amp7);
}
// 009 PT2, AMP8
std::string Dui009(const std::array<int, 1>& pt2Amp8)
{
    return FilteredOrNotFiltered(pt2Amp8);
}
// 010 PT2, AMP9
std::string Dui010(const std::array<int, 1>& pt2Amp9)
{
    return FilteredOrNotFiltered(pt2Amp9);
}
// 011 PT2, AMP10
std::string Dui011(const std::array<int, 1>& pt2Amp10)
{
    return FilteredOrNotFiltered(pt2Amp10);
}
// 012 PT2, AMP11
std::string Dui012(const std::array<int, 1>& pt2Amp11)
{
    return FilteredOrNotFiltered(pt2Amp11);
}
// 013 PT2, AMP12
std::string Dui013(const std::array<int, 1>& pt2Amp12)
{
    return FilteredOrNotFiltered(pt2Amp12);
}
// 014 PT2, AMP13
std::string Dui014(const std::array<int, 1>& pt2Amp13)
{
    return FilteredOrNotFiltered(pt2Amp13);
}
// 015 PT2, AMP14
std::string Dui015(const std::array<int, 1>& pt2Amp14)
{
    return FilteredOrNotFiltered(pt2Amp14);
}
// 016 PT2, AMP15
std::string Dui016(const std::array<int, 1>& pt2Amp15)
{
    return FilteredOrNotFiltered(pt2Amp15);
}
}
