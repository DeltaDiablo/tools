#include "dfiset3063.h"

namespace dfi3063 {
namespace {
std::string FilteredOrNotFiltered(const std::array<int, 1>& inputArray)
{
    if (inputArray[0] == 0)
    {
        return "Not Filtered ///-> 0";
    }
    if (inputArray[0] == 1)
    {
        return "Filtered ///-> 1";
    }
    return "Invalid input, must be 0 or 1";
}
}

std::string Dui001(const std::array<int, 1>& pt12_amp0)
{
    return FilteredOrNotFiltered(pt12_amp0);
}

std::string Dui002(const std::array<int, 1>& pt12_amp1)
{
    return FilteredOrNotFiltered(pt12_amp1);
}

std::string Dui003(const std::array<int, 1>& pt12_amp2)
{
    return FilteredOrNotFiltered(pt12_amp2);
}

std::string Dui004(const std::array<int, 1>& pt12_amp3)
{
    return FilteredOrNotFiltered(pt12_amp3);
}

std::string Dui005(const std::array<int, 1>& pt12_amp4)
{
    return FilteredOrNotFiltered(pt12_amp4);
}

std::string Dui006(const std::array<int, 1>& pt12_amp5)
{
    return FilteredOrNotFiltered(pt12_amp5);
}

std::string Dui007(const std::array<int, 1>& pt12_amp6)
{
    return FilteredOrNotFiltered(pt12_amp6);
}

std::string Dui008(const std::array<int, 1>& pt12_amp7)
{
    return FilteredOrNotFiltered(pt12_amp7);
}

std::string Dui009(const std::array<int, 1>& pt12_amp8)
{
    return FilteredOrNotFiltered(pt12_amp8);
}

std::string Dui010(const std::array<int, 1>& pt12_amp9)
{
    return FilteredOrNotFiltered(pt12_amp9);
}

std::string Dui011(const std::array<int, 1>& pt12_amp10)
{
    return FilteredOrNotFiltered(pt12_amp10);
}

std::string Dui012(const std::array<int, 1>& pt12_amp11)
{
    return FilteredOrNotFiltered(pt12_amp11);
}

std::string Dui013(const std::array<int, 1>& pt12_amp12)
{
    return FilteredOrNotFiltered(pt12_amp12);
}

std::string Dui014(const std::array<int, 1>& pt12_amp13)
{
    return FilteredOrNotFiltered(pt12_amp13);
}

std::string Dui015(const std::array<int, 1>& pt12_amp14)
{
    return FilteredOrNotFiltered(pt12_amp14);
}

std::string Dui016(const std::array<int, 1>& pt12_amp15)
{
    return FilteredOrNotFiltered(pt12_amp15);
}
}
