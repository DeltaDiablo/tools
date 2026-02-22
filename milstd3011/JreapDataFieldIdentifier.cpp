// this is the dfi (data Field Identifier) converter for MILSTD 3011D
//  This library contains all the DFIs and the related DataUseIdentifiers (DUIs) for the JREAP-C fields.

#include "jreapdatafieldidentifier.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "milstd3011/dfiset3000.h"
#include "milstd3011/dfiset3001.h"
#include "milstd3011/dfiset3002.h"
#include "milstd3011/dfiset3003.h"
#include "milstd3011/dfiset3004.h"
#include "milstd3011/dfiset3005.h"
#include "milstd3011/dfiset3006.h"
#include "milstd3011/dfiset3007.h"
#include "milstd3011/dfiset3008.h"
#include "milstd3011/dfiset3009.h"
#include "milstd3011/dfiset3010.h"
#include "milstd3011/dfiset3011.h"
#include "milstd3011/dfiset3012.h"
#include "milstd3011/dfiset3013.h"
#include "milstd3011/dfiset3014.h"
#include "milstd3011/dfiset3015.h"
#include "milstd3011/dfiset3016.h"
#include "milstd3011/dfiset3017.h"
#include "milstd3011/dfiset3018.h"
#include "milstd3011/dfiset3019.h"
#include "milstd3011/dfiset3020.h"
#include "milstd3011/dfiset3021.h"
#include "milstd3011/dfiset3022.h"
#include "milstd3011/dfiset3023.h"
#include "milstd3011/dfiset3024.h"
#include "milstd3011/dfiset3025.h"
#include "milstd3011/dfiset3027.h"
#include "milstd3011/dfiset3028.h"
#include "milstd3011/dfiset3029.h"
#include "milstd3011/dfiset3030.h"
#include "milstd3011/dfiset3031.h"
#include "milstd3011/dfiset3032.h"
#include "milstd3011/dfiset3033.h"
#include "milstd3011/dfiset3034.h"
#include "milstd3011/dfiset3035.h"
#include "milstd3011/dfiset3036.h"
#include "milstd3011/dfiset3037.h"
#include "milstd3011/dfiset3038.h"
#include "milstd3011/dfiset3039.h"
#include "milstd3011/dfiset3040.h"
#include "milstd3011/dfiset3042.h"
#include "milstd3011/dfiset3043.h"
#include "milstd3011/dfiset3044.h"
#include "milstd3011/dfiset3045.h"
#include "milstd3011/dfiset3050.h"
#include "milstd3011/dfiset3051.h"
#include "milstd3011/dfiset3052.h"
#include "milstd3011/dfiset3053.h"
#include "milstd3011/dfiset3054.h"
#include "milstd3011/dfiset3055.h"
#include "milstd3011/dfiset3056.h"
#include "milstd3011/dfiset3057.h"
#include "milstd3011/dfiset3058.h"
#include "milstd3011/dfiset3059.h"
#include "milstd3011/dfiset3060.h"
#include "milstd3011/dfiset3061.h"
#include "milstd3011/dfiset3062.h"
#include "milstd3011/dfiset3063.h"
#include "milstd3011/dfiset3064.h"
#include "milstd3011/dfiset3065.h"
#include "milstd3011/dfiset3066.h"
#include "milstd3011/dfiset3080.h"
#include "milstd3011/dfiset3081.h"
#include "milstd3011/dfiset3082.h"
#include "milstd3011/dfiset3083.h"
#include "milstd3011/dfiset3084.h"
#include "milstd3011/dfiset3085.h"
#include "milstd3011/dfiset3086.h"
#include "milstd3011/dfiset3087.h"
#include "milstd3011/dfiset3099.h"
#include "milstd3011/dfiset3100.h"
#include "milstd3011/dfiset3101.h"
#include "milstd3011/dfiset3102.h"
#include "milstd3011/dfiset3103.h"
#include "milstd3011/dfiset3104.h"
#include "milstd3011/dfiset3105.h"
#include "milstd3011/dfiset3106.h"
#include "milstd3011/dfiset3107.h"
#include "milstd3011/dfiset3108.h"
#include "milstd3011/dfiset3109.h"
#include "milstd3011/dfiset3110.h"
#include "milstd3011/dfiset3111.h"
#include "milstd3011/dfiset3112.h"
#include "milstd3011/dfiset3113.h"
#include "milstd3011/dfiset3114.h"
#include "milstd3011/dfiset3115.h"
#include "milstd3011/dfiset3116.h"
#include "milstd3011/dfiset3117.h"
#include "milstd3011/dfiset3118.h"
#include "milstd3011/dfiset3119.h"
#include "milstd3011/dfiset3120.h"
#include "milstd3011/dfiset3121.h"
#include "milstd3011/dfiset3122.h"
#include "milstd3011/dfiset3123.h"
#include "milstd3011/dfiset3124.h"
#include "milstd3011/dfiset3125.h"
#include "milstd3011/dfiset3126.h"
#include "milstd3011/dfiset3127.h"
#include "milstd3011/dfiset3128.h"
#include "milstd3011/dfiset3129.h"
#include "milstd3011/dfiset3130.h"
#include "milstd3011/dfiset3131.h"
#include "milstd3011/dfiset3140.h"

/* DFI 3000 DUI 001 PERCENT EXCEEDING LATENCY 7 bits*/
std::string Dfi3000Dui001(std::array<int, 7> percentExceedingLatency)
{   return dfi3000::dui001(percentExceedingLatency);
}

/* DFI 3001 DUI 001 TRANSMISSION SEQUENCE NUMBER 8 bits*/
std::string Dfi3001Dui001(const std::array<int, 8>& transmissionSequenceNumber)
{
       return dfi3001::dui001(transmissionSequenceNumber);
}
/* DFI 3001 DUI 002 TRANSMISSION SEQUENCE LIST COUNT 7 bits*/
std::string Dfi3001Dui002(const std::array<int, 7>& transmissionSequenceListCount)
{
    return dfi3001::dui002(transmissionSequenceListCount);
}

/* Dfi 3002 DUI 001 ADD/DELETE INDICATOR 1 bit*/
std::string Dfi3002Dui001(const std::array<int, 1>& addDeleteIndicator)
{    //use the Dfiset3002 Dui001 function to process the addDeleteIndicator array and return the output
    return dfi3002::Dui001(addDeleteIndicator);
}
/* Dfi 3002 DUI 002 ACTIVE/INACTIVE FLAG 1 bit*/
std::string Dfi3002Dui002(const std::array<int, 1>& activeInactiveFlag)
{
    //use the Dfiset3002 Dui002 function to process the activeInactiveFlag array and return the output
    return dfi3002::Dui002(activeInactiveFlag);
}
/* Dfi 3002 DUI 003 ACKNOWLEDGEMENT REQUEST FLAG 1 bit*/
std::string Dfi3002Dui003(const std::array<int, 1>& acknowledgementRequestFlag)
{
    //use the Dfiset3002 Dui003 function to process the acknowledgementRequestFlag array and return the output
    return dfi3002::Dui003(acknowledgementRequestFlag);
}
/* Dfi 3002 DUI 004 COMMAND AND CONTROL INDICATOR OVERRIDE*/
std::string Dfi3002Dui004(const std::array<int, 1>& commandAndControlIndicatorOverride)
{
    //use the Dfiset3002 Dui004 function to process the commandAndControlIndicatorOverride array and return the output
    return dfi3002::Dui004(commandAndControlIndicatorOverride);
}
/* DFI 3002 DUI 005 EMERGENCY INDICATOR OVERRIDE 1 bit*/
std::string Dfi3002Dui005(const std::array<int, 1>& emergencyIndicatorOverride)
{
    //use the dfiset3002 Dui005 function to process the emergencyIndicatorOverride array and return the output
    return dfi3002::Dui005(emergencyIndicatorOverride);
}
/* DFI 3002 DUI 006 FORCE TELL INDICATOR OVERRIDE 1 bit*/
std::string Dfi3002Dui006(const std::array<int, 1>& forceTellIndicatorOverride)
{
    //use the dfiset3002 Dui006 function to process the forceTellIndicatorOverride array and return the output
    return dfi3002::Dui006(forceTellIndicatorOverride);
}
/* DFI 3002 DUI 007 LAST POINT FLAG 1 bit 0 no last point 1 Last point*/
std::string Dfi3002Dui007(const std::array<int, 1>& lastPointFlag)
{
    //use the dfiset3002 Dui007 function to process the lastPointFlag array and return the output
    return dfi3002::Dui007(lastPointFlag);
}
/* DFI 3002 DUI 008 RECTANGLE FLAG 1 bit*/
std::string Dfi3002Dui008(const std::array<int, 1>& rectangleFlag)
{
    //use the dfiset3002 Dui008 function to process the rectangleFlag array and return the output
    return dfi3002::Dui008(rectangleFlag);
}
/* DFI 3002 DUI 009 RELAY FLAG 1 bit*/
std::string Dfi3002Dui009(const std::array<int, 1>& relayFlag)
{
    //use the dfiset3002 Dui009 function to process the relayFlag array and return the output
    return dfi3002::Dui009(relayFlag);
}
/* DFI 3002 DUI 010 SIMULATION INDICATOR FILTER FLAG 1 bit*/
std::string Dfi3002Dui010(const std::array<int, 1>& simulationIndicatorFilterFlag)
{
    //use the dfiset3002 Dui010 function to process the simulationIndicatorFilterFlag array and return the output
    return dfi3002::Dui010(simulationIndicatorFilterFlag);
}
/* DFI 3002 DUI 011 TRANSMISSION TIME REFERENCE FLAG 1 bit*/
std::string Dfi3002Dui011(const std::array<int, 1>& transmissionTimeReferenceFlag)
{
    //use the dfiset3002 Dui011 function to process the transmissionTimeReferenceFlag array and return the output
    return dfi3002::Dui011(transmissionTimeReferenceFlag);
}
/* DFI 3002 DUI 012 UPPER ALTITUDE LIMIT FLAG 1 bit*/
std::string Dfi3002Dui012(const std::array<int, 1>& upperAltitudeLimitFlag)
{
    //use the dfiset3002 Dui012 function to process the upperAltitudeLimitFlag array and return the output
    return dfi3002::Dui012(upperAltitudeLimitFlag);
}
/* DFI 3002 DUI 013 LOWER ALTITUDE LIMIT FLAG 1 bit*/
std::string Dfi3002Dui013(const std::array<int, 1>& lowerAltitudeLimitFlag)
{
    //use the dfiset3002 Dui013 function to process the lowerAltitudeLimitFlag array and return the output
    return dfi3002::Dui013(lowerAltitudeLimitFlag);
}
/* DFI 3002 DUI 014 J28.2(0) FILTER FLAG 1 bit*/
std::string Dfi3002Dui014(const std::array<int, 1>& j2820FilterFlag)
{
    //use the dfiset3002 Dui014 function to process the j2820FilterFlag array and return the output
    return dfi3002::Dui014(j2820FilterFlag);
}
/* DFI 3002 DUI 015 J28.2(X) FILTER FLAG 1 bit*/
std::string Dfi3002Dui015(const std::array<int, 1>& j28XFilterFlag)
{
    //use the dfiset3002 Dui015 function to process the j28XFilterFlag array and return the output
    return dfi3002::Dui015(j28XFilterFlag);
}
/* DFI 3002 DUI 016 SPECIAL PROCESSING INDICATOR FILTER FLAG 1 bit*/
std::string Dfi3002Dui016(const std::array<int, 1>& specialProcessingIndicatorFilterFlag)
{
    //use the dfiset3002 Dui016 function to process the specialProcessingIndicatorFilterFlag array and return the output
    return dfi3002::Dui016(specialProcessingIndicatorFilterFlag);
}
/* DFI 3002 DUI 017 TYPE FILTER 1 bit*/
std::string Dfi3002Dui017(const std::array<int, 1>& typeFilter)
{
    //use the dfiset3002 Dui017 function to process the typeFilter array and return the output
    return dfi3002::Dui017(typeFilter);
}
/* DFI 3002 DUI 018 GEOGRAPHIC FILTER 1 bit*/
std::string Dfi3002Dui018(const std::array<int, 1>& geographicFilter)
{
    //use the dfiset3002 Dui018 function to process the geographicFilter array and return the output
    return dfi3002::Dui018(geographicFilter);
}
/* DFI 3002 DUI 019 ALL FILTERS 1 bit*/
std::string Dfi3002Dui019(const std::array<int, 1>& allFilters)
{
    //use the dfiset3002 Dui019 function to process the allFilters array and return the output
    return dfi3002::Dui019(allFilters);
}
/* DFI 3002 DUI 020 ALTERNATE NETWORK CONTROLLER ASSIGNMENT FLAG 1 bit*/
std::string Dfi3002Dui020(const std::array<int, 1>& alternateNetworkControllerAssignmentFlag)
{
    //use the dfiset3002 Dui020 function to process the alternateNetworkControllerAssignmentFlag array and return the output
    return dfi3002::Dui020(alternateNetworkControllerAssignmentFlag);
}
/* DFI 3002 DUI 021 ALTERNATE NETWORK CONTROLLER ASSIGNMENT RECOGNITION 1 bit*/
std::string Dfi3002Dui021(const std::array<int, 1>& alternateNetworkControllerAssignmentRecognition)
{
    //use the dfiset3002 Dui021 function to process the alternateNetworkControllerAssignmentRecognition array and return the output
    return dfi3002::Dui021(alternateNetworkControllerAssignmentRecognition);
}

/* DFI 3003 DUI 001 AGE LIMIT VALUE 8 bits */
std::string Dfi3003Dui001(const std::array<int, 8>& ageLimitValue)
{
    return dfi3003::Dui001(ageLimitValue);
}
/* DFI 3003 DUI 002 AVERAGE RECEIVED DATA MEDIA LATENCY 16 bits*/
std::string Dfi3003Dui002(const std::array<int, 16>& averageReceivedDataMediaLatency)
{    return dfi3003::Dui002(averageReceivedDataMediaLatency);
}
/* DFI 3003 DUI 003 DATA AGE 13 bits*/
std::string Dfi3003Dui003(const std::array<int, 13>& dataAge)
{
    return dfi3003::Dui003(dataAge);
}
/* DFI 3003 DUI 004 DATA VALID TIME 28 bits*/
std::string Dfi3003Dui004(const std::array<int, 28>& dataValidTime)
{
    return dfi3003::Dui004(dataValidTime);
}
/* DFI 3003 DUI 005 EVENT TIME ACCURACY 4 bits*/
std::string Dfi3003Dui005(const std::array<int, 4>& eventTimeAccuracy)
{
    return dfi3003::Dui005(eventTimeAccuracy);
}
/* DFI 3003 DUI 007 MAXIMUM LATENCY 16 bits*/
std::string Dfi3003Dui007(const std::array<int, 16>& maximumLatency)
{
    return dfi3003::Dui007(maximumLatency);
}
/* DFI 3003 DUI 008 RX JRE RECEIVE TIME (R2) 28 bits
same as coding for JRE Transmit Time*/
std::string Dfi3003Dui008(const std::array<int, 28>& rxJreReceiveTime)
{    return dfi3003::Dui008(rxJreReceiveTime);
}
/* DFI 3003 DUI 009 TX JRE TRANSMIT TIME (T1) 28 bits*/
std::string Dfi3003Dui009(const std::array<int, 28>& txJreTransmitTime)
{
    return dfi3003::Dui009(txJreTransmitTime);
}
/* DFI 3003 DUI 010 RX JRE TRANSMIT TIME (T2) 28 bits*/
std::string Dfi3003Dui010(const std::array<int, 28>& rxJreTransmitTime)
{
    return dfi3003::Dui010(rxJreTransmitTime);
}
/* DFI 3003 DUI 011 TIME ACCURACY 4 bits*/
std::string Dfi3003Dui011(const std::array<int, 4>& timeAccuracy)
{    return dfi3003::Dui011(timeAccuracy);
}
/* DFI 3003 DUI 012 EVENT TIME 28 bits*/
std::string Dfi3003Dui012(const std::array<int, 28>& eventTime)
{
    return dfi3003::Dui012(eventTime);
}
/* DFI 3003 DUI 013 INTERVAL TIME 10 bits*/
std::string Dfi3003Dui013(const std::array<int, 10>& intervalTime)
{
    return dfi3003::Dui013(intervalTime);
}
/* DFI 3003 DUI 014 TIME ACCURACY (R2) 4 bits*/
std::string Dfi3003Dui014(const std::array<int, 4>& timeAccuracyR2)
{
    return dfi3003::Dui014(timeAccuracyR2);
}
/* DFI 3003 DUI 015 TIME ACCURACY (T1) 4 bits*/
std::string Dfi3003Dui015(const std::array<int, 4>& timeAccuracyT1)
{
    return dfi3003::Dui015(timeAccuracyT1);
}
/* DFI 3003 DUI 016 TIME ACCURACY (T2) 4 bits*/
std::string Dfi3003Dui016(const std::array<int, 4>& timeAccuracyT2)
{
    return dfi3003::Dui016(timeAccuracyT2);
}
/* DFI 3004 DUI 001 JRE NC, C 1 bit*/
std::string Dfi3004Dui001(const std::array<int, 1>& jreNcC)
{
    return dfi3004::Dui001(jreNcC);
}

/* DFI 3004 DUI 002 RTTIME, C*/
std::string Dfi3004Dui002(const std::array<int, 1>& rttimeC)
{
    return dfi3004::Dui002(rttimeC);
}
/* DFI 3004 DUI 003 FIXED DELAY, C 1 bit*/
std::string Dfi3004Dui003(const std::array<int, 1>& fixedDelayC)
{
    return dfi3004::Dui003(fixedDelayC);
}
/* DFI 3004 DUI 004 EVENT STROBE, C 1 bit*/
std::string Dfi3004Dui004(const std::array<int, 1>& eventStrobeC)
{
    return dfi3004::Dui004(eventStrobeC);
}
/* DFI 3004 DUI 005 UTC, C 1 bit*/
std::string Dfi3004Dui005(const std::array<int, 1>& utcC)
{
    return dfi3004::Dui005(utcC);
}

/* DFI 3005 DUI 001 JRE NC, P 1 bit*/
std::string Dfi3005Dui001(const std::array<int, 1>& jreNcP)
{
    return dfi3005::Dui001(jreNcP);
}
/* DFI 3005 DUI 002 RTTIME, P 1 bit*/
std::string Dfi3005Dui002(const std::array<int, 1>& rttimeP)
{
    return dfi3005::Dui002(rttimeP);
}
/* DFI 3005 DUI 003 FIXED DELAY, P 1 bit*/
std::string Dfi3005Dui003(const std::array<int, 1>& fixedDelayP)
{
    return dfi3005::Dui003(fixedDelayP);
}
/* DFI 3005 DUI 004 EVENT STROBE, P 1 bit*/
std::string Dfi3005Dui004(const std::array<int, 1>& eventStrobeP)
{
    return dfi3005::Dui004(eventStrobeP);
}
/* DFI 3005 DUI 005 UTC, P 1 bit*/
std::string Dfi3005Dui005(const std::array<int, 1>& utcP)
{
    return dfi3005::Dui005(utcP);
}

/* DFI 3006 DUI 001 ACKNOWLEDGEMENT PROTOCOL, 1 4 bits*/
std::string Dfi3006Dui001(const std::array<int, 4>& acknowledgementProtocol1)
{
    return dfi3006::Dui001(acknowledgementProtocol1);
}
/* DFI 3006 DUI 002 ACKNOWLEDGEMENT PROTOCOL, 2 4 bits*/
std::string Dfi3006Dui002(const std::array<int, 4>& acknowledgementProtocol2)
{
    return dfi3006::Dui002(acknowledgementProtocol2);
}
/* DFI 3006 DUI 003 ACKNOWLEDGEMENT PROTOCOL, 3 4 bits*/
std::string Dfi3006Dui003(const std::array<int, 4>& acknowledgementProtocol3)
{
    return dfi3006::Dui003(acknowledgementProtocol3);
}
/* DFI 3006 DUI 004 ACKNOWLEDGEMENT PROTOCOL, 4 4 bits*/
std::string Dfi3006Dui004(const std::array<int, 4>& acknowledgementProtocol4)
{
    return dfi3006::Dui004(acknowledgementProtocol4);
}
/* DFI 3006 DUI 005 ACKNOWLEDGEMENT PROTOCOL, 5 4 bits*/
std::string Dfi3006Dui005(const std::array<int, 4>& acknowledgementProtocol5)
{
    return dfi3006::Dui005(acknowledgementProtocol5);
}

/* DFI 3007 DUI 001 TRANSMISSION BLOCK HEADER TYPE 4 bits*/
std::string Dfi3007Dui001(const std::array<int, 4>& transmissionBlockHeaderType)
{
    return dfi3007::Dui001(transmissionBlockHeaderType);
}
/* DFI 3007 DUI 002 MESSAGE GROUP HEADER TYPE 2 bits*/
std::string Dfi3007Dui002(const std::array<int, 2>& messageGroupHeaderType)
{
    return dfi3007::Dui002(messageGroupHeaderType);
}
/* DFI 3007 DUI 003 HEADER TYPE 4 bits*/
std::string Dfi3007Dui003(const std::array<int, 4>& headerType)
{
    return dfi3007::Dui003(headerType);
}

/* DFI 3008 DUI 001 MESSAGE TYPE 4 bits*/
std::string Dfi3008Dui001(const std::array<int, 4>& messageType)
{
    return dfi3008::Dui001(messageType);
}   
/* DFI 3008 DUI 002 MANAGEMENT MESSAGE SUBTYPE 8 bits*/
std::string Dfi3008Dui002(const std::array<int, 8>& managementMessageSubtype)
{
    return dfi3008::Dui002(managementMessageSubtype);
}
/* DFI 3008 DUI 003 FILTER MESSAGE TYPE 8 bits*/
std::string Dfi3008Dui003(const std::array<int, 8>& filterMessageType)
{
    return dfi3008::Dui003(filterMessageType);
}
/* DFI 3008 DUI 004 REQUESTED FILTER MESSAGE TYPE 8 bits*/
std::string Dfi3008Dui004(const std::array<int, 8>& requestedFilterMessageType)
{
    return dfi3008::Dui004(requestedFilterMessageType);
}

std::string JreNcP(const std::array<int, 1>& jreNcP)
{
    return Dfi3005Dui001(jreNcP);
}

std::string RttimeP(std::array<int, 1> rttimeP)
{
    return Dfi3005Dui002(rttimeP);
}

std::string FixedDelayP(std::array<int, 1> fixedDelayP)
{
    return Dfi3005Dui003(fixedDelayP);
}

std::string EventStrobeP(std::array<int, 1> eventStrobeP)
{
    return Dfi3005Dui004(eventStrobeP);
}

std::string UtcP(std::array<int, 1> utcP)
{
    return Dfi3005Dui005(utcP);
}

std::string TransmissionBlockHeaderType(std::array<int, 4> transmissionBlockHeaderType)
{
    return Dfi3007Dui001(transmissionBlockHeaderType);
}

std::string MessageGroupHeaderType(std::array<int, 2> messageGroupHeaderType)
{
    return Dfi3007Dui002(messageGroupHeaderType);
}

std::string HeaderType(std::array<int, 4> headerType)
{
    return Dfi3007Dui003(headerType);
}

std::string MessageType(std::array<int, 4> messageType)
{
    return Dfi3008Dui001(messageType);
}

std::string ManagementMessageSubtype(std::array<int, 8> managementMessageSubtype)
{
    return Dfi3008Dui002(managementMessageSubtype);
}

std::string FilterMessageType(std::array<int, 8> filterMessageType)
{
    return Dfi3008Dui003(filterMessageType);
}

/* DFI 3009 DUI 001 GEO FILTER SUBTYPE 3 bits*/
std::string Dfi3009Dui001(const std::array<int, 3>& geoFilterSubtype)
{
    return dfi3009::Dui001(geoFilterSubtype);
}

/* DFI 3010 DUI 015 LATITUDE, 0.0013 MINUTE 23 bits*/
std::string Dfi3010Dui015(const std::array<int, 23>& latitude)
{
    return dfi3010::Dui015(latitude);
}
/* DFI 3010 DUI 018 LATITUDE, CENTER 0.0013 MINUTE 23 bits*/
std::string Dfi3010Dui018(const std::array<int, 23>& latitudeCenter)
{
    return dfi3010::Dui018(latitudeCenter);
}

/* DFI 3011 DUI 015 LONGITUDE, 0.0013 MINUTE 24 bits*/
std::string Dfi3011Dui015(const std::array<int, 24>& longitude)
{
    return dfi3011::Dui015(longitude);
}
/* DFI 3011 DUI 016 LONGITUDE, CENTER 0.0013 MINUTE 24 bits*/
std::string Dfi3011Dui016(const std::array<int, 24>& longitudeCenter)
{
    return dfi3011::Dui016(longitudeCenter);
}

/* DFI 3012 DUI 001 APPLICATION BLOCK MESSAGE LENGTH*/
std::string Dfi3012Dui001(const std::array<int, 16>& applicationBlockMessageLength)
{
    return dfi3012::Dui001(applicationBlockMessageLength);
}
/* DFI 3012 DUI 002 LENGTH OF MESSAGE*/
std::string Dfi3012Dui002(const std::array<int, 16>& lengthOfMessage)
{
    return dfi3012::Dui002(lengthOfMessage);
}
/* DFI 3012 DUI 003 MANAGEMENT MESSAGE LENGTH*/
std::string Dfi3012Dui003(const std::array<int, 16>& managementMessageLength)
{
    return dfi3012::Dui003(managementMessageLength);
}

/* DFI 3013 DUI 001 MAJOR AXIS LENGTH 12 bits*/
std::string Dfi3013Dui001(const std::array<int, 12>& majorAxisLength)
{
    return dfi3013::Dui001(majorAxisLength);
}
/* DFI 3013 DUI 002 MINOR AXIS LENGTH 12 bits*/
std::string Dfi3013Dui002(const std::array<int, 12>& minorAxisLength)
{
    return dfi3013::Dui002(minorAxisLength);
}

/* DFI 3014 DUI 001 TRANSMISSION BLOCK HEADER LENGTH 8 bits*/
std::string Dfi3014Dui001(const std::array<int, 12>& transmissionBlockHeaderLength)
{
    return dfi3014::Dui001(transmissionBlockHeaderLength);
}
/* DFI 3014 DUI 002 TRANSMISSION BLOCK HEADER LENGTH, 1 8 bits*/
std::string Dfi3014Dui002(const std::array<int, 12>& transmissionBlockHeaderLength1)
{
    return dfi3014::Dui002(transmissionBlockHeaderLength1);
}
/* DFI 3014 DUI 003 TRANSMISSION BLOCK HEADER LENGTH, 2 8 bits*/
std::string Dfi3014Dui003(const std::array<int, 12>& transmissionBlockHeaderLength2)
{
    return dfi3014::Dui003(transmissionBlockHeaderLength2);
}
/* DFI 3014 DUI 004 TRANSMISSION BLOCK HEADER LENGTH, 3 8 bits*/
std::string Dfi3014Dui004(const std::array<int, 12>& transmissionBlockHeaderLength3)
{
    return dfi3014::Dui004(transmissionBlockHeaderLength3);
}

/* DFI 3015 DUI 001 CURRENT ERROR RATE 7 bits*/
std::string Dfi3015Dui001(const std::array<int, 7>& currentErrorRate)
{
    return dfi3015::Dui001(currentErrorRate);
}
/* DFI 3015 DUI 002 JRE-NP ERROR RATE 7 bits*/
std::string Dfi3015Dui002(const std::array<int, 7>& jreNpErrorRate)
{
    return dfi3015::Dui002(jreNpErrorRate);
}
/* DFI 3015 DUI 017 JRE-NC ERROR RATE 7 bits*/
std::string Dfi3015Dui017(const std::array<int, 7>& jreNcErrorRate)
{
    return dfi3015::Dui017(jreNcErrorRate);
}
/* DFI 3015 DUI 018 ERROR RATE, CURRENT 16 bits*/
std::string Dfi3015Dui018(const std::array<int, 16>& errorRateCurrent)
{
    return dfi3015::Dui018(errorRateCurrent);
}

/* DFI 3016 DUI 001 APPLICATION DATA 32 bits*/
std::string Dfi3016Dui001(const std::array<int, 32>& applicationData)
{
    return dfi3016::Dui001(applicationData);
}
/* DFI 3016 DUI 002 DATA WORDS 10 bits*/
std::string Dfi3016Dui002(const std::array<int, 10>& dataWords)
{
    return dfi3016::Dui002(dataWords);
}
/* DFI 3016 DUI 003 TRANSPORT DATA WORD COUNT, 1 16 bits*/
std::string Dfi3016Dui003(const std::array<int, 16>& transportDataWordCount1)
{
    return dfi3016::Dui003(transportDataWordCount1);
}
/* DFI 3016 DUI 004 TRANSPORT DATA WORD COUNT, 2 16 bits*/
std::string Dfi3016Dui004(const std::array<int, 16>& transportDataWordCount2)
{
    return dfi3016::Dui004(transportDataWordCount2);
}
/* DFI 3016 DUI 005 TRANSPORT DATA WORD COUNT, 3 16 bits*/
std::string Dfi3016Dui005(const std::array<int, 16>& transportDataWordCount3)
{
    return dfi3016::Dui005(transportDataWordCount3);
}

/* DFI 3017 DUI 001 NUMBER DESTINATION ADDRESSES 8 bits*/
std::string Dfi3017Dui001(const std::array<int, 8>& numberDestinationAddresses)
{
    return dfi3017::Dui001(numberDestinationAddresses);
}
/* DFI 3017 DUI 002 NUMBER ADDRESSES THIS DESIGNATOR 8 bits*/
std::string Dfi3017Dui002(const std::array<int, 8>& numberAddressesThisDesignator)
{
    return dfi3017::Dui002(numberAddressesThisDesignator);
}
/* DFI 3017 DUI 003 NUMBER DESTINATION ADDRESSES, NON-ZERO 8 bits*/
std::string Dfi3017Dui003(const std::array<int, 8>& numberDestinationAddressesNonZero)
{
    return dfi3017::Dui003(numberDestinationAddressesNonZero);
}

/* DFI 3018 DUI 001 NUMBER OF DESIGNATORS SUPPORTED*/
std::string Dfi3018Dui001(const std::array<int, 8>& numberOfDesignatorsSupported)
{
    return dfi3018::Dui001(numberOfDesignatorsSupported);
}
/* DFI 3018 DUI 002 TOTAL NUMBER OF ACTIVE DESIGNATORS*/
std::string Dfi3018Dui002(const std::array<int, 8>& totalNumberOfActiveDesignators)
{
    return dfi3018::Dui002(totalNumberOfActiveDesignators);
}

/* DFI 3019 DUI 001 CONNECTIVITY MATRIX BIT*/
std::string Dfi3019Dui001(const std::array<int, 1>& connectivityMatrixBit)
{
    return dfi3019::Dui001(connectivityMatrixBit);
}

/* DFI 3020 DUI 001 CONTROL/RESPONSE INDICATOR, 1*/
std::string Dfi3020Dui001(const std::array<int, 8>& controlResponseIndicator1)
{
    return dfi3020::Dui001(controlResponseIndicator1);
}
/* DFI 3020 DUI 002 CONTROL/RESPONSE INDICATOR, 2*/
std::string Dfi3020Dui002(const std::array<int, 8>& controlResponseIndicator2)
{
    return dfi3020::Dui002(controlResponseIndicator2);
}
/* DFI 3020 DUI 003 CONTROL/RESPONSE INDICATOR, 3*/
std::string Dfi3020Dui003(const std::array<int, 8>& controlResponseIndicator3)
{
    return dfi3020::Dui003(controlResponseIndicator3);
}
/* DFI 3020 DUI 004 CONTROL/RESPONSE INDICATOR, 4*/
std::string Dfi3020Dui004(const std::array<int, 8>& controlResponseIndicator4)
{
    return dfi3020::Dui004(controlResponseIndicator4);
}
/* DFI 3020 DUI 005 CONTROL/RESPONSE INDICATOR, 5*/
std::string Dfi3020Dui005(const std::array<int, 8>& controlResponseIndicator5)
{
    return dfi3020::Dui005(controlResponseIndicator5);
}
/* DFI 3020 DUI 006 CONTROL/RESPONSE INDICATOR, 6*/
std::string Dfi3020Dui006(const std::array<int, 8>& controlResponseIndicator6)
{
    return dfi3020::Dui006(controlResponseIndicator6);
}
/* DFI 3020 DUI 007 CONTROL/RESPONSE INDICATOR, 7*/
std::string Dfi3020Dui007(const std::array<int, 8>& controlResponseIndicator7)
{
    return dfi3020::Dui007(controlResponseIndicator7);
}
/* DFI 3020 DUI 008 CONTROL/RESPONSE INDICATOR, 8*/
std::string Dfi3020Dui008(const std::array<int, 8>& controlResponseIndicator8)
{
    return dfi3020::Dui008(controlResponseIndicator8);
}
/* DFI 3020 DUI 009 CONTROL/RESPONSE INDICATOR, 9*/
std::string Dfi3020Dui009(const std::array<int, 8>& controlResponseIndicator9)
{
    return dfi3020::Dui009(controlResponseIndicator9);
}
/* DFI 3020 DUI 010 CONTROL/RESPONSE INDICATOR, 10*/
std::string Dfi3020Dui010(const std::array<int, 8>& controlResponseIndicator10)
{
    return dfi3020::Dui010(controlResponseIndicator10);
}
/* DFI 3020 DUI 011 CONTROL/RESPONSE INDICATOR, 11*/
std::string Dfi3020Dui011(const std::array<int, 8>& controlResponseIndicator11)
{
    return dfi3020::Dui011(controlResponseIndicator11);
}
/* DFI 3020 DUI 012 CONTROL/RESPONSE INDICATOR, 12*/
std::string Dfi3020Dui012(const std::array<int, 8>& controlResponseIndicator12)
{
    return dfi3020::Dui012(controlResponseIndicator12);
}
/* DFI 3020 DUI 013 CONTROL/RESPONSE INDICATOR, 13*/
std::string Dfi3020Dui013(const std::array<int, 8>& controlResponseIndicator13)
{
    return dfi3020::Dui013(controlResponseIndicator13);
}
/* DFI 3020 DUI 014 CONTROL/RESPONSE INDICATOR*/
std::string Dfi3020Dui014(const std::array<int, 8>& controlResponseIndicator)
{
    return dfi3020::Dui014(controlResponseIndicator);
}

/* DFI 3021 DUI 001 LINK DESIGNATOR TO FILTER*/
std::string Dfi3021Dui001(const std::array<int, 16>& linkDesignatorToFilter)
{
    return dfi3021::Dui001(linkDesignatorToFilter);
}
/* DFI 3021 DUI 002 LINK DESIGNATOR*/
std::string Dfi3021Dui002(const std::array<int, 16>& linkDesignator)
{
    return dfi3021::Dui002(linkDesignator);
}
/* DFI 3021 DUI 003 SOURCE LINK DESIGNATOR*/
std::string Dfi3021Dui003(const std::array<int, 16>& sourceLinkDesignator)
{
    return dfi3021::Dui003(sourceLinkDesignator);
}
/* DFI 3021 DUI 004 TRANSMIT LINK DESIGNATOR*/
std::string Dfi3021Dui004(const std::array<int, 16>& transmitLinkDesignator)
{
    return dfi3021::Dui004(transmitLinkDesignator);
}

/* DFI 3022 DUI 001 EVENT TYPE 5 bits*/
std::string Dfi3022Dui001(const std::array<int, 5>& eventType)
{
    return dfi3022::Dui001(eventType);
}

/* DFI 3023 DUI 001 APPLICATION PROTOCOL VERSION*/
std::string Dfi3023Dui001(const std::array<int, 4>& applicationProtocolVersion)
{
    return dfi3023::Dui001(applicationProtocolVersion);
}

/* DFI 3024 DUI 001 ASCII*/
std::string Dfi3024Dui001(const std::array<int, 8>& asciiCharacters)
{
    return dfi3024::Dui001(asciiCharacters);
}

/* DFI 3025 DUI 001 CONTROLLER MODE NP*/
std::string Dfi3025Dui001(const std::array<int, 2>& controllerModeNp)
{
    return dfi3025::Dui001(controllerModeNp);
}
/* DFI 3025 DUI 002 CONTROLLER MODE NC*/
std::string Dfi3025Dui002(const std::array<int, 2>& controllerModeNc)
{
    return dfi3025::Dui002(controllerModeNc);
}

/* DFI 3027 DUI 001 SOURCE TRACK NUMBER*/
std::string Dfi3027Dui001(const std::array<int, 15>& sourceTrackNumber)
{
    return dfi3027::Dui001(sourceTrackNumber);
}
/* DFI 3027 DUI 002 SECONDARY TRACK NUMBER*/
std::string Dfi3027Dui002(const std::array<int, 15>& secondaryTrackNumber)
{
    return dfi3027::Dui002(secondaryTrackNumber);
}
/* DFI 3027 DUI 003 JRE SOURCE TRACK NUMBER*/
std::string Dfi3027Dui003(const std::array<int, 16>& jreSourceTrackNumber)
{
    return dfi3027::Dui003(jreSourceTrackNumber);
}

/* DFI 3028 DUI 001 JREAP J-SERIES MESSAGE WORD, 1*/
std::string Dfi3028Dui001(const std::array<int, 16>& jreapJSeriesMessageWord1)
{
    return dfi3028::Dui001(jreapJSeriesMessageWord1);
}
/* DFI 3028 DUI 002 JREAP J-SERIES MESSAGE WORD, 2*/
std::string Dfi3028Dui002(const std::array<int, 16>& jreapJSeriesMessageWord2)
{
    return dfi3028::Dui002(jreapJSeriesMessageWord2);
}
/* DFI 3028 DUI 003 JREAP J-SERIES MESSAGE WORD, 3*/
std::string Dfi3028Dui003(const std::array<int, 16>& jreapJSeriesMessageWord3)
{
    return dfi3028::Dui003(jreapJSeriesMessageWord3);
}
/* DFI 3028 DUI 004 JREAP J-SERIES MESSAGE WORD, 4*/
std::string Dfi3028Dui004(const std::array<int, 16>& jreapJSeriesMessageWord4)
{
    return dfi3028::Dui004(jreapJSeriesMessageWord4);
}
/* DFI 3028 DUI 005 JREAP J-SERIES MESSAGE WORD, 5*/
std::string Dfi3028Dui005(const std::array<int, 6>& jreapJSeriesMessageWord5)
{
    return dfi3028::Dui005(jreapJSeriesMessageWord5);
}

/* DFI 3029 DUI 001 COMPLETION TIMEOUT 8 bits*/
std::string Dfi3029Dui001(const std::array<int, 8>& completionTimeout)
{
    return dfi3029::Dui001(completionTimeout);
}

/* DFI 3030 DUI 001 JREAP/JTIDS FREE TEXT, 1 16 bits*/
std::string Dfi3030Dui001(const std::array<int, 16>& jreapJtidsFreeText1)
{
    return dfi3030::Dui001(jreapJtidsFreeText1);
}
/* DFI 3030 DUI 002 JREAP/JTIDS FREE TEXT, 2 16 bits*/
std::string Dfi3030Dui002(const std::array<int, 16>& jreapJtidsFreeText2)
{
    return dfi3030::Dui002(jreapJtidsFreeText2);
}
/* DFI 3030 DUI 003 JREAP/JTIDS FREE TEXT, 3 16 bits*/
std::string Dfi3030Dui003(const std::array<int, 16>& jreapJtidsFreeText3)
{
    return dfi3030::Dui003(jreapJtidsFreeText3);
}
/* DFI 3030 DUI 004 JREAP/JTIDS FREE TEXT, 4 16 bits*/
std::string Dfi3030Dui004(const std::array<int, 16>& jreapJtidsFreeText4)
{
    return dfi3030::Dui004(jreapJtidsFreeText4);
}
/* DFI 3030 DUI 005 JREAP/JTIDS FREE TEXT, 5 16 bits*/
std::string Dfi3030Dui005(const std::array<int, 16>& jreapJtidsFreeText5)
{
    return dfi3030::Dui005(jreapJtidsFreeText5);
}
/* DFI 3030 DUI 006 JREAP/JTIDS FREE TEXT, 6 16 bits*/
std::string Dfi3030Dui006(const std::array<int, 16>& jreapJtidsFreeText6)
{
    return dfi3030::Dui006(jreapJtidsFreeText6);
}
/* DFI 3030 DUI 007 JREAP/JTIDS FREE TEXT, 7 16 bits*/
std::string Dfi3030Dui007(const std::array<int, 16>& jreapJtidsFreeText7)
{
    return dfi3030::Dui007(jreapJtidsFreeText7);
}
/* DFI 3030 DUI 008 JREAP/JTIDS FREE TEXT, 8 16 bits*/
std::string Dfi3030Dui008(const std::array<int, 16>& jreapJtidsFreeText8)
{
    return dfi3030::Dui008(jreapJtidsFreeText8);
}
/* DFI 3030 DUI 009 JREAP/JTIDS FREE TEXT, 9 16 bits*/
std::string Dfi3030Dui009(const std::array<int, 16>& jreapJtidsFreeText9)
{
    return dfi3030::Dui009(jreapJtidsFreeText9);
}
/* DFI 3030 DUI 010 JREAP/JTIDS FREE TEXT, 10 16 bits*/
std::string Dfi3030Dui010(const std::array<int, 16>& jreapJtidsFreeText10)
{
    return dfi3030::Dui010(jreapJtidsFreeText10);
}
/* DFI 3030 DUI 011 JREAP/JTIDS FREE TEXT, 11 16 bits*/
std::string Dfi3030Dui011(const std::array<int, 16>& jreapJtidsFreeText11)
{
    return dfi3030::Dui011(jreapJtidsFreeText11);
}
/* DFI 3030 DUI 012 JREAP/JTIDS FREE TEXT, 12 16 bits*/
std::string Dfi3030Dui012(const std::array<int, 16>& jreapJtidsFreeText12)
{
    return dfi3030::Dui012(jreapJtidsFreeText12);
}
/* DFI 3030 DUI 013 JREAP/JTIDS FREE TEXT, 13 16 bits*/
std::string Dfi3030Dui013(const std::array<int, 16>& jreapJtidsFreeText13)
{
    return dfi3030::Dui013(jreapJtidsFreeText13);
}
/* DFI 3030 DUI 014 JREAP/JTIDS FREE TEXT, 14 16 bits*/
std::string Dfi3030Dui014(const std::array<int, 16>& jreapJtidsFreeText14)
{
    return dfi3030::Dui014(jreapJtidsFreeText14);
}
/* DFI 3030 DUI 015 JREAP/JTIDS FREE TEXT, 15 16 bits*/
std::string Dfi3030Dui015(const std::array<int, 16>& jreapJtidsFreeText15)
{
    return dfi3030::Dui015(jreapJtidsFreeText15);
}
/* DFI 3030 DUI 016 JREAP/JTIDS FREE TEXT, 16 16 bits*/
std::string Dfi3030Dui016(const std::array<int, 16>& jreapJtidsFreeText16)
{
    return dfi3030::Dui016(jreapJtidsFreeText16);
}
/* DFI 3030 DUI 017 JREAP/JTIDS FREE TEXT, 17 16 bits*/
std::string Dfi3030Dui017(const std::array<int, 16>& jreapJtidsFreeText17)
{
    return dfi3030::Dui017(jreapJtidsFreeText17);
}
/* DFI 3030 DUI 018 JREAP/JTIDS FREE TEXT, 18 16 bits*/
std::string Dfi3030Dui018(const std::array<int, 16>& jreapJtidsFreeText18)
{
    return dfi3030::Dui018(jreapJtidsFreeText18);
}
/* DFI 3030 DUI 019 JREAP/JTIDS FREE TEXT, 19 16 bits*/
std::string Dfi3030Dui019(const std::array<int, 16>& jreapJtidsFreeText19)
{
    return dfi3030::Dui019(jreapJtidsFreeText19);
}
/* DFI 3030 DUI 020 JREAP/JTIDS FREE TEXT, 20 16 bits*/
std::string Dfi3030Dui020(const std::array<int, 16>& jreapJtidsFreeText20)
{
    return dfi3030::Dui020(jreapJtidsFreeText20);
}
/* DFI 3030 DUI 021 JREAP/JTIDS FREE TEXT, 21 16 bits*/
std::string Dfi3030Dui021(const std::array<int, 16>& jreapJtidsFreeText21)
{
    return dfi3030::Dui021(jreapJtidsFreeText21);
}
/* DFI 3030 DUI 022 JREAP/JTIDS FREE TEXT, 22 16 bits*/
std::string Dfi3030Dui022(const std::array<int, 16>& jreapJtidsFreeText22)
{
    return dfi3030::Dui022(jreapJtidsFreeText22);
}
/* DFI 3030 DUI 023 JREAP/JTIDS FREE TEXT, 23 16 bits*/
std::string Dfi3030Dui023(const std::array<int, 16>& jreapJtidsFreeText23)
{
    return dfi3030::Dui023(jreapJtidsFreeText23);
}
/* DFI 3030 DUI 024 JREAP/JTIDS FREE TEXT, 24 16 bits*/
std::string Dfi3030Dui024(const std::array<int, 16>& jreapJtidsFreeText24)
{
    return dfi3030::Dui024(jreapJtidsFreeText24);
}
/* DFI 3030 DUI 025 JREAP/JTIDS FREE TEXT, 25 16 bits*/
std::string Dfi3030Dui025(const std::array<int, 16>& jreapJtidsFreeText25)
{
    return dfi3030::Dui025(jreapJtidsFreeText25);
}
/* DFI 3030 DUI 026 JREAP/JTIDS FREE TEXT, 26 16 bits*/
std::string Dfi3030Dui026(const std::array<int, 16>& jreapJtidsFreeText26)
{
    return dfi3030::Dui026(jreapJtidsFreeText26);
}
/* DFI 3030 DUI 027 JREAP/JTIDS FREE TEXT, 27 16 bits*/
std::string Dfi3030Dui027(const std::array<int, 16>& jreapJtidsFreeText27)
{
    return dfi3030::Dui027(jreapJtidsFreeText27);
}
/* DFI 3030 DUI 028 JREAP/JTIDS FREE TEXT, 28 16 bits*/
std::string Dfi3030Dui028(const std::array<int, 16>& jreapJtidsFreeText28)
{
    return dfi3030::Dui028(jreapJtidsFreeText28);
}
/* DFI 3030 DUI 029 JREAP/JTIDS FREE TEXT, 29 16 bits*/
std::string Dfi3030Dui029(const std::array<int, 16>& jreapJtidsFreeText29)
{
    return dfi3030::Dui029(jreapJtidsFreeText29);
}
/* DFI 3030 DUI 030 JREAP/JTIDS FREE TEXT, 30 16 bits*/
std::string Dfi3030Dui030(const std::array<int, 16>& jreapJtidsFreeText30)
{
    return dfi3030::Dui030(jreapJtidsFreeText30);
}

/* DFI 3031 DUI 001 GEOGRAPHIC FILTER INDEX 5 bits*/
std::string Dfi3031Dui001(const std::array<int, 5>& geographicFilterIndex)
{
    return dfi3031::Dui001(geographicFilterIndex);
}

/*DFI 3032 SEQUENCE NUMBER*/
/* DFI 3032 DUI 001 MESSAGE SEQUENCE NUMBER*/
std::string Dfi3032Dui001(const std::array<int, 16>& messageSequenceNumber)
{
    return dfi3032::Dui001(messageSequenceNumber);
}
/* DFI 3032 DUI 002 ORIGINATING MESSAGE SEQUENCE NUMBER*/
std::string Dfi3032Dui002(const std::array<int, 16>& originatingMessageSequenceNumber)
{
    return dfi3032::Dui002(originatingMessageSequenceNumber);
}
/* DFI 3032 DUI 003 J-SERIES MESSAGE SEQUENCE NUMBER*/
std::string Dfi3032Dui003(const std::array<int, 16>& jSeriesMessageSequenceNumber)
{
    return dfi3032::Dui003(jSeriesMessageSequenceNumber);
}
/* DFI 3032 DUI 004 ORIGINATING J-SERIES MESSAGE SEQUENCE NUMBER*/
std::string Dfi3032Dui004(const std::array<int, 16>& originatingJSeriesMessageSequenceNumber)
{
    return dfi3032::Dui004(originatingJSeriesMessageSequenceNumber);
}
/* DFI 3032 DUI 005 NETWORK PARTICIPATION GROUP*/
std::string Dfi3032Dui005(const std::array<int, 16>& networkParticipationGroup)
{
    return dfi3032::Dui005(networkParticipationGroup);
}

/* DFI 3033 Number*/
/* DFI 3033 Number DUI 001 COUNT*/
std::string Dfi3033Dui001(const std::array<int, 8>& count)
{
    return dfi3033::Dui001(count);
}
/* DFI 3033 DUI 002 FRAGMENT NUMBER*/
std::string Dfi3033Dui002(const std::array<int, 8>& fragmentNumber)
{
    return dfi3033::Dui002(fragmentNumber);
}
/* DFI 3033 DUI 003 TOTAL NUMBER FRAGMENTS*/
std::string Dfi3033Dui003(const std::array<int, 8>& totalNumberFragments)
{
    return dfi3033::Dui003(totalNumberFragments);
}
/* DFI 3033 DUI 004 NUMBER OF BLOCKS*/
std::string Dfi3033Dui004(const std::array<int, 7>& numberOfBlocks)
{
    return dfi3033::Dui004(numberOfBlocks);
}
/* DFI 3033 DUI 005 NUMBER OF J-WORDS*/
std::string Dfi3033Dui005(const std::array<int, 12>& numberOfJWords)
{
    return dfi3033::Dui005(numberOfJWords);
}

/*DFI 3034 ERROR*/
/* DFI 3034 DUI 001 ERROR CODE, 1 8 bits*/
std::string Dfi3034Dui001(const std::array<int, 8>& errorCode1)
{
    return dfi3034::Dui001(errorCode1);
}
/* DFI 3034 DUI 002 ERROR CODE, 2 8 bits*/
std::string Dfi3034Dui002(const std::array<int, 8>& errorCode2)
{
    return dfi3034::Dui002(errorCode2);
}
/* DFI 3034 DUI 003 ERROR CODE, 3 8 bits*/
std::string Dfi3034Dui003(const std::array<int, 8>& errorCode3)
{
    return dfi3034::Dui003(errorCode3);
}
/* DFI 3034 DUI 004 ERROR CODE, 4 8 bits*/
std::string Dfi3034Dui004(const std::array<int, 8>& errorCode4)
{
    return dfi3034::Dui004(errorCode4);
}
/* DFI 3034 DUI 005 ERROR CODE, 5 8 bits*/
std::string Dfi3034Dui005(const std::array<int, 8>& errorCode5)
{
    return dfi3034::Dui005(errorCode5);
}
/* DFI 3034 DUI 006 ERROR CODE, 6 8 bits*/
std::string Dfi3034Dui006(const std::array<int, 8>& errorCode6)
{
    return dfi3034::Dui006(errorCode6);
}
/* DFI 3034 DUI 007 ERROR CODE, 7 8 bits*/
std::string Dfi3034Dui007(const std::array<int, 8>& errorCode7)
{
    return dfi3034::Dui007(errorCode7);
}

/* Transmit Limit*/
/* DFI 3035 DUI 001 JRE-NP TRANSMIT LIMIT*/
std::string Dfi3035Dui001(const std::array<int, 4>& jreNpTransmitLimit)
{
    return dfi3035::Dui001(jreNpTransmitLimit);
}

/* DFI 3036 DUI 001 JRE SENDER ID*/
std::string Dfi3036Dui001(const std::array<int, 16>& jreSenderId)
{
    return dfi3036::Dfi3036Dui001(jreSenderId);
}
/* DFI 3036 DUI 002 JRE SENDER ID, 1 16 bits*/
std::string Dfi3036Dui002(const std::array<int, 16>& jreSenderId1)
{
    return dfi3036::Dfi3036Dui002(jreSenderId1);
}
/* DFI 3036 DUI 003 JRE SENDER ID, 2 16 bits*/
std::string Dfi3036Dui003(const std::array<int, 16>& jreSenderId2)
{
    return dfi3036::Dfi3036Dui003(jreSenderId2);
}
/* DFI 3036 DUI 004 JRE SENDER ID, 3 16 bits*/
std::string Dfi3036Dui004(const std::array<int, 16>& jreSenderId3)
{
    return dfi3036::Dfi3036Dui004(jreSenderId3);
}
/* DFI 3036 DUI 005 JRE NETWORK PARTICIPANT 16 bits*/
std::string Dfi3036Dui005(const std::array<int, 16>& jreNetworkParticipant)
{
    return dfi3036::Dfi3036Dui005(jreNetworkParticipant);
}
/* DFI 3036 DUI 020 DESTINATION ADDRESS 16 bits*/
std::string Dfi3036Dui020(const std::array<int, 16>& destinationAddress)
{
    return dfi3036::Dfi3036Dui020(destinationAddress);
}
/* DFI 3036 DUI 021 ORIGINATING J-SERIES JRE SENDER ID 16 bits*/
std::string Dfi3036Dui021(const std::array<int, 16>& originatingJSeriesJreSenderId)
{
    return dfi3036::Dfi3036Dui021(originatingJSeriesJreSenderId);
}
/* DFI 3036 DUI 022 LINK INTERFACE UNIT 16 bits*/
std::string Dfi3036Dui022(const std::array<int, 16>& linkInterfaceUnit)
{
    return dfi3036::Dfi3036Dui022(linkInterfaceUnit);
}

/*LABEL*/
/* DFI 3037 DUI 001 LABEL, J-SERIES*/
std::string Dfi3037Dui001(const std::array<int, 5>& labelJSeries)
{
    return dfi3037::Dui001(labelJSeries);
}

/*SUBLABEL*/
/* DFI 3038 DUI 001 SUBLABEL, J-SERIES*/
std::string Dfi3038Dui001(const std::array<int, 3>& sublabelJSeries){
    return dfi3038::Dui001(sublabelJSeries);
}

/*CRC*/
/* DFI 3039 DUI 001 MESSAGE GROUP HEADER CRC*/
std::string Dfi3039Dui001(const std::array<int, 16>& messageGroupHeaderCrc)
{
    return dfi3039::Dui001(messageGroupHeaderCrc);
}
/* DFI 3039 DUI 002 TRANSMISSION BLOCK HEADER CRC*/
std::string Dfi3039Dui002(const std::array<int, 16>& transmissionBlockHeaderCrc)
{
    return dfi3039::Dui002(transmissionBlockHeaderCrc);
}

/*ParticipationGroup*/
/* DFI 3040 DUI 001 JTIDS/MIDS PARTICIPATION GROUP*/
std::string Dfi3040Dui001(const std::array<int, 9>& jtidsMidsParticipationGroup)
{
    return dfi3040::Dui001(jtidsMidsParticipationGroup);
}
/* DFI 3040 DUI 002 NETWORK PARTICIPATION GROUP*/
std::string Dfi3040Dui002(const std::array<int, 9>& networkParticipationGroup)
{
    return dfi3040::Dui002(networkParticipationGroup);
}
/* DFI 3040 DUI 003 NETWORK PARTICIPATION GROUP TO FILTER*/
std::string Dfi3040Dui003(const std::array<int, 9>& networkParticipationGroupToFilter)
{
    return dfi3040::Dui003(networkParticipationGroupToFilter);
}

/*ALtitudeHeight*/
/* DFI 3042 DUI 001 LOWER ALTITUDE LIMIT 13 bits */
std::string Dfi3042Dui001(const std::array<int, 13>& lowerAltitudeLimit)
{
    return dfi3042::Dui001(lowerAltitudeLimit);
}
/* DFI 3042 DUI 002 UPPER ALTITUDE LIMIT 13 bits */
std::string Dfi3042Dui002(const std::array<int, 13>& upperAltitudeLimit)
{
    return dfi3042::Dui002(upperAltitudeLimit);
}

/*AxisOrientation*/
/* DFI 3043 DUI 001 MAJOR AXIS ORIENTATION*/
std::string Dfi3043Dui001(const std::array<int, 8>& majorAxisOrientation)
{
    return dfi3043::Dui001(majorAxisOrientation);
}

/*Version*/
/* DFI 3044 DUI 001 MANAGEMENT VERSION 4 bits*/
std::string Dfi3044Dui001(const std::array<int, 4>& managementVersion)
{
    return dfi3044::Dfi3044Dui001(managementVersion);
}

/* DFI 3045 DUI 001 START OF TRANSMISSION FLAG, 1*/
std::string Dfi3045Dui001(const std::array<int, 8>& startOfTransmissionFlag1)
{
    return dfi3045::Dui001(startOfTransmissionFlag1);
}
/* DFI 3045 DUI 002 START OF TRANSMISSION FLAG, 2*/
std::string Dfi3045Dui002(const std::array<int, 8>& startOfTransmissionFlag2)
{
    return dfi3045::Dui002(startOfTransmissionFlag2);
}

/*TransmissionFlag*/
/* DFI 3050 DUI 001 NO STATEMENT*/
std::string Dfi3050Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3050::Dui001(noStatement);
}
/* DFI 3050 DUI 002 NAVIGATION*/
std::string Dfi3050Dui002(const std::array<int, 1>& navigation)
{
    return dfi3050::Dui002(navigation);
}
/* DFI 3050 DUI 003 MINE*/
std::string Dfi3050Dui003(const std::array<int, 1>& mine)
{
    return dfi3050::Dui003(mine);
}
/* DFI 3050 DUI 004 IMPACT POINT*/
std::string Dfi3050Dui004(const std::array<int, 1>& impactPoint)
{
    return dfi3050::Dui004(impactPoint);
}
/* DFI 3050 DUI 005 GROUND ZERO*/
std::string Dfi3050Dui005(const std::array<int, 1>& groundZero)
{
    return dfi3050::Dui005(groundZero);
}
/* DFI 3050 DUI 006 AIM/WEAPON ENTRY POINT*/
std::string Dfi3050Dui006(const std::array<int, 1>& aimWeaponEntryPoint)
{
    return dfi3050::Dui006(aimWeaponEntryPoint);
}
/* DFI 3050 DUI 007 MISSILE LAUNCH POINT*/
std::string Dfi3050Dui007(const std::array<int, 1>& missileLaunchPoint)
{
    return dfi3050::Dui007(missileLaunchPoint);
}
/* DFI 3050 DUI 008 ELECTRONIC ATTACK (EA) DECOY*/
std::string Dfi3050Dui008(const std::array<int, 1>& electronicAttackDecoy)
{
    return dfi3050::Dui008(electronicAttackDecoy);
}
/* DFI 3050 DUI 009 ENGAGEMENT POINT*/
std::string Dfi3050Dui009(const std::array<int, 1>& engagementPoint)
{
    return dfi3050::Dui009(engagementPoint);
}
/* DFI 3050 DUI 010 OIL RIG*/
std::string Dfi3050Dui010(const std::array<int, 1>& oilRig)
{
    return dfi3050::Dui010(oilRig);
}
/* DFI 3050 DUI 011 PT0, AMP10*/
std::string Dfi3050Dui011(const std::array<int, 1>& pt0Amp10)
{
    return dfi3050::Dui011(pt0Amp10);
}
/* DFI 3050 DUI 012 PT0, AMP11*/
std::string Dfi3050Dui012(const std::array<int, 1>& pt0Amp11)
{
    return dfi3050::Dui012(pt0Amp11);
}
/* DFI 3050 DUI 013 PT0, AMP12*/
std::string Dfi3050Dui013(const std::array<int, 1>& pt0Amp12)
{
    return dfi3050::Dui013(pt0Amp12);
}
/* DFI 3050 DUI 014 PT0, AMP13*/
std::string Dfi3050Dui014(const std::array<int, 1>& pt0Amp13)
{
    return dfi3050::Dui014(pt0Amp13);
}
/* DFI 3050 DUI 015 PT0, AMP14*/
std::string Dfi3050Dui015(const std::array<int, 1>& pt0Amp14)
{
    return dfi3050::Dui015(pt0Amp14);
}
/* DFI 3050 DUI 016 PT0, AMP15*/
std::string Dfi3050Dui016(const std::array<int, 1>& pt0Amp15)
{
    return dfi3050::Dui016(pt0Amp15);
}

/* DFI 3051 DUI 001 NO STATEMENT*/
std::string Dfi3051Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3051::Dui001(noStatement);
}
/* DFI 3051 DUI 002 MARSHALL POINT*/
std::string Dfi3051Dui002(const std::array<int, 1>& marshallPoint)
{
    return dfi3051::Dui002(marshallPoint);
}
/* DFI 3051 DUI 003 WAYPOINT*/
std::string Dfi3051Dui003(const std::array<int, 1>& waypoint)
{
    return dfi3051::Dui003(waypoint);
}
/* DFI 3051 DUI 004 CORRIDOR TAB*/
std::string Dfi3051Dui004(const std::array<int, 1>& corridorTab)
{
    return dfi3051::Dui004(corridorTab);
}
/* DFI 3051 DUI 005 POSITION AND INTENDED MOVEMENT (PIM)*/
std::string Dfi3051Dui005(const std::array<int, 1>& positionAndIntendedMovement)
{
    return dfi3051::Dui005(positionAndIntendedMovement);
}
/* DFI 3051 DUI 006 DISPOSITION CENTER*/
std::string Dfi3051Dui006(const std::array<int, 1>& dispositionCenter)
{
    return dfi3051::Dui006(dispositionCenter);
}
/* DFI 3051 DUI 007 FORMATION CENTER*/
std::string Dfi3051Dui007(const std::array<int, 1>& formationCenter)
{
    return dfi3051::Dui007(formationCenter);
}
/* DFI 3051 DUI 008 SEARCH AREA*/
std::string Dfi3051Dui008(const std::array<int, 1>& searchArea)
{
    return dfi3051::Dui008(searchArea);
}
/* DFI 3051 DUI 009 VICTOR LIMA (VL)*/
std::string Dfi3051Dui009(const std::array<int, 1>& victorLima)
{
    return dfi3051::Dui009(victorLima);
}
/* DFI 3051 DUI 010 SUBMARINE POSITION AND INTENDED MOVEMENT (SIM)*/
std::string Dfi3051Dui010(const std::array<int, 1>& submarinePositionAndIntendedMovement)
{
    return dfi3051::Dui010(submarinePositionAndIntendedMovement);
}
/* DFI 3051 DUI 011 PT1, AMP10*/
std::string Dfi3051Dui011(const std::array<int, 1>& pt1Amp10)
{
    return dfi3051::Dui011(pt1Amp10);
}
/* DFI 3051 DUI 012 DEFENDED ASSET*/
std::string Dfi3051Dui012(const std::array<int, 1>& defendedAsset)
{
    return dfi3051::Dui012(defendedAsset);
}
/* DFI 3051 DUI 013 PT1, AMP12*/
std::string Dfi3051Dui013(const std::array<int, 1>& pt1Amp12)
{
    return dfi3051::Dui013(pt1Amp12);
}
/* DFI 3051 DUI 014 PT1, AMP13*/
std::string Dfi3051Dui014(const std::array<int, 1>& pt1Amp13)
{
    return dfi3051::Dui014(pt1Amp13);
}
/* DFI 3051 DUI 015 PT1, AMP14*/
std::string Dfi3051Dui015(const std::array<int, 1>& pt1Amp14)
{
    return dfi3051::Dui015(pt1Amp14);
}
/* DFI 3051 DUI 016 PT1, AMP15*/
std::string Dfi3051Dui016(const std::array<int, 1>& pt1Amp15)
{
    return dfi3051::Dui016(pt1Amp15);
}

/* DFI 3052 DUI 001 NO STATEMENT*/
std::string Dfi3052Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3052::Dui001(noStatement);
}
/* DFI 3052 DUI 002 TOMCAT*/
std::string Dfi3052Dui002(const std::array<int, 1>& tomcat)
{
    return dfi3052::Dui002(tomcat);
}
/* DFI 3052 DUI 003 PICKET*/
std::string Dfi3052Dui003(const std::array<int, 1>& picket)
{
    return dfi3052::Dui003(picket);
}
/* DFI 3052 DUI 004 RENDEZVOUS*/
std::string Dfi3052Dui004(const std::array<int, 1>& rendezvous)
{
    return dfi3052::Dui004(rendezvous);
}
/* DFI 3052 DUI 005 PT2, AMP4*/
std::string Dfi3052Dui005(const std::array<int, 1>& pt2Amp4)
{
    return dfi3052::Dui005(pt2Amp4);
}
/* DFI 3052 DUI 006 REPLENISHMENT*/
std::string Dfi3052Dui006(const std::array<int, 1>& replenishment)
{
    return dfi3052::Dui006(replenishment);
}
/* DFI 3052 DUI 007 RESCUE*/
std::string Dfi3052Dui007(const std::array<int, 1>& rescue)
{
    return dfi3052::Dui007(rescue);
}
/* DFI 3052 DUI 008 PT2, AMP7*/
std::string Dfi3052Dui008(const std::array<int, 1>& pt2Amp7)
{
    return dfi3052::Dui008(pt2Amp7);
}
/* DFI 3052 DUI 009 PT2, AMP8*/
std::string Dfi3052Dui009(const std::array<int, 1>& pt2Amp8)
{
    return dfi3052::Dui009(pt2Amp8);
}
/* DFI 3052 DUI 010 PT2, AMP9*/
std::string Dfi3052Dui010(const std::array<int, 1>& pt2Amp9)
{
    return dfi3052::Dui010(pt2Amp9);
}
/* DFI 3052 DUI 011 PT2, AMP10*/
std::string Dfi3052Dui011(const std::array<int, 1>& pt2Amp10)
{
    return dfi3052::Dui011(pt2Amp10);
}
/* DFI 3052 DUI 012 PT2, AMP11*/
std::string Dfi3052Dui012(const std::array<int, 1>& pt2Amp11)
{
    return dfi3052::Dui012(pt2Amp11);
}
/* DFI 3052 DUI 013 PT2, AMP12*/
std::string Dfi3052Dui013(const std::array<int, 1>& pt2Amp12)
{
    return dfi3052::Dui013(pt2Amp12);
}
/* DFI 3052 DUI 014 PT2, AMP13*/
std::string Dfi3052Dui014(const std::array<int, 1>& pt2Amp13)
{
    return dfi3052::Dui014(pt2Amp13);
}
/* DFI 3052 DUI 015 PT2, AMP14*/
std::string Dfi3052Dui015(const std::array<int, 1>& pt2Amp14)
{
    return dfi3052::Dui015(pt2Amp14);
}
/* DFI 3052 DUI 016 PT2, AMP15*/
std::string Dfi3052Dui016(const std::array<int, 1>& pt2Amp15)
{
    return dfi3052::Dui016(pt2Amp15);
}

/*StationToAirPointType*/
/* DFI 3053 DUI 001 NO STATEMENT*/
std::string Dfi3053Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3053::Dui001(noStatement);
}
/* DFI 3053 DUI 002 COMBAT AIR PATROL (CAP)*/
std::string Dfi3053Dui002(const std::array<int, 1>& combatAirPatrol)
{
    return dfi3053::Dui002(combatAirPatrol);
}
/* DFI 3053 DUI 003 AIRBORNE EARLY WARNING (AEW)*/
std::string Dfi3053Dui003(const std::array<int, 1>& airborneEarlyWarning)
{
    return dfi3053::Dui003(airborneEarlyWarning);
}
/* DFI 3053 DUI 004 ANTISUBMARINE WARFARE (ASW)FIXED WING*/
std::string Dfi3053Dui004(const std::array<int, 1>& antisubmarineWarfareFixedWing)
{
    return dfi3053::Dui004(antisubmarineWarfareFixedWing);
}
/* DFI 3053 DUI 005 ANTISUBMARINE WARFARE (ASW)HELICOPTER (HELO)*/
std::string Dfi3053Dui005(const std::array<int, 1>& antisubmarineWarfareHelicopter)
{
    return dfi3053::Dui005(antisubmarineWarfareHelicopter);
}
/* DFI 3053 DUI 006 REPLENISHMENT*/
std::string Dfi3053Dui006(const std::array<int, 1>& replenishment)
{
    return dfi3053::Dui006(replenishment);
}
/* DFI 3053 DUI 007 STRIKE INITIAL POINT (IP)*/
std::string Dfi3053Dui007(const std::array<int, 1>& strikeInitialPoint)
{
    return dfi3053::Dui007(strikeInitialPoint);
}
/* DFI 3053 DUI 008 TACAN*/
std::string Dfi3053Dui008(const std::array<int, 1>& tacan)
{
    return dfi3053::Dui008(tacan);
}
/* DFI 3053 DUI 009 TANKER*/
std::string Dfi3053Dui009(const std::array<int, 1>& tanker)
{
    return dfi3053::Dui009(tanker);
}
/* DFI 3053 DUI 010 ORBIT, RACE TRACK*/
std::string Dfi3053Dui010(const std::array<int, 1>& orbitRaceTrack)
{
    return dfi3053::Dui010(orbitRaceTrack);
}
/* DFI 3053 DUI 011 ORBIT, FIGURE EIGHT*/
std::string Dfi3053Dui011(const std::array<int, 1>& orbitFigureEight)
{
    return dfi3053::Dui011(orbitFigureEight);
}
/* DFI 3053 DUI 012 ORBIT, RANDOM CLOSED*/
std::string Dfi3053Dui012(const std::array<int, 1>& orbitRandomClosed)
{
    return dfi3053::Dui012(orbitRandomClosed);
}
/* DFI 3053 DUI 013 ORBIT POINT*/
std::string Dfi3053Dui013(const std::array<int, 1>& orbitPoint)
{
    return dfi3053::Dui013(orbitPoint);
}
/* DFI 3053 DUI 014 PT3, AMP13*/
std::string Dfi3053Dui014(const std::array<int, 1>& pt3Amp13)
{
    return dfi3053::Dui014(pt3Amp13);
}
/* DFI 3053 DUI 015 PT3, AMP14*/
std::string Dfi3053Dui015(const std::array<int, 1>& pt3Amp14)
{
    return dfi3053::Dui015(pt3Amp14);
}
/* DFI 3053 DUI 016 PT3, AMP15*/
std::string Dfi3053Dui016(const std::array<int, 1>& pt3Amp15)
{
    return dfi3053::Dui016(pt3Amp15);
}

/*LinePointType*/
/* DFI 3054 DUI 001 NO STATEMENT*/
std::string Dfi3054Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3054::Dui001(noStatement);
}
/* DFI 3054 DUI 002 FORWARD EDGE OF THE BATTLE AREA (FEBA)*/
std::string Dfi3054Dui002(const std::array<int, 1>& forwardEdgeOfTheBattleArea)
{
    return dfi3054::Dui002(forwardEdgeOfTheBattleArea);
}
/* DFI 3054 DUI 003 GUN TARGET LINE*/
std::string Dfi3054Dui003(const std::array<int, 1>& gunTargetLine)
{
    return dfi3054::Dui003(gunTargetLine);
}
/* DFI 3054 DUI 004 CORRIDOR*/
std::string Dfi3054Dui004(const std::array<int, 1>& corridor)
{
    return dfi3054::Dui004(corridor);
}
/* DFI 3054 DUI 005 HOSTILE BOUNDARY*/
std::string Dfi3054Dui005(const std::array<int, 1>& hostileBoundary)
{
    return dfi3054::Dui005(hostileBoundary);
}
/* DFI 3054 DUI 006 BUFFER ZONE BOUNDARY*/
std::string Dfi3054Dui006(const std::array<int, 1>& bufferZoneBoundary)
{
    return dfi3054::Dui006(bufferZoneBoundary);
}
/* DFI 3054 DUI 007 LOW LEVEL TRANSIT ROUTE*/
std::string Dfi3054Dui007(const std::array<int, 1>& lowLevelTransitRoute)
{
    return dfi3054::Dui007(lowLevelTransitRoute);
}
/* DFI 3054 DUI 008 TACTICAL ACTION LINE*/
std::string Dfi3054Dui008(const std::array<int, 1>& tacticalActionLine)
{
    return dfi3054::Dui008(tacticalActionLine);
}
/* DFI 3054 DUI 009 FIRE SUPPORT COORDINATION LINE (FSCL)*/
std::string Dfi3054Dui009(const std::array<int, 1>& fireSupportCoordinationLine)
{
    return dfi3054::Dui009(fireSupportCoordinationLine);
}
/* DFI 3054 DUI 010 FORWARD LINE OF OWN TROOPS (FLOT)*/
std::string Dfi3054Dui010(const std::array<int, 1>& forwardLineOfOwnTroops)
{
    return dfi3054::Dui010(forwardLineOfOwnTroops);
}
/* DFI 3054 DUI 011 PT4, AMP10*/
std::string Dfi3054Dui011(const std::array<int, 1>& pt4Amp10)
{
    return dfi3054::Dui011(pt4Amp10);
}
/* DFI 3054 DUI 012 PT4, AMP11*/
std::string Dfi3054Dui012(const std::array<int, 1>& pt4Amp11)
{
    return dfi3054::Dui012(pt4Amp11);
}
/* DFI 3054 DUI 013 PT4, AMP12*/
std::string Dfi3054Dui013(const std::array<int, 1>& pt4Amp12)
{
    return dfi3054::Dui013(pt4Amp12);
}
/* DFI 3054 DUI 014 PT4, AMP13*/
std::string Dfi3054Dui014(const std::array<int, 1>& pt4Amp13)
{
    return dfi3054::Dui014(pt4Amp13);
}
/* DFI 3054 DUI 015 PT4, AMP14*/
std::string Dfi3054Dui015(const std::array<int, 1>& pt4Amp14)
{
    return dfi3054::Dui015(pt4Amp14);
}
/* DFI 3054 DUI 016 PT4, AMP15*/
std::string Dfi3054Dui016(const std::array<int, 1>& pt4Amp15)
{
    return dfi3054::Dui016(pt4Amp15);
}

/*GeneralAreaPointType*/
/* DFI 3055 DUI 001 NO STATEMENT*/
std::string Dfi3055Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3055::Dui001(noStatement);
}
/* DFI 3055 DUI 002 SEARCH*/
std::string Dfi3055Dui002(const std::array<int, 1>& search)
{
    return dfi3055::Dui002(search);
}
/* DFI 3055 DUI 003 RESTRICTED*/
std::string Dfi3055Dui003(const std::array<int, 1>& restricted)
{
    return dfi3055::Dui003(restricted);
}
/* DFI 3055 DUI 004 EXERCISE*/
std::string Dfi3055Dui004(const std::array<int, 1>& exercise)
{
    return dfi3055::Dui004(exercise);
}
/* DFI 3055 DUI 005 SUBMARINE PATROL AREA*/
std::string Dfi3055Dui005(const std::array<int, 1>& submarinePatrolArea)
{
    return dfi3055::Dui005(submarinePatrolArea);
}
/* DFI 3055 DUI 006 FIGHTER ENGAGEMENT ZONE*/
std::string Dfi3055Dui006(const std::array<int, 1>& fighterEngagementZone)
{
    return dfi3055::Dui006(fighterEngagementZone);
}
/* DFI 3055 DUI 007 GROUND AREA OF RESPONSIBILITY*/
std::string Dfi3055Dui007(const std::array<int, 1>& groundAreaOfResponsibility)
{
    return dfi3055::Dui007(groundAreaOfResponsibility);
}
/* DFI 3055 DUI 008 DEFENDED AREA*/
std::string Dfi3055Dui008(const std::array<int, 1>& defendedArea)
{
    return dfi3055::Dui008(defendedArea);
}
/* DFI 3055 DUI 009 PT5, AMP8*/
std::string Dfi3055Dui009(const std::array<int, 1>& pt5Amp8)
{
    return dfi3055::Dui009(pt5Amp8);
}
/* DFI 3055 DUI 010 PT5, AMP9*/
std::string Dfi3055Dui010(const std::array<int, 1>& pt5Amp9)
{
    return dfi3055::Dui010(pt5Amp9);
}
/* DFI 3055 DUI 011 PT5, AMP10*/
std::string Dfi3055Dui011(const std::array<int, 1>& pt5Amp10)
{
    return dfi3055::Dui011(pt5Amp10);
}
/* DFI 3055 DUI 012 PT5, AMP11*/
std::string Dfi3055Dui012(const std::array<int, 1>& pt5Amp11)
{
    return dfi3055::Dui012(pt5Amp11);
}
/* DFI 3055 DUI 013 PT5, AMP12*/
std::string Dfi3055Dui013(const std::array<int, 1>& pt5Amp12)
{
    return dfi3055::Dui013(pt5Amp12);
}
/* DFI 3055 DUI 014 PT5, AMP13*/
std::string Dfi3055Dui014(const std::array<int, 1>& pt5Amp13)
{
    return dfi3055::Dui014(pt5Amp13);
}
/* DFI 3055 DUI 015 PT5, AMP14*/
std::string Dfi3055Dui015(const std::array<int, 1>& pt5Amp14)
{
    return dfi3055::Dui015(pt5Amp14);
}
/* DFI 3055 DUI 016 PT5, AMP15*/
std::string Dfi3055Dui016(const std::array<int, 1>& pt5Amp15)
{
    return dfi3055::Dui016(pt5Amp15);
}

/*HazardAreaPointType*/
/* DFI 3056 DUI 001 NO STATEMENT*/
std::string Dfi3056Dui001(const std::array<int, 1>& noStatement)
{
    return dfi3056::Dui001(noStatement);
}
/* DFI 3056 DUI 002 DANGER*/
std::string Dfi3056Dui002(const std::array<int, 1>& danger)
{
    return dfi3056::Dui002(danger);
}
/* DFI 3056 DUI 003 CONTAMINATED*/
std::string Dfi3056Dui003(const std::array<int, 1>& contaminated)
{
    return dfi3056::Dui003(contaminated);
}
/* DFI 3056 DUI 004 MISSILE ENGAGEMENT ZONE*/
std::string Dfi3056Dui004(const std::array<int, 1>& missileEngagementZone)
{
    return dfi3056::Dui004(missileEngagementZone);
}
/* DFI 3056 DUI 005 DISUSED*/
std::string Dfi3056Dui005(const std::array<int, 1>& disused)
{
    return dfi3056::Dui005(disused);
}
/* DFI 3056 DUI 006 HOSTILE WEAPON ZONE*/
std::string Dfi3056Dui006(const std::array<int, 1>& hostileWeaponZone)
{
    return dfi3056::Dui006(hostileWeaponZone);
}
/* DFI 3056 DUI 007 HOSTILE TACTICAL ZONE*/
std::string Dfi3056Dui007(const std::array<int, 1>& hostileTacticalZone)
{
    return dfi3056::Dui007(hostileTacticalZone);
}
/* DFI 3056 DUI 008 SHORAD*/
std::string Dfi3056Dui008(const std::array<int, 1>& shorad)
{
    return dfi3056::Dui008(shorad);
}
/* DFI 3056 DUI 009 KILL ZONE*/
std::string Dfi3056Dui009(const std::array<int, 1>& killZone)
{
    return dfi3056::Dui009(killZone);
}
/* DFI 3056 DUI 010 TARGET AREA OF INTEREST*/
std::string Dfi3056Dui010(const std::array<int, 1>& targetAreaOfInterest)
{
    return dfi3056::Dui010(targetAreaOfInterest);
}
/* DFI 3056 DUI 011 NAMED AREA OF INTEREST*/
std::string Dfi3056Dui011(const std::array<int, 1>& namedAreaOfInterest)
{
    return dfi3056::Dui011(namedAreaOfInterest);
}
/* DFI 3056 DUI 012 PT6, AMP11*/
std::string Dfi3056Dui012(const std::array<int, 1>& pt6Amp11)
{
    return dfi3056::Dui012(pt6Amp11);
}
/* DFI 3056 DUI 013 PT6, AMP12*/
std::string Dfi3056Dui013(const std::array<int, 1>& pt6Amp12)
{
    return dfi3056::Dui013(pt6Amp12);
}
/* DFI 3056 DUI 014 PT6, AMP13*/
std::string Dfi3056Dui014(const std::array<int, 1>& pt6Amp13)
{
    return dfi3056::Dui014(pt6Amp13);
}
/* DFI 3056 DUI 015 PT6, AMP14*/
std::string Dfi3056Dui015(const std::array<int, 1>& pt6Amp14)
{
    return dfi3056::Dui015(pt6Amp14);
}
/* DFI 3056 DUI 016 PT6, AMP15*/
std::string Dfi3056Dui016(const std::array<int, 1>& pt6Amp15)
{
    return dfi3056::Dui016(pt6Amp15);
}

// DFI 3057-3066, 3080-3087, 3099-3140 wrapper group

std::string Dfi3057Dui001(const std::array<int, 1>& no_statement)
{
    return dfi3057::Dui001(no_statement);
}

std::string Dfi3057Dui002(const std::array<int, 1>& sinker)
{
    return dfi3057::Dui002(sinker);
}

std::string Dfi3057Dui003(const std::array<int, 1>& brief_contact)
{
    return dfi3057::Dui003(brief_contact);
}

std::string Dfi3057Dui004(const std::array<int, 1>& search_center_asw)
{
    return dfi3057::Dui004(search_center_asw);
}

std::string Dfi3057Dui005(const std::array<int, 1>& estimated_position_ep)
{
    return dfi3057::Dui005(estimated_position_ep);
}

std::string Dfi3057Dui006(const std::array<int, 1>& fix_asw)
{
    return dfi3057::Dui006(fix_asw);
}

std::string Dfi3057Dui007(const std::array<int, 1>& notack_area)
{
    return dfi3057::Dui007(notack_area);
}

std::string Dfi3057Dui008(const std::array<int, 1>& moving_haven)
{
    return dfi3057::Dui008(moving_haven);
}

std::string Dfi3057Dui009(const std::array<int, 1>& disused)
{
    return dfi3057::Dui009(disused);
}

std::string Dfi3057Dui010(const std::array<int, 1>& sonobuoy_position)
{
    return dfi3057::Dui010(sonobuoy_position);
}

std::string Dfi3057Dui011(const std::array<int, 1>& sonobuoy_pattern_reference_position)
{
    return dfi3057::Dui011(sonobuoy_pattern_reference_position);
}

std::string Dfi3057Dui012(const std::array<int, 1>& limiting_line_of_approach)
{
    return dfi3057::Dui012(limiting_line_of_approach);
}

std::string Dfi3057Dui013(const std::array<int, 1>& area_of_probability_asw)
{
    return dfi3057::Dui013(area_of_probability_asw);
}

std::string Dfi3057Dui014(const std::array<int, 1>& friendly_weapon_danger_area_fwda)
{
    return dfi3057::Dui014(friendly_weapon_danger_area_fwda);
}

std::string Dfi3057Dui015(const std::array<int, 1>& pt7_amp14)
{
    return dfi3057::Dui015(pt7_amp14);
}

std::string Dfi3057Dui016(const std::array<int, 1>& pt7_amp15)
{
    return dfi3057::Dui016(pt7_amp15);
}

std::string Dfi3058Dui001(const std::array<int, 1>& charted_wreck)
{
    return dfi3058::Dui001(charted_wreck);
}

std::string Dfi3058Dui002(const std::array<int, 1>& bottomed_nonsubmarine)
{
    return dfi3058::Dui002(bottomed_nonsubmarine);
}

std::string Dfi3058Dui003(const std::array<int, 1>& asw_station)
{
    return dfi3058::Dui003(asw_station);
}

std::string Dfi3058Dui004(const std::array<int, 1>& pt8_amp3)
{
    return dfi3058::Dui004(pt8_amp3);
}

std::string Dfi3058Dui005(const std::array<int, 1>& pt8_amp4)
{
    return dfi3058::Dui005(pt8_amp4);
}

std::string Dfi3058Dui006(const std::array<int, 1>& pt8_amp5)
{
    return dfi3058::Dui006(pt8_amp5);
}

std::string Dfi3058Dui007(const std::array<int, 1>& pt8_amp6)
{
    return dfi3058::Dui007(pt8_amp6);
}

std::string Dfi3058Dui008(const std::array<int, 1>& pt8_amp7)
{
    return dfi3058::Dui008(pt8_amp7);
}

std::string Dfi3058Dui009(const std::array<int, 1>& pt8_amp8)
{
    return dfi3058::Dui009(pt8_amp8);
}

std::string Dfi3058Dui010(const std::array<int, 1>& pt8_amp9)
{
    return dfi3058::Dui010(pt8_amp9);
}

std::string Dfi3058Dui011(const std::array<int, 1>& pt8_amp10)
{
    return dfi3058::Dui011(pt8_amp10);
}

std::string Dfi3058Dui012(const std::array<int, 1>& pt8_amp11)
{
    return dfi3058::Dui012(pt8_amp11);
}

std::string Dfi3058Dui013(const std::array<int, 1>& pt8_amp12)
{
    return dfi3058::Dui013(pt8_amp12);
}

std::string Dfi3058Dui014(const std::array<int, 1>& pt8_amp13)
{
    return dfi3058::Dui014(pt8_amp13);
}

std::string Dfi3058Dui015(const std::array<int, 1>& pt8_amp14)
{
    return dfi3058::Dui015(pt8_amp14);
}

std::string Dfi3058Dui016(const std::array<int, 1>& pt8_amp15)
{
    return dfi3058::Dui016(pt8_amp15);
}

std::string Dfi3059Dui001(const std::array<int, 1>& pt9_amp0)
{
    return dfi3059::Dui001(pt9_amp0);
}

std::string Dfi3059Dui002(const std::array<int, 1>& pt9_amp1)
{
    return dfi3059::Dui002(pt9_amp1);
}

std::string Dfi3059Dui003(const std::array<int, 1>& pt9_amp2)
{
    return dfi3059::Dui003(pt9_amp2);
}

std::string Dfi3059Dui004(const std::array<int, 1>& pt9_amp3)
{
    return dfi3059::Dui004(pt9_amp3);
}

std::string Dfi3059Dui005(const std::array<int, 1>& pt9_amp4)
{
    return dfi3059::Dui005(pt9_amp4);
}

std::string Dfi3059Dui006(const std::array<int, 1>& pt9_amp5)
{
    return dfi3059::Dui006(pt9_amp5);
}

std::string Dfi3059Dui007(const std::array<int, 1>& pt9_amp6)
{
    return dfi3059::Dui007(pt9_amp6);
}

std::string Dfi3059Dui008(const std::array<int, 1>& pt9_amp7)
{
    return dfi3059::Dui008(pt9_amp7);
}

std::string Dfi3059Dui009(const std::array<int, 1>& pt9_amp8)
{
    return dfi3059::Dui009(pt9_amp8);
}

std::string Dfi3059Dui010(const std::array<int, 1>& pt9_amp9)
{
    return dfi3059::Dui010(pt9_amp9);
}

std::string Dfi3059Dui011(const std::array<int, 1>& pt9_amp10)
{
    return dfi3059::Dui011(pt9_amp10);
}

std::string Dfi3059Dui012(const std::array<int, 1>& pt9_amp11)
{
    return dfi3059::Dui012(pt9_amp11);
}

std::string Dfi3059Dui013(const std::array<int, 1>& pt9_amp12)
{
    return dfi3059::Dui013(pt9_amp12);
}

std::string Dfi3059Dui014(const std::array<int, 1>& pt9_amp13)
{
    return dfi3059::Dui014(pt9_amp13);
}

std::string Dfi3059Dui015(const std::array<int, 1>& pt9_amp14)
{
    return dfi3059::Dui015(pt9_amp14);
}

std::string Dfi3059Dui016(const std::array<int, 1>& pt9_amp15)
{
    return dfi3059::Dui016(pt9_amp15);
}

std::string Dfi3060Dui001(const std::array<int, 1>& disused)
{
    return dfi3060::Dui001(disused);
}

std::string Dfi3060Dui002(const std::array<int, 1>& disused_2)
{
    return dfi3060::Dui002(disused_2);
}

std::string Dfi3060Dui003(const std::array<int, 1>& filter_rocket_di_1)
{
    return dfi3060::Dui003(filter_rocket_di_1);
}

std::string Dfi3061Dui001(const std::array<int, 1>& pt10_amp0)
{
    return dfi3061::Dui001(pt10_amp0);
}

std::string Dfi3061Dui002(const std::array<int, 1>& pt10_amp1)
{
    return dfi3061::Dui002(pt10_amp1);
}

std::string Dfi3061Dui003(const std::array<int, 1>& pt10_amp2)
{
    return dfi3061::Dui003(pt10_amp2);
}

std::string Dfi3061Dui004(const std::array<int, 1>& pt10_amp3)
{
    return dfi3061::Dui004(pt10_amp3);
}

std::string Dfi3061Dui005(const std::array<int, 1>& pt10_amp4)
{
    return dfi3061::Dui005(pt10_amp4);
}

std::string Dfi3061Dui006(const std::array<int, 1>& pt10_amp5)
{
    return dfi3061::Dui006(pt10_amp5);
}

std::string Dfi3061Dui007(const std::array<int, 1>& pt10_amp6)
{
    return dfi3061::Dui007(pt10_amp6);
}

std::string Dfi3061Dui008(const std::array<int, 1>& pt10_amp7)
{
    return dfi3061::Dui008(pt10_amp7);
}

std::string Dfi3061Dui009(const std::array<int, 1>& pt10_amp8)
{
    return dfi3061::Dui009(pt10_amp8);
}

std::string Dfi3061Dui010(const std::array<int, 1>& pt10_amp9)
{
    return dfi3061::Dui010(pt10_amp9);
}

std::string Dfi3061Dui011(const std::array<int, 1>& pt10_amp10)
{
    return dfi3061::Dui011(pt10_amp10);
}

std::string Dfi3061Dui012(const std::array<int, 1>& pt10_amp11)
{
    return dfi3061::Dui012(pt10_amp11);
}

std::string Dfi3061Dui013(const std::array<int, 1>& pt10_amp12)
{
    return dfi3061::Dui013(pt10_amp12);
}

std::string Dfi3061Dui014(const std::array<int, 1>& pt10_amp13)
{
    return dfi3061::Dui014(pt10_amp13);
}

std::string Dfi3061Dui015(const std::array<int, 1>& pt10_amp14)
{
    return dfi3061::Dui015(pt10_amp14);
}

std::string Dfi3061Dui016(const std::array<int, 1>& pt10_amp15)
{
    return dfi3061::Dui016(pt10_amp15);
}

std::string Dfi3062Dui001(const std::array<int, 1>& pt11_amp0)
{
    return dfi3062::Dui001(pt11_amp0);
}

std::string Dfi3062Dui002(const std::array<int, 1>& pt11_amp1)
{
    return dfi3062::Dui002(pt11_amp1);
}

std::string Dfi3062Dui003(const std::array<int, 1>& pt11_amp2)
{
    return dfi3062::Dui003(pt11_amp2);
}

std::string Dfi3062Dui004(const std::array<int, 1>& pt11_amp3)
{
    return dfi3062::Dui004(pt11_amp3);
}

std::string Dfi3062Dui005(const std::array<int, 1>& pt11_amp4)
{
    return dfi3062::Dui005(pt11_amp4);
}

std::string Dfi3062Dui006(const std::array<int, 1>& pt11_amp5)
{
    return dfi3062::Dui006(pt11_amp5);
}

std::string Dfi3062Dui007(const std::array<int, 1>& pt11_amp6)
{
    return dfi3062::Dui007(pt11_amp6);
}

std::string Dfi3062Dui008(const std::array<int, 1>& pt11_amp7)
{
    return dfi3062::Dui008(pt11_amp7);
}

std::string Dfi3062Dui009(const std::array<int, 1>& pt11_amp8)
{
    return dfi3062::Dui009(pt11_amp8);
}

std::string Dfi3062Dui010(const std::array<int, 1>& pt11_amp9)
{
    return dfi3062::Dui010(pt11_amp9);
}

std::string Dfi3062Dui011(const std::array<int, 1>& pt11_amp10)
{
    return dfi3062::Dui011(pt11_amp10);
}

std::string Dfi3062Dui012(const std::array<int, 1>& pt11_amp11)
{
    return dfi3062::Dui012(pt11_amp11);
}

std::string Dfi3062Dui013(const std::array<int, 1>& pt11_amp12)
{
    return dfi3062::Dui013(pt11_amp12);
}

std::string Dfi3062Dui014(const std::array<int, 1>& pt11_amp13)
{
    return dfi3062::Dui014(pt11_amp13);
}

std::string Dfi3062Dui015(const std::array<int, 1>& pt11_amp14)
{
    return dfi3062::Dui015(pt11_amp14);
}

std::string Dfi3062Dui016(const std::array<int, 1>& pt11_amp15)
{
    return dfi3062::Dui016(pt11_amp15);
}

std::string Dfi3063Dui001(const std::array<int, 1>& pt12_amp0)
{
    return dfi3063::Dui001(pt12_amp0);
}

std::string Dfi3063Dui002(const std::array<int, 1>& pt12_amp1)
{
    return dfi3063::Dui002(pt12_amp1);
}

std::string Dfi3063Dui003(const std::array<int, 1>& pt12_amp2)
{
    return dfi3063::Dui003(pt12_amp2);
}

std::string Dfi3063Dui004(const std::array<int, 1>& pt12_amp3)
{
    return dfi3063::Dui004(pt12_amp3);
}

std::string Dfi3063Dui005(const std::array<int, 1>& pt12_amp4)
{
    return dfi3063::Dui005(pt12_amp4);
}

std::string Dfi3063Dui006(const std::array<int, 1>& pt12_amp5)
{
    return dfi3063::Dui006(pt12_amp5);
}

std::string Dfi3063Dui007(const std::array<int, 1>& pt12_amp6)
{
    return dfi3063::Dui007(pt12_amp6);
}

std::string Dfi3063Dui008(const std::array<int, 1>& pt12_amp7)
{
    return dfi3063::Dui008(pt12_amp7);
}

std::string Dfi3063Dui009(const std::array<int, 1>& pt12_amp8)
{
    return dfi3063::Dui009(pt12_amp8);
}

std::string Dfi3063Dui010(const std::array<int, 1>& pt12_amp9)
{
    return dfi3063::Dui010(pt12_amp9);
}

std::string Dfi3063Dui011(const std::array<int, 1>& pt12_amp10)
{
    return dfi3063::Dui011(pt12_amp10);
}

std::string Dfi3063Dui012(const std::array<int, 1>& pt12_amp11)
{
    return dfi3063::Dui012(pt12_amp11);
}

std::string Dfi3063Dui013(const std::array<int, 1>& pt12_amp12)
{
    return dfi3063::Dui013(pt12_amp12);
}

std::string Dfi3063Dui014(const std::array<int, 1>& pt12_amp13)
{
    return dfi3063::Dui014(pt12_amp13);
}

std::string Dfi3063Dui015(const std::array<int, 1>& pt12_amp14)
{
    return dfi3063::Dui015(pt12_amp14);
}

std::string Dfi3063Dui016(const std::array<int, 1>& pt12_amp15)
{
    return dfi3063::Dui016(pt12_amp15);
}

std::string Dfi3064Dui001(const std::array<int, 1>& pt13_amp0)
{
    return dfi3064::Dui001(pt13_amp0);
}

std::string Dfi3064Dui002(const std::array<int, 1>& pt13_amp1)
{
    return dfi3064::Dui002(pt13_amp1);
}

std::string Dfi3064Dui003(const std::array<int, 1>& pt13_amp2)
{
    return dfi3064::Dui003(pt13_amp2);
}

std::string Dfi3064Dui004(const std::array<int, 1>& pt13_amp3)
{
    return dfi3064::Dui004(pt13_amp3);
}

std::string Dfi3064Dui005(const std::array<int, 1>& pt13_amp4)
{
    return dfi3064::Dui005(pt13_amp4);
}

std::string Dfi3064Dui006(const std::array<int, 1>& pt13_amp5)
{
    return dfi3064::Dui006(pt13_amp5);
}

std::string Dfi3064Dui007(const std::array<int, 1>& pt13_amp6)
{
    return dfi3064::Dui007(pt13_amp6);
}

std::string Dfi3064Dui008(const std::array<int, 1>& pt13_amp7)
{
    return dfi3064::Dui008(pt13_amp7);
}

std::string Dfi3064Dui009(const std::array<int, 1>& pt13_amp8)
{
    return dfi3064::Dui009(pt13_amp8);
}

std::string Dfi3064Dui010(const std::array<int, 1>& pt13_amp9)
{
    return dfi3064::Dui010(pt13_amp9);
}

std::string Dfi3064Dui011(const std::array<int, 1>& pt13_amp10)
{
    return dfi3064::Dui011(pt13_amp10);
}

std::string Dfi3064Dui012(const std::array<int, 1>& pt13_amp11)
{
    return dfi3064::Dui012(pt13_amp11);
}

std::string Dfi3064Dui013(const std::array<int, 1>& pt13_amp12)
{
    return dfi3064::Dui013(pt13_amp12);
}

std::string Dfi3064Dui014(const std::array<int, 1>& pt13_amp13)
{
    return dfi3064::Dui014(pt13_amp13);
}

std::string Dfi3064Dui015(const std::array<int, 1>& pt13_amp14)
{
    return dfi3064::Dui015(pt13_amp14);
}

std::string Dfi3064Dui016(const std::array<int, 1>& pt13_amp15)
{
    return dfi3064::Dui016(pt13_amp15);
}

std::string Dfi3065Dui001(const std::array<int, 1>& pt14_amp0)
{
    return dfi3065::Dui001(pt14_amp0);
}

std::string Dfi3065Dui002(const std::array<int, 1>& pt14_amp1)
{
    return dfi3065::Dui002(pt14_amp1);
}

std::string Dfi3065Dui003(const std::array<int, 1>& pt14_amp2)
{
    return dfi3065::Dui003(pt14_amp2);
}

std::string Dfi3065Dui004(const std::array<int, 1>& pt14_amp3)
{
    return dfi3065::Dui004(pt14_amp3);
}

std::string Dfi3065Dui005(const std::array<int, 1>& pt14_amp4)
{
    return dfi3065::Dui005(pt14_amp4);
}

std::string Dfi3065Dui006(const std::array<int, 1>& pt14_amp5)
{
    return dfi3065::Dui006(pt14_amp5);
}

std::string Dfi3065Dui007(const std::array<int, 1>& pt14_amp6)
{
    return dfi3065::Dui007(pt14_amp6);
}

std::string Dfi3065Dui008(const std::array<int, 1>& pt14_amp7)
{
    return dfi3065::Dui008(pt14_amp7);
}

std::string Dfi3065Dui009(const std::array<int, 1>& pt14_amp8)
{
    return dfi3065::Dui009(pt14_amp8);
}

std::string Dfi3065Dui010(const std::array<int, 1>& pt14_amp9)
{
    return dfi3065::Dui010(pt14_amp9);
}

std::string Dfi3065Dui011(const std::array<int, 1>& pt14_amp10)
{
    return dfi3065::Dui011(pt14_amp10);
}

std::string Dfi3065Dui012(const std::array<int, 1>& pt14_amp11)
{
    return dfi3065::Dui012(pt14_amp11);
}

std::string Dfi3065Dui013(const std::array<int, 1>& pt14_amp12)
{
    return dfi3065::Dui013(pt14_amp12);
}

std::string Dfi3065Dui014(const std::array<int, 1>& pt14_amp13)
{
    return dfi3065::Dui014(pt14_amp13);
}

std::string Dfi3065Dui015(const std::array<int, 1>& pt14_amp14)
{
    return dfi3065::Dui015(pt14_amp14);
}

std::string Dfi3065Dui016(const std::array<int, 1>& pt14_amp15)
{
    return dfi3065::Dui016(pt14_amp15);
}

std::string Dfi3066Dui001(const std::array<int, 1>& pt15_amp0)
{
    return dfi3066::Dui001(pt15_amp0);
}

std::string Dfi3066Dui002(const std::array<int, 1>& pt15_amp1)
{
    return dfi3066::Dui002(pt15_amp1);
}

std::string Dfi3066Dui003(const std::array<int, 1>& pt15_amp2)
{
    return dfi3066::Dui003(pt15_amp2);
}

std::string Dfi3066Dui004(const std::array<int, 1>& pt15_amp3)
{
    return dfi3066::Dui004(pt15_amp3);
}

std::string Dfi3066Dui005(const std::array<int, 1>& pt15_amp4)
{
    return dfi3066::Dui005(pt15_amp4);
}

std::string Dfi3066Dui006(const std::array<int, 1>& pt15_amp5)
{
    return dfi3066::Dui006(pt15_amp5);
}

std::string Dfi3066Dui007(const std::array<int, 1>& pt15_amp6)
{
    return dfi3066::Dui007(pt15_amp6);
}

std::string Dfi3066Dui008(const std::array<int, 1>& pt15_amp7)
{
    return dfi3066::Dui008(pt15_amp7);
}

std::string Dfi3066Dui009(const std::array<int, 1>& pt15_amp8)
{
    return dfi3066::Dui009(pt15_amp8);
}

std::string Dfi3066Dui010(const std::array<int, 1>& pt15_amp9)
{
    return dfi3066::Dui010(pt15_amp9);
}

std::string Dfi3066Dui011(const std::array<int, 1>& pt15_amp10)
{
    return dfi3066::Dui011(pt15_amp10);
}

std::string Dfi3066Dui012(const std::array<int, 1>& pt15_amp11)
{
    return dfi3066::Dui012(pt15_amp11);
}

std::string Dfi3066Dui013(const std::array<int, 1>& pt15_amp12)
{
    return dfi3066::Dui013(pt15_amp12);
}

std::string Dfi3066Dui014(const std::array<int, 1>& pt15_amp13)
{
    return dfi3066::Dui014(pt15_amp13);
}

std::string Dfi3066Dui015(const std::array<int, 1>& pt15_amp14)
{
    return dfi3066::Dui015(pt15_amp14);
}

std::string Dfi3066Dui016(const std::array<int, 1>& pt15_amp15)
{
    return dfi3066::Dui016(pt15_amp15);
}

std::string Dfi3080Dui001(const std::array<int, 1>& undefined)
{
    return dfi3080::Dui001(undefined);
}

std::string Dfi3080Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3080::Dui002(undefined_2);
}

std::string Dfi3080Dui003(const std::array<int, 1>& j3_2_air_0)
{
    return dfi3080::Dui003(j3_2_air_0);
}

std::string Dfi3080Dui004(const std::array<int, 1>& j3_3_surface_0)
{
    return dfi3080::Dui004(j3_3_surface_0);
}

std::string Dfi3080Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_0)
{
    return dfi3080::Dui005(j3_4_and_j5_4_subsurface_0);
}

std::string Dfi3080Dui006(const std::array<int, 1>& j3_5_land_ground_0)
{
    return dfi3080::Dui006(j3_5_land_ground_0);
}

std::string Dfi3080Dui007(const std::array<int, 1>& j3_6_space_0)
{
    return dfi3080::Dui007(j3_6_space_0);
}

std::string Dfi3080Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_0)
{
    return dfi3080::Dui008(j3_7_and_j14_0_ew_product_information_0);
}

std::string Dfi3081Dui001(const std::array<int, 1>& undefined)
{
    return dfi3081::Dui001(undefined);
}

std::string Dfi3081Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3081::Dui002(undefined_2);
}

std::string Dfi3081Dui003(const std::array<int, 1>& j3_2_air_1)
{
    return dfi3081::Dui003(j3_2_air_1);
}

std::string Dfi3081Dui004(const std::array<int, 1>& j3_3_surface_1)
{
    return dfi3081::Dui004(j3_3_surface_1);
}

std::string Dfi3081Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_1)
{
    return dfi3081::Dui005(j3_4_and_j5_4_subsurface_1);
}

std::string Dfi3081Dui006(const std::array<int, 1>& j3_5_land_ground_1)
{
    return dfi3081::Dui006(j3_5_land_ground_1);
}

std::string Dfi3081Dui007(const std::array<int, 1>& j3_6_space_1)
{
    return dfi3081::Dui007(j3_6_space_1);
}

std::string Dfi3081Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_1)
{
    return dfi3081::Dui008(j3_7_and_j14_0_ew_product_information_1);
}

std::string Dfi3082Dui001(const std::array<int, 1>& undefined)
{
    return dfi3082::Dui001(undefined);
}

std::string Dfi3082Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3082::Dui002(undefined_2);
}

std::string Dfi3082Dui003(const std::array<int, 1>& j3_2_air_2)
{
    return dfi3082::Dui003(j3_2_air_2);
}

std::string Dfi3082Dui004(const std::array<int, 1>& j3_3_surface_2)
{
    return dfi3082::Dui004(j3_3_surface_2);
}

std::string Dfi3082Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_2)
{
    return dfi3082::Dui005(j3_4_and_j5_4_subsurface_2);
}

std::string Dfi3082Dui006(const std::array<int, 1>& j3_5_land_ground_2)
{
    return dfi3082::Dui006(j3_5_land_ground_2);
}

std::string Dfi3082Dui007(const std::array<int, 1>& j3_6_space_2)
{
    return dfi3082::Dui007(j3_6_space_2);
}

std::string Dfi3082Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_2)
{
    return dfi3082::Dui008(j3_7_and_j14_0_ew_product_information_2);
}

std::string Dfi3083Dui001(const std::array<int, 1>& undefined)
{
    return dfi3083::Dui001(undefined);
}

std::string Dfi3083Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3083::Dui002(undefined_2);
}

std::string Dfi3083Dui003(const std::array<int, 1>& j3_2_air_3)
{
    return dfi3083::Dui003(j3_2_air_3);
}

std::string Dfi3083Dui004(const std::array<int, 1>& j3_3_surface_3)
{
    return dfi3083::Dui004(j3_3_surface_3);
}

std::string Dfi3083Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_3)
{
    return dfi3083::Dui005(j3_4_and_j5_4_subsurface_3);
}

std::string Dfi3083Dui006(const std::array<int, 1>& j3_5_land_ground_3)
{
    return dfi3083::Dui006(j3_5_land_ground_3);
}

std::string Dfi3083Dui007(const std::array<int, 1>& j3_6_space_3)
{
    return dfi3083::Dui007(j3_6_space_3);
}

std::string Dfi3083Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_3)
{
    return dfi3083::Dui008(j3_7_and_j14_0_ew_product_information_3);
}

std::string Dfi3084Dui001(const std::array<int, 1>& undefined)
{
    return dfi3084::Dui001(undefined);
}

std::string Dfi3084Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3084::Dui002(undefined_2);
}

std::string Dfi3084Dui003(const std::array<int, 1>& j3_2_air_4)
{
    return dfi3084::Dui003(j3_2_air_4);
}

std::string Dfi3084Dui004(const std::array<int, 1>& j3_3_surface_4)
{
    return dfi3084::Dui004(j3_3_surface_4);
}

std::string Dfi3084Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_4)
{
    return dfi3084::Dui005(j3_4_and_j5_4_subsurface_4);
}

std::string Dfi3084Dui006(const std::array<int, 1>& j3_5_land_ground_4)
{
    return dfi3084::Dui006(j3_5_land_ground_4);
}

std::string Dfi3084Dui007(const std::array<int, 1>& j3_6_space_4)
{
    return dfi3084::Dui007(j3_6_space_4);
}

std::string Dfi3084Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_4)
{
    return dfi3084::Dui008(j3_7_and_j14_0_ew_product_information_4);
}

std::string Dfi3085Dui001(const std::array<int, 1>& undefined)
{
    return dfi3085::Dui001(undefined);
}

std::string Dfi3085Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3085::Dui002(undefined_2);
}

std::string Dfi3085Dui003(const std::array<int, 1>& j3_2_air_5)
{
    return dfi3085::Dui003(j3_2_air_5);
}

std::string Dfi3085Dui004(const std::array<int, 1>& j3_3_surface_5)
{
    return dfi3085::Dui004(j3_3_surface_5);
}

std::string Dfi3085Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_5)
{
    return dfi3085::Dui005(j3_4_and_j5_4_subsurface_5);
}

std::string Dfi3085Dui006(const std::array<int, 1>& j3_5_land_ground_5)
{
    return dfi3085::Dui006(j3_5_land_ground_5);
}

std::string Dfi3085Dui007(const std::array<int, 1>& j3_6_space_5)
{
    return dfi3085::Dui007(j3_6_space_5);
}

std::string Dfi3085Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_5)
{
    return dfi3085::Dui008(j3_7_and_j14_0_ew_product_information_5);
}

std::string Dfi3086Dui001(const std::array<int, 1>& undefined)
{
    return dfi3086::Dui001(undefined);
}

std::string Dfi3086Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3086::Dui002(undefined_2);
}

std::string Dfi3086Dui003(const std::array<int, 1>& j3_2_air_6)
{
    return dfi3086::Dui003(j3_2_air_6);
}

std::string Dfi3086Dui004(const std::array<int, 1>& j3_3_surface_6)
{
    return dfi3086::Dui004(j3_3_surface_6);
}

std::string Dfi3086Dui005(const std::array<int, 1>& j3_4_and_j5_4_subsurface_6)
{
    return dfi3086::Dui005(j3_4_and_j5_4_subsurface_6);
}

std::string Dfi3086Dui006(const std::array<int, 1>& j3_5_land_ground_6)
{
    return dfi3086::Dui006(j3_5_land_ground_6);
}

std::string Dfi3086Dui007(const std::array<int, 1>& j3_6_space_6)
{
    return dfi3086::Dui007(j3_6_space_6);
}

std::string Dfi3086Dui008(const std::array<int, 1>& j3_7_and_j14_0_ew_product_information_6)
{
    return dfi3086::Dui008(j3_7_and_j14_0_ew_product_information_6);
}

std::string Dfi3087Dui001(const std::array<int, 1>& undefined)
{
    return dfi3087::Dui001(undefined);
}

std::string Dfi3087Dui002(const std::array<int, 1>& undefined_2)
{
    return dfi3087::Dui002(undefined_2);
}

std::string Dfi3087Dui003(const std::array<int, 1>& j2_2_and_j2_0_air)
{
    return dfi3087::Dui003(j2_2_and_j2_0_air);
}

std::string Dfi3087Dui004(const std::array<int, 1>& j2_3_and_j2_0_surface)
{
    return dfi3087::Dui004(j2_3_and_j2_0_surface);
}

std::string Dfi3087Dui005(const std::array<int, 1>& j2_4_and_j2_0_subsurface)
{
    return dfi3087::Dui005(j2_4_and_j2_0_subsurface);
}

std::string Dfi3087Dui006(const std::array<int, 1>& j2_5_j2_6_and_j2_0_land)
{
    return dfi3087::Dui006(j2_5_j2_6_and_j2_0_land);
}

std::string Dfi3087Dui007(const std::array<int, 1>& undefined_3)
{
    return dfi3087::Dui007(undefined_3);
}

std::string Dfi3087Dui008(const std::array<int, 1>& undefined_4)
{
    return dfi3087::Dui008(undefined_4);
}

std::string Dfi3099Dui001(const std::array<int, 1>& spare)
{
    return dfi3099::Dui001(spare);
}

std::string Dfi3099Dui002(const std::array<int, 1>& spare_2)
{
    return dfi3099::Dui002(spare_2);
}

std::string Dfi3099Dui003(const std::array<int, 1>& spare_3)
{
    return dfi3099::Dui003(spare_3);
}

std::string Dfi3099Dui004(const std::array<int, 1>& spare_4)
{
    return dfi3099::Dui004(spare_4);
}

std::string Dfi3099Dui005(const std::array<int, 1>& spare_5)
{
    return dfi3099::Dui005(spare_5);
}

std::string Dfi3099Dui006(const std::array<int, 1>& spare_6)
{
    return dfi3099::Dui006(spare_6);
}

std::string Dfi3099Dui007(const std::array<int, 1>& spare_7)
{
    return dfi3099::Dui007(spare_7);
}

std::string Dfi3099Dui008(const std::array<int, 1>& spare_8)
{
    return dfi3099::Dui008(spare_8);
}

std::string Dfi3099Dui009(const std::array<int, 1>& spare_9)
{
    return dfi3099::Dui009(spare_9);
}

std::string Dfi3099Dui010(const std::array<int, 1>& spare_10)
{
    return dfi3099::Dui010(spare_10);
}

std::string Dfi3099Dui011(const std::array<int, 1>& spare_11)
{
    return dfi3099::Dui011(spare_11);
}

std::string Dfi3099Dui012(const std::array<int, 1>& spare_12)
{
    return dfi3099::Dui012(spare_12);
}

std::string Dfi3099Dui013(const std::array<int, 1>& spare_13)
{
    return dfi3099::Dui013(spare_13);
}

std::string Dfi3099Dui014(const std::array<int, 1>& spare_14)
{
    return dfi3099::Dui014(spare_14);
}

std::string Dfi3099Dui015(const std::array<int, 1>& spare_15)
{
    return dfi3099::Dui015(spare_15);
}

std::string Dfi3099Dui016(const std::array<int, 1>& spare_16)
{
    return dfi3099::Dui016(spare_16);
}

std::string Dfi3099Dui017(const std::array<int, 1>& spare_17)
{
    return dfi3099::Dui017(spare_17);
}

std::string Dfi3099Dui018(const std::array<int, 1>& spare_18)
{
    return dfi3099::Dui018(spare_18);
}

std::string Dfi3099Dui019(const std::array<int, 1>& spare_19)
{
    return dfi3099::Dui019(spare_19);
}

std::string Dfi3099Dui020(const std::array<int, 1>& spare_20)
{
    return dfi3099::Dui020(spare_20);
}

std::string Dfi3099Dui021(const std::array<int, 1>& spare_21)
{
    return dfi3099::Dui021(spare_21);
}

std::string Dfi3099Dui022(const std::array<int, 1>& spare_22)
{
    return dfi3099::Dui022(spare_22);
}

std::string Dfi3099Dui023(const std::array<int, 1>& spare_23)
{
    return dfi3099::Dui023(spare_23);
}

std::string Dfi3099Dui024(const std::array<int, 1>& spare_24)
{
    return dfi3099::Dui024(spare_24);
}

std::string Dfi3099Dui025(const std::array<int, 1>& spare_25)
{
    return dfi3099::Dui025(spare_25);
}

std::string Dfi3099Dui026(const std::array<int, 1>& spare_26)
{
    return dfi3099::Dui026(spare_26);
}

std::string Dfi3099Dui027(const std::array<int, 1>& spare_27)
{
    return dfi3099::Dui027(spare_27);
}

std::string Dfi3099Dui028(const std::array<int, 1>& spare_28)
{
    return dfi3099::Dui028(spare_28);
}

std::string Dfi3099Dui029(const std::array<int, 1>& spare_29)
{
    return dfi3099::Dui029(spare_29);
}

std::string Dfi3099Dui030(const std::array<int, 1>& spare_30)
{
    return dfi3099::Dui030(spare_30);
}

std::string Dfi3099Dui031(const std::array<int, 1>& spare_31)
{
    return dfi3099::Dui031(spare_31);
}

std::string Dfi3100Dui001(const std::array<int, 1>& sublabel_0_0)
{
    return dfi3100::Dui001(sublabel_0_0);
}

std::string Dfi3100Dui002(const std::array<int, 1>& sublabel_1_0)
{
    return dfi3100::Dui002(sublabel_1_0);
}

std::string Dfi3100Dui003(const std::array<int, 1>& sublabel_2_0)
{
    return dfi3100::Dui003(sublabel_2_0);
}

std::string Dfi3100Dui004(const std::array<int, 1>& sublabel_3_0)
{
    return dfi3100::Dui004(sublabel_3_0);
}

std::string Dfi3100Dui005(const std::array<int, 1>& sublabel_4_0)
{
    return dfi3100::Dui005(sublabel_4_0);
}

std::string Dfi3100Dui006(const std::array<int, 1>& sublabel_5_0)
{
    return dfi3100::Dui006(sublabel_5_0);
}

std::string Dfi3100Dui007(const std::array<int, 1>& sublabel_6_0)
{
    return dfi3100::Dui007(sublabel_6_0);
}

std::string Dfi3100Dui008(const std::array<int, 1>& sublabel_7_0)
{
    return dfi3100::Dui008(sublabel_7_0);
}

std::string Dfi3101Dui001(const std::array<int, 1>& sublabel_0_1)
{
    return dfi3101::Dui001(sublabel_0_1);
}

std::string Dfi3101Dui002(const std::array<int, 1>& sublabel_1_1)
{
    return dfi3101::Dui002(sublabel_1_1);
}

std::string Dfi3101Dui003(const std::array<int, 1>& sublabel_2_1)
{
    return dfi3101::Dui003(sublabel_2_1);
}

std::string Dfi3101Dui004(const std::array<int, 1>& sublabel_3_1)
{
    return dfi3101::Dui004(sublabel_3_1);
}

std::string Dfi3101Dui005(const std::array<int, 1>& sublabel_4_1)
{
    return dfi3101::Dui005(sublabel_4_1);
}

std::string Dfi3101Dui006(const std::array<int, 1>& sublabel_5_1)
{
    return dfi3101::Dui006(sublabel_5_1);
}

std::string Dfi3101Dui007(const std::array<int, 1>& sublabel_6_1)
{
    return dfi3101::Dui007(sublabel_6_1);
}

std::string Dfi3101Dui008(const std::array<int, 1>& sublabel_7_1)
{
    return dfi3101::Dui008(sublabel_7_1);
}

std::string Dfi3102Dui001(const std::array<int, 1>& sublabel_0_2)
{
    return dfi3102::Dui001(sublabel_0_2);
}

std::string Dfi3102Dui002(const std::array<int, 1>& sublabel_1_2)
{
    return dfi3102::Dui002(sublabel_1_2);
}

std::string Dfi3102Dui003(const std::array<int, 1>& sublabel_2_2)
{
    return dfi3102::Dui003(sublabel_2_2);
}

std::string Dfi3102Dui004(const std::array<int, 1>& sublabel_3_2)
{
    return dfi3102::Dui004(sublabel_3_2);
}

std::string Dfi3102Dui005(const std::array<int, 1>& sublabel_4_2)
{
    return dfi3102::Dui005(sublabel_4_2);
}

std::string Dfi3102Dui006(const std::array<int, 1>& sublabel_5_2)
{
    return dfi3102::Dui006(sublabel_5_2);
}

std::string Dfi3102Dui007(const std::array<int, 1>& sublabel_6_2)
{
    return dfi3102::Dui007(sublabel_6_2);
}

std::string Dfi3102Dui008(const std::array<int, 1>& sublabel_7_2)
{
    return dfi3102::Dui008(sublabel_7_2);
}

std::string Dfi3103Dui001(const std::array<int, 1>& sublabel_0_3)
{
    return dfi3103::Dui001(sublabel_0_3);
}

std::string Dfi3103Dui002(const std::array<int, 1>& sublabel_1_3)
{
    return dfi3103::Dui002(sublabel_1_3);
}

std::string Dfi3103Dui003(const std::array<int, 1>& sublabel_2_3)
{
    return dfi3103::Dui003(sublabel_2_3);
}

std::string Dfi3103Dui004(const std::array<int, 1>& sublabel_3_3)
{
    return dfi3103::Dui004(sublabel_3_3);
}

std::string Dfi3103Dui005(const std::array<int, 1>& sublabel_4_3)
{
    return dfi3103::Dui005(sublabel_4_3);
}

std::string Dfi3103Dui006(const std::array<int, 1>& sublabel_5_3)
{
    return dfi3103::Dui006(sublabel_5_3);
}

std::string Dfi3103Dui007(const std::array<int, 1>& sublabel_6_3)
{
    return dfi3103::Dui007(sublabel_6_3);
}

std::string Dfi3103Dui008(const std::array<int, 1>& sublabel_7_3)
{
    return dfi3103::Dui008(sublabel_7_3);
}

std::string Dfi3104Dui001(const std::array<int, 1>& sublabel_0_4)
{
    return dfi3104::Dui001(sublabel_0_4);
}

std::string Dfi3104Dui002(const std::array<int, 1>& sublabel_1_4)
{
    return dfi3104::Dui002(sublabel_1_4);
}

std::string Dfi3104Dui003(const std::array<int, 1>& sublabel_2_4)
{
    return dfi3104::Dui003(sublabel_2_4);
}

std::string Dfi3104Dui004(const std::array<int, 1>& sublabel_3_4)
{
    return dfi3104::Dui004(sublabel_3_4);
}

std::string Dfi3104Dui005(const std::array<int, 1>& sublabel_4_4)
{
    return dfi3104::Dui005(sublabel_4_4);
}

std::string Dfi3104Dui006(const std::array<int, 1>& sublabel_5_4)
{
    return dfi3104::Dui006(sublabel_5_4);
}

std::string Dfi3104Dui007(const std::array<int, 1>& sublabel_6_4)
{
    return dfi3104::Dui007(sublabel_6_4);
}

std::string Dfi3104Dui008(const std::array<int, 1>& sublabel_7_4)
{
    return dfi3104::Dui008(sublabel_7_4);
}

std::string Dfi3105Dui001(const std::array<int, 1>& sublabel_0_5)
{
    return dfi3105::Dui001(sublabel_0_5);
}

std::string Dfi3105Dui002(const std::array<int, 1>& sublabel_1_5)
{
    return dfi3105::Dui002(sublabel_1_5);
}

std::string Dfi3105Dui003(const std::array<int, 1>& sublabel_2_5)
{
    return dfi3105::Dui003(sublabel_2_5);
}

std::string Dfi3105Dui004(const std::array<int, 1>& sublabel_3_5)
{
    return dfi3105::Dui004(sublabel_3_5);
}

std::string Dfi3105Dui005(const std::array<int, 1>& sublabel_4_5)
{
    return dfi3105::Dui005(sublabel_4_5);
}

std::string Dfi3105Dui006(const std::array<int, 1>& sublabel_5_5)
{
    return dfi3105::Dui006(sublabel_5_5);
}

std::string Dfi3105Dui007(const std::array<int, 1>& sublabel_6_5)
{
    return dfi3105::Dui007(sublabel_6_5);
}

std::string Dfi3105Dui008(const std::array<int, 1>& sublabel_7_5)
{
    return dfi3105::Dui008(sublabel_7_5);
}

std::string Dfi3106Dui001(const std::array<int, 1>& sublabel_0_6)
{
    return dfi3106::Dui001(sublabel_0_6);
}

std::string Dfi3106Dui002(const std::array<int, 1>& sublabel_1_6)
{
    return dfi3106::Dui002(sublabel_1_6);
}

std::string Dfi3106Dui003(const std::array<int, 1>& sublabel_2_6)
{
    return dfi3106::Dui003(sublabel_2_6);
}

std::string Dfi3106Dui004(const std::array<int, 1>& sublabel_3_6)
{
    return dfi3106::Dui004(sublabel_3_6);
}

std::string Dfi3106Dui005(const std::array<int, 1>& sublabel_4_6)
{
    return dfi3106::Dui005(sublabel_4_6);
}

std::string Dfi3106Dui006(const std::array<int, 1>& sublabel_5_6)
{
    return dfi3106::Dui006(sublabel_5_6);
}

std::string Dfi3106Dui007(const std::array<int, 1>& sublabel_6_6)
{
    return dfi3106::Dui007(sublabel_6_6);
}

std::string Dfi3106Dui008(const std::array<int, 1>& sublabel_7_6)
{
    return dfi3106::Dui008(sublabel_7_6);
}

std::string Dfi3107Dui001(const std::array<int, 1>& sublabel_0_7)
{
    return dfi3107::Dui001(sublabel_0_7);
}

std::string Dfi3107Dui002(const std::array<int, 1>& sublabel_1_7)
{
    return dfi3107::Dui002(sublabel_1_7);
}

std::string Dfi3107Dui003(const std::array<int, 1>& sublabel_2_7)
{
    return dfi3107::Dui003(sublabel_2_7);
}

std::string Dfi3107Dui004(const std::array<int, 1>& sublabel_3_7)
{
    return dfi3107::Dui004(sublabel_3_7);
}

std::string Dfi3107Dui005(const std::array<int, 1>& sublabel_4_7)
{
    return dfi3107::Dui005(sublabel_4_7);
}

std::string Dfi3107Dui006(const std::array<int, 1>& sublabel_5_7)
{
    return dfi3107::Dui006(sublabel_5_7);
}

std::string Dfi3107Dui007(const std::array<int, 1>& sublabel_6_7)
{
    return dfi3107::Dui007(sublabel_6_7);
}

std::string Dfi3107Dui008(const std::array<int, 1>& sublabel_7_7)
{
    return dfi3107::Dui008(sublabel_7_7);
}

std::string Dfi3108Dui001(const std::array<int, 1>& sublabel_0_8)
{
    return dfi3108::Dui001(sublabel_0_8);
}

std::string Dfi3108Dui002(const std::array<int, 1>& sublabel_1_8)
{
    return dfi3108::Dui002(sublabel_1_8);
}

std::string Dfi3108Dui003(const std::array<int, 1>& sublabel_2_8)
{
    return dfi3108::Dui003(sublabel_2_8);
}

std::string Dfi3108Dui004(const std::array<int, 1>& sublabel_3_8)
{
    return dfi3108::Dui004(sublabel_3_8);
}

std::string Dfi3108Dui005(const std::array<int, 1>& sublabel_4_8)
{
    return dfi3108::Dui005(sublabel_4_8);
}

std::string Dfi3108Dui006(const std::array<int, 1>& sublabel_5_8)
{
    return dfi3108::Dui006(sublabel_5_8);
}

std::string Dfi3108Dui007(const std::array<int, 1>& sublabel_6_8)
{
    return dfi3108::Dui007(sublabel_6_8);
}

std::string Dfi3108Dui008(const std::array<int, 1>& sublabel_7_8)
{
    return dfi3108::Dui008(sublabel_7_8);
}

std::string Dfi3109Dui001(const std::array<int, 1>& sublabel_0_9)
{
    return dfi3109::Dui001(sublabel_0_9);
}

std::string Dfi3109Dui002(const std::array<int, 1>& sublabel_1_9)
{
    return dfi3109::Dui002(sublabel_1_9);
}

std::string Dfi3109Dui003(const std::array<int, 1>& sublabel_2_9)
{
    return dfi3109::Dui003(sublabel_2_9);
}

std::string Dfi3109Dui004(const std::array<int, 1>& sublabel_3_9)
{
    return dfi3109::Dui004(sublabel_3_9);
}

std::string Dfi3109Dui005(const std::array<int, 1>& sublabel_4_9)
{
    return dfi3109::Dui005(sublabel_4_9);
}

std::string Dfi3109Dui006(const std::array<int, 1>& sublabel_5_9)
{
    return dfi3109::Dui006(sublabel_5_9);
}

std::string Dfi3109Dui007(const std::array<int, 1>& sublabel_6_9)
{
    return dfi3109::Dui007(sublabel_6_9);
}

std::string Dfi3109Dui008(const std::array<int, 1>& sublabel_7_9)
{
    return dfi3109::Dui008(sublabel_7_9);
}

std::string Dfi3110Dui001(const std::array<int, 1>& sublabel_0_10)
{
    return dfi3110::Dui001(sublabel_0_10);
}

std::string Dfi3110Dui002(const std::array<int, 1>& sublabel_1_10)
{
    return dfi3110::Dui002(sublabel_1_10);
}

std::string Dfi3110Dui003(const std::array<int, 1>& sublabel_2_10)
{
    return dfi3110::Dui003(sublabel_2_10);
}

std::string Dfi3110Dui004(const std::array<int, 1>& sublabel_3_10)
{
    return dfi3110::Dui004(sublabel_3_10);
}

std::string Dfi3110Dui005(const std::array<int, 1>& sublabel_4_10)
{
    return dfi3110::Dui005(sublabel_4_10);
}

std::string Dfi3110Dui006(const std::array<int, 1>& sublabel_5_10)
{
    return dfi3110::Dui006(sublabel_5_10);
}

std::string Dfi3110Dui007(const std::array<int, 1>& sublabel_6_10)
{
    return dfi3110::Dui007(sublabel_6_10);
}

std::string Dfi3110Dui008(const std::array<int, 1>& sublabel_7_10)
{
    return dfi3110::Dui008(sublabel_7_10);
}

std::string Dfi3111Dui001(const std::array<int, 1>& sublabel_0_11)
{
    return dfi3111::Dui001(sublabel_0_11);
}

std::string Dfi3111Dui002(const std::array<int, 1>& sublabel_1_11)
{
    return dfi3111::Dui002(sublabel_1_11);
}

std::string Dfi3111Dui003(const std::array<int, 1>& sublabel_2_11)
{
    return dfi3111::Dui003(sublabel_2_11);
}

std::string Dfi3111Dui004(const std::array<int, 1>& sublabel_3_11)
{
    return dfi3111::Dui004(sublabel_3_11);
}

std::string Dfi3111Dui005(const std::array<int, 1>& sublabel_4_11)
{
    return dfi3111::Dui005(sublabel_4_11);
}

std::string Dfi3111Dui006(const std::array<int, 1>& sublabel_5_11)
{
    return dfi3111::Dui006(sublabel_5_11);
}

std::string Dfi3111Dui007(const std::array<int, 1>& sublabel_6_11)
{
    return dfi3111::Dui007(sublabel_6_11);
}

std::string Dfi3111Dui008(const std::array<int, 1>& sublabel_7_11)
{
    return dfi3111::Dui008(sublabel_7_11);
}

std::string Dfi3112Dui001(const std::array<int, 1>& sublabel_0_12)
{
    return dfi3112::Dui001(sublabel_0_12);
}

std::string Dfi3112Dui002(const std::array<int, 1>& sublabel_1_12)
{
    return dfi3112::Dui002(sublabel_1_12);
}

std::string Dfi3112Dui003(const std::array<int, 1>& sublabel_2_12)
{
    return dfi3112::Dui003(sublabel_2_12);
}

std::string Dfi3112Dui004(const std::array<int, 1>& sublabel_3_12)
{
    return dfi3112::Dui004(sublabel_3_12);
}

std::string Dfi3112Dui005(const std::array<int, 1>& sublabel_4_12)
{
    return dfi3112::Dui005(sublabel_4_12);
}

std::string Dfi3112Dui006(const std::array<int, 1>& sublabel_5_12)
{
    return dfi3112::Dui006(sublabel_5_12);
}

std::string Dfi3112Dui007(const std::array<int, 1>& sublabel_6_12)
{
    return dfi3112::Dui007(sublabel_6_12);
}

std::string Dfi3112Dui008(const std::array<int, 1>& sublabel_7_12)
{
    return dfi3112::Dui008(sublabel_7_12);
}

std::string Dfi3113Dui001(const std::array<int, 1>& sublabel_0_13)
{
    return dfi3113::Dui001(sublabel_0_13);
}

std::string Dfi3113Dui002(const std::array<int, 1>& sublabel_1_13)
{
    return dfi3113::Dui002(sublabel_1_13);
}

std::string Dfi3113Dui003(const std::array<int, 1>& sublabel_2_13)
{
    return dfi3113::Dui003(sublabel_2_13);
}

std::string Dfi3113Dui004(const std::array<int, 1>& sublabel_3_13)
{
    return dfi3113::Dui004(sublabel_3_13);
}

std::string Dfi3113Dui005(const std::array<int, 1>& sublabel_4_13)
{
    return dfi3113::Dui005(sublabel_4_13);
}

std::string Dfi3113Dui006(const std::array<int, 1>& sublabel_5_13)
{
    return dfi3113::Dui006(sublabel_5_13);
}

std::string Dfi3113Dui007(const std::array<int, 1>& sublabel_6_13)
{
    return dfi3113::Dui007(sublabel_6_13);
}

std::string Dfi3113Dui008(const std::array<int, 1>& sublabel_7_13)
{
    return dfi3113::Dui008(sublabel_7_13);
}

std::string Dfi3114Dui001(const std::array<int, 1>& sublabel_0_14)
{
    return dfi3114::Dui001(sublabel_0_14);
}

std::string Dfi3114Dui002(const std::array<int, 1>& sublabel_1_14)
{
    return dfi3114::Dui002(sublabel_1_14);
}

std::string Dfi3114Dui003(const std::array<int, 1>& sublabel_2_14)
{
    return dfi3114::Dui003(sublabel_2_14);
}

std::string Dfi3114Dui004(const std::array<int, 1>& sublabel_3_14)
{
    return dfi3114::Dui004(sublabel_3_14);
}

std::string Dfi3114Dui005(const std::array<int, 1>& sublabel_4_14)
{
    return dfi3114::Dui005(sublabel_4_14);
}

std::string Dfi3114Dui006(const std::array<int, 1>& sublabel_5_14)
{
    return dfi3114::Dui006(sublabel_5_14);
}

std::string Dfi3114Dui007(const std::array<int, 1>& sublabel_6_14)
{
    return dfi3114::Dui007(sublabel_6_14);
}

std::string Dfi3114Dui008(const std::array<int, 1>& sublabel_7_14)
{
    return dfi3114::Dui008(sublabel_7_14);
}

std::string Dfi3115Dui001(const std::array<int, 1>& sublabel_0_15)
{
    return dfi3115::Dui001(sublabel_0_15);
}

std::string Dfi3115Dui002(const std::array<int, 1>& sublabel_1_15)
{
    return dfi3115::Dui002(sublabel_1_15);
}

std::string Dfi3115Dui003(const std::array<int, 1>& sublabel_2_15)
{
    return dfi3115::Dui003(sublabel_2_15);
}

std::string Dfi3115Dui004(const std::array<int, 1>& sublabel_3_15)
{
    return dfi3115::Dui004(sublabel_3_15);
}

std::string Dfi3115Dui005(const std::array<int, 1>& sublabel_4_15)
{
    return dfi3115::Dui005(sublabel_4_15);
}

std::string Dfi3115Dui006(const std::array<int, 1>& sublabel_5_15)
{
    return dfi3115::Dui006(sublabel_5_15);
}

std::string Dfi3115Dui007(const std::array<int, 1>& sublabel_6_15)
{
    return dfi3115::Dui007(sublabel_6_15);
}

std::string Dfi3115Dui008(const std::array<int, 1>& sublabel_7_15)
{
    return dfi3115::Dui008(sublabel_7_15);
}

std::string Dfi3116Dui001(const std::array<int, 1>& sublabel_0_16)
{
    return dfi3116::Dui001(sublabel_0_16);
}

std::string Dfi3116Dui002(const std::array<int, 1>& sublabel_1_16)
{
    return dfi3116::Dui002(sublabel_1_16);
}

std::string Dfi3116Dui003(const std::array<int, 1>& sublabel_2_16)
{
    return dfi3116::Dui003(sublabel_2_16);
}

std::string Dfi3116Dui004(const std::array<int, 1>& sublabel_3_16)
{
    return dfi3116::Dui004(sublabel_3_16);
}

std::string Dfi3116Dui005(const std::array<int, 1>& sublabel_4_16)
{
    return dfi3116::Dui005(sublabel_4_16);
}

std::string Dfi3116Dui006(const std::array<int, 1>& sublabel_5_16)
{
    return dfi3116::Dui006(sublabel_5_16);
}

std::string Dfi3116Dui007(const std::array<int, 1>& sublabel_6_16)
{
    return dfi3116::Dui007(sublabel_6_16);
}

std::string Dfi3116Dui008(const std::array<int, 1>& sublabel_7_16)
{
    return dfi3116::Dui008(sublabel_7_16);
}

std::string Dfi3117Dui001(const std::array<int, 1>& sublabel_0_17)
{
    return dfi3117::Dui001(sublabel_0_17);
}

std::string Dfi3117Dui002(const std::array<int, 1>& sublabel_1_17)
{
    return dfi3117::Dui002(sublabel_1_17);
}

std::string Dfi3117Dui003(const std::array<int, 1>& sublabel_2_17)
{
    return dfi3117::Dui003(sublabel_2_17);
}

std::string Dfi3117Dui004(const std::array<int, 1>& sublabel_3_17)
{
    return dfi3117::Dui004(sublabel_3_17);
}

std::string Dfi3117Dui005(const std::array<int, 1>& sublabel_4_17)
{
    return dfi3117::Dui005(sublabel_4_17);
}

std::string Dfi3117Dui006(const std::array<int, 1>& sublabel_5_17)
{
    return dfi3117::Dui006(sublabel_5_17);
}

std::string Dfi3117Dui007(const std::array<int, 1>& sublabel_6_17)
{
    return dfi3117::Dui007(sublabel_6_17);
}

std::string Dfi3117Dui008(const std::array<int, 1>& sublabel_7_17)
{
    return dfi3117::Dui008(sublabel_7_17);
}

std::string Dfi3118Dui001(const std::array<int, 1>& sublabel_0_18)
{
    return dfi3118::Dui001(sublabel_0_18);
}

std::string Dfi3118Dui002(const std::array<int, 1>& sublabel_1_18)
{
    return dfi3118::Dui002(sublabel_1_18);
}

std::string Dfi3118Dui003(const std::array<int, 1>& sublabel_2_18)
{
    return dfi3118::Dui003(sublabel_2_18);
}

std::string Dfi3118Dui004(const std::array<int, 1>& sublabel_3_18)
{
    return dfi3118::Dui004(sublabel_3_18);
}

std::string Dfi3118Dui005(const std::array<int, 1>& sublabel_4_18)
{
    return dfi3118::Dui005(sublabel_4_18);
}

std::string Dfi3118Dui006(const std::array<int, 1>& sublabel_5_18)
{
    return dfi3118::Dui006(sublabel_5_18);
}

std::string Dfi3118Dui007(const std::array<int, 1>& sublabel_6_18)
{
    return dfi3118::Dui007(sublabel_6_18);
}

std::string Dfi3118Dui008(const std::array<int, 1>& sublabel_7_18)
{
    return dfi3118::Dui008(sublabel_7_18);
}

std::string Dfi3119Dui001(const std::array<int, 1>& sublabel_0_19)
{
    return dfi3119::Dui001(sublabel_0_19);
}

std::string Dfi3119Dui002(const std::array<int, 1>& sublabel_1_19)
{
    return dfi3119::Dui002(sublabel_1_19);
}

std::string Dfi3119Dui003(const std::array<int, 1>& sublabel_2_19)
{
    return dfi3119::Dui003(sublabel_2_19);
}

std::string Dfi3119Dui004(const std::array<int, 1>& sublabel_3_19)
{
    return dfi3119::Dui004(sublabel_3_19);
}

std::string Dfi3119Dui005(const std::array<int, 1>& sublabel_4_19)
{
    return dfi3119::Dui005(sublabel_4_19);
}

std::string Dfi3119Dui006(const std::array<int, 1>& sublabel_5_19)
{
    return dfi3119::Dui006(sublabel_5_19);
}

std::string Dfi3119Dui007(const std::array<int, 1>& sublabel_6_19)
{
    return dfi3119::Dui007(sublabel_6_19);
}

std::string Dfi3119Dui008(const std::array<int, 1>& sublabel_7_19)
{
    return dfi3119::Dui008(sublabel_7_19);
}

std::string Dfi3120Dui001(const std::array<int, 1>& sublabel_0_20)
{
    return dfi3120::Dui001(sublabel_0_20);
}

std::string Dfi3120Dui002(const std::array<int, 1>& sublabel_1_20)
{
    return dfi3120::Dui002(sublabel_1_20);
}

std::string Dfi3120Dui003(const std::array<int, 1>& sublabel_2_20)
{
    return dfi3120::Dui003(sublabel_2_20);
}

std::string Dfi3120Dui004(const std::array<int, 1>& sublabel_3_20)
{
    return dfi3120::Dui004(sublabel_3_20);
}

std::string Dfi3120Dui005(const std::array<int, 1>& sublabel_4_20)
{
    return dfi3120::Dui005(sublabel_4_20);
}

std::string Dfi3120Dui006(const std::array<int, 1>& sublabel_5_20)
{
    return dfi3120::Dui006(sublabel_5_20);
}

std::string Dfi3120Dui007(const std::array<int, 1>& sublabel_6_20)
{
    return dfi3120::Dui007(sublabel_6_20);
}

std::string Dfi3120Dui008(const std::array<int, 1>& sublabel_7_20)
{
    return dfi3120::Dui008(sublabel_7_20);
}

std::string Dfi3121Dui001(const std::array<int, 1>& sublabel_0_21)
{
    return dfi3121::Dui001(sublabel_0_21);
}

std::string Dfi3121Dui002(const std::array<int, 1>& sublabel_1_21)
{
    return dfi3121::Dui002(sublabel_1_21);
}

std::string Dfi3121Dui003(const std::array<int, 1>& sublabel_2_21)
{
    return dfi3121::Dui003(sublabel_2_21);
}

std::string Dfi3121Dui004(const std::array<int, 1>& sublabel_3_21)
{
    return dfi3121::Dui004(sublabel_3_21);
}

std::string Dfi3121Dui005(const std::array<int, 1>& sublabel_4_21)
{
    return dfi3121::Dui005(sublabel_4_21);
}

std::string Dfi3121Dui006(const std::array<int, 1>& sublabel_5_21)
{
    return dfi3121::Dui006(sublabel_5_21);
}

std::string Dfi3121Dui007(const std::array<int, 1>& sublabel_6_21)
{
    return dfi3121::Dui007(sublabel_6_21);
}

std::string Dfi3121Dui008(const std::array<int, 1>& sublabel_7_21)
{
    return dfi3121::Dui008(sublabel_7_21);
}

std::string Dfi3122Dui001(const std::array<int, 1>& sublabel_0_22)
{
    return dfi3122::Dui001(sublabel_0_22);
}

std::string Dfi3122Dui002(const std::array<int, 1>& sublabel_1_22)
{
    return dfi3122::Dui002(sublabel_1_22);
}

std::string Dfi3122Dui003(const std::array<int, 1>& sublabel_2_22)
{
    return dfi3122::Dui003(sublabel_2_22);
}

std::string Dfi3122Dui004(const std::array<int, 1>& sublabel_3_22)
{
    return dfi3122::Dui004(sublabel_3_22);
}

std::string Dfi3122Dui005(const std::array<int, 1>& sublabel_4_22)
{
    return dfi3122::Dui005(sublabel_4_22);
}

std::string Dfi3122Dui006(const std::array<int, 1>& sublabel_5_22)
{
    return dfi3122::Dui006(sublabel_5_22);
}

std::string Dfi3122Dui007(const std::array<int, 1>& sublabel_6_22)
{
    return dfi3122::Dui007(sublabel_6_22);
}

std::string Dfi3122Dui008(const std::array<int, 1>& sublabel_7_22)
{
    return dfi3122::Dui008(sublabel_7_22);
}

std::string Dfi3123Dui001(const std::array<int, 1>& sublabel_0_23)
{
    return dfi3123::Dui001(sublabel_0_23);
}

std::string Dfi3123Dui002(const std::array<int, 1>& sublabel_1_23)
{
    return dfi3123::Dui002(sublabel_1_23);
}

std::string Dfi3123Dui003(const std::array<int, 1>& sublabel_2_23)
{
    return dfi3123::Dui003(sublabel_2_23);
}

std::string Dfi3123Dui004(const std::array<int, 1>& sublabel_3_23)
{
    return dfi3123::Dui004(sublabel_3_23);
}

std::string Dfi3123Dui005(const std::array<int, 1>& sublabel_4_23)
{
    return dfi3123::Dui005(sublabel_4_23);
}

std::string Dfi3123Dui006(const std::array<int, 1>& sublabel_5_23)
{
    return dfi3123::Dui006(sublabel_5_23);
}

std::string Dfi3123Dui007(const std::array<int, 1>& sublabel_6_23)
{
    return dfi3123::Dui007(sublabel_6_23);
}

std::string Dfi3123Dui008(const std::array<int, 1>& sublabel_7_23)
{
    return dfi3123::Dui008(sublabel_7_23);
}

std::string Dfi3124Dui001(const std::array<int, 1>& sublabel_0_24)
{
    return dfi3124::Dui001(sublabel_0_24);
}

std::string Dfi3124Dui002(const std::array<int, 1>& sublabel_1_24)
{
    return dfi3124::Dui002(sublabel_1_24);
}

std::string Dfi3124Dui003(const std::array<int, 1>& sublabel_2_24)
{
    return dfi3124::Dui003(sublabel_2_24);
}

std::string Dfi3124Dui004(const std::array<int, 1>& sublabel_3_24)
{
    return dfi3124::Dui004(sublabel_3_24);
}

std::string Dfi3124Dui005(const std::array<int, 1>& sublabel_4_24)
{
    return dfi3124::Dui005(sublabel_4_24);
}

std::string Dfi3124Dui006(const std::array<int, 1>& sublabel_5_24)
{
    return dfi3124::Dui006(sublabel_5_24);
}

std::string Dfi3124Dui007(const std::array<int, 1>& sublabel_6_24)
{
    return dfi3124::Dui007(sublabel_6_24);
}

std::string Dfi3124Dui008(const std::array<int, 1>& sublabel_7_24)
{
    return dfi3124::Dui008(sublabel_7_24);
}

std::string Dfi3125Dui001(const std::array<int, 1>& sublabel_0_25)
{
    return dfi3125::Dui001(sublabel_0_25);
}

std::string Dfi3125Dui002(const std::array<int, 1>& sublabel_1_25)
{
    return dfi3125::Dui002(sublabel_1_25);
}

std::string Dfi3125Dui003(const std::array<int, 1>& sublabel_2_25)
{
    return dfi3125::Dui003(sublabel_2_25);
}

std::string Dfi3125Dui004(const std::array<int, 1>& sublabel_3_25)
{
    return dfi3125::Dui004(sublabel_3_25);
}

std::string Dfi3125Dui005(const std::array<int, 1>& sublabel_4_25)
{
    return dfi3125::Dui005(sublabel_4_25);
}

std::string Dfi3125Dui006(const std::array<int, 1>& sublabel_5_25)
{
    return dfi3125::Dui006(sublabel_5_25);
}

std::string Dfi3125Dui007(const std::array<int, 1>& sublabel_6_25)
{
    return dfi3125::Dui007(sublabel_6_25);
}

std::string Dfi3125Dui008(const std::array<int, 1>& sublabel_7_25)
{
    return dfi3125::Dui008(sublabel_7_25);
}

std::string Dfi3126Dui001(const std::array<int, 1>& sublabel_0_26)
{
    return dfi3126::Dui001(sublabel_0_26);
}

std::string Dfi3126Dui002(const std::array<int, 1>& sublabel_1_26)
{
    return dfi3126::Dui002(sublabel_1_26);
}

std::string Dfi3126Dui003(const std::array<int, 1>& sublabel_2_26)
{
    return dfi3126::Dui003(sublabel_2_26);
}

std::string Dfi3126Dui004(const std::array<int, 1>& sublabel_3_26)
{
    return dfi3126::Dui004(sublabel_3_26);
}

std::string Dfi3126Dui005(const std::array<int, 1>& sublabel_4_26)
{
    return dfi3126::Dui005(sublabel_4_26);
}

std::string Dfi3126Dui006(const std::array<int, 1>& sublabel_5_26)
{
    return dfi3126::Dui006(sublabel_5_26);
}

std::string Dfi3126Dui007(const std::array<int, 1>& sublabel_6_26)
{
    return dfi3126::Dui007(sublabel_6_26);
}

std::string Dfi3126Dui008(const std::array<int, 1>& sublabel_7_26)
{
    return dfi3126::Dui008(sublabel_7_26);
}

std::string Dfi3127Dui001(const std::array<int, 1>& sublabel_0_27)
{
    return dfi3127::Dui001(sublabel_0_27);
}

std::string Dfi3127Dui002(const std::array<int, 1>& sublabel_1_27)
{
    return dfi3127::Dui002(sublabel_1_27);
}

std::string Dfi3127Dui003(const std::array<int, 1>& sublabel_2_27)
{
    return dfi3127::Dui003(sublabel_2_27);
}

std::string Dfi3127Dui004(const std::array<int, 1>& sublabel_3_27)
{
    return dfi3127::Dui004(sublabel_3_27);
}

std::string Dfi3127Dui005(const std::array<int, 1>& sublabel_4_27)
{
    return dfi3127::Dui005(sublabel_4_27);
}

std::string Dfi3127Dui006(const std::array<int, 1>& sublabel_5_27)
{
    return dfi3127::Dui006(sublabel_5_27);
}

std::string Dfi3127Dui007(const std::array<int, 1>& sublabel_6_27)
{
    return dfi3127::Dui007(sublabel_6_27);
}

std::string Dfi3127Dui008(const std::array<int, 1>& sublabel_7_27)
{
    return dfi3127::Dui008(sublabel_7_27);
}

std::string Dfi3128Dui001(const std::array<int, 1>& sublabel_0_28)
{
    return dfi3128::Dui001(sublabel_0_28);
}

std::string Dfi3128Dui002(const std::array<int, 1>& sublabel_1_28)
{
    return dfi3128::Dui002(sublabel_1_28);
}

std::string Dfi3128Dui003(const std::array<int, 1>& sublabel_2_28)
{
    return dfi3128::Dui003(sublabel_2_28);
}

std::string Dfi3128Dui004(const std::array<int, 1>& sublabel_3_28)
{
    return dfi3128::Dui004(sublabel_3_28);
}

std::string Dfi3128Dui005(const std::array<int, 1>& sublabel_4_28)
{
    return dfi3128::Dui005(sublabel_4_28);
}

std::string Dfi3128Dui006(const std::array<int, 1>& sublabel_5_28)
{
    return dfi3128::Dui006(sublabel_5_28);
}

std::string Dfi3128Dui007(const std::array<int, 1>& sublabel_6_28)
{
    return dfi3128::Dui007(sublabel_6_28);
}

std::string Dfi3128Dui008(const std::array<int, 1>& sublabel_7_28)
{
    return dfi3128::Dui008(sublabel_7_28);
}

std::string Dfi3129Dui001(const std::array<int, 1>& sublabel_0_29)
{
    return dfi3129::Dui001(sublabel_0_29);
}

std::string Dfi3129Dui002(const std::array<int, 1>& sublabel_1_29)
{
    return dfi3129::Dui002(sublabel_1_29);
}

std::string Dfi3129Dui003(const std::array<int, 1>& sublabel_2_29)
{
    return dfi3129::Dui003(sublabel_2_29);
}

std::string Dfi3129Dui004(const std::array<int, 1>& sublabel_3_29)
{
    return dfi3129::Dui004(sublabel_3_29);
}

std::string Dfi3129Dui005(const std::array<int, 1>& sublabel_4_29)
{
    return dfi3129::Dui005(sublabel_4_29);
}

std::string Dfi3129Dui006(const std::array<int, 1>& sublabel_5_29)
{
    return dfi3129::Dui006(sublabel_5_29);
}

std::string Dfi3129Dui007(const std::array<int, 1>& sublabel_6_29)
{
    return dfi3129::Dui007(sublabel_6_29);
}

std::string Dfi3129Dui008(const std::array<int, 1>& sublabel_7_29)
{
    return dfi3129::Dui008(sublabel_7_29);
}

std::string Dfi3130Dui001(const std::array<int, 1>& sublabel_0_30)
{
    return dfi3130::Dui001(sublabel_0_30);
}

std::string Dfi3130Dui002(const std::array<int, 1>& sublabel_1_30)
{
    return dfi3130::Dui002(sublabel_1_30);
}

std::string Dfi3130Dui003(const std::array<int, 1>& sublabel_2_30)
{
    return dfi3130::Dui003(sublabel_2_30);
}

std::string Dfi3130Dui004(const std::array<int, 1>& sublabel_3_30)
{
    return dfi3130::Dui004(sublabel_3_30);
}

std::string Dfi3130Dui005(const std::array<int, 1>& sublabel_4_30)
{
    return dfi3130::Dui005(sublabel_4_30);
}

std::string Dfi3130Dui006(const std::array<int, 1>& sublabel_5_30)
{
    return dfi3130::Dui006(sublabel_5_30);
}

std::string Dfi3130Dui007(const std::array<int, 1>& sublabel_6_30)
{
    return dfi3130::Dui007(sublabel_6_30);
}

std::string Dfi3130Dui008(const std::array<int, 1>& sublabel_7_30)
{
    return dfi3130::Dui008(sublabel_7_30);
}

std::string Dfi3131Dui001(const std::array<int, 1>& sublabel_0_31)
{
    return dfi3131::Dui001(sublabel_0_31);
}

std::string Dfi3131Dui002(const std::array<int, 1>& sublabel_1_31)
{
    return dfi3131::Dui002(sublabel_1_31);
}

std::string Dfi3131Dui003(const std::array<int, 1>& sublabel_2_31)
{
    return dfi3131::Dui003(sublabel_2_31);
}

std::string Dfi3131Dui004(const std::array<int, 1>& sublabel_3_31)
{
    return dfi3131::Dui004(sublabel_3_31);
}

std::string Dfi3131Dui005(const std::array<int, 1>& sublabel_4_31)
{
    return dfi3131::Dui005(sublabel_4_31);
}

std::string Dfi3131Dui006(const std::array<int, 1>& sublabel_5_31)
{
    return dfi3131::Dui006(sublabel_5_31);
}

std::string Dfi3131Dui007(const std::array<int, 1>& sublabel_6_31)
{
    return dfi3131::Dui007(sublabel_6_31);
}

std::string Dfi3131Dui008(const std::array<int, 1>& sublabel_7_31)
{
    return dfi3131::Dui008(sublabel_7_31);
}

std::string Dfi3140Dui001(const std::array<int, 1>& sub_sublabel_0)
{
    return dfi3140::Dui001(sub_sublabel_0);
}

std::string Dfi3140Dui002(const std::array<int, 1>& sub_sublabel_1)
{
    return dfi3140::Dui002(sub_sublabel_1);
}

std::string Dfi3140Dui003(const std::array<int, 1>& sub_sublabel_2)
{
    return dfi3140::Dui003(sub_sublabel_2);
}

std::string Dfi3140Dui004(const std::array<int, 1>& sub_sublabel_3)
{
    return dfi3140::Dui004(sub_sublabel_3);
}

std::string Dfi3140Dui005(const std::array<int, 1>& sub_sublabel_4)
{
    return dfi3140::Dui005(sub_sublabel_4);
}

std::string Dfi3140Dui006(const std::array<int, 1>& sub_sublabel_5)
{
    return dfi3140::Dui006(sub_sublabel_5);
}

std::string Dfi3140Dui007(const std::array<int, 1>& sub_sublabel_6)
{
    return dfi3140::Dui007(sub_sublabel_6);
}

std::string Dfi3140Dui008(const std::array<int, 1>& sub_sublabel_7)
{
    return dfi3140::Dui008(sub_sublabel_7);
}

std::string Dfi3140Dui009(const std::array<int, 1>& sub_sublabel_8)
{
    return dfi3140::Dui009(sub_sublabel_8);
}

std::string Dfi3140Dui010(const std::array<int, 1>& sub_sublabel_9)
{
    return dfi3140::Dui010(sub_sublabel_9);
}

std::string Dfi3140Dui011(const std::array<int, 1>& sub_sublabel_10)
{
    return dfi3140::Dui011(sub_sublabel_10);
}

std::string Dfi3140Dui012(const std::array<int, 1>& sub_sublabel_11)
{
    return dfi3140::Dui012(sub_sublabel_11);
}

std::string Dfi3140Dui013(const std::array<int, 1>& sub_sublabel_12)
{
    return dfi3140::Dui013(sub_sublabel_12);
}

std::string Dfi3140Dui014(const std::array<int, 1>& sub_sublabel_13)
{
    return dfi3140::Dui014(sub_sublabel_13);
}

std::string Dfi3140Dui015(const std::array<int, 1>& sub_sublabel_14)
{
    return dfi3140::Dui015(sub_sublabel_14);
}

std::string Dfi3140Dui016(const std::array<int, 1>& sub_sublabel_15)
{
    return dfi3140::Dui016(sub_sublabel_15);
}

std::string Dfi3140Dui017(const std::array<int, 1>& sub_sublabel_16)
{
    return dfi3140::Dui017(sub_sublabel_16);
}

std::string Dfi3140Dui018(const std::array<int, 1>& sub_sublabel_17)
{
    return dfi3140::Dui018(sub_sublabel_17);
}

std::string Dfi3140Dui019(const std::array<int, 1>& sub_sublabel_18)
{
    return dfi3140::Dui019(sub_sublabel_18);
}

std::string Dfi3140Dui020(const std::array<int, 1>& sub_sublabel_19)
{
    return dfi3140::Dui020(sub_sublabel_19);
}

std::string Dfi3140Dui021(const std::array<int, 1>& sub_sublabel_20)
{
    return dfi3140::Dui021(sub_sublabel_20);
}

std::string Dfi3140Dui022(const std::array<int, 1>& sub_sublabel_21)
{
    return dfi3140::Dui022(sub_sublabel_21);
}

std::string Dfi3140Dui023(const std::array<int, 1>& sub_sublabel_22)
{
    return dfi3140::Dui023(sub_sublabel_22);
}

std::string Dfi3140Dui024(const std::array<int, 1>& sub_sublabel_23)
{
    return dfi3140::Dui024(sub_sublabel_23);
}

std::string Dfi3140Dui025(const std::array<int, 1>& sub_sublabel_24)
{
    return dfi3140::Dui025(sub_sublabel_24);
}

std::string Dfi3140Dui026(const std::array<int, 1>& sub_sublabel_25)
{
    return dfi3140::Dui026(sub_sublabel_25);
}

std::string Dfi3140Dui027(const std::array<int, 1>& sub_sublabel_26)
{
    return dfi3140::Dui027(sub_sublabel_26);
}

std::string Dfi3140Dui028(const std::array<int, 1>& sub_sublabel_27)
{
    return dfi3140::Dui028(sub_sublabel_27);
}

std::string Dfi3140Dui029(const std::array<int, 1>& sub_sublabel_28)
{
    return dfi3140::Dui029(sub_sublabel_28);
}

std::string Dfi3140Dui030(const std::array<int, 1>& sub_sublabel_29)
{
    return dfi3140::Dui030(sub_sublabel_29);
}

std::string Dfi3140Dui031(const std::array<int, 1>& sub_sublabel_30)
{
    return dfi3140::Dui031(sub_sublabel_30);
}

std::string Dfi3140Dui032(const std::array<int, 1>& sub_sublabel_31)
{
    return dfi3140::Dui032(sub_sublabel_31);
}

