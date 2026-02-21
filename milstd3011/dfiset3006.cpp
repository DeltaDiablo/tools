
#include <iostream>
#include <array>
#include <cmath>
#include <string>

namespace dfi3006 {
/* DFI 3006 DUI 001 ACKNOWLEDGEMENT PROTOCOL, 1 4 bits*/
std::string Dui001(const std::array<int, 4>& acknowledgementProtocol1)
{
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol1[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1 ... 2:
        output = "Illegal ///-> 0001 through 0010";
        break;
    default:
        output = "Undefined ///-> 0011 through 1111";
        break;
    }
    return output;
}

/* DFI 3006 DUI 002 ACKNOWLEDGEMENT PROTOCOL, 2 4 bits*/
std::string Dui002(const std::array<int, 4>& acknowledgementProtocol2)
{
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol2[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1:
        output = "Processor Ack ///-> 0001";
        break;
    case 2:
        output = "Illegal ///-> 0010";
        break;
    case 3 ... 15:
        output = "undefined ///-> 0011 through 1111";
        break;
    default:
        output = "Undefined ///-> 0000 through 1111 not set";
        break;
    }
    return output;
}

/* DFI 3006 DUI 003 ACKNOWLEDGEMENT PROTOCOL, 3 4 bits*/
std::string Dui003(const std::array<int, 4>& acknowledgementProtocol3)
{
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol3[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1:
        output = "Processor Ack ///-> 0001";
        break;
    case 2:
        output = "Operator Ack ///-> 0010";
        break;
    case 3 ... 15:
        output = "Illegal ///-> 0011 through 1111";
        break;
    default:
        output = "Undefined ///-> 0000 through 1111 not set";
        break;
    }
    return output;
}

/* DFI 3006 DUI 004 ACKNOWLEDGEMENT PROTOCOL, 4 4 bits*/
std::string Dui004(const std::array<int, 4>& acknowledgementProtocol4)
{
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol4[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Illegal ///-> 0000";
        break;
    case 1:
        output = "Processor Ack ///-> 0001";
        break;
    case 2:
        output = "Illegal ///-> 0010";
        break;
    case 3 ... 15:
        output = "Undefined ///-> 0011 through 1111";
    default:
        output = "Undefined ///-> 0000 through 1111 not set";
        break;
    }
    return output;
}

/* DFI 3006 DUI 005 ACKNOWLEDGEMENT PROTOCOL, 5 4 bits*/
std::string Dui005(const std::array<int, 4>& acknowledgementProtocol5)
{
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol5[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1:
        output = "Processor Ack ///-> 0001";
        break;
    case 2:
        output = "Operator Ack ///-> 0010";
        break;
    case 3 ... 15:
        output = "undefined ///-> 0011 through 1111";
    default:
        output = "Undefined ///-> 0000 through 1111 not set";
        break;
    }

    return output;
}
}
