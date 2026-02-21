#include "dfiset3081.h"

namespace dfi3081 {
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

std::string Dui003(const std::array<int, 1>& j3_2_air_1)
{
    return FilteredOrNotFiltered(j3_2_air_1);
}

std::string Dui004(const std::array<int, 1>& j3_3_surface_1)
{
    return FilteredOrNotFiltered(j3_3_surface_1);
}

std::string Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_1)
{
    return FilteredOrNotFiltered(j3_4_and_j5_4_subsurface_1);
}

std::string Dui006(const std::array<int, 1>& j3_5_land_ground_1)
{
    return FilteredOrNotFiltered(j3_5_land_ground_1);
}

std::string Dui007(const std::array<int, 1>& j3_6_space_1)
{
    return FilteredOrNotFiltered(j3_6_space_1);
}

std::string Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_1)
{
    return FilteredOrNotFiltered(j3_7_and_j14_0_ew_product_information_1);
}
}
