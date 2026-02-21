#include <array>
#include <string>
#include<cmath>

namespace dfi3038 {
//repeated function for Dfi 3038
//end of repeated functions

/* DFI 3038 DUI 001 SUBLABEL, J-SERIES*/
std::string Dui001(const std::array<int, 3>& sublabelJSeries)
{
    int sublabelValue = 0;
    for (size_t i = 0; i < sublabelJSeries.size(); ++i) {
        sublabelValue += sublabelJSeries[i] * static_cast<int>(std::pow(2, 2 - i));
    }
    return "SUBLABEL, J-SERIES ///-> " + std::to_string(sublabelValue);
}
}
