#include <array>
#include <string>
#include <cmath>

namespace dfi3033 {
//repeated function for Dfi 3033

int BinaryConversion8bit(const std::array<int, 8>& inputArray)
{
    int result = 0;
    for (std::size_t i = 0; i < inputArray.size(); i++)
    {
        result = result * 2 + inputArray[i];
    }
    return result;
}
int BinaryConversion7bit(const std::array<int, 7>& inputArray)
{
    int result = 0;
    for (std::size_t i = 0; i < inputArray.size(); i++)
    {
        result = result * 2 + inputArray[i];
    }
    return result;
}
int BinaryConversion12bit(const std::array<int, 12>& inputArray)
{
    int result = 0;
    for (std::size_t i = 0; i < inputArray.size(); i++)
    {
        result = result * 2 + inputArray[i];
    }
    return result;
}

//end of repeated functions

/* DFI 3033 Number DUI 001 COUNT 8 bits*/
std::string Dui001(const std::array<int, 8>& count)
{
    return "///-> "+ std::to_string(BinaryConversion8bit(count));
}
/* DFI 3033 DUI 002 FRAGMENT NUMBER 8 bits*/
std::string Dui002(const std::array<int, 8>& fragmentNumber)
{
return "///-> "+ std::to_string(BinaryConversion8bit(fragmentNumber));
}
/* DFI 3033 DUI 003 TOTAL NUMBER FRAGMENTS 8 bits*/
std::string Dui003(const std::array<int, 8>& totalFragments)
{
    int convertedValue = BinaryConversion8bit(totalFragments);
    if(convertedValue == 0) {
        return "No Fragments ///-> " + std::to_string(convertedValue);
    } else if (convertedValue == 1) {
        return "Illegal ///-> " + std::to_string(convertedValue);
    } else if (convertedValue >= 2 && convertedValue <= 255) {
        return "Number of Fragments ///-> " + std::to_string(convertedValue);
    } else {
        return "Illegal ///-> " + std::to_string(convertedValue);
    }
     
}
/* DFI 3033 DUI 004 NUMBER OF BLOCKS 7 bits 0 is illegal*/
std::string Dui004(const std::array<int, 7>& numberOfBlocks)
{
    int convertedValue = BinaryConversion7bit(numberOfBlocks);
    if (convertedValue == 0) {
        return "Illegal ///-> " + std::to_string(convertedValue);
    } else if (convertedValue >= 1 && convertedValue <= 127) {
        return "Number of Blocks ///-> " + std::to_string(convertedValue);
    } else {
        return "Illegal ///-> " + std::to_string(convertedValue);
    }
}
/* DFI 3033 DUI 005 NUMBER OF J-WORDS 12 bits 0 is illegal*/
std::string Dui005(const std::array<int, 12>& numberOfJWords)
{
    int convertedValue = BinaryConversion12bit(numberOfJWords);
    if (convertedValue == 0) {
        return "Illegal ///-> " + std::to_string(convertedValue);
    } else if (convertedValue >= 1 && convertedValue <= 4095) {
        return "Number of J-Words ///-> " + std::to_string(convertedValue);
    } else {
        return "Illegal ///-> " + std::to_string(convertedValue);
    }
}
}
