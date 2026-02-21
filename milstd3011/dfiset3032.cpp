#include <array>
#include <string>
#include <cmath>

namespace dfi3032 {
//repeated function for Dfi 3032
std::string BinaryConversion16bit(const std::array<int, 16>& inputArray)
{
    std::string binaryset = "";
    for (std::size_t i = 0; i < inputArray.size(); i++)
    {
        binaryset.append(std::to_string(inputArray[i]));
    }
    return binaryset;
}
//end of repeated functions

/* DFI 3032 DUI 001 MESSAGE SEQUENCE NUMBER 16 bits*/
std::string Dui001(const std::array<int, 16>& messageSequenceNumber)
{
    int sequenceNumber = 0;
    for (int i = 0; i < 16; i++)
    {
        sequenceNumber += messageSequenceNumber[i] * std::pow(2, 15 - i);
    }
    std::string output = std::to_string(sequenceNumber) + " ///-> ";
    std::string binaryset = BinaryConversion16bit(messageSequenceNumber);
    // Valid range is 0-65535
    if (sequenceNumber >= 0 && sequenceNumber <= 65535) {
        output = "Message Sequence Number ///-> " + output;
    } else {
        output = "Illegal Message Sequence Number ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3032 DUI 002 ORIGINATING MESSAGE SEQUENCE NUMBER 16 bits*/
std::string Dui002(const std::array<int, 16>& originatingMessageSequenceNumber)
{
    int sequenceNumber = 0;
    for (int i = 0; i < 16; i++)
    {
        sequenceNumber += originatingMessageSequenceNumber[i] * std::pow(2, 15 - i);
    }
    std::string output = std::to_string(sequenceNumber) + " ///-> ";
    std::string binaryset = BinaryConversion16bit(originatingMessageSequenceNumber);
    // Valid range is 0-65535
    if (sequenceNumber >= 0 && sequenceNumber <= 65535) {
        output = "Originating Message Sequence Number ///-> " + output;
    } else {
        output = "Illegal Originating Message Sequence Number ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3032 DUI 003 J-SERIES MESSAGE SEQUENCE NUMBER 16 bits*/
std::string Dui003(const std::array<int, 16>& jSeriesMessageSequenceNumber)
{
    int sequenceNumber = 0;
    for (int i = 0; i < 16; i++)
    {
        sequenceNumber += jSeriesMessageSequenceNumber[i] * std::pow(2, 15 - i);
    }
    std::string output = std::to_string(sequenceNumber) + " ///-> ";
    std::string binaryset = BinaryConversion16bit(jSeriesMessageSequenceNumber);
    // Valid range is 0-65535
    if (sequenceNumber >= 0 && sequenceNumber <= 65535) {
        output = "J-Series Message Sequence Number ///-> " + output;
    } else {
        output = "Illegal J-Series Message Sequence Number ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3032 DUI 004 ORIGINATING J-SERIES MESSAGE SEQUENCE NUMBER 16 bits*/
std::string Dui004(const std::array<int, 16>& originatingJSeriesMessageSequenceNumber)
{
    int sequenceNumber = 0;
    for (int i = 0; i < 16; i++)
    {
        sequenceNumber += originatingJSeriesMessageSequenceNumber[i] * std::pow(2, 15 - i);
    }
    std::string output = std::to_string(sequenceNumber) + " ///-> ";
    std::string binaryset = BinaryConversion16bit(originatingJSeriesMessageSequenceNumber);
    // Valid range is 0-65535
    if (sequenceNumber >= 0 && sequenceNumber <= 65535) {
        output = "Originating J-Series Message Sequence Number ///-> " + output;
    } else {
        output = "Illegal Originating J-Series Message Sequence Number ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3032 DUI 005 NETWORK PARTICIPATION GROUP 16 bits*/
std::string Dui005(const std::array<int, 16>& networkParticipationGroup)
{
    int groupNumber = 0;
    for (int i = 0; i < 16; i++)
    {
        groupNumber += networkParticipationGroup[i] * std::pow(2, 15 - i);
    }
    std::string output = std::to_string(groupNumber) + " ///-> ";
    std::string binaryset = BinaryConversion16bit(networkParticipationGroup);
    // Valid range is 0-65535
    if (groupNumber >= 0 && groupNumber <= 65535) {
        output = "Network Participation Group ///-> " + output;
    } else {
        output = "Illegal Network Participation Group ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
}
