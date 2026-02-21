#include <array>
#include <string>
#include <cstdint>

namespace dfi3036 {
//repeated function for Dfi 3036
//take in a binary array 16 bits long and convert it to an octal value
int BinaryConversion16bitOctal(const std::array<int, 16>& inputArray) {
    std::uint16_t value = 0;

    for (int bit : inputArray) {
        if (bit != 0 && bit != 1) {
            return -1; // invalid input
        }
        value = static_cast<std::uint16_t>((value << 1) | bit);
    }

    int octalValue = 0;
    int placeValue = 1;

    do {
        octalValue += (value % 8) * placeValue;
        value /= 8;
        placeValue *= 10;
    } while (value > 0);

    return octalValue;
}
//end of repeated functions

/* DFI 3036 DUI 001 JRE SENDER ID 16 bits octal output*/
std::string Dfi3036Dui001(const std::array<int, 16>& jreSenderId)
{
    int octalValue = BinaryConversion16bitOctal(jreSenderId);
    if (octalValue == -1) {
        return "Illegal JRE Sender ID ///-> " + std::to_string(octalValue);
    }
    return "JRE Sender ID (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 002 JRE SENDER ID, 1 16 bits octal output*/
std::string Dfi3036Dui002(const std::array<int, 16>& jreSenderId1)
{
    int octalValue = BinaryConversion16bitOctal(jreSenderId1);
    if (octalValue == -1) {
        return "Illegal JRE Sender ID ///-> " + std::to_string(octalValue);
    }
    return "JRE Sender ID, 1 (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 003 JRE SENDER ID, 2 16 bits octal output*/
std::string Dfi3036Dui003(const std::array<int, 16>& jreSenderId2)
{
    int octalValue = BinaryConversion16bitOctal(jreSenderId2);
    if (octalValue == -1) {
        return "Illegal JRE Sender ID ///-> " + std::to_string(octalValue);
    }
    return "JRE Sender ID, 2 (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 004 JRE SENDER ID, 3 16 bits octal output*/
std::string Dfi3036Dui004(const std::array<int, 16>& jreSenderId3)
{
    int octalValue = BinaryConversion16bitOctal(jreSenderId3);
    if (octalValue == -1) {
        return "Illegal JRE Sender ID ///-> " + std::to_string(octalValue);
    }
    return "JRE Sender ID, 3 (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 005 JRE NETWORK PARTICIPANT 16 bits octal output*/
std::string Dfi3036Dui005(const std::array<int, 16>& jreNetworkParticipant)
{
    int octalValue = BinaryConversion16bitOctal(jreNetworkParticipant);
    if (octalValue == -1) {
        return "Illegal JRE Network Participant ///-> " + std::to_string(octalValue);
    }
    return "JRE Network Participant (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 020 DESTINATION ADDRESS 16 bits octal output*/
std::string Dfi3036Dui020(const std::array<int, 16>& destinationAddress)
{
    int octalValue = BinaryConversion16bitOctal(destinationAddress);
    if (octalValue == -1) {
        return "Illegal Destination Address ///-> " + std::to_string(octalValue);
    }
    return "Destination Address (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 021 ORIGINATING J-SERIES JRE SENDER ID 16 bits octal output*/
std::string Dfi3036Dui021(const std::array<int, 16>& originatingJSeriesJreSenderId)
{
    int octalValue = BinaryConversion16bitOctal(originatingJSeriesJreSenderId);
    if (octalValue == -1) {
        return "Illegal Originating J-Series JRE Sender ID ///-> " + std::to_string(octalValue);
    }
    return "Originating J-Series JRE Sender ID (Octal) ///-> " + std::to_string(octalValue);
}
/* DFI 3036 DUI 022 LINK INTERFACE UNIT 16 bits octal output*/
std::string Dfi3036Dui022(const std::array<int, 16>& linkInterfaceUnit)
{
    int octalValue = BinaryConversion16bitOctal(linkInterfaceUnit);
    if (octalValue == -1) {
        return "Illegal Link Interface Unit ///-> " + std::to_string(octalValue);
    }
    return "Link Interface Unit (Octal) ///-> " + std::to_string(octalValue);
}
}
