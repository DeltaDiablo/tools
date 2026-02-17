#include <array>
#include <cmath>
#include <string>

//repeatable function for Dfi 3029
int CompletionTimeoutConversion(const std::array<int, 8>& inputArray)
{
    int inputInt = 0;
    for (int i = 0; i < 8; i++)
    {
        inputInt += inputArray[i] * std::pow(2, 7 - i);
    }
    return inputInt;
}
//end of repeatable functions

/* DFI 3029 DUI 001 COMPLETION TIMEOUT 8 bits*/
std::string Dui001(const std::array<int, 8>& completionTimeout)
{
    int seconds = CompletionTimeoutConversion(completionTimeout);
    std::string output = std::to_string(seconds) + " ///-> ";
    if(seconds == 0) {
        output += "No Statement ///-> ";
    } else if (seconds >= 1 && seconds <= 255) {
        output += std::to_string(seconds) + " Seconds ///-> ";
    } else {
        output += "Illegal Value ///-> ";
    }
    output;
    return output;
}
    // NO STATEMENT: 0
    // 1 THROUGH 255 SECONDS: 1 THROUGH 255 IN ONE SECOND INCREMENTS
// NO STATEMENT: 0
// 1 THROUGH 255 SECONDS: 1 THROUGH 255 IN ONE SECOND INCREMENTS
