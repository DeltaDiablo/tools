#include "dfiset3111.h"

namespace dfi3111 {
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

std::string Dui001(const std::array<int, 1>& sublabel_0_11)
{
    return FilteredOrNotFiltered(sublabel_0_11);
}

std::string Dui002(const std::array<int, 1>& sublabel_1_11)
{
    return FilteredOrNotFiltered(sublabel_1_11);
}

std::string Dui003(const std::array<int, 1>& sublabel_2_11)
{
    return FilteredOrNotFiltered(sublabel_2_11);
}

std::string Dui004(const std::array<int, 1>& sublabel_3_11)
{
    return FilteredOrNotFiltered(sublabel_3_11);
}

std::string Dui005(const std::array<int, 1>& sublabel_4_11)
{
    return FilteredOrNotFiltered(sublabel_4_11);
}

std::string Dui006(const std::array<int, 1>& sublabel_5_11)
{
    return FilteredOrNotFiltered(sublabel_5_11);
}

std::string Dui007(const std::array<int, 1>& sublabel_6_11)
{
    return FilteredOrNotFiltered(sublabel_6_11);
}

std::string Dui008(const std::array<int, 1>& sublabel_7_11)
{
    return FilteredOrNotFiltered(sublabel_7_11);
}
}
