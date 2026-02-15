
#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

/* DFI 3002 DUI 001 ADD/DELETE INDICATOR 1 bit*/
std::string Dui001(std::array<int, 1> addDeleteIndicator)
{
    if (addDeleteIndicator[0] == 1)
    {
        return "Add ///-> 1";
    }
    else
    {
        return "Delete ///-> 0";
    }
}
/* DFI 3002 DUI 002 ACTIVE/INACTIVE FLAG 1 bit*/
std::string Dui002(std::array<int, 1> activeInactiveFlag)
{
    if (activeInactiveFlag[0] == 1)
    {
        return "Active ///-> 1";
    }
    else
    {
        return "Inactive ///-> 0";
    }
}
/* DFI 3002 DUI 003 ACKNOWLEDGEMENT REQUEST FLAG 1 bit*/
std::string Dui003(std::array<int, 1> acknowledgementRequestFlag)
{
    if (acknowledgementRequestFlag[0] == 1)
    {
        return "Acknowledgement requested ///-> 1";
    }
    else
    {
        return "No acknowledgement requested ///-> 0";
    }
}
/* DFI 3002 DUI 004 COMMAND AND CONTROL INDICATOR OVERRIDE*/
std::string Dui004(std::array<int, 1> commandAndControlIndicatorOverride)
{
    if (commandAndControlIndicatorOverride[0] == 1)
    {
        return "filter ///-> 1";
    }
    else
    {
        return "override filter ///-> 0";
    }
}
/* DFI 3002 DUI 005 EMERGENCY INDICATOR OVERRIDE 1 bit*/
std::string Dui005(std::array<int, 1> emergencyIndicatorOverride)
{
    if (emergencyIndicatorOverride[0] == 1)
    {
        return "filter ///-> 1";
    }
    else
    {
        return "override filter ///-> 0";
    }
}
/* DFI 3002 DUI 006 FORCE TELL INDICATOR OVERRIDE 1 bit*/
std::string Dui006(std::array<int, 1> forceTellIndicatorOverride)
{
    if (forceTellIndicatorOverride[0] == 1)
    {
        return "filter ///-> 1";
    }
    else
    {
        return "override filter ///-> 0";
    }
}
/* DFI 3002 DUI 007 LAST POINT FLAG 1 bit 0 no last point 1 Last point*/
std::string Dui007(std::array<int, 1> lastPointFlag)
{
    if (lastPointFlag[0] == 1)
    {
        return "Last point ///-> 1";
    }
    else
    {
        return "No last point ///-> 0";
    }
}
/* DFI 3002 DUI 008 RECTANGLE FLAG 1 bit*/
std::string Dui008(std::array<int, 1> rectangleFlag)
{
    if (rectangleFlag[0] == 1)
    {
        return "Rectangle ///-> 1";
    }
    else
    {
        return "Ellipse ///-> 0";
    }
}
/* DFI 3002 DUI 009 RELAY FLAG 1 bit*/
std::string Dui009(std::array<int, 1> relayFlag)
{
    if (relayFlag[0] == 1)
    {
        return "Relayed Message ///-> 1";
    }
    else
    {
        return "Message Directly Received ///-> 0";
    }
}
/* DFI 3002 DUI 010 SIMULATION INDICATOR FILTER FLAG 1 bit*/
std::string Dui010(std::array<int, 1> simulationIndicatorFilterFlag)
{
    if (simulationIndicatorFilterFlag[0] == 1)
    {
        return "filter simulated Messages///-> 1";
    }
    else
    {
        return "Accept Simulated Messages ///-> 0";
    }
}
/* DFI 3002 DUI 011 TRANSMISSION TIME REFERENCE FLAG 1 bit*/
std::string Dui011(std::array<int, 1> transmissionTimeReferenceFlag)
{
    if (transmissionTimeReferenceFlag[0] == 1)
    {
        return "Within Time Accuracy ///-> 1";
    }
    else
    {
        return "Not within Time Accuracy ///-> 0";
    }
}
/* DFI 3002 DUI 012 UPPER ALTITUDE LIMIT FLAG 1 bit*/
std::string Dui012(std::array<int, 1> upperAltitudeLimitFlag)
{
    if (upperAltitudeLimitFlag[0] == 1)
    {
        return "Upper Altitude Limit ///-> 1";
    }
    else
    {
        return "No Limit ///-> 0";
    }
}
/* DFI 3002 DUI 013 LOWER ALTITUDE LIMIT FLAG 1 bit*/
std::string Dui013(std::array<int, 1> lowerAltitudeLimitFlag)
{
    if (lowerAltitudeLimitFlag[0] == 1)
    {
        return "Lower Altitude Limit ///-> 1";
    }
    else
    {
        return "No Limit ///-> 0";
    }
}
/* DFI 3002 DUI 014 J28.2(0) FILTER FLAG 1 bit*/
std::string Dui014(std::array<int, 1> j2820FilterFlag)
{
    if (j2820FilterFlag[0] == 1)
    {
        return "filter all J28.2(0) Messages ///-> 1";
    }
    else
    {
        return "Accept all J28.2(0) Messages ///-> 0";
    }
}
/* DFI 3002 DUI 015 J28.2(X) FILTER FLAG 1 bit*/
std::string Dui015(std::array<int, 1> j28XFilterFlag)
{
    if (j28XFilterFlag[0] == 1)
    {
        return "filter all J28.2(X) Messages ///-> 1";
    }
    else
    {
        return "Accept all J28.2(X) Messages ///-> 0";
    }
}
/* DFI 3002 DUI 016 SPECIAL PROCESSING INDICATOR FILTER FLAG 1 bit*/
std::string Dui016(std::array<int, 1> specialProcessingIndicatorFilterFlag)
{
    if (specialProcessingIndicatorFilterFlag[0] == 1)
    {
        return "filter SPI Messages ///-> 1";
    }
    else
    {
        return "No Filter ///-> 0";
    }
}
/* DFI 3002 DUI 017 TYPE FILTER 1 bit*/
std::string Dui017(std::array<int, 1> typeFilter)
{
    if (typeFilter[0] == 1)
    {
        return "Request Transmit Filter settings of specified type ///-> 1";
    }
    else
    {
        return "Not Specified ///-> 0";
    }
}
/* DFI 3002 DUI 018 GEOGRAPHIC FILTER 1 bit*/
std::string Dui018(std::array<int, 1> geographicFilter)
{
    if (geographicFilter[0] == 1)
    {
        return "Request Transmit Filter settings of all Geographic Filters ///-> 1";
    }
    else
    {
        return "No Request ///-> 0";
    }
}
/* DFI 3002 DUI 019 ALL FILTERS 1 bit*/
std::string Dui019(std::array<int, 1> allFilters)
{
    if (allFilters[0] == 1)
    {
        return "Request Transmit Filter settings of all Filters ///-> 1";
    }
    else
    {
        return "No Request ///-> 0";
    }
}
/* DFI 3002 DUI 020 ALTERNATE NETWORK CONTROLLER ASSIGNMENT FLAG 1 bit*/
std::string Dui020(std::array<int, 1> alternateNetworkControllerAssignmentFlag)
{
    if (alternateNetworkControllerAssignmentFlag[0] == 1)
    {
        return "Alternate Network Controller Assignment ///-> 1";
    }
    else
    {
        return "No Alternate Network Controller Assignment ///-> 0";
    }
}
/* DFI 3002 DUI 021 ALTERNATE NETWORK CONTROLLER ASSIGNMENT RECOGNITION 1 bit*/
std::string Dui021(std::array<int, 1> alternateNetworkControllerAssignmentRecognition)
{
    if (alternateNetworkControllerAssignmentRecognition[0] == 1)
    {
        return "Alternate Network Controller Assignment Recognized ///-> 1";
    }
    else
    {
        return "Alternate Network Controller Assignment Not Recognized ///-> 0";
    }
}
