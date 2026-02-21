#include <array>
#include <string>
#include <cmath>

namespace dfi3034 {
//repeated function for Dfi 3034
//convert 8 bit array into a single int value
int BinaryConversion8bit(const std::array<int, 8>& inputArray)
{
    int result = 0;
    for (std::size_t i = 0; i < inputArray.size(); i++)
    {
        result = result * 2 + inputArray[i];
    }
    return result;
}
//end of repeated functions

/* DFI 3034 DUI 001 ERROR CODE, 1 8 bits*/
std::string Dui001(const std::array<int, 8>& errorCode1)
{
    int code = BinaryConversion8bit(errorCode1);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code >= 1 && code <= 6) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}

/* DFI 3034 DUI 002 ERROR CODE, 2 8 bits*/
std::string Dui002(const std::array<int, 8>& errorCode2)
{
    int code = BinaryConversion8bit(errorCode2);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code == 1) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code == 2) {
        return "Not Implemented ///-> " + std::to_string(code);
    } else if (code >= 3 && code <= 6) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
/* DFI 3034 DUI 003 ERROR CODE, 3 8 bits*/
std::string Dui003(const std::array<int, 8>& errorCode3)
{
    int code = BinaryConversion8bit(errorCode3);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code >= 1 && code <= 4) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code == 5) {
        return "Resource Not Available ///-> " + std::to_string(code);
    } else if (code == 6) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC OR UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
/* DFI 3034 DUI 004 ERROR CODE, 4 8 bits*/
std::string Dui004(const std::array<int, 8>& errorCode4)
{
    int code = BinaryConversion8bit(errorCode4);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code == 1) {
        return "Missing Fragment ///-> " + std::to_string(code);
    } else if (code >= 2 && code <= 5) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code == 6) {
        return "Processing Timeout ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC OR UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
/* DFI 3034 DUI 005 ERROR CODE, 5 8 bits*/
std::string Dui005(const std::array<int, 8>& errorCode5)
{
    int code = BinaryConversion8bit(errorCode5);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code == 1) {
        return "Missing Fragment ///-> " + std::to_string(code);
    } else if (code == 2) {
        return "Not Implemented ///-> " + std::to_string(code);
    } else if (code >= 3 && code <= 5) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code == 6) {
        return "Processing Timeout ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC OR UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
/* DFI 3034 DUI 006 ERROR CODE, 6 8 bits*/
std::string Dui006(const std::array<int, 8>& errorCode6)
{
    int code = BinaryConversion8bit(errorCode6);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code == 1) {
        return "Missing Fragment ///-> " + std::to_string(code);
    } else if (code == 2) {
        return "Not Implemented ///-> " + std::to_string(code);
    } else if (code == 3) {
        return "Lockout/Restricted ///-> " + std::to_string(code);
    } else if (code == 4) {
        return "Illegal ///-> " + std::to_string(code);
    } else if (code == 5) {
        return "Resource Not Available ///-> " + std::to_string(code);
    } else if (code == 6) {
        return "Processing Timeout ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC OR UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
/* DFI 3034 DUI 007 ERROR CODE, 7 8 bits*/
std::string Dui007(const std::array<int, 8>& errorCode7)
{
    int code = BinaryConversion8bit(errorCode7);
    if(code == 0) {
        return "No Error ///-> " + std::to_string(code);
    } else if (code == 1) {
        return "Missing Fragment ///-> " + std::to_string(code);
    } else if (code == 2) {
        return "Not Implemented ///-> " + std::to_string(code);
    } else if (code == 3) {
        return "Lockout/Restricted ///-> " + std::to_string(code);
    } else if (code == 4) {
        return "Message Error ///-> " + std::to_string(code);
    } else if (code == 5) {
        return "Resource Not Available ///-> " + std::to_string(code);
    } else if (code == 6) {
        return "Processing Timeout ///-> " + std::to_string(code);
    } else if (code >= 7 && code <= 31) {
        return "COMMON UNUSED ///-> " + std::to_string(code);
    } else if (code >= 32 && code <= 255) {
        return "SUBTYPE SPECIFIC OR UNUSED ///-> " + std::to_string(code);
    }
    else {
        return "Illegal ///-> " + std::to_string(code);
    }
}
}
