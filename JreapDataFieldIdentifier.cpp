//this is the dfi (data Field Identifier) converter for MILSTD 3011D
// This library contains all the DFIs and the related DataUseIdentifiers (DUIs) for the JREAP-C fields.

#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

/* DFI 3000 DUI 001 PERCENT EXCEEDING LATENCY 7 bits*/
std::string PercentExceedingLatency(std::array<int, 7> percentExceedingLatency)
{
    int percentExceedingLatencyInt = 0;
    //copy the bits from the array into an integer
    for (int i = 0; i < 7; i++)
    {
        percentExceedingLatencyInt += percentExceedingLatency[i] * std::pow(2, 6 - i);
    }
    std::string output = "";
    switch (percentExceedingLatencyInt)
    {
    case 0 ... 100:
        output = std::to_string(percentExceedingLatencyInt) + "% ///-> ";
        for (std::size_t i = 0; i < percentExceedingLatency.size(); i++)
        {
            output += std::to_string(percentExceedingLatency[i]);
        }
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3001 DUI 001 TRANSMISSION SEQUENCE NUMBER 8 bits*/
std::string TransmissionSequenceNumber(std::array<int, 8> transmissionSequenceNumber)
{
    int transmissionSequenceNumberInt = 0;
    for (int i = 0; i < 8; i++)
    {
        transmissionSequenceNumberInt += transmissionSequenceNumber[i] * std::pow(2, 7 - i);
    }
    std::string output = "";
    if (transmissionSequenceNumberInt >= 0 && transmissionSequenceNumberInt <= 255)
    {
        output = std::to_string(transmissionSequenceNumberInt) + " ///-> ";
        for (std::size_t i = 0; i < transmissionSequenceNumber.size(); i++)
        {
            output += std::to_string(transmissionSequenceNumber[i]);
        }
    }
    else
    {
        output = "Illegal ///-> ";
        for (std::size_t i = 0; i < transmissionSequenceNumber.size(); i++)
        {
            output += std::to_string(transmissionSequenceNumber[i]);
        }
    }
    return output;
}
/* DFI 3001 DUI 002 TRANSMISSION SEQUENCE LIST COUNT 7 bits*/
std::string TransmissionSequenceListCount(std::array<int, 7> transmissionSequenceListCount)
{
    // A ONE BYTE FIELD THAT INCREMENTS BY ONE FOR EACH PACKET TRANSMITTED BY A JREAP PROCESSOR  ON A JREAP TOKEN PASSING NETWORK.
    int transmissionSequenceListCountInt = 0;
    for (int i = 0; i < 7; i++)
    {
        transmissionSequenceListCountInt += transmissionSequenceListCount[i] * std::pow(2, 6 - i);
    }
    std::string output = "";
    if (transmissionSequenceListCountInt >= 0 && transmissionSequenceListCountInt <= 127)
    {
        output = std::to_string(transmissionSequenceListCountInt) + " ///-> ";
        for (std::size_t i = 0; i < transmissionSequenceListCount.size(); i++)
        {
            output += std::to_string(transmissionSequenceListCount[i]);
        }
    }
    else
    {
        output = "Illegal ///-> ";
        for (std::size_t i = 0; i < transmissionSequenceListCount.size(); i++)
        {
            output += std::to_string(transmissionSequenceListCount[i]);
        }
    }
    return output;
}
/* DFI 3002 DUI 001 ADD/DELETE INDICATOR 1 bit*/
std::string AddDeleteIndicator(std::array<int, 1> addDeleteIndicator)
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
std::string ActiveInactiveFlag(std::array<int, 1> activeInactiveFlag)
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
std::string AcknowledgementRequestFlag(std::array<int, 1> acknowledgementRequestFlag)
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
std::string CommandAndControlIndicatorOverride(std::array<int, 1> commandAndControlIndicatorOverride)
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
std::string EmergencyIndicatorOverride(std::array<int, 1> emergencyIndicatorOverride)
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
std::string ForceTellIndicatorOverride(std::array<int, 1> forceTellIndicatorOverride)
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
std::string LastPointFlag(std::array<int, 1> lastPointFlag)
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
std::string RectangleFlag(std::array<int, 1> rectangleFlag)
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
std::string RelayFlag(std::array<int, 1> relayFlag)
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
std::string SimulationIndicatorFilterFlag(std::array<int, 1> simulationIndicatorFilterFlag)
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
std::string TransmissionTimeReferenceFlag(std::array<int, 1> transmissionTimeReferenceFlag)
{
    if (transmissionTimeReferenceFlag[0] == 1)
    {
        return "within Time Accuracy ///-> 1";
    }
    else
    {
        return "Not within Time Accuracy ///-> 0";
    }
}
/* DFI 3002 DUI 012 UPPER ALTITUDE LIMIT FLAG 1 bit*/
std::string UpperAltitudeLimitFlag(std::array<int, 1> upperAltitudeLimitFlag)
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
std::string LowerAltitudeLimitFlag(std::array<int, 1> lowerAltitudeLimitFlag)
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
std::string J2820FilterFlag(std::array<int, 1> j2820FilterFlag)
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
std::string J28XFilterFlag(std::array<int, 1> j28XFilterFlag)
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
std::string SpecialProcessingIndicatorFilterFlag(std::array<int, 1> specialProcessingIndicatorFilterFlag)
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
std::string TypeFilter(std::array<int, 1> typeFilter)
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
std::string GeographicFilter(std::array<int, 1> geographicFilter)
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
std::string AllFilters(std::array<int, 1> allFilters)
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
std::string AlternateNetworkControllerAssignmentFlag(std::array<int, 1> alternateNetworkControllerAssignmentFlag)
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
std::string AlternateNetworkControllerAssignmentRecognition(std::array<int, 1> alternateNetworkControllerAssignmentRecognition)
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

/* DFI 3003 DUI 001 AGE LIMIT VALUE 8 bits SPECIFIED IN ONE SECOND INCREMENTS.
 * MESSAGES OLDER THAN THIS LIMIT WILL BE FILTERED BY THE DATA AGE LIMIT*/
std::string AgeLimitValue(std::array<int, 8> ageLimitValue)
{
    //no limit 0
    // 1 through 255 is the age limit in seconds
    int ageLimitValueInt = 0;
    for (int i = 0; i < 8; i++)
    {
        ageLimitValueInt += ageLimitValue[i] * std::pow(2, 7 - i);
    }
    std::string output = "";
    if (ageLimitValueInt == 0)
    {
        output = "No limit ///-> 00000000";
    }
    else
    {
        output = std::to_string(ageLimitValueInt) + " seconds ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < ageLimitValue.size(); i++)
        {
            binaryset.append(std::to_string(ageLimitValue[i]));
        }
        output += binaryset;
    }

    return output;
}

/* DFI 3003 DUI 002 AVERAGE RECEIVED DATA MEDIA LATENCY 16 bits*/
std::string AverageReceivedDataMediaLatency(std::array<int, 16> averageReceivedDataMediaLatency)
{
    int averageReceivedDataMediaLatencyInt = 0;
    // 0 THROUGH 65535 (int 32) specific interval on the data that the JRE Processor is receiving from the source in 1/32 second increments. 
    // For example, a value of 32 would indicate that the average latency of the data being received from the source is 1 second. 
    //A value of 0 would indicate that the average latency is less than 1/32 second.
    //it will respond in 0 through 2047 and 31/32 seconds
    for (int i = 0; i < 16; i++)
    {
        averageReceivedDataMediaLatencyInt += averageReceivedDataMediaLatency[i] * std::pow(2, 15 - i);
    }
    std::string output = "";
    if (averageReceivedDataMediaLatencyInt == 0)
    {
        output = "Less than 1/32 second ///-> 0000000000000000";
    }
    else
    {
        double latencyInSeconds = averageReceivedDataMediaLatencyInt / 32.0;
        output = std::to_string(latencyInSeconds) + " seconds ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < averageReceivedDataMediaLatency.size(); i++)
        {
            binaryset.append(std::to_string(averageReceivedDataMediaLatency[i]));
        }
        output += binaryset;
    }
    return output;
}
/* DFI 3003 DUI 003 DATA AGE 13 bits
Typical response is 0 THROUGH 255 AND 31/32 seconds atual values are 0-8191 */
std::string DataAge(std::array<int, 13> dataAge)
{
    int dataAgeInt = 0;
    for (int i = 0; i < 13; i++)
    {
        dataAgeInt += dataAge[i] * std::pow(2, 12 - i);
    }
    std::string output = "";
    if (dataAgeInt == 0)
    {
        output = "Less than 1/32 second ///-> 0000000000000";
    }
    else
    {
        double ageInSeconds = dataAgeInt / 32.0;
        output = std::to_string(ageInSeconds) + " seconds ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < dataAge.size(); i++)
        {
            binaryset.append(std::to_string(dataAge[i]));
        }
        output += binaryset;
    }
    return output;
}

/* DFI 3003 DUI 004 DATA VALID TIME 28 bits
 0 – 86399 AND 1023/1024 SECONDS 0 - 88473599  88473600 THROUGH  268435455 are illegal*/
std::string DataValidTime(std::array<int, 28> dataValidTime)
{
    int dataValidTimeInt = 0;
    for (std::size_t i = 0; i < dataValidTime.size(); i++)
    {
        dataValidTimeInt += dataValidTime[i] * std::pow(2, 27 - i);
    }
    std::string output = "";
    if (dataValidTimeInt >= 0 && dataValidTimeInt <= 88473599)
    {
        double timeInSeconds = dataValidTimeInt / 1024.0;
        output = std::to_string(timeInSeconds) + " seconds since 00:00:00 ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < dataValidTime.size(); i++)
        {
            binaryset.append(std::to_string(dataValidTime[i]));
        }
        output += binaryset;
    }
    else
    {
        output = "Illegal ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < dataValidTime.size(); i++)
        {
            binaryset.append(std::to_string(dataValidTime[i]));
        }
        output += binaryset;
    }
    return output;
}
/* DFI 3003 DUI 005 EVENT TIME ACCURACY 4 bits*/
std::string EventTimeAccuracy(std::array<int, 4> eventTimeAccuracy)
{
    int eventTimeAccuracyInt = 0;
    for (int i = 0; i < 4; i++)
    {
        eventTimeAccuracyInt += eventTimeAccuracy[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    switch (eventTimeAccuracyInt)
    {
    case 0:
        output = "No statement ///-> 0000";
        break;
    case 1:
        output = "Less than or equal to 1 ms ///-> 0001";
        break;
    case 2:
        output = "Greater than 1 ms, less than or equal to 2 ms ///-> 0010";
        break;
    case 3:
        output = "Greater than 2 ms, less than or equal to 4 ms ///-> 0011";
        break;
    case 4:
        output = "Greater than 4 ms, less than or equal to 8 ms ///-> 0100";
        break;
    case 5:
        output = "Greater than 8 ms, less than or equal to 16 ms ///-> 0101";
        break;
    case 6:
        output = "Greater than 16 ms, less than or equal to 32 ms ///-> 0110";
        break;
    case 7:
        output = "Greater than 32 ms, less than or equal to 64 ms ///-> 0111";
        break;
    case 8:
        output = "Greater than 64 ms, less than or equal to 128 ms ///-> 1000";
        break;
    case 9:
        output = "Greater than 128 ms, less than or equal to 256 ms ///->1001";
        break;
    case 10:
        output = "Greater than 256 ms, less than or equal to 512 ms ///->1010";
        break;
    case 11:
        output = "Greater than 512 ms, less than or equal to1024 ms ///->1011";
        break;
    case 12:
        output = "Greater than1024 ms, less than or equal to2048 ms ///->1100";
        break;
    case 13:
        output = "Greater than2048 ms, less than or equal to4096 ms ///->1101";
        break;
    case 14:
        output = "Greater than4096 ms, less than or equal to8192 ms ///->1110";
        break;
    case 15:
        output = "Greater than8192 ms, less than or equal to16384 ms ///->1111";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3003 DUI 007 MAXIMUM LATENCY 16 bits
 0 THROUGH 2047 AND 31/32 SECONDS 0 throught 65535*/
std::string MaximumLatency(std::array<int, 16> maximumLatency)
{
    int maximumLatencyInt = 0;
    //take all the bits and convert them into an int32
    for (int i = 0; i < 16; i++)
    {
        maximumLatencyInt += maximumLatency[i] * std::pow(2, 15 - i);
    }
    std::string output = "";
    if (maximumLatencyInt == 0)
    {
        output = "Less than 1/32 second ///-> 0000000000000000";
    }
    else
    {
        double latencyInSeconds = maximumLatencyInt / 32.0;
        output = std::to_string(latencyInSeconds) + " seconds ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < maximumLatency.size(); i++)
        {
            binaryset.append(std::to_string(maximumLatency[i]));
        }
        output += binaryset;
    }
    return output;
}
/* DFI 3003 DUI 008 RX JRE RECEIVE TIME (R2) 28 bits
same as coding for JRE Transmit Time*/
std::string RxJreReceiveTime(std::array<int, 28> rxJreReceiveTime)
{
//process through JRE Transmit Time since it is the same coding
    return TxJreTransmitTime(rxJreReceiveTime);
}   
/* DFI 3003 DUI 009 TX JRE TRANSMIT TIME (T1) 28 bits*/
std::string TxJreTransmitTime(std::array<int, 28> txJreTransmitTime)
{
    int txJreTransmitTimeInt = 0;
    for (std::size_t i = 0; i < txJreTransmitTime.size(); i++)
    {
        txJreTransmitTimeInt += txJreTransmitTime[i] * std::pow(2, 27 - i);
    }
    std::string output = "";
    if (txJreTransmitTimeInt >= 0 && txJreTransmitTimeInt <= 88473599)
    {
        double timeInSeconds = txJreTransmitTimeInt / 1024.0;
        output = std::to_string(timeInSeconds) + " seconds since 00:00:00 ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < txJreTransmitTime.size(); i++)
        {
            binaryset.append(std::to_string(txJreTransmitTime[i]));
        }
        output += binaryset;
    }
    else
    {
        output = "Illegal ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < txJreTransmitTime.size(); i++)
        {
            binaryset.append(std::to_string(txJreTransmitTime[i]));
        }
        output += binaryset;
    }
    return output;
}
/* DFI 3003 DUI 010 RX JRE TRANSMIT TIME (T2) 28 bits*/
std::string RxJreTransmitTime(std::array<int, 28> rxJreTransmitTime)
{
    //same coding as Tx JRE Transmit Time
    return TxJreTransmitTime(rxJreTransmitTime);
}   
/* DFI 3003 DUI 011 TIME ACCURACY 4 bits*/
std::string TimeAccuracy(std::array<int, 4> timeAccuracy)
{
    int timeAccuracyInt = 0;
    for (int i = 0; i < 4; i++)
    {
        timeAccuracyInt += timeAccuracy[i] * std::pow(2, 3 - i);
    }
    std::string output = "";
    switch (timeAccuracyInt)
    {
    case 0:
        output = "No statement ///-> 0000";
        break;
    case 1:
        output = "Less than or equal to 1 ms ///-> 0001";
        break;
    case 2:
        output = "Greater than 1 ms, less than or equal to 2 ms ///-> 0010";
        break;
    case 3:
        output = "Greater than 2 ms, less than or equal to 4 ms ///-> 0011";
        break;
    case 4:
        output = "Greater than 4 ms, less than or equal to 8 ms ///-> 0100";
        break;
    case 5:
        output = "Greater than 8 ms, less than or equal to 16 ms ///-> 0101";
        break;
    case 6:
        output = "Greater than 16 ms, less than or equal to 32 ms ///-> 0110";
        break;
    case 7:
        output = "Greater than 32 ms, less than or equal to 64 ms ///-> 0111";
        break;
    case 8:
        output = "Greater than 64 ms, less than or equal to 128 ms ///->1000";
        break;
    case 9:
        output = "Greater than 128 ms, less than or equal to256 ms ///->1001";
        break;
    case 10:
        output = "Greater than 256 ms, less than or equal to 512 ms ///->1010";
        break;
    case 11:
        output = "Greater than 512 ms, less than or equal to 1024 ms ///->1011";
        break;
    case 12:
        output = "Greater than 1024 ms, less than or equal to 2048 ms ///->1100";
        break;
    case 13:
        output = "Greater than 2048 ms, less than or equal to 4096 ms ///->1101";
        break;
    case 14:
        output = "Greater than 4096 ms, less than or equal to 8192 ms ///->1110";
        break;
    case 15:
        output = "Greater than 8192 ms, less than or equal to 16384 ms ///->1111";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3003 DUI 012 EVENT TIME 28 bits
 0 – 86399 AND 1023/1024 seconds 0- 88473599,  88473600-268435455 are illegal  
 NUMBER OF SECONDS ELAPSED PAST MIDNIGHT in 1/1024 SECOND INCREMENTS*/
std::string EventTime(std::array<int, 28> eventTime)
{
    int eventTimeInt = 0;
    for (std::size_t i = 0; i < eventTime.size(); i++)
    {
        eventTimeInt += eventTime[i] * std::pow(2, 27 - i);
    }
    std::string output = "";
    if (eventTimeInt >= 0 && eventTimeInt <= 88473599)
    {
        double timeInSeconds = eventTimeInt / 1024.0;
        output = std::to_string(timeInSeconds) + " seconds since 00:00:00 ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < eventTime.size(); i++)
        {
            binaryset.append(std::to_string(eventTime[i]));
        }
        output += binaryset;
    }
    else
    {
        output = "Illegal ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < eventTime.size(); i++)
        {
            binaryset.append(std::to_string(eventTime[i]));
        }
        output += binaryset;
    }
    return output;
}   
/* DFI 3003 DUI 013 INTERVAL TIME 10 bits
 0-no interval 1-1023 seconds*/
std::string IntervalTime(std::array<int, 10> intervalTime)
{
    int intervalTimeInt = 0;
    for (int i = 0; i < 10; i++)
    {
        intervalTimeInt += intervalTime[i] * std::pow(2, 9 - i);
    }
    std::string output = "";
    if (intervalTimeInt == 0)
    {
        output = "No interval ///-> 0000000000";
    }
    else
    {
        output = std::to_string(intervalTimeInt) + " seconds ///-> ";
        std::string binaryset = "";
        for (std::size_t i = 0; i < intervalTime.size(); i++)
        {
            binaryset.append(std::to_string(intervalTime[i]));
        }
        output += binaryset;
    }
    return output;
}   
/* DFI 3003 DUI 014 TIME ACCURACY (R2) 4 bits 
Same as Time Accuracy*/
std::string TimeAccuracyR2(std::array<int, 4> timeAccuracyR2)
{
    //same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyR2);
}
/* DFI 3003 DUI 015 TIME ACCURACY (T1) 4 bits*/
std::string TimeAccuracyT1(std::array<int, 4> timeAccuracyT1)
{
    //same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyT1);
}
/* DFI 3003 DUI 016 TIME ACCURACY (T2) 4 bits*/
std::string TimeAccuracyT2(std::array<int, 4> timeAccuracyT2)
{
    //same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyT2);
}
/* DFI 3004 DUI 001 JRE NC, C 1 bit*/
std::string JreNcC(std::array<int, 1> jreNcC)
{
    if (jreNcC[0] == 1)
    {
        return "Capable ///-> 1";
    }
    else
    {
        return "Not Capable ///-> 0";
    }
}
/* DFI 3004 DUI 002 RTTIME, C*/
std::string RttimeC(std::array<int, 1> rttimeC)
{
    return JreNcC(rttimeC);
}
/* DFI 3004 DUI 003 FIXED DELAY, C 1 bit*/
std::string FixedDelayC(std::array<int, 1> fixedDelayC)
{
    return JreNcC(fixedDelayC);
}
/* DFI 3004 DUI 004 EVENT STROBE, C 1 bit*/
std::string EventStrobeC(std::array<int, 1> eventStrobeC)
{
    return JreNcC(eventStrobeC);
}
/* DFI 3004 DUI 005 UTC, C 1 bit*/
std::string UtcC(std::array<int, 1> utcC)
{
    return JreNcC(utcC);
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
        output = "No header ///-> 0000";
        break;
    case 1:
        output = "Message Group Header ///-> 0001";
        break;
    case 2:
        output = "Message Header ///-> 0010";
        break;
    case 3:
        output = "Filter Header ///-> 0011";
        break;
    case 4:
        output = "Requested Filter Header ///-> 0100";
        break;
    default:
        output = "Illegal ///-> ";
        break;
    }
    return output;
}
/* DFI 3007 DUI 002 MESSAGE GROUP HEADER TYPE*/
/* DFI 3007 DUI 003 HEADER TYPE*/

/* DFI 3008 DUI 001 MESSAGE TYPE*/
/* DFI 3008 DUI 002 MANAGEMENT MESSAGE SUBTYPE*/
/* DFI 3008 DUI 003 FILTER MESSAGE TYPE*/
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
    //we take in the four bits and it should output one of these responses
    //Normal 0
    //illegal 1 through 2
    //undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch(acknowledgementProtocolInt)
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
    //we take in the four bits and it should output one of these responses
    //Normal 0
    //Processor Ack 1
    //illegal 2
    //undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch(acknowledgementProtocolInt)
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
    //we take in the four bits and it should output one of these responses
    //Normal 0
    //Processor Ack 1
    //Operator Ack 2
    //undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch(acknowledgementProtocolInt)
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
    //we take in the four bits and it should output one of these responses
    //illegal 0
    //Processor Ack 1
    //Illegal 2
    //undefined 3 through 15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch(acknowledgementProtocolInt)
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
    //we take in the four bits and it should output one of these responses
    //Normal 0
    //Illegal 1-2
    //undefined 3-15
    int acknowledgementProtocolInt = 0;
    std::string output = "";
    for (int i = 0; i < 4; i++)
    {
        acknowledgementProtocolInt += acknowledgementProtocol[i] * std::pow(2, 3 - i);
    }
    switch(acknowledgementProtocolInt)
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
