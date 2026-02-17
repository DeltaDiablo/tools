#include <array>
#include <cmath>
#include <string>

//repeated function for Dfi 3027
//take in an array of ints and convert to a single octal value and return the octal vlaue
int OctalConversion15bit(const std::array<int, 15>& inputArray)
{
    int inputInt = 0;
    for (int i = 0; i < 15; i++)
    {
        inputInt += inputArray[i] * std::pow(2, 14 - i);
    }
    // convert the int to octal
    int octal = 0;
    int i = 1;
    while (inputInt != 0)
    {
        octal += (inputInt % 8) * i;
        inputInt /= 8;
        i *= 10;
    }
    return octal;
}
int OctalConversion16bit(const std::array<int, 16>& inputArray)
{
    int inputInt = 0;
    for (int i = 0; i < 16; i++)
    {
        inputInt += inputArray[i] * std::pow(2, 15 - i);
    }
    // convert the int to octal
    int octal = 0;
    int i = 1;
    while (inputInt != 0)
    {
        octal += (inputInt % 8) * i;
        inputInt /= 8;
        i *= 10;
    }
    return octal;
}
//end of repeated functions

/* DFI 3027 DUI 001 SOURCE TRACK NUMBER 15 bits*/
std::string Dui001(const std::array<int, 15>& sourceTrackNumber)
{
    int octal = OctalConversion15bit(sourceTrackNumber);
    std::string output = std::to_string(octal) + " ///-> ";
    std::string binaryset = "";
    for (std::size_t i = 0; i < sourceTrackNumber.size(); i++)
    {
        binaryset.append(std::to_string(sourceTrackNumber[i]));
    }// ILLEGAL: 0
    // NUMERIC: 00001-00076 (OCTAL) - Valid track numbers
    // ILLEGAL: 00077 (OCTAL)
    // NUMERIC: 00100-00175 (OCTAL) - Valid track numbers
    // NUMERIC: 00176 (OCTAL) - Pseudo source track number address
    // NUMERIC: 00177 (OCTAL) - Collective address
    // NUMERIC: 00200-07776 (OCTAL) - Valid track numbers
    // ILLEGAL: 07777 (OCTAL)
    // NUMERIC: 10000-77776 (OCTAL) - Valid track numbers
    // NUMERIC: 77777 (OCTAL) - Link 16 network manager identifier
    // Octal ranges as integers for comparison
    if (octal == 0) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 1 && octal <= 76) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 77) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 100 && octal <= 175) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 176) {
        output = "Pseudo Source Track Number Address ///-> " + output;
    } else if (octal == 177) {
        output = "Collective Address ///-> " + output;
    } else if (octal >= 200 && octal <= 7776) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 7777) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 10000 && octal <= 77776) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 77777) {
        output = "Link 16 Network Manager Identifier ///-> " + output;
    } else {
        output = "Illegal Value ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3027 DUI 002 SECONDARY TRACK NUMBER 15 bits*/
std::string Dui002(const std::array<int, 15>& secondaryTrackNumber)
{
    int octal = OctalConversion15bit(secondaryTrackNumber);
    std::string output = std::to_string(octal) + " ///-> ";
    std::string binaryset = "";
    for (std::size_t i = 0; i < secondaryTrackNumber.size(); i++)
    {
        binaryset.append(std::to_string(secondaryTrackNumber[i]));
    }
    // ILLEGAL: 0
    // NUMERIC: 00001-00076 (OCTAL) - Valid track numbers
    // ILLEGAL: 00077 (OCTAL)
    // NUMERIC: 00100-00175 (OCTAL) - Valid track numbers
    // NUMERIC: 00176 (OCTAL) - Reserved for pseudo source track number address
    // NUMERIC: 00177 (OCTAL) - Collective address
    // NUMERIC: 00200-07776 (OCTAL) - Valid track numbers
    // ILLEGAL: 07777 (OCTAL)
    // NUMERIC: 10000-77776 (OCTAL) - Valid track numbers
    // NUMERIC: 77777 (OCTAL) - Link 16 network manager identifier
    if (octal == 0) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 1 && octal <= 76) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 77) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 100 && octal <= 175) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 176) {
        output = "Pseudo Source Track Number Address ///-> " + output;
    } else if (octal == 177) {
        output = "Collective Address ///-> " + output;
    } else if (octal >= 200 && octal <= 7776) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 7777) {
        output = "Illegal ///-> " + output;
    } else if (octal >= 10000 && octal <= 77776) {
        output = "Valid Track ///-> " + output;
    } else if (octal == 77777) {
        output = "Link 16 Network Manager Identifier ///-> " + output;
    } else {
        output = "Illegal Value ///-> " + output;
    }
    output = output + binaryset;
    return output;
}
/* DFI 3027 DUI 003 JRE SOURCE TRACK NUMBER 16 bits*/
std::string Dui003(const std::array<int, 16>& jreSourceTrackNumber)
{
    int octal = OctalConversion16bit(jreSourceTrackNumber);
    std::string output = "Valid Track ///-> " + std::to_string(octal);
    std::string binaryset = "";
    for (std::size_t i = 0; i < jreSourceTrackNumber.size(); i++)
    {
        binaryset.append(std::to_string(jreSourceTrackNumber[i]));
    }
//NUMERIC 000000 THROUGH 177777 A RANGE OF VALID OCTALTRACK NUMBERS.
    output = output + binaryset;
    return output;
}