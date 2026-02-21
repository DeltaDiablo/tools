#include "dfiset3087.h"

namespace dfi3087 {
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

std::string Dui001(const std::array<int, 1>& undefined)
{
    return FilteredOrNotFiltered(undefined);
}

std::string Dui002(const std::array<int, 1>& undefined_2)
{
    return FilteredOrNotFiltered(undefined_2);
}

std::string Dui003(const std::array<int, 1>& j2_2_and_j2_0_air)
{
    return FilteredOrNotFiltered(j2_2_and_j2_0_air);
}

std::string Dui004(const std::array<int, 1>& j2_3_and_j2_0_surface)
{
    return FilteredOrNotFiltered(j2_3_and_j2_0_surface);
}

std::string Dui005(const std::array<int, 1>& j2_4_and_j2_0_subsurface)
{
    return FilteredOrNotFiltered(j2_4_and_j2_0_subsurface);
}

std::string Dui006(const std::array<int, 1>& j2_5_j2_6_and_j2_0_land)
{
    return FilteredOrNotFiltered(j2_5_j2_6_and_j2_0_land);
}

std::string Dui007(const std::array<int, 1>& undefined_3)
{
    return FilteredOrNotFiltered(undefined_3);
}

std::string Dui008(const std::array<int, 1>& undefined_4)
{
    return FilteredOrNotFiltered(undefined_4);
}
}
