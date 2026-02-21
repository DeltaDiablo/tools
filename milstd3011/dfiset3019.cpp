#include <string>
#include <array>

namespace dfi3019 {
std::string Dui001(const std::array<int, 1>& connectivityMatrixBit)
{
    if(connectivityMatrixBit[0] == 0)
    {
        return "No data flow ///-> 0";
    }
    else
    {
        return "Data flow ///-> 1";
    }

}
}
