#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

std::string dui001(const std::array<int, 8> &transmissionSequenceNumber)
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

std::string dui002(const std::array<int, 7> &transmissionSequenceListCount)
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