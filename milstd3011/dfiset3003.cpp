
#include <iostream>
#include <array>
#include <cmath>
#include <string>


/*internal repeated grouping responses*/
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

std::string txTransmitTime(std::array<int, 28> txJreTransmitTime)
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

/*end of repeated grouping responses*/

/* DFI 3003 DUI 001 AGE LIMIT VALUE 8 bits*/
std::string Dui001( std::array<int, 8> ageLimitValue)
{
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
std::string Dui002(std::array<int, 16> averageReceivedDataMediaLatency)
{
    int averageReceivedDataMediaLatencyInt = 0;
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
/* DFI 3003 DUI 003 DATA AGE 13 bits*/
std::string Dui003(std::array<int, 13> dataAge)
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
std::string Dui004(std::array<int, 28> dataValidTime)
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
std::string Dui005(std::array<int, 4> eventTimeAccuracy)
{
    // same coding as Time Accuracy
    return TimeAccuracy(eventTimeAccuracy);
}
/* DFI 3003 DUI 007 MAXIMUM LATENCY 16 bits
 0 THROUGH 2047 AND 31/32 SECONDS 0 throught 65535*/
std::string Dui007(std::array<int, 16> maximumLatency)
{
    int maximumLatencyInt = 0;
    // take all the bits and convert them into an int32
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
std::string Dui008(std::array<int, 28> rxJreReceiveTime)
{
    // process through JRE Transmit Time since it is the same coding
    return txTransmitTime(rxJreReceiveTime);
}
/* DFI 3003 DUI 009 TX JRE TRANSMIT TIME (T1) 28 bits*/
std::string Dui009(std::array<int, 28> txJreTransmitTime)
{
    return txTransmitTime(txJreTransmitTime);
}
/* DFI 3003 DUI 010 RX JRE TRANSMIT TIME (T2) 28 bits*/
std::string Dui010(std::array<int, 28> rxJreTransmitTime)
{
    // same coding as Tx JRE Transmit Time
    return txTransmitTime(rxJreTransmitTime);
}
/* DFI 3003 DUI 011 TIME ACCURACY 4 bits*/
std::string Dui011(std::array<int, 4> timeAccuracy)
{
    // same coding as Time Accuracy
    return TimeAccuracy(timeAccuracy);
}
/* DFI 3003 DUI 012 EVENT TIME 28 bits*/
std::string Dui012(std::array<int, 28> eventTime)
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
/* DFI 3003 DUI 013 INTERVAL TIME 10 bits*/
std::string Dui013(std::array<int, 10> intervalTime)
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
/* DFI 3003 DUI 014 TIME ACCURACY (R2) 4 bits*/
std::string Dui014(std::array<int, 4> timeAccuracyR2)
{
    // same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyR2);
}
/* DFI 3003 DUI 015 TIME ACCURACY (T1) 4 bits*/
std::string Dui015(std::array<int, 4> timeAccuracyT1)
{
    // same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyT1);
}
/* DFI 3003 DUI 016 TIME ACCURACY (T2) 4 bits*/
std::string Dui016(std::array<int, 4> timeAccuracyT2)
{
    // same coding as Time Accuracy
    return TimeAccuracy(timeAccuracyT2);
}
