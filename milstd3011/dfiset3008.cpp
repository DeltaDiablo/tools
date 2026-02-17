#include <array>
#include <string>
#include <cmath>

//repeated functions for DFI 3008
std::string MsgFilterTypeReqested(const std::array<int, 8>& requestedFilterMessageType)
{
    std::string resp = "";
    for (std::size_t i = 0; i < requestedFilterMessageType.size(); i++)
    {
        resp.append(std::to_string(requestedFilterMessageType[i]));
    }
    int filterMessageTypeInt = 0;
    for (int i = 0; i < 8; i++)
    {
        filterMessageTypeInt += requestedFilterMessageType[i] * std::pow(2, 7 - i);
    }
    std::string output = "";
    switch (filterMessageTypeInt)
    {
    case 0:
        output = "All Filter Types ///-> 00000000";
        break;
    case 1:
        output = "Filter Settings Summary ///-> 00000001";
        break;
    case 2:
        output = "Category Identity Filter///-> 00000010";
        break;
    case 3:
        output = "Label/SubLabel Filter ///-> 00000011";
        break;
    case 4:
        output = "Point Type/Point Amplification Filter ///-> 00000100";
        break;
    case 5:
        output = "Ellipse-Rectangle GraphicFilter ///-> 00000101";
        break;
    case 6:
        output = "CClosed Polygon Geographic Filter ///-> 00000110";
        break;
    case 7:
        output = "Source Track Number Filter ///-> 00000111";
        break;
    case 8:
        output = "Special Processing Indicator Filter ///-> 00001000";
        break;
    case 9:
        output = "J28.2(X) FILTER Filter ///-> 00001001";
        break;
    case 10:
        output = "Data Age Filter ///-> 00001010";
        break;
    case 11:
        output = "Simulator Filter ///-> 00001011";
        break;
    case 12:
        output = "J3.6 Rocket Filter///-> 00001100";
        break;
    case 13:
        output = "National use sublabel Filter ///-> 00001101";
        break;
    case 14:
        output = "Network Participation Group Filter ///-> 00001110";
        break;
    default:
        output = "Undefined ///-> " + resp;
        break;
    }
    return output;
}
//end of repeated functions for DFI 3008

/* DFI 3008 DUI 001 MESSAGE TYPE 4 bits*/
std::string Dui001(std::array<int, 4> messageType)
{
    int messageTypeInt = 0;
    for (int i = 0; i < 4; i++)
    {
        messageTypeInt += messageType[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    switch (messageTypeInt)
    {
    case 0:
        output = "Management Message ///-> 0000";
        break;
    case 1:
        output = "JREAP J-SERIES ///-> 0001";
        break;
    case 2:
        output = "JTIDS/MIDS JREAP FREE TEXT (CODED) ///-> 0010";
        break;
    case 3:
        output = "JTIDS/MIDS JREAP FREE TEXT (UNCODED) ///-> 0011";
        break;
    case 4:
        output = "VMF ///-> 0100";
        break;
    case 5:
        output = "LINK 22 ///-> 0101";
        break;
    case 6:
        output = "CMF IBS ///-> 0110";
        break;
    case 7:
        output = "JREAP J SERIES WITH NPG ASSIGHMENT ///-> 0111";
        break;
    case 8:
        output = "Undefined ///-> 1000";
        break;
    case 9:
        output = "Undefined ///-> 1001";
        break;
    case 10:
        output = "Undefined ///-> 1010";
        break;
    case 11:
        output = "Undefined ///-> 1011";
        break;
    case 12:
        output = "Undefined ///-> 1100";
        break;
    case 13:
        output = "Undefined ///-> 1101";
        break;
    case 14:
        output = "Undefined ///-> 1110";
        break;
    case 15:
        output = "Reserved ///-> 1111";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}

/* DFI 3008 DUI 002 MANAGEMENT MESSAGE SUBTYPE 8 bits*/
std::string Dui002(const std::array<int, 8>& managementMessageSubtype)
{
    std::string resp = "";
    for (std::size_t i = 0; i < managementMessageSubtype.size(); i++)
    {
        resp.append(std::to_string(managementMessageSubtype[i]));
    }
    int managementMessageSubtypeInt = 0;
    for (int i = 0; i < 8; i++)
    {
        managementMessageSubtypeInt += managementMessageSubtype[i] * std::pow(2, 7 - i);
    }
    std::string output = "";
    switch (managementMessageSubtypeInt)
    {
    case 0:
        output = "Echo ///-> 00000000";
        break;
    case 1:
        output = "Common Time Reference ///-> 00000001";
        break;
    case 2:
        output = "ROUND-TRIP TIME DELAY ///-> 00000010";
        break;
    case 3:
        output = "JREAP J-SERIES ACK (Full Stack) ///-> 00000011";
        break;
    case 4:
        output = "JREAP J-SERIES ACK (Application Layer) ///-> 00000100";
        break;
    case 5:
        output = "Latency Threshhold ///-> 00000101";
        break;
    case 6:
        output = "Latency Exceeded ///-> 00000110";
        break;
    case 7:
        output = "Operator to Operator ///-> 00000111";
        break;
    case 8:
        output = "Special Event ///-> 00001000";
        break;
    case 9:
        output = "Terminate Link ///-> 00001001";
        break;
    case 10:
        output = "Remote Filter///-> 00001010";
        break;
    case 11:
        output = "Secondary Track Number List ///-> 00001011";
        break;
    case 12:
        output = "Direct Connection List ///-> 00001100";
        break;
    case 13:
        output = "Network Connectivity Matrix ///-> 00001101";
        break;
    case 14:
        output = "Connectivity Feedback ///-> 00001110";
        break;
    case 15 ... 199:
        output = "Undefined ///-> " + resp;
        break;
    case 200 ... 209:
        output = "Reserved for USA prototyping efforts ///-> " + resp;
        break;
    case 210 ... 219:
        output = "Reserved for USAF prototyping efforts ///-> " + resp;
        break;
    case 220 ... 229:
        output = "Reserved for USMC prototyping efforts ///-> " + resp;
        break;
    case 230 ... 239:
        output = "Reserved for USN prototyping efforts ///-> " + resp;
        break;
    case 240 ... 249:
         output = "Reserved for MDA prototyping efforts ///-> " + resp;
        break;
    case 250 ... 254:
         output = "undefined ///-> " + resp;
        break;
    default:
        output = "Reserved for Expansion ///-> ";
        break;
    }
    return output;
}

/* DFI 3008 DUI 003 FILTER MESSAGE TYPE 8 bits*/
std::string Dui003(const std::array<int, 8>& filterMessageType)
{
    return MsgFilterTypeReqested(filterMessageType);
}

/* DFI 3008 DUI 004 REQUESTED FILTER MESSAGE TYPE 8 bits*/
std::string Dui004(const std::array<int, 8>& requestedFilterMessageType)
{
    return MsgFilterTypeReqested(requestedFilterMessageType);
}