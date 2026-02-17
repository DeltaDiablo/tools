#include <array>
#include <cmath>
#include <string>



//repeated function for Dfi 3028
std::array<int, 16> ConvertJSeriesWord(const std::array<int, 16>& input)
{
    std::array<int, 16> output = {};
    // Map according to the bit swap pattern
    // Input bits 0-7 map to output positions 7,6,5,4,3,2,1,0
    // Input bits 8-15 map to output positions 15,14,13,12,11,10,9,8
    for (int i = 0; i < 8; i++)
    {
        output[7 - i] = input[i];
        output[15 - i] = input[8 + i];
    }
    return output;
}
//end of repeated functions

/* DFI 3028 DUI 001 JREAP J-SERIES MESSAGE WORD, 1 16 bits*/
std::string Dui001(const std::array<int, 16>& jreapJSeriesMessageWord1)
{
    std::array<int, 16> outputArray = ConvertJSeriesWord(jreapJSeriesMessageWord1);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3028 DUI 002 JREAP J-SERIES MESSAGE WORD, 2 16 bits*/
std::string Dui002(const std::array<int, 16>& jreapJSeriesMessageWord2)
{
    std::array<int, 16> outputArray = ConvertJSeriesWord(jreapJSeriesMessageWord2);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3028 DUI 003 JREAP J-SERIES MESSAGE WORD, 3 16 bits*/
std::string Dui003(const std::array<int, 16>& jreapJSeriesMessageWord3)
{
    std::array<int, 16> outputArray = ConvertJSeriesWord(jreapJSeriesMessageWord3);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3028 DUI 004 JREAP J-SERIES MESSAGE WORD, 4 16 bits*/
std::string Dui004(const std::array<int, 16>& jreapJSeriesMessageWord4)
{
    std::array<int, 16> outputArray = ConvertJSeriesWord(jreapJSeriesMessageWord4);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3028 DUI 005 JREAP J-SERIES MESSAGE WORD, 5 6 bits*/
std::string Dui005(const std::array<int, 6>& jreapJSeriesMessageWord5)
{
    std::string output = "";
    for (std::size_t i = 0; i < jreapJSeriesMessageWord5.size(); i++)
    {
        output.append(std::to_string(jreapJSeriesMessageWord5[i]));
    }
    return output;
}
