#include <string>
#include <array>
#include <cmath>

namespace dfi3016 {
//repreated components for DFI 3016

std::string GetTransportDataWordCount(const std::array<int, 16>& binary)
{
    int decimalValue = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        decimalValue += binary[i] * std::pow(2, binary.size() - 1 - i);
    }

    std::string binaryString = "";
    for (std::size_t i = 0; i < binary.size(); i++)
    {
        binaryString.append(std::to_string(binary[i]));
    }
    std::string output = "";
    if (decimalValue == 0)
    {
        output = "No statement ///-> " + binaryString;
    }
    else
    {
        output = std::to_string(decimalValue) + " ///-> " + binaryString;
    }
    return output;
}

//end repeated components for DFI 3016

/* DFI 3016 DUI 001 APPLICATION DATA 32 bits*/
std::string Dui001(const std::array<int, 32>& applicationData)
{
    int decimalValue = 0;
    for (size_t i = 0; i < applicationData.size(); ++i) {
        decimalValue += applicationData[i] * std::pow(2, applicationData.size() - 1 - i);
    }

    std::string binaryString = "";
    for (std::size_t i = 0; i < applicationData.size(); i++)
    {
        binaryString.append(std::to_string(applicationData[i]));
    }
    std::string output = std::to_string(decimalValue) + " ///-> " + binaryString;
    return output;
}
/* DFI 3016 DUI 002 DATA WORDS 10 bits*/
std::string Dui002(const std::array<int, 10>& dataWords)
{
    int decimalValue = 0;
    for (size_t i = 0; i < dataWords.size(); ++i) {
        decimalValue += dataWords[i] * std::pow(2, dataWords.size() - 1 - i);
    }

    std::string binaryString = "";
    for (std::size_t i = 0; i < dataWords.size(); i++)
    {
        binaryString.append(std::to_string(dataWords[i]));
    }
    std::string output = "";
    if (decimalValue == 0)
    {
        output = "Illegal ///-> " + binaryString;
    }
    else if (decimalValue >= 1 && decimalValue <= 165)
    {
        output = std::to_string(decimalValue) + " ///-> " + binaryString;
    }
    else
    {
        output = "Undefined ///-> " + binaryString;
    }
    return output;
}
/* DFI 3016 DUI 003 TRANSPORT DATA WORD COUNT, 1 16 bits*/
std::string Dui003(const std::array<int, 16>& transportDataWordCount1)
{
    return GetTransportDataWordCount(transportDataWordCount1);
}
/* DFI 3016 DUI 004 TRANSPORT DATA WORD COUNT, 2 16 bits*/
std::string Dui004(const std::array<int, 16>& transportDataWordCount2)
{
    return GetTransportDataWordCount(transportDataWordCount2);
}
/* DFI 3016 DUI 005 TRANSPORT DATA WORD COUNT, 3 16 bits*/
std::string Dui005(const std::array<int, 16>& transportDataWordCount3)
{
    return GetTransportDataWordCount(transportDataWordCount3);
}
}
