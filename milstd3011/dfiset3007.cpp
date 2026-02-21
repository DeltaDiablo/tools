#include <iostream>
#include <array>
#include <cmath>
#include <string>

namespace dfi3007 {
/* DFI 3007 DUI 001 TRANSMISSION BLOCK HEADER TYPE 4 bits*/
std::string Dui001(const std::array<int, 4>& transmissionBlockHeaderType)
{
    int transmissionBlockHeaderTypeInt = 0;
    for (int i = 0; i < 4; i++)
    {
        transmissionBlockHeaderTypeInt += transmissionBlockHeaderType[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    switch (transmissionBlockHeaderTypeInt)
    {
    case 0:
        output = "Undefined ///-> 0000";
        break;
    case 1:
        output = "JREAP-A ///-> 0001";
        break;
    case 2:
        output = "JREAP-B ///-> 0010";
        break;
    case 3:
        output = "JREAP-C ///-> 0011";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3007 DUI 002 MESSAGE GROUP HEADER TYPE 2 bits*/
std::string Dui002(const std::array<int, 2>& messageGroupHeaderType)
{
    int messageGroupHeaderTypeInt = 0;
    for (int i = 0; i < 2; i++)
    {
        messageGroupHeaderTypeInt += messageGroupHeaderType[i] * std::pow(2, 1 - i);
    }
    std::string output = "";
    switch (messageGroupHeaderTypeInt)
    {
    case 0:
        output = "Reserved ///-> 00";
        break;
    case 1:
        output = "Reserved ///-> 01";
        break;
    case 2:
        output = "Reserved ///-> 10";
        break;
    case 3:
        output = "Full Stack Message Group Header ///-> 11";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3007 DUI 003 HEADER TYPE 4 bits*/
std::string Dui003(const std::array<int, 4>& headerType)
{
    int headerTypeInt = 0;
    for (int i = 0; i < 4; i++)
    {
        headerTypeInt += headerType[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    switch (headerTypeInt)
    {
    case 0:
        output = "Undefined ///-> 0000";
        break;
    case 1:
        output = "Announced Token Passing ///-> 0001";
        break;
    case 2:
        output = "Point To Point///-> 0010";
        break;
    case 3:
        output = "Application Layer ///-> 0011";
        break;
    default:
        output = "Reserved ///-> ";
        break;
    }
    return output;
}
}
