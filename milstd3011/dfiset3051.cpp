#include <array>
#include <string>

namespace dfi3051 {
std::string FilteredOrNotFiltered(const std::array<int, 1>& inputArray)
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

std::string Dui001(const std::array<int, 1>& noStatement)
{
    return FilteredOrNotFiltered(noStatement);
}

std::string Dui002(const std::array<int, 1>& marshallPoint)
{
    return FilteredOrNotFiltered(marshallPoint);
}

std::string Dui003(const std::array<int, 1>& waypoint)
{
    return FilteredOrNotFiltered(waypoint);
}

std::string Dui004(const std::array<int, 1>& corridorTab)
{
    return FilteredOrNotFiltered(corridorTab);
}

std::string Dui005(const std::array<int, 1>& positionIntendedMovement)
{
    return FilteredOrNotFiltered(positionIntendedMovement);
}

std::string Dui006(const std::array<int, 1>& dispositionCenter)
{
    return FilteredOrNotFiltered(dispositionCenter);
}

std::string Dui007(const std::array<int, 1>& formationCenter)
{
    return FilteredOrNotFiltered(formationCenter);
}

std::string Dui008(const std::array<int, 1>& searchArea)
{
    return FilteredOrNotFiltered(searchArea);
}

std::string Dui009(const std::array<int, 1>& victorLima)
{
    return FilteredOrNotFiltered(victorLima);
}

std::string Dui010(const std::array<int, 1>& submarinePositionIntendedMovement)
{
    return FilteredOrNotFiltered(submarinePositionIntendedMovement);
}

std::string Dui011(const std::array<int, 1>& pt1Amp10)
{
    return FilteredOrNotFiltered(pt1Amp10);
}

std::string Dui012(const std::array<int, 1>& defendedAsset)
{
    return FilteredOrNotFiltered(defendedAsset);
}

std::string Dui013(const std::array<int, 1>& pt1Amp12)
{
    return FilteredOrNotFiltered(pt1Amp12);
}

std::string Dui014(const std::array<int, 1>& pt1Amp13)
{
    return FilteredOrNotFiltered(pt1Amp13);
}

std::string Dui015(const std::array<int, 1>& pt1Amp14)
{
    return FilteredOrNotFiltered(pt1Amp14);
}

std::string Dui016(const std::array<int, 1>& pt1Amp15)
{
    return FilteredOrNotFiltered(pt1Amp15);
}
}
