#include "dfiset3060.h"

namespace dfi3060 {
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

std::string Dui001(const std::array<int, 1>& disused)
{
    return FilteredOrNotFiltered(disused);
}

std::string Dui002(const std::array<int, 1>& disused_2)
{
    return FilteredOrNotFiltered(disused_2);
}

std::string Dui003(const std::array<int, 1>& filter_rocket_di_1)
{
    return FilteredOrNotFiltered(filter_rocket_di_1);
}
}
