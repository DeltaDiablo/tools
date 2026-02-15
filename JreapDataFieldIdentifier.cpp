// this is the dfi (data Field Identifier) converter for MILSTD 3011D
//  This library contains all the DFIs and the related DataUseIdentifiers (DUIs) for the JREAP-C fields.

#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include "milstd3011/dfiset3000.cpp"
#include "milstd3011/dfiset3001.cpp"
#include "milstd3011/dfiset3002.cpp"
#include "milstd3011/dfiset3003.cpp"
#include "milstd3011/dfiset3004.cpp"

/* DFI 3000 DUI 001 PERCENT EXCEEDING LATENCY 7 bits*/
std::string dfi3000dui001(std::array<int, 7> percentExceedingLatency)
{   return dui001(percentExceedingLatency);
}
/* DFI 3001 DUI 001 TRANSMISSION SEQUENCE NUMBER 8 bits*/
std::string dfi3001dui001(std::array<int, 7> transmissionSequenceNumber)
{
       return dui001(transmissionSequenceNumber);
}
/* DFI 3001 DUI 002 TRANSMISSION SEQUENCE LIST COUNT 7 bits*/
std::string dfi3001dui002(std::array<int, 7> transmissionSequenceListCount)
{
    return dui002(transmissionSequenceListCount);
}
/* DFI 3002 DUI 001 ADD/DELETE INDICATOR 1 bit*/
std::string dfi3002dui001(std::array<int, 1> addDeleteIndicator)
{    //use the dfiset3002 Dui001 function to process the addDeleteIndicator array and return the output
    return Dui001(addDeleteIndicator);
}
/* DFI 3002 DUI 002 ACTIVE/INACTIVE FLAG 1 bit*/
std::string dfi3002dui002(std::array<int, 1> activeInactiveFlag)
{
    //use the dfiset3002 Dui002 function to process the activeInactiveFlag array and return the output
    return Dui002(activeInactiveFlag);
}
/* DFI 3002 DUI 003 ACKNOWLEDGEMENT REQUEST FLAG 1 bit*/
std::string dfi3002dui003(std::array<int, 1> acknowledgementRequestFlag)
{
    //use the dfiset3002 Dui003 function to process the acknowledgementRequestFlag array and return the output
    return Dui003(acknowledgementRequestFlag);
}
/* DFI 3002 DUI 004 COMMAND AND CONTROL INDICATOR OVERRIDE*/
std::string dfi3002dui004(std::array<int, 1> commandAndControlIndicatorOverride)
{
    //use the dfiset3002 Dui004 function to process the commandAndControlIndicatorOverride array and return the output
    return Dui004(commandAndControlIndicatorOverride);
}
/* DFI 3002 DUI 005 EMERGENCY INDICATOR OVERRIDE 1 bit*/
std::string dfi3002dui005(std::array<int, 1> emergencyIndicatorOverride)
{
    //use the dfiset3002 Dui005 function to process the emergencyIndicatorOverride array and return the output
    return Dui005(emergencyIndicatorOverride);
}
/* DFI 3002 DUI 006 FORCE TELL INDICATOR OVERRIDE 1 bit*/
std::string dfi3002dui006(std::array<int, 1> forceTellIndicatorOverride)
{
    //use the dfiset3002 Dui006 function to process the forceTellIndicatorOverride array and return the output
    return Dui006(forceTellIndicatorOverride);
}
/* DFI 3002 DUI 007 LAST POINT FLAG 1 bit 0 no last point 1 Last point*/
std::string dfi3002dui007(std::array<int, 1> lastPointFlag)
{
    //use the dfiset3002 Dui007 function to process the lastPointFlag array and return the output
    return Dui007(lastPointFlag);
}
/* DFI 3002 DUI 008 RECTANGLE FLAG 1 bit*/
std::string dfi3002dui008(std::array<int, 1> rectangleFlag)
{
    //use the dfiset3002 Dui008 function to process the rectangleFlag array and return the output
    return Dui008(rectangleFlag);
}
/* DFI 3002 DUI 009 RELAY FLAG 1 bit*/
std::string dfi3002dui009(std::array<int, 1> relayFlag)
{
    //use the dfiset3002 Dui009 function to process the relayFlag array and return the output
    return Dui009(relayFlag);
}
/* DFI 3002 DUI 010 SIMULATION INDICATOR FILTER FLAG 1 bit*/
std::string dfi3002dui010(std::array<int, 1> simulationIndicatorFilterFlag)
{
    //use the dfiset3002 Dui010 function to process the simulationIndicatorFilterFlag array and return the output
    return Dui010(simulationIndicatorFilterFlag);
}
/* DFI 3002 DUI 011 TRANSMISSION TIME REFERENCE FLAG 1 bit*/
std::string dfi3002dui011(std::array<int, 1> transmissionTimeReferenceFlag)
{
    //use the dfiset3002 Dui011 function to process the transmissionTimeReferenceFlag array and return the output
    return Dui011(transmissionTimeReferenceFlag);
}
/* DFI 3002 DUI 012 UPPER ALTITUDE LIMIT FLAG 1 bit*/
std::string dfi3002dui012(std::array<int, 1> upperAltitudeLimitFlag)
{
    //use the dfiset3002 Dui012 function to process the upperAltitudeLimitFlag array and return the output
    return Dui012(upperAltitudeLimitFlag);
}
/* DFI 3002 DUI 013 LOWER ALTITUDE LIMIT FLAG 1 bit*/
std::string dfi3002dui013(std::array<int, 1> lowerAltitudeLimitFlag)
{
    //use the dfiset3002 Dui013 function to process the lowerAltitudeLimitFlag array and return the output
    return Dui013(lowerAltitudeLimitFlag);
}
/* DFI 3002 DUI 014 J28.2(0) FILTER FLAG 1 bit*/
std::string dfi3002dui014(std::array<int, 1> j2820FilterFlag)
{
    //use the dfiset3002 Dui014 function to process the j2820FilterFlag array and return the output
    return Dui014(j2820FilterFlag);
}
/* DFI 3002 DUI 015 J28.2(X) FILTER FLAG 1 bit*/
std::string dfi3002dui015(std::array<int, 1> j28XFilterFlag)
{
    //use the dfiset3002 Dui015 function to process the j28XFilterFlag array and return the output
    return Dui015(j28XFilterFlag);
}
/* DFI 3002 DUI 015 J28.2(X) FILTER FLAG 1 bit*/
std::string dfi3002dui015(std::array<int, 1> j28XFilterFlag)
{
    //use the dfiset3002 Dui015 function to process the j28XFilterFlag array and return the output
        return "Accept all J28.2(X) Messages ///-> 0";
}
/* DFI 3002 DUI 016 SPECIAL PROCESSING INDICATOR FILTER FLAG 1 bit*/
std::string dfi3002dui016(std::array<int, 1> specialProcessingIndicatorFilterFlag)
{
    //use the dfiset3002 Dui016 function to process the specialProcessingIndicatorFilterFlag array and return the output
    return Dui016(specialProcessingIndicatorFilterFlag);
}
/* DFI 3002 DUI 017 TYPE FILTER 1 bit*/
std::string dfi3002dui017(std::array<int, 1> typeFilter)
{
    //use the dfiset3002 Dui017 function to process the typeFilter array and return the output
    return Dui017(typeFilter);
}
/* DFI 3002 DUI 018 GEOGRAPHIC FILTER 1 bit*/
std::string dfi3002dui018(std::array<int, 1> geographicFilter)
{
    //use the dfiset3002 Dui018 function to process the geographicFilter array and return the output
    return Dui018(geographicFilter);
}
/* DFI 3002 DUI 019 ALL FILTERS 1 bit*/
std::string dfi3002dui019(std::array<int, 1> allFilters)
{
    //use the dfiset3002 Dui019 function to process the allFilters array and return the output
    return Dui019(allFilters);
}
/* DFI 3002 DUI 020 ALTERNATE NETWORK CONTROLLER ASSIGNMENT FLAG 1 bit*/
std::string dfi3002dui020(std::array<int, 1> alternateNetworkControllerAssignmentFlag)
{
    //use the dfiset3002 Dui020 function to process the alternateNetworkControllerAssignmentFlag array and return the output
    return Dui020(alternateNetworkControllerAssignmentFlag);
}
/* DFI 3002 DUI 021 ALTERNATE NETWORK CONTROLLER ASSIGNMENT RECOGNITION 1 bit*/
std::string dfi3002dui021(std::array<int, 1> alternateNetworkControllerAssignmentRecognition)
{
    //use the dfiset3002 Dui021 function to process the alternateNetworkControllerAssignmentRecognition array and return the output
    return Dui021(alternateNetworkControllerAssignmentRecognition);
}

/* DFI 3003 DUI 001 AGE LIMIT VALUE 8 bits SPECIFIED IN ONE SECOND INCREMENTS.
 * MESSAGES OLDER THAN THIS LIMIT WILL BE FILTERED BY THE DATA AGE LIMIT*/
std::string Dif3003Dui001(std::array<int, 8> ageLimitValue)
{
    return Dui001(ageLimitValue);
}

/* DFI 3003 DUI 002 AVERAGE RECEIVED DATA MEDIA LATENCY 16 bits*/
std::string Dfi3003Dui002(std::array<int, 16> averageReceivedDataMediaLatency)
{    return Dui002(averageReceivedDataMediaLatency);
}
/* DFI 3003 DUI 003 DATA AGE 13 bits*/
std::string Dfi3003Dui003(std::array<int, 13> dataAge)
{
    return Dui003(dataAge);
}

/* DFI 3003 DUI 004 DATA VALID TIME 28 bits
*/
std::string Dfi3003Dui004(std::array<int, 28> dataValidTime)
{
    return Dui004(dataValidTime);
}
/* DFI 3003 DUI 005 EVENT TIME ACCURACY 4 bits*/
std::string Dfi3003Dui005(std::array<int, 4> eventTimeAccuracy)
{
    return Dui005(eventTimeAccuracy);
}
/* DFI 3003 DUI 007 MAXIMUM LATENCY 16 bits*/
std::string Dfi3003Dui007(std::array<int, 16> maximumLatency)
{
    return Dui007(maximumLatency);
}
/* DFI 3003 DUI 008 RX JRE RECEIVE TIME (R2) 28 bits
same as coding for JRE Transmit Time*/
std::string Dfi3003Dui008(std::array<int, 28> rxJreReceiveTime)
{    return Dui008(rxJreReceiveTime);
}
/* DFI 3003 DUI 009 TX JRE TRANSMIT TIME (T1) 28 bits*/
std::string Dfi3003Dui009(std::array<int, 28> txJreTransmitTime)
{
    return Dui009(txJreTransmitTime);
}
/* DFI 3003 DUI 010 RX JRE TRANSMIT TIME (T2) 28 bits*/
std::string Dfi3003Dui010(std::array<int, 28> rxJreTransmitTime)
{
    return Dui010(rxJreTransmitTime);
}
/* DFI 3003 DUI 011 TIME ACCURACY 4 bits*/
std::string Dfi3003Dui011(std::array<int, 4> timeAccuracy)
{    return Dui011(timeAccuracy);
}
/* DFI 3003 DUI 012 EVENT TIME 28 bits*/
std::string Dfi3003Dui012(std::array<int, 28> eventTime)
{
    return Dui012(eventTime);
}
/* DFI 3003 DUI 013 INTERVAL TIME 10 bits*/
std::string Dfi3003Dui013(std::array<int, 10> intervalTime)
{
    return Dui013(intervalTime);
}
/* DFI 3003 DUI 014 TIME ACCURACY (R2) 4 bits*/
std::string Dfi3003Dui014(std::array<int, 4> timeAccuracyR2)
{
    return Dui014(timeAccuracyR2);
}
/* DFI 3003 DUI 015 TIME ACCURACY (T1) 4 bits*/
std::string Dfi3003Dui015(std::array<int, 4> timeAccuracyT1)
{
    return Dui015(timeAccuracyT1);
}
/* DFI 3003 DUI 016 TIME ACCURACY (T2) 4 bits*/
std::string Dfi3003Dui016(std::array<int, 4> timeAccuracyT2)
{
    return Dui016(timeAccuracyT2);
}
/* DFI 3004 DUI 001 JRE NC, C 1 bit*/
std::string Dfi3004Dui001(std::array<int, 1> jreNcC)
{
    return Dui001(jreNcC);
}
/* DFI 3004 DUI 002 RTTIME, C*/
std::string Dfi3004Dui002(std::array<int, 1> rttimeC)
{
    return Dui002(rttimeC);
}
/* DFI 3004 DUI 003 FIXED DELAY, C 1 bit*/
std::string Dfi3004Dui003(std::array<int, 1> fixedDelayC)
{
    return Dui003(fixedDelayC);
}
/* DFI 3004 DUI 004 EVENT STROBE, C 1 bit*/
std::string Dfi3004Dui004(std::array<int, 1> eventStrobeC)
{
    return Dui004(eventStrobeC);
}
/* DFI 3004 DUI 005 UTC, C 1 bit*/
std::string Dfi3004Dui005(std::array<int, 1> utcC)
{
    return Dui005(utcC);
}

/* DFI 3005 DUI 001 JRE NC, P 1 bit*/
std::string JreNcP(std::array<int, 1> jreNcP)
{
    if (jreNcP[0] == 1)
    {
        return "Preferred ///-> 1";
    }
    else
    {
        return "Not Preferred ///-> 0";
    }
}
/* DFI 3005 DUI 002 RTTIME, P 1 bit*/
std::string RttimeP(std::array<int, 1> rttimeP)
{
    return JreNcP(rttimeP);
}
/* DFI 3005 DUI 003 FIXED DELAY, P 1 bit*/
std::string FixedDelayP(std::array<int, 1> fixedDelayP)
{
    return JreNcP(fixedDelayP);
}
/* DFI 3005 DUI 004 EVENT STROBE, P 1 bit*/
std::string EventStrobeP(std::array<int, 1> eventStrobeP)
{
    return JreNcP(eventStrobeP);
}
/* DFI 3005 DUI 005 UTC, P 1 bit*/
std::string UtcP(std::array<int, 1> utcP)
{
    return JreNcP(utcP);
}
/* DFI 3007 DUI 001 TRANSMISSION BLOCK HEADER TYPE 4 bits*/
std::string TransmissionBlockHeaderType(std::array<int, 4> transmissionBlockHeaderType)
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
std::string MessageGroupHeaderType(std::array<int, 2> messageGroupHeaderType)
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
std::string HeaderType(std::array<int, 4> headerType)
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

/* DFI 3008 DUI 001 MESSAGE TYPE 4 bits*/
std::string MessageType(std::array<int, 4> messageType)
{
    int messageTypeInt = 0;
    for (int i = 0; i < 4; i++)
    {
        messageTypeInt += messageType[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    /*
    MANAGEMENT                        0
    JREAP J-SERIES                    1
    JTIDS/MIDS JREAP FREE             2
    TEXT (CODED)
    JTIDS/MIDS JREAP FREE             3
    TEXT (UNCODED)
    VMF                               4
    LINK 22                           5
    CMF IBS                           6
    JREAP J SERIES WITH               7
    NPG ASSIGHMENT
    UNDEFINED                         8 THROUGH 14
    RESERVED FOR EXPANSION            15*/
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
std::string ManagementMessageSubtype(std::array<int, 8> managementMessageSubtype)
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
std::string FilterMessageType(std::array<int, 8> filterMessageType)
{
    std::string resp = "";
    for (std::size_t i = 0; i < filterMessageType.size(); i++)
    {
        resp.append(std::to_string(filterMessageType[i]));
    }
    int filterMessageTypeInt = 0;
    for (int i = 0; i < 8; i++)
    {
        filterMessageTypeInt += filterMessageType[i] * std::pow(2, 7 - i);
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
/* DFI 3008 DUI 004 REQUESTED FILTER MESSAGE TYPE*/

/* DFI 3009 DUI 001 GEO FILTER SUBTYPE*/

/* DFI 3010 DUI 015 LATITUDE, 0.0013 MINUTE*/
/* DFI 3010 DUI 018 LATITUDE, CENTER 0.0013 MINUTE*/

/* DFI 3011 DUI 015 LONGITUDE, 0.0013 MINUTE*/
/* DFI 3011 DUI 016 LONGITUDE, CENTER 0.0013 MINUTE*/

/* DFI 3012 DUI 001 APPLICATION BLOCK MESSAGE LENGTH*/
/* DFI 3012 DUI 002 LENGTH OF MESSAGE*/
/* DFI 3012 DUI 003 MANAGEMENT MESSAGE LENGTH*/

/* DFI 3013 DUI 001 MAJOR AXIS LENGTH*/
/* DFI 3013 DUI 002 MINOR AXIS LENGTH*/

/* DFI 3014 DUI 001 TRANSMISSION BLOCK HEADER LENGTH*/
/* DFI 3014 DUI 002 TRANSMISSION BLOCK HEADER LENGTH, 1*/
/* DFI 3014 DUI 003 TRANSMISSION BLOCK HEADER LENGTH, 2*/
/* DFI 3014 DUI 004 TRANSMISSION BLOCK HEADER LENGTH, 3*/

/* DFI 3015 DUI 002 JRE-NP ERROR RATE*/
/* DFI 3015 DUI 017 JRE-NC ERROR RATE*/
/* DFI 3015 DUI 018 ERROR RATE, CURRENT*/

/* DFI 3016 DUI 001 APPLICATION DATA*/
/* DFI 3016 DUI 002 DATA WORDS*/
/* DFI 3016 DUI 003 TRANSPORT DATA WORD COUNT, 1*/
/* DFI 3016 DUI 004 TRANSPORT DATA WORD COUNT, 2*/
/* DFI 3016 DUI 005 TRANSPORT DATA WORD COUNT, 3*/

/* DFI 3017 DUI 001 NUMBER DESTINATION ADDRESSES*/
/* DFI 3017 DUI 002 NUMBER ADDRESSES THIS DESIGNATOR*/
/* DFI 3017 DUI 003 NUMBER DESTINATION ADDRESSES, NON-ZERO*/

/* DFI 3018 DUI 001 NUMBER OF DESIGNATORS SUPPORTED*/
/* DFI 3018 DUI 002 TOTAL NUMBER OF ACTIVE DESIGNATORS*/

/* DFI 3019 DUI 001 CONNECTIVITY MATRIX BIT*/

/* DFI 3020 DUI 001 CONTROL/RESPONSE INDICATOR, 1*/
/* DFI 3020 DUI 002 CONTROL/RESPONSE INDICATOR, 2*/
/* DFI 3020 DUI 003 CONTROL/RESPONSE INDICATOR, 3*/
/* DFI 3020 DUI 004 CONTROL/RESPONSE INDICATOR, 4*/
/* DFI 3020 DUI 005 CONTROL/RESPONSE INDICATOR, 5*/
/* DFI 3020 DUI 006 CONTROL/RESPONSE INDICATOR, 6*/
/* DFI 3020 DUI 007 CONTROL/RESPONSE INDICATOR, 7*/
/* DFI 3020 DUI 008 CONTROL/RESPONSE INDICATOR, 8*/
/* DFI 3020 DUI 009 CONTROL/RESPONSE INDICATOR, 9*/
/* DFI 3020 DUI 010 CONTROL/RESPONSE INDICATOR, 10*/
/* DFI 3020 DUI 011 CONTROL/RESPONSE INDICATOR, 11*/
/* DFI 3020 DUI 012 CONTROL/RESPONSE INDICATOR, 12*/
/* DFI 3020 DUI 013 CONTROL/RESPONSE INDICATOR, 13*/
/* DFI 3020 DUI 014 CONTROL/RESPONSE INDICATOR*/

/* DFI 3021 DUI 001 LINK DESIGNATOR TO FILTER*/
/* DFI 3021 DUI 002 LINK DESIGNATOR*/
/* DFI 3021 DUI 003 SOURCE LINK DESIGNATOR*/
/* DFI 3021 DUI 004 TRANSMIT LINK DESIGNATOR*/

/* DFI 3022 DUI 001 EVENT TYPE*/

/* DFI 3023 DUI 001 APPLICATION PROTOCOL VERSION*/

/* DFI 3024 DUI 001 ASCII*/

/* DFI 3025 DUI 001 CONTROLLER MODE NP*/
/* DFI 3025 DUI 002 CONTROLLER MODE NC*/

/* DFI 3027 DUI 001 SOURCE TRACK NUMBER*/
/* DFI 3027 DUI 002 SECONDARY TRACK NUMBER*/
/* DFI 3027 DUI 003 JRE SOURCE TRACK NUMBER*/

/* DFI 3028 DUI 001 JREAP J-SERIES MESSAGE WORD, 1*/
/* DFI 3028 DUI 002 JREAP J-SERIES MESSAGE WORD, 2*/
/* DFI 3028 DUI 003 JREAP J-SERIES MESSAGE WORD, 3*/
/* DFI 3028 DUI 004 JREAP J-SERIES MESSAGE WORD, 4*/
/* DFI 3028 DUI 005 JREAP J-SERIES MESSAGE WORD, 5*/

/* DFI 3029 DUI 001 COMPLETION TIMEOUT*/

/* DFI 3030 DUI 001 JREAP/JTIDS FREE TEXT, 1*/
/* DFI 3030 DUI 002 JREAP/JTIDS FREE TEXT, 2*/
/* DFI 3030 DUI 003 JREAP/JTIDS FREE TEXT, 3*/
/* DFI 3030 DUI 004 JREAP/JTIDS FREE TEXT, 4*/
/* DFI 3030 DUI 005 JREAP/JTIDS FREE TEXT, 5*/
/* DFI 3030 DUI 006 JREAP/JTIDS FREE TEXT, 6*/
/* DFI 3030 DUI 007 JREAP/JTIDS FREE TEXT, 7*/
/* DFI 3030 DUI 008 JREAP/JTIDS FREE TEXT, 8*/
/* DFI 3030 DUI 009 JREAP/JTIDS FREE TEXT, 9*/
/* DFI 3030 DUI 010 JREAP/JTIDS FREE TEXT, 10*/
/* DFI 3030 DUI 011 JREAP/JTIDS FREE TEXT, 11*/
/* DFI 3030 DUI 012 JREAP/JTIDS FREE TEXT, 12*/
/* DFI 3030 DUI 013 JREAP/JTIDS FREE TEXT, 13*/
/* DFI 3030 DUI 014 JREAP/JTIDS FREE TEXT, 14*/
/* DFI 3030 DUI 015 JREAP/JTIDS FREE TEXT, 15*/
/* DFI 3030 DUI 016 JREAP/JTIDS FREE TEXT, 16*/
/* DFI 3030 DUI 017 JREAP/JTIDS FREE TEXT, 17*/
/* DFI 3030 DUI 018 JREAP/JTIDS FREE TEXT, 18*/
/* DFI 3030 DUI 019 JREAP/JTIDS FREE TEXT, 19*/
/* DFI 3030 DUI 020 JREAP/JTIDS FREE TEXT, 20*/
/* DFI 3030 DUI 021 JREAP/JTIDS FREE TEXT, 21*/
/* DFI 3030 DUI 022 JREAP/JTIDS FREE TEXT, 22*/
/* DFI 3030 DUI 023 JREAP/JTIDS FREE TEXT, 23*/
/* DFI 3030 DUI 024 JREAP/JTIDS FREE TEXT, 24*/
/* DFI 3030 DUI 025 JREAP/JTIDS FREE TEXT, 25*/
/* DFI 3030 DUI 026 JREAP/JTIDS FREE TEXT, 26*/
/* DFI 3030 DUI 027 JREAP/JTIDS FREE TEXT, 27*/
/* DFI 3030 DUI 028 JREAP/JTIDS FREE TEXT, 28*/
/* DFI 3030 DUI 029 JREAP/JTIDS FREE TEXT, 29*/
/* DFI 3030 DUI 030 JREAP/JTIDS FREE TEXT, 30*/

/* DFI 3031 DUI 001 GEOGRAPHIC FILTER INDEX*/

/* DFI 3032 DUI 001 MESSAGE SEQUENCE NUMBER*/
/* DFI 3032 DUI 002 ORIGINATING MESSAGE SEQUENCE NUMBER*/
/* DFI 3032 DUI 003 J-SERIES MESSAGE SEQUENCE NUMBER*/
/* DFI 3032 DUI 004 ORIGINATING J-SERIES MESSAGE SEQUENCE NUMBER*/
/* DFI 3032 DUI 005 NETWORK PARTICIPATION GROUP*/

/* DFI 3033 DUI 001 COUNT*/
/* DFI 3033 DUI 002 FRAGMENT NUMBER*/
/* DFI 3033 DUI 003 TOTAL NUMBER FRAGMENTS*/
/* DFI 3033 DUI 004 NUMBER OF BLOCKS*/
/* DFI 3033 DUI 005 NUMBER OF J-WORDS*/

/* DFI 3034 DUI 001 ERROR CODE, 1*/
/* DFI 3034 DUI 002 ERROR CODE, 2*/
/* DFI 3034 DUI 003 ERROR CODE, 3*/
/* DFI 3034 DUI 004 ERROR CODE, 4*/
/* DFI 3034 DUI 005 ERROR CODE, 5*/
/* DFI 3034 DUI 006 ERROR CODE, 6*/
/* DFI 3034 DUI 007 ERROR CODE, 7*/

/* DFI 3035 DUI 001 JRE-NP TRANSMIT LIMIT*/

/* DFI 3036 DUI 001 JRE SENDER ID*/
/* DFI 3036 DUI 002 JRE SENDER ID, 1*/
/* DFI 3036 DUI 003 JRE SENDER ID, 2*/
/* DFI 3036 DUI 004 JRE SENDER ID, 3*/
/* DFI 3036 DUI 005 JRE NETWORK PARTICIPANT*/
/* DFI 3036 DUI 020 DESTINATION ADDRESS*/
/* DFI 3036 DUI 021 ORIGINATING J-SERIES JRE SENDER ID*/
/* DFI 3036 DUI 022 LINK INTERFACE UNIT*/

/* DFI 3037 DUI 001 LABEL, J-SERIES*/

/* DFI 3038 DUI 001 SUBLABEL, J-SERIES*/

/* DFI 3039 DUI 001 MESSAGE GROUP HEADER CRC*/
/* DFI 3039 DUI 002 TRANSMISSION BLOCK HEADER CRC*/

/* DFI 3040 DUI 001 JTIDS/MIDS PARTICIPATION GROUP*/
/* DFI 3040 DUI 002 NETWORK PARTICIPATION GROUP*/
/* DFI 3040 DUI 003 NETWORK PARTICIPATION GROUP TO FILTER*/

/* DFI 3042 DUI 001 LOWER ALTITUDE LIMIT*/
/* DFI 3042 DUI 002 UPPER ALTITUDE LIMIT*/

/* DFI 3043 DUI 001 MAJOR AXIS ORIENTATION*/

/* DFI 3044 DUI 001 MANAGEMENT VERSION*/

/* DFI 3045 DUI 001 START OF TRANSMISSION FLAG, 1*/
/* DFI 3045 DUI 002 START OF TRANSMISSION FLAG, 2*/

/* DFI 3050 DUI 001 NO STATEMENT*/
/* DFI 3050 DUI 002 NAVIGATION*/
/* DFI 3050 DUI 003 MINE*/
/* DFI 3050 DUI 004 IMPACT POINT*/
/* DFI 3050 DUI 005 GROUND ZERO*/
/* DFI 3050 DUI 006 AIM/WEAPON ENTRY POINT*/
/* DFI 3050 DUI 007 MISSILE LAUNCH POINT*/
/* DFI 3050 DUI 008 ELECTRONIC ATTACK (EA) DECOY*/
/* DFI 3050 DUI 009 ENGAGEMENT POINT*/
/* DFI 3050 DUI 010 OIL RIG*/
/* DFI 3050 DUI 011 PT0, AMP10*/
/* DFI 3050 DUI 012 PT0, AMP11*/
/* DFI 3050 DUI 013 PT0, AMP12*/
/* DFI 3050 DUI 014 PT0, AMP13*/
/* DFI 3050 DUI 015 PT0, AMP14*/
/* DFI 3050 DUI 016 PT0, AMP15*/

/* DFI 3051 DUI 001 NO STATEMENT*/
/* DFI 3051 DUI 002 MARSHALL POINT*/
/* DFI 3051 DUI 003 WAYPOINT*/
/* DFI 3051 DUI 004 CORRIDOR TAB*/
/* DFI 3051 DUI 005 POSITION AND INTENDED MOVEMENT (PIM)*/
/* DFI 3051 DUI 006 DISPOSITION CENTER*/
/* DFI 3051 DUI 007 FORMATION CENTER*/
/* DFI 3051 DUI 008 SEARCH AREA*/
/* DFI 3051 DUI 009 VICTOR LIMA (VL)*/
/* DFI 3051 DUI 010 SUBMARINE POSITION AND INTENDED MOVEMENT (SIM)*/
/* DFI 3051 DUI 011 PT1, AMP10*/
/* DFI 3051 DUI 012 DEFENDED ASSET*/
/* DFI 3051 DUI 013 PT1, AMP12*/
/* DFI 3051 DUI 014 PT1, AMP13*/
/* DFI 3051 DUI 015 PT1, AMP14*/
/* DFI 3051 DUI 016 PT1, AMP15*/

/* DFI 3052 DUI 001 NO STATEMENT*/
/* DFI 3052 DUI 002 TOMCAT*/
/* DFI 3052 DUI 003 PICKET*/
/* DFI 3052 DUI 004 RENDEZVOUS*/
/* DFI 3052 DUI 005 PT2, AMP4*/
/* DFI 3052 DUI 006 REPLENISHMENT*/
/* DFI 3052 DUI 007 RESCUE*/
/* DFI 3052 DUI 008 PT2, AMP7*/
/* DFI 3052 DUI 009 PT2, AMP8*/
/* DFI 3052 DUI 010 PT2, AMP9*/
/* DFI 3052 DUI 011 PT2, AMP10*/
/* DFI 3052 DUI 012 PT2, AMP11*/
/* DFI 3052 DUI 013 PT2, AMP12*/
/* DFI 3052 DUI 014 PT2, AMP13*/
/* DFI 3052 DUI 015 PT2, AMP14*/
/* DFI 3052 DUI 016 PT2, AMP15*/

/* DFI 3053 DUI 001 NO STATEMENT*/
/* DFI 3053 DUI 002 COMBAT AIR PATROL (CAP)*/
/* DFI 3053 DUI 003 AIRBORNE EARLY WARNING (AEW)*/
/* DFI 3053 DUI 004 ANTISUBMARINE WARFARE (ASW)FIXED WING*/
/* DFI 3053 DUI 005 ANTISUBMARINE WARFARE (ASW)HELICOPTER (HELO)*/
/* DFI 3053 DUI 006 REPLENISHMENT*/
/* DFI 3053 DUI 007 STRIKE INITIAL POINT (IP)*/
/* DFI 3053 DUI 008 TACAN*/
/* DFI 3053 DUI 009 TANKER*/
/* DFI 3053 DUI 010 ORBIT, RACE TRACK*/
/* DFI 3053 DUI 011 ORBIT, FIGURE EIGHT*/
/* DFI 3053 DUI 012 ORBIT, RANDOM CLOSED*/
/* DFI 3053 DUI 013 ORBIT POINT*/
/* DFI 3053 DUI 014 PT3, AMP13*/
/* DFI 3053 DUI 015 PT3, AMP14*/
/* DFI 3053 DUI 016 PT3, AMP15*/

/* DFI 3054 DUI 001 NO STATEMENT*/
/* DFI 3054 DUI 002 FORWARD EDGE OF THE BATTLE AREA (FEBA)*/
/* DFI 3054 DUI 003 GUN TARGET LINE*/
/* DFI 3054 DUI 004 CORRIDOR*/
/* DFI 3054 DUI 005 HOSTILE BOUNDARY*/
/* DFI 3054 DUI 006 BUFFER ZONE BOUNDARY*/
/* DFI 3054 DUI 007 LOW LEVEL TRANSIT ROUTE*/
/* DFI 3054 DUI 008 TACTICAL ACTION LINE*/
/* DFI 3054 DUI 009 FIRE SUPPORT COORDINATION LINE (FSCL)*/
/* DFI 3054 DUI 010 FORWARD LINE OF OWN TROOPS (FLOT)*/
/* DFI 3054 DUI 011 PT4, AMP10*/
/* DFI 3054 DUI 012 PT4, AMP11*/
/* DFI 3054 DUI 013 PT4, AMP12*/
/* DFI 3054 DUI 014 PT4, AMP13*/
/* DFI 3054 DUI 015 PT4, AMP14*/
/* DFI 3054 DUI 016 PT4, AMP15*/

/* DFI 3055 DUI 001 NO STATEMENT*/
/* DFI 3055 DUI 002 SEARCH*/
/* DFI 3055 DUI 003 RESTRICTED*/
/* DFI 3055 DUI 004 EXERCISE*/
/* DFI 3055 DUI 005 SUBMARINE PATROL AREA*/
/* DFI 3055 DUI 006 FIGHTER ENGAGEMENT ZONE*/
/* DFI 3055 DUI 007 GROUND AREA OF RESPONSIBILITY*/
/* DFI 3055 DUI 008 DEFENDED AREA*/
/* DFI 3055 DUI 009 PT5, AMP8*/
/* DFI 3055 DUI 010 PT5, AMP9*/
/* DFI 3055 DUI 011 PT5, AMP10*/
/* DFI 3055 DUI 012 PT5, AMP11*/
/* DFI 3055 DUI 013 PT5, AMP12*/
/* DFI 3055 DUI 014 PT5, AMP13*/
/* DFI 3055 DUI 015 PT5, AMP14*/
/* DFI 3055 DUI 016 PT5, AMP15*/

/* DFI 3056 DUI 001 NO STATEMENT*/
/* DFI 3056 DUI 002 DANGER*/
/* DFI 3056 DUI 003 CONTAMINATED*/
/* DFI 3056 DUI 004 MISSILE ENGAGEMENT ZONE*/
/* DFI 3056 DUI 005 DISUSED*/
/* DFI 3056 DUI 006 HOSTILE WEAPON ZONE*/
/* DFI 3056 DUI 007 HOSTILE TACTICAL ZONE*/
/* DFI 3056 DUI 008 SHORAD*/
/* DFI 3056 DUI 009 KILL ZONE*/
/* DFI 3056 DUI 010 TARGET AREA OF INTEREST*/
/* DFI 3056 DUI 011 NAMED AREA OF INTEREST*/
/* DFI 3056 DUI 012 PT6, AMP11*/
/* DFI 3056 DUI 013 PT6, AMP12*/
/* DFI 3056 DUI 014 PT6, AMP13*/
/* DFI 3056 DUI 015 PT6, AMP14*/
/* DFI 3056 DUI 016 PT6, AMP15*/

/* DFI 3057 DUI 001 NO STATEMENT*/
/* DFI 3057 DUI 002 SINKER*/
/* DFI 3057 DUI 003 BRIEF CONTACT*/
/* DFI 3057 DUI 004 SEARCH CENTER (ASW)*/
/* DFI 3057 DUI 005 ESTIMATED POSITION (EP)*/
/* DFI 3057 DUI 006 FIX (ASW)*/
/* DFI 3057 DUI 007 NOTACK AREA*/
/* DFI 3057 DUI 008 MOVING HAVEN*/
/* DFI 3057 DUI 009 DISUSED*/
/* DFI 3057 DUI 010 SONOBUOY POSITION*/
/* DFI 3057 DUI 011 SONOBUOY PATTERN REFERENCE POSITION*/
/* DFI 3057 DUI 012 LIMITING LINE OF APPROACH*/
/* DFI 3057 DUI 013 AREA OF PROBABILITY (ASW)*/
/* DFI 3057 DUI 014 FRIENDLY WEAPON DANGER AREA (FWDA)*/
/* DFI 3057 DUI 015 PT7, AMP14*/
/* DFI 3057 DUI 016 PT7, AMP15*/

/* DFI 3058 DUI 001 CHARTED WRECK*/
/* DFI 3058 DUI 002 BOTTOMED NONSUBMARINE*/
/* DFI 3058 DUI 003 ASW STATION*/
/* DFI 3058 DUI 004 PT8, AMP3*/
/* DFI 3058 DUI 005 PT8, AMP4*/
/* DFI 3058 DUI 006 PT8, AMP5*/
/* DFI 3058 DUI 007 PT8, AMP6*/
/* DFI 3058 DUI 008 PT8, AMP7*/
/* DFI 3058 DUI 009 PT8, AMP8*/
/* DFI 3058 DUI 010 PT8, AMP9*/
/* DFI 3058 DUI 011 PT8, AMP10*/
/* DFI 3058 DUI 012 PT8, AMP11*/
/* DFI 3058 DUI 013 PT8, AMP12*/
/* DFI 3058 DUI 014 PT8, AMP13*/
/* DFI 3058 DUI 015 PT8, AMP14*/
/* DFI 3058 DUI 016 PT8, AMP15*/

/* DFI 3059 DUI 001 PT9, AMP0*/
/* DFI 3059 DUI 002 PT9, AMP1*/
/* DFI 3059 DUI 003 PT9, AMP2*/
/* DFI 3059 DUI 004 PT9, AMP3*/
/* DFI 3059 DUI 005 PT9, AMP4*/
/* DFI 3059 DUI 006 PT9, AMP5*/
/* DFI 3059 DUI 007 PT9, AMP6*/
/* DFI 3059 DUI 008 PT9, AMP7*/
/* DFI 3059 DUI 009 PT9, AMP8*/
/* DFI 3059 DUI 010 PT9, AMP9*/
/* DFI 3059 DUI 011 PT9, AMP10*/
/* DFI 3059 DUI 012 PT9, AMP11*/
/* DFI 3059 DUI 013 PT9, AMP12*/
/* DFI 3059 DUI 014 PT9, AMP13*/
/* DFI 3059 DUI 015 PT9, AMP14*/
/* DFI 3059 DUI 016 PT9, AMP15*/

/* DFI 3060 DUI 001 DISUSED*/
/* DFI 3060 DUI 002 DISUSED*/
/* DFI 3060 DUI 003 FILTER ROCKEET (DI 1)*/

/* DFI 3061 DUI 001 PT10, AMP0*/
/* DFI 3061 DUI 002 PT10, AMP1*/
/* DFI 3061 DUI 003 PT10, AMP2*/
/* DFI 3061 DUI 004 PT10, AMP3*/
/* DFI 3061 DUI 005 PT10, AMP4*/
/* DFI 3061 DUI 006 PT10, AMP5*/
/* DFI 3061 DUI 007 PT10, AMP6*/
/* DFI 3061 DUI 008 PT10, AMP7*/
/* DFI 3061 DUI 009 PT10, AMP8*/
/* DFI 3061 DUI 010 PT10, AMP9*/
/* DFI 3061 DUI 011 PT10, AMP10*/
/* DFI 3061 DUI 012 PT10, AMP11*/
/* DFI 3061 DUI 013 PT10, AMP12*/
/* DFI 3061 DUI 014 PT10, AMP13*/
/* DFI 3061 DUI 015 PT10, AMP14*/
/* DFI 3061 DUI 016 PT10, AMP15*/

/* DFI 3062 DUI 001 PT11, AMP0*/
/* DFI 3062 DUI 002 PT11, AMP1*/
/* DFI 3062 DUI 003 PT11, AMP2*/
/* DFI 3062 DUI 004 PT11, AMP3*/
/* DFI 3062 DUI 005 PT11, AMP4*/
/* DFI 3062 DUI 006 PT11, AMP5*/
/* DFI 3062 DUI 007 PT11, AMP6*/
/* DFI 3062 DUI 008 PT11, AMP7*/
/* DFI 3062 DUI 009 PT11, AMP8*/
/* DFI 3062 DUI 010 PT11, AMP9*/
/* DFI 3062 DUI 011 PT11, AMP10*/
/* DFI 3062 DUI 012 PT11, AMP11*/
/* DFI 3062 DUI 013 PT11, AMP12*/
/* DFI 3062 DUI 014 PT11, AMP13*/
/* DFI 3062 DUI 015 PT11, AMP14*/
/* DFI 3062 DUI 016 PT11, AMP15*/

/* DFI 3063 DUI 001 PT12, AMP0*/
/* DFI 3063 DUI 002 PT12, AMP1*/
/* DFI 3063 DUI 003 PT12, AMP2*/
/* DFI 3063 DUI 004 PT12, AMP3*/
/* DFI 3063 DUI 005 PT12, AMP4*/
/* DFI 3063 DUI 006 PT12, AMP5*/
/* DFI 3063 DUI 007 PT12, AMP6*/
/* DFI 3063 DUI 008 PT12, AMP7*/
/* DFI 3063 DUI 009 PT12, AMP8*/
/* DFI 3063 DUI 010 PT12, AMP9*/
/* DFI 3063 DUI 011 PT12, AMP10*/
/* DFI 3063 DUI 012 PT12, AMP11*/
/* DFI 3063 DUI 013 PT12, AMP12*/
/* DFI 3063 DUI 014 PT12, AMP13*/
/* DFI 3063 DUI 015 PT12, AMP14*/
/* DFI 3063 DUI 016 PT12, AMP15*/

/* DFI 3064 DUI 001 PT13, AMP0*/
/* DFI 3064 DUI 002 PT13, AMP1*/
/* DFI 3064 DUI 003 PT13, AMP2*/
/* DFI 3064 DUI 004 PT13, AMP3*/
/* DFI 3064 DUI 005 PT13, AMP4*/
/* DFI 3064 DUI 006 PT13, AMP5*/
/* DFI 3064 DUI 007 PT13, AMP6*/
/* DFI 3064 DUI 008 PT13, AMP7*/
/* DFI 3064 DUI 009 PT13, AMP8*/
/* DFI 3064 DUI 010 PT13, AMP9*/
/* DFI 3064 DUI 011 PT13, AMP10*/
/* DFI 3064 DUI 012 PT13, AMP11*/
/* DFI 3064 DUI 013 PT13, AMP12*/
/* DFI 3064 DUI 014 PT13, AMP13*/
/* DFI 3064 DUI 015 PT13, AMP14*/
/* DFI 3064 DUI 016 PT13, AMP15*/

/* DFI 3065 DUI 001 PT14, AMP0*/
/* DFI 3065 DUI 002 PT14, AMP1*/
/* DFI 3065 DUI 003 PT14, AMP2*/
/* DFI 3065 DUI 004 PT14, AMP3*/
/* DFI 3065 DUI 005 PT14, AMP4*/
/* DFI 3065 DUI 006 PT14, AMP5*/
/* DFI 3065 DUI 007 PT14, AMP6*/
/* DFI 3065 DUI 008 PT14, AMP7*/
/* DFI 3065 DUI 009 PT14, AMP8*/
/* DFI 3065 DUI 010 PT14, AMP9*/
/* DFI 3065 DUI 011 PT14, AMP10*/
/* DFI 3065 DUI 012 PT14, AMP11*/
/* DFI 3065 DUI 013 PT14, AMP12*/
/* DFI 3065 DUI 014 PT14, AMP13*/
/* DFI 3065 DUI 015 PT14, AMP14*/
/* DFI 3065 DUI 016 PT14, AMP15*/

/* DFI 3066 DUI 001 PT15, AMP0*/
/* DFI 3066 DUI 002 PT15, AMP1*/
/* DFI 3066 DUI 003 PT15, AMP2*/
/* DFI 3066 DUI 004 PT15, AMP3*/
/* DFI 3066 DUI 005 PT15, AMP4*/
/* DFI 3066 DUI 006 PT15, AMP5*/
/* DFI 3066 DUI 007 PT15, AMP6*/
/* DFI 3066 DUI 008 PT15, AMP7*/
/* DFI 3066 DUI 009 PT15, AMP8*/
/* DFI 3066 DUI 010 PT15, AMP9*/
/* DFI 3066 DUI 011 PT15, AMP10*/
/* DFI 3066 DUI 012 PT15, AMP11*/
/* DFI 3066 DUI 013 PT15, AMP12*/
/* DFI 3066 DUI 014 PT15, AMP13*/
/* DFI 3066 DUI 015 PT15, AMP14*/
/* DFI 3066 DUI 016 PT15, AMP15*/

/* DFI 3080 DUI 001 UNDEFINED*/
/* DFI 3080 DUI 002 UNDEFINED*/
/* DFI 3080 DUI 003 J3.2 AIR, 0*/
/* DFI 3080 DUI 004 J3.3 SURFACE, 0*/
/* DFI 3080 DUI 005 J3.4 AND J5.4 SUBSURFACE, 0*/
/* DFI 3080 DUI 006 J3.5 LAND/GROUND, 0*/
/* DFI 3080 DUI 007 J3.6 SPACE, 0*/
/* DFI 3080 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 0*/

/* DFI 3081 DUI 001 UNDEFINED*/
/* DFI 3081 DUI 002 UNDEFINED*/
/* DFI 3081 DUI 003 J3.2 AIR, 1*/
/* DFI 3081 DUI 004 J3.3 SURFACE, 1*/
/* DFI 3081 DUI 005 J3.4 AND J5.4 SUBSURFACE, 1*/
/* DFI 3081 DUI 006 J3.5 LAND/GROUND, 1*/
/* DFI 3081 DUI 007 J3.6 SPACE, 1*/
/* DFI 3081 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 1*/

/* DFI 3082 DUI 001 UNDEFINED*/
/* DFI 3082 DUI 002 UNDEFINED*/
/* DFI 3082 DUI 003 J3.2 AIR, 2*/
/* DFI 3082 DUI 004 J3.3 SURFACE, 2*/
/* DFI 3082 DUI 005 J3.4 AND J5.4 SUBSURFACE, 2*/
/* DFI 3082 DUI 006 J3.5 LAND/GROUND, 2*/
/* DFI 3082 DUI 007 J3.6 SPACE, 2*/
/* DFI 3082 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 2*/

/* DFI 3083 DUI 001 UNDEFINED*/
/* DFI 3083 DUI 002 UNDEFINED*/
/* DFI 3083 DUI 003 J3.2 AIR, 3*/
/* DFI 3083 DUI 004 J3.3 SURFACE, 3*/
/* DFI 3083 DUI 005 J3.4 AND J5.4 SUBSURFACE, 3*/
/* DFI 3083 DUI 006 J3.5 LAND/GROUND, 3*/
/* DFI 3083 DUI 007 J3.6 SPACE, 3*/
/* DFI 3083 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 3*/

/* DFI 3084 DUI 001 UNDEFINED*/
/* DFI 3084 DUI 002 UNDEFINED*/
/* DFI 3084 DUI 003 J3.2 AIR, 4*/
/* DFI 3084 DUI 004 J3.3 SURFACE, 4*/
/* DFI 3084 DUI 005 J3.4 AND J5.4 SUBSURFACE, 4*/
/* DFI 3084 DUI 006 J3.5 LAND/GROUND, 4*/
/* DFI 3084 DUI 007 J3.6 SPACE, 4*/
/* DFI 3084 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 4*/

/* DFI 3085 DUI 001 UNDEFINED*/
/* DFI 3085 DUI 002 UNDEFINED*/
/* DFI 3085 DUI 003 J3.2 AIR, 5*/
/* DFI 3085 DUI 004 J3.3 SURFACE, 5*/
/* DFI 3085 DUI 005 J3.4 AND J5.4 SUBSURFACE, 5*/
/* DFI 3085 DUI 006 J3.5 LAND/GROUND, 5*/
/* DFI 3085 DUI 007 J3.6 SPACE, 5*/
/* DFI 3085 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 5*/

/* DFI 3086 DUI 001 UNDEFINED*/
/* DFI 3086 DUI 002 UNDEFINED*/
/* DFI 3086 DUI 003 J3.2 AIR, 6*/
/* DFI 3086 DUI 004 J3.3 SURFACE, 6*/
/* DFI 3086 DUI 005 J3.4 AND J5.4 SUBSURFACE, 6*/
/* DFI 3086 DUI 006 J3.5 LAND/GROUND, 6*/
/* DFI 3086 DUI 007 J3.6 SPACE, 6*/
/* DFI 3086 DUI 008 J3.7 AND J14.0 EW PRODUCT INFORMATION, 6*/

/* DFI 3087 DUI 001 UNDEFINED*/
/* DFI 3087 DUI 002 UNDEFINED*/
/* DFI 3087 DUI 003 J2.2 AND J2.0 AIR*/
/* DFI 3087 DUI 004 J2.3 AND J2.0 SURFACE*/
/* DFI 3087 DUI 005 J2.4 AND J2.0 SUBSURFACE*/
/* DFI 3087 DUI 006 J2.5, J2.6 AND J2.0 LAND*/
/* DFI 3087 DUI 007 UNDEFINED*/
/* DFI 3087 DUI 008 UNDEFINED*/

/* DFI 3099 DUI 001 SPARE*/
/* DFI 3099 DUI 002 SPARE*/
/* DFI 3099 DUI 003 SPARE*/
/* DFI 3099 DUI 004 SPARE*/
/* DFI 3099 DUI 005 SPARE*/
/* DFI 3099 DUI 006 SPARE*/
/* DFI 3099 DUI 007 SPARE*/
/* DFI 3099 DUI 008 SPARE*/
/* DFI 3099 DUI 009 SPARE*/
/* DFI 3099 DUI 010 SPARE*/
/* DFI 3099 DUI 011 SPARE*/
/* DFI 3099 DUI 012 SPARE*/
/* DFI 3099 DUI 013 SPARE*/
/* DFI 3099 DUI 014 SPARE*/
/* DFI 3099 DUI 015 SPARE*/
/* DFI 3099 DUI 016 SPARE*/
/* DFI 3099 DUI 017 SPARE*/
/* DFI 3099 DUI 018 SPARE*/
/* DFI 3099 DUI 019 SPARE*/
/* DFI 3099 DUI 020 SPARE*/
/* DFI 3099 DUI 021 SPARE*/
/* DFI 3099 DUI 022 SPARE*/
/* DFI 3099 DUI 023 SPARE*/
/* DFI 3099 DUI 024 SPARE*/
/* DFI 3099 DUI 025 SPARE*/
/* DFI 3099 DUI 026 SPARE*/
/* DFI 3099 DUI 027 SPARE*/
/* DFI 3099 DUI 028 SPARE*/
/* DFI 3099 DUI 029 SPARE*/
/* DFI 3099 DUI 030 SPARE*/
/* DFI 3099 DUI 031 SPARE*/

/* DFI 3100 DUI 001 SUBLABEL 0, 0*/
/* DFI 3100 DUI 002 SUBLABEL 1, 0*/
/* DFI 3100 DUI 003 SUBLABEL 2, 0*/
/* DFI 3100 DUI 004 SUBLABEL 3, 0*/
/* DFI 3100 DUI 005 SUBLABEL 4, 0*/
/* DFI 3100 DUI 006 SUBLABEL 5, 0*/
/* DFI 3100 DUI 007 SUBLABEL 6, 0*/
/* DFI 3100 DUI 008 SUBLABEL 7, 0*/

/* DFI 3101 DUI 001 SUBLABEL 0, 1*/
/* DFI 3101 DUI 002 SUBLABEL 1, 1*/
/* DFI 3101 DUI 003 SUBLABEL 2, 1*/
/* DFI 3101 DUI 004 SUBLABEL 3, 1*/
/* DFI 3101 DUI 005 SUBLABEL 4, 1*/
/* DFI 3101 DUI 006 SUBLABEL 5, 1*/
/* DFI 3101 DUI 007 SUBLABEL 6, 1*/
/* DFI 3101 DUI 008 SUBLABEL 7, 1*/

/* DFI 3102 DUI 001 SUBLABEL 0, 2*/
/* DFI 3102 DUI 002 SUBLABEL 1, 2*/
/* DFI 3102 DUI 003 SUBLABEL 2, 2*/
/* DFI 3102 DUI 004 SUBLABEL 3, 2*/
/* DFI 3102 DUI 005 SUBLABEL 4, 2*/
/* DFI 3102 DUI 006 SUBLABEL 5, 2*/
/* DFI 3102 DUI 007 SUBLABEL 6, 2*/
/* DFI 3102 DUI 008 SUBLABEL 7, 2*/

/* DFI 3103 DUI 001 SUBLABEL 0, 3*/
/* DFI 3103 DUI 002 SUBLABEL 1, 3*/
/* DFI 3103 DUI 003 SUBLABEL 2, 3*/
/* DFI 3103 DUI 004 SUBLABEL 3, 3*/
/* DFI 3103 DUI 005 SUBLABEL 4, 3*/
/* DFI 3103 DUI 006 SUBLABEL 5, 3*/
/* DFI 3103 DUI 007 SUBLABEL 6, 3*/
/* DFI 3103 DUI 008 SUBLABEL 7, 3*/

/* DFI 3104 DUI 001 SUBLABEL 0, 4*/
/* DFI 3104 DUI 002 SUBLABEL 1, 4*/
/* DFI 3104 DUI 003 SUBLABEL 2, 4*/
/* DFI 3104 DUI 004 SUBLABEL 3, 4*/
/* DFI 3104 DUI 005 SUBLABEL 4, 4*/
/* DFI 3104 DUI 006 SUBLABEL 5, 4*/
/* DFI 3104 DUI 007 SUBLABEL 6, 4*/
/* DFI 3104 DUI 008 SUBLABEL 7, 4*/

/* DFI 3105 DUI 001 SUBLABEL 0, 5*/
/* DFI 3105 DUI 002 SUBLABEL 1, 5*/
/* DFI 3105 DUI 003 SUBLABEL 2, 5*/
/* DFI 3105 DUI 004 SUBLABEL 3, 5*/
/* DFI 3105 DUI 005 SUBLABEL 4, 5*/
/* DFI 3105 DUI 006 SUBLABEL 5, 5*/
/* DFI 3105 DUI 007 SUBLABEL 6, 5*/
/* DFI 3105 DUI 008 SUBLABEL 7, 5*/

/* DFI 3106 DUI 001 SUBLABEL 0, 6*/
/* DFI 3106 DUI 002 SUBLABEL 1, 6*/
/* DFI 3106 DUI 003 SUBLABEL 2, 6*/
/* DFI 3106 DUI 004 SUBLABEL 3, 6*/
/* DFI 3106 DUI 005 SUBLABEL 4, 6*/
/* DFI 3106 DUI 006 SUBLABEL 5, 6*/
/* DFI 3106 DUI 007 SUBLABEL 6, 6*/
/* DFI 3106 DUI 008 SUBLABEL 7, 6*/

/* DFI 3107 DUI 001 SUBLABEL 0, 7*/
/* DFI 3107 DUI 002 SUBLABEL 1, 7*/
/* DFI 3107 DUI 003 SUBLABEL 2, 7*/
/* DFI 3107 DUI 004 SUBLABEL 3, 7*/
/* DFI 3107 DUI 005 SUBLABEL 4, 7*/
/* DFI 3107 DUI 006 SUBLABEL 5, 7*/
/* DFI 3107 DUI 007 SUBLABEL 6, 7*/
/* DFI 3107 DUI 008 SUBLABEL 7, 7*/

/* DFI 3108 DUI 001 SUBLABEL 0, 8*/
/* DFI 3108 DUI 002 SUBLABEL 1, 8*/
/* DFI 3108 DUI 003 SUBLABEL 2, 8*/
/* DFI 3108 DUI 004 SUBLABEL 3, 8*/
/* DFI 3108 DUI 005 SUBLABEL 4, 8*/
/* DFI 3108 DUI 006 SUBLABEL 5, 8*/
/* DFI 3108 DUI 007 SUBLABEL 6, 8*/
/* DFI 3108 DUI 008 SUBLABEL 7, 8*/

/* DFI 3109 DUI 001 SUBLABEL 0, 9*/
/* DFI 3109 DUI 002 SUBLABEL 1, 9*/
/* DFI 3109 DUI 003 SUBLABEL 2, 9*/
/* DFI 3109 DUI 004 SUBLABEL 3, 9*/
/* DFI 3109 DUI 005 SUBLABEL 4, 9*/
/* DFI 3109 DUI 006 SUBLABEL 5, 9*/
/* DFI 3109 DUI 007 SUBLABEL 6, 9*/
/* DFI 3109 DUI 008 SUBLABEL 7, 9*/

/* DFI 3110 DUI 001 SUBLABEL 0, 10*/
/* DFI 3110 DUI 002 SUBLABEL 1, 10*/
/* DFI 3110 DUI 003 SUBLABEL 2, 10*/
/* DFI 3110 DUI 004 SUBLABEL 3, 10*/
/* DFI 3110 DUI 005 SUBLABEL 4, 10*/
/* DFI 3110 DUI 006 SUBLABEL 5, 10*/
/* DFI 3110 DUI 007 SUBLABEL 6, 10*/
/* DFI 3110 DUI 008 SUBLABEL 7, 10*/

/* DFI 3111 DUI 001 SUBLABEL 0, 11*/
/* DFI 3111 DUI 002 SUBLABEL 1, 11*/
/* DFI 3111 DUI 003 SUBLABEL 2, 11*/
/* DFI 3111 DUI 004 SUBLABEL 3, 11*/
/* DFI 3111 DUI 005 SUBLABEL 4, 11*/
/* DFI 3111 DUI 006 SUBLABEL 5, 11*/
/* DFI 3111 DUI 007 SUBLABEL 6, 11*/
/* DFI 3111 DUI 008 SUBLABEL 7, 11*/

/* DFI 3112 DUI 001 SUBLABEL 0, 12*/
/* DFI 3112 DUI 002 SUBLABEL 1, 12*/
/* DFI 3112 DUI 003 SUBLABEL 2, 12*/
/* DFI 3112 DUI 004 SUBLABEL 3, 12*/
/* DFI 3112 DUI 005 SUBLABEL 4, 12*/
/* DFI 3112 DUI 006 SUBLABEL 5, 12*/
/* DFI 3112 DUI 007 SUBLABEL 6, 12*/
/* DFI 3112 DUI 008 SUBLABEL 7, 12*/

/* DFI 3113 DUI 001 SUBLABEL 0, 13*/
/* DFI 3113 DUI 002 SUBLABEL 1, 13*/
/* DFI 3113 DUI 003 SUBLABEL 2, 13*/
/* DFI 3113 DUI 004 SUBLABEL 3, 13*/
/* DFI 3113 DUI 005 SUBLABEL 4, 13*/
/* DFI 3113 DUI 006 SUBLABEL 5, 13*/
/* DFI 3113 DUI 007 SUBLABEL 6, 13*/
/* DFI 3113 DUI 008 SUBLABEL 7, 13*/

/* DFI 3114 DUI 001 SUBLABEL 0, 14*/
/* DFI 3114 DUI 002 SUBLABEL 1, 14*/
/* DFI 3114 DUI 003 SUBLABEL 2, 14*/
/* DFI 3114 DUI 004 SUBLABEL 3, 14*/
/* DFI 3114 DUI 005 SUBLABEL 4, 14*/
/* DFI 3114 DUI 006 SUBLABEL 5, 14*/
/* DFI 3114 DUI 007 SUBLABEL 6, 14*/
/* DFI 3114 DUI 008 SUBLABEL 7, 14*/

/* DFI 3115 DUI 001 SUBLABEL 0, 15*/
/* DFI 3115 DUI 002 SUBLABEL 1, 15*/
/* DFI 3115 DUI 003 SUBLABEL 2, 15*/
/* DFI 3115 DUI 004 SUBLABEL 3, 15*/
/* DFI 3115 DUI 005 SUBLABEL 4, 15*/
/* DFI 3115 DUI 006 SUBLABEL 5, 15*/
/* DFI 3115 DUI 007 SUBLABEL 6, 15*/
/* DFI 3115 DUI 008 SUBLABEL 7, 15*/

/* DFI 3116 DUI 001 SUBLABEL 0, 16*/
/* DFI 3116 DUI 002 SUBLABEL 1, 16*/
/* DFI 3116 DUI 003 SUBLABEL 2, 16*/
/* DFI 3116 DUI 004 SUBLABEL 3, 16*/
/* DFI 3116 DUI 005 SUBLABEL 4, 16*/
/* DFI 3116 DUI 006 SUBLABEL 5, 16*/
/* DFI 3116 DUI 007 SUBLABEL 6, 16*/
/* DFI 3116 DUI 008 SUBLABEL 7, 16*/

/* DFI 3117 DUI 001 SUBLABEL 0, 17*/
/* DFI 3117 DUI 002 SUBLABEL 1, 17*/
/* DFI 3117 DUI 003 SUBLABEL 2, 17*/
/* DFI 3117 DUI 004 SUBLABEL 3, 17*/
/* DFI 3117 DUI 005 SUBLABEL 4, 17*/
/* DFI 3117 DUI 006 SUBLABEL 5, 17*/
/* DFI 3117 DUI 007 SUBLABEL 6, 17*/
/* DFI 3117 DUI 008 SUBLABEL 7, 17*/

/* DFI 3118 DUI 001 SUBLABEL 0, 18*/
/* DFI 3118 DUI 002 SUBLABEL 1, 18*/
/* DFI 3118 DUI 003 SUBLABEL 2, 18*/
/* DFI 3118 DUI 004 SUBLABEL 3, 18*/
/* DFI 3118 DUI 005 SUBLABEL 4, 18*/
/* DFI 3118 DUI 006 SUBLABEL 5, 18*/
/* DFI 3118 DUI 007 SUBLABEL 6, 18*/
/* DFI 3118 DUI 008 SUBLABEL 7, 18*/

/* DFI 3119 DUI 001 SUBLABEL 0, 19*/
/* DFI 3119 DUI 002 SUBLABEL 1, 19*/
/* DFI 3119 DUI 003 SUBLABEL 2, 19*/
/* DFI 3119 DUI 004 SUBLABEL 3, 19*/
/* DFI 3119 DUI 005 SUBLABEL 4, 19*/
/* DFI 3119 DUI 006 SUBLABEL 5, 19*/
/* DFI 3119 DUI 007 SUBLABEL 6, 19*/
/* DFI 3119 DUI 008 SUBLABEL 7, 19*/

/* DFI 3120 DUI 001 SUBLABEL 0, 20*/
/* DFI 3120 DUI 002 SUBLABEL 1, 20*/
/* DFI 3120 DUI 003 SUBLABEL 2, 20*/
/* DFI 3120 DUI 004 SUBLABEL 3, 20*/
/* DFI 3120 DUI 005 SUBLABEL 4, 20*/
/* DFI 3120 DUI 006 SUBLABEL 5, 20*/
/* DFI 3120 DUI 007 SUBLABEL 6, 20*/
/* DFI 3120 DUI 008 SUBLABEL 7, 20*/

/* DFI 3121 DUI 001 SUBLABEL 0, 21*/
/* DFI 3121 DUI 002 SUBLABEL 1, 21*/
/* DFI 3121 DUI 003 SUBLABEL 2, 21*/
/* DFI 3121 DUI 004 SUBLABEL 3, 21*/
/* DFI 3121 DUI 005 SUBLABEL 4, 21*/
/* DFI 3121 DUI 006 SUBLABEL 5, 21*/
/* DFI 3121 DUI 007 SUBLABEL 6, 21*/
/* DFI 3121 DUI 008 SUBLABEL 7, 21*/

/* DFI 3122 DUI 001 SUBLABEL 0, 22*/
/* DFI 3122 DUI 002 SUBLABEL 1, 22*/
/* DFI 3122 DUI 003 SUBLABEL 2, 22*/
/* DFI 3122 DUI 004 SUBLABEL 3, 22*/
/* DFI 3122 DUI 005 SUBLABEL 4, 22*/
/* DFI 3122 DUI 006 SUBLABEL 5, 22*/
/* DFI 3122 DUI 007 SUBLABEL 6, 22*/
/* DFI 3122 DUI 008 SUBLABEL 7, 22*/

/* DFI 3123 DUI 001 SUBLABEL 0, 23*/
/* DFI 3123 DUI 002 SUBLABEL 1, 23*/
/* DFI 3123 DUI 003 SUBLABEL 2, 23*/
/* DFI 3123 DUI 004 SUBLABEL 3, 23*/
/* DFI 3123 DUI 005 SUBLABEL 4, 23*/
/* DFI 3123 DUI 006 SUBLABEL 5, 23*/
/* DFI 3123 DUI 007 SUBLABEL 6, 23*/
/* DFI 3123 DUI 008 SUBLABEL 7, 23*/

/* DFI 3124 DUI 001 SUBLABEL 0, 24*/
/* DFI 3124 DUI 002 SUBLABEL 1, 24*/
/* DFI 3124 DUI 003 SUBLABEL 2, 24*/
/* DFI 3124 DUI 004 SUBLABEL 3, 24*/
/* DFI 3124 DUI 005 SUBLABEL 4, 24*/
/* DFI 3124 DUI 006 SUBLABEL 5, 24*/
/* DFI 3124 DUI 007 SUBLABEL 6, 24*/
/* DFI 3124 DUI 008 SUBLABEL 7, 24*/

/* DFI 3125 DUI 001 SUBLABEL 0, 25*/
/* DFI 3125 DUI 002 SUBLABEL 1, 25*/
/* DFI 3125 DUI 003 SUBLABEL 2, 25*/
/* DFI 3125 DUI 004 SUBLABEL 3, 25*/
/* DFI 3125 DUI 005 SUBLABEL 4, 25*/
/* DFI 3125 DUI 006 SUBLABEL 5, 25*/
/* DFI 3125 DUI 007 SUBLABEL 6, 25*/
/* DFI 3125 DUI 008 SUBLABEL 7, 25*/

/* DFI 3126 DUI 001 SUBLABEL 0, 26*/
/* DFI 3126 DUI 002 SUBLABEL 1, 26*/
/* DFI 3126 DUI 003 SUBLABEL 2, 26*/
/* DFI 3126 DUI 004 SUBLABEL 3, 26*/
/* DFI 3126 DUI 005 SUBLABEL 4, 26*/
/* DFI 3126 DUI 006 SUBLABEL 5, 26*/
/* DFI 3126 DUI 007 SUBLABEL 6, 26*/
/* DFI 3126 DUI 008 SUBLABEL 7, 26*/

/* DFI 3127 DUI 001 SUBLABEL 0, 27*/
/* DFI 3127 DUI 002 SUBLABEL 1, 27*/
/* DFI 3127 DUI 003 SUBLABEL 2, 27*/
/* DFI 3127 DUI 004 SUBLABEL 3, 27*/
/* DFI 3127 DUI 005 SUBLABEL 4, 27*/
/* DFI 3127 DUI 006 SUBLABEL 5, 27*/
/* DFI 3127 DUI 007 SUBLABEL 6, 27*/
/* DFI 3127 DUI 008 SUBLABEL 7, 27*/

/* DFI 3128 DUI 001 SUBLABEL 0, 28*/
/* DFI 3128 DUI 002 SUBLABEL 1, 28*/
/* DFI 3128 DUI 003 SUBLABEL 2, 28*/
/* DFI 3128 DUI 004 SUBLABEL 3, 28*/
/* DFI 3128 DUI 005 SUBLABEL 4, 28*/
/* DFI 3128 DUI 006 SUBLABEL 5, 28*/
/* DFI 3128 DUI 007 SUBLABEL 6, 28*/
/* DFI 3128 DUI 008 SUBLABEL 7, 28*/

/* DFI 3129 DUI 001 SUBLABEL 0, 29*/
/* DFI 3129 DUI 002 SUBLABEL 1, 29*/
/* DFI 3129 DUI 003 SUBLABEL 2, 29*/
/* DFI 3129 DUI 004 SUBLABEL 3, 29*/
/* DFI 3129 DUI 005 SUBLABEL 4, 29*/
/* DFI 3129 DUI 006 SUBLABEL 5, 29*/
/* DFI 3129 DUI 007 SUBLABEL 6, 29*/
/* DFI 3129 DUI 008 SUBLABEL 7, 29*/

/* DFI 3130 DUI 001 SUBLABEL 0, 30*/
/* DFI 3130 DUI 002 SUBLABEL 1, 30*/
/* DFI 3130 DUI 003 SUBLABEL 2, 30*/
/* DFI 3130 DUI 004 SUBLABEL 3, 30*/
/* DFI 3130 DUI 005 SUBLABEL 4, 30*/
/* DFI 3130 DUI 006 SUBLABEL 5, 30*/
/* DFI 3130 DUI 007 SUBLABEL 6, 30*/
/* DFI 3130 DUI 008 SUBLABEL 7, 30*/

/* DFI 3131 DUI 001 SUBLABEL 0, 31*/
/* DFI 3131 DUI 002 SUBLABEL 1, 31*/
/* DFI 3131 DUI 003 SUBLABEL 2, 31*/
/* DFI 3131 DUI 004 SUBLABEL 3, 31*/
/* DFI 3131 DUI 005 SUBLABEL 4, 31*/
/* DFI 3131 DUI 006 SUBLABEL 5, 31*/
/* DFI 3131 DUI 007 SUBLABEL 6, 31*/
/* DFI 3131 DUI 008 SUBLABEL 7, 31*/

/* DFI 3140 DUI 001 SUB-SUBLABEL 0*/
/* DFI 3140 DUI 002 SUB-SUBLABEL 1*/
/* DFI 3140 DUI 003 SUB-SUBLABEL 2*/
/* DFI 3140 DUI 004 SUB-SUBLABEL 3*/
/* DFI 3140 DUI 005 SUB-SUBLABEL 4*/
/* DFI 3140 DUI 006 SUB-SUBLABEL 5*/
/* DFI 3140 DUI 007 SUB-SUBLABEL 6*/
/* DFI 3140 DUI 008 SUB-SUBLABEL 7*/
/* DFI 3140 DUI 009 SUB-SUBLABEL 8*/
/* DFI 3140 DUI 010 SUB-SUBLABEL 9*/
/* DFI 3140 DUI 011 SUB-SUBLABEL 10*/
/* DFI 3140 DUI 012 SUB-SUBLABEL 11*/
/* DFI 3140 DUI 013 SUB-SUBLABEL 12*/
/* DFI 3140 DUI 014 SUB-SUBLABEL 13*/
/* DFI 3140 DUI 015 SUB-SUBLABEL 14*/
/* DFI 3140 DUI 016 SUB-SUBLABEL 15*/
/* DFI 3140 DUI 017 SUB-SUBLABEL 16*/
/* DFI 3140 DUI 018 SUB-SUBLABEL 17*/
/* DFI 3140 DUI 019 SUB-SUBLABEL 18*/
/* DFI 3140 DUI 020 SUB-SUBLABEL 19*/
/* DFI 3140 DUI 021 SUB-SUBLABEL 20*/
/* DFI 3140 DUI 022 SUB-SUBLABEL 21*/
/* DFI 3140 DUI 023 SUB-SUBLABEL 22*/
/* DFI 3140 DUI 024 SUB-SUBLABEL 23*/
/* DFI 3140 DUI 025 SUB-SUBLABEL 24*/
/* DFI 3140 DUI 026 SUB-SUBLABEL 25*/
/* DFI 3140 DUI 027 SUB-SUBLABEL 26*/
/* DFI 3140 DUI 028 SUB-SUBLABEL 27*/
/* DFI 3140 DUI 029 SUB-SUBLABEL 28*/
/* DFI 3140 DUI 030 SUB-SUBLABEL 29*/
/* DFI 3140 DUI 031 SUB-SUBLABEL 30*/
/* DFI 3140 DUI 032 SUB-SUBLABEL 31*/

/* DFI 3006 DUI 001 ACKNOWLEDGEMENT PROTOCOL, 1 4 bits*/
std::string AcknowledgementProtocol(std::array<int, 4> acknowledgementProtocol)
{
    // we take in the four bits and it should output one of these responses
    // Normal 0
    // illegal 1 through 2
    // undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1:
    case 2:
        output = "Illegal ///-> 0001 through 0010";
        break;
    default:
        output = "Undefined ///-> 0011 through 1111";
        break;
    }
    return output;
}

/* DFI 3006 DUI 002 ACKNOWLEDGEMENT PROTOCOL, 2 4 bits*/
std::string AcknowledgementProtocol2(std::array<int, 4> acknowledgementProtocol)
{
    // we take in the four bits and it should output one of these responses
    // Normal 0
    // Processor Ack 1
    // illegal 2
    // undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
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
    default:
        output = "Undefined ///-> 0011 through 1111";
        break;
    }
    return output;
}

/* DFI 3006 DUI 003 ACKNOWLEDGEMENT PROTOCOL, 3 4 bits*/
std::string AcknowledgementProtocol3(std::array<int, 4> acknowledgementProtocol)
{
    // we take in the four bits and it should output one of these responses
    // Normal 0
    // Processor Ack 1
    // Operator Ack 2
    // undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
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
    case 3:
        output = "Illegal ///-> 0011";
        break;
    default:
        output = "Undefined ///-> 0100 through 1111";
        break;
    }
    return output;
}

/* DFI 3006 DUI 004 ACKNOWLEDGEMENT PROTOCOL, 4 4 bits*/
std::string AcknowledgementProtocol4(std::array<int, 4> acknowledgementProtocol)
{
    // we take in the four bits and it should output one of these responses
    // illegal 0
    // Processor Ack 1
    // Illegal 2
    // undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
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
    default:
        output = "Undefined ///-> 0011 through 1111";
        break;
    }
    return output;
}

/* DFI 3006 DUI 005 ACKNOWLEDGEMENT PROTOCOL, 5 4 bits*/
std::string AcknowledgementProtocol5(std::array<int, 4> acknowledgementProtocol)
{
    // we take in the four bits and it should output one of these responses
    // Normal 0
    // Illegal 1-2
    // undefined 3-15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch (acknowledgementProtocolInt)
    {
    case 0:
        output = "Normal ///-> 0000";
        break;
    case 1:
    case 2:
        output = "Illegal ///-> 0001 through 0010";
        break;
    default:
        output = "Undefined ///-> 0011 through 1111";
        break;
    }

    return output;
}
