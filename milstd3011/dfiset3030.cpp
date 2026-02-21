#include <array>
#include <string>
#include <cmath>

namespace dfi3030 {
//repeatable function for Dfi 3030

std::array<int, 16> converter(const std::array<int, 16>& freeTextWord) {
    std::array<int, 16> output = {};
    // Swap bit order within each byte (bits 0-7 and 8-15)
    for (int i = 0; i < 8; ++i) {
        output[7 - i] = freeTextWord[i];      // First byte
        output[15 - i] = freeTextWord[8 + i]; // Second byte
    }
    return output;
}

//end of repeatable functions

/* DFI 3030 DUI 001 JREAP/JTIDS FREE TEXT, 1 16 bits used to transfer binary data */
std::string Dui001(const std::array<int, 16>& jreapJtidsFreeText1)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText1);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 002 JREAP/JTIDS FREE TEXT, 2 16 bits*/
std::string Dui002(const std::array<int, 16>& jreapJtidsFreeText2)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText2);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 003 JREAP/JTIDS FREE TEXT, 3 16 bits*/
std::string Dui003(const std::array<int, 16>& jreapJtidsFreeText3)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText3);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 004 JREAP/JTIDS FREE TEXT, 4 16 bits*/
std::string Dui004(const std::array<int, 16>& jreapJtidsFreeText4)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText4);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 005 JREAP/JTIDS FREE TEXT, 5 16 bits*/
std::string Dui005(const std::array<int, 16>& jreapJtidsFreeText5)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText5);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 006 JREAP/JTIDS FREE TEXT, 6 16 bits*/
std::string Dui006(const std::array<int, 16>& jreapJtidsFreeText6)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText6);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 007 JREAP/JTIDS FREE TEXT, 7 16 bits*/
std::string Dui007(const std::array<int, 16>& jreapJtidsFreeText7)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText7);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 008 JREAP/JTIDS FREE TEXT, 8 16 bits*/
std::string Dui008(const std::array<int, 16>& jreapJtidsFreeText8)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText8);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 009 JREAP/JTIDS FREE TEXT, 9 16 bits*/
std::string Dui009(const std::array<int, 16>& jreapJtidsFreeText9)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText9);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 010 JREAP/JTIDS FREE TEXT, 10 16 bits*/
std::string Dui010(const std::array<int, 16>& jreapJtidsFreeText10)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText10);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 011 JREAP/JTIDS FREE TEXT, 11 16 bits*/
std::string Dui011(const std::array<int, 16>& jreapJtidsFreeText11)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText11);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 012 JREAP/JTIDS FREE TEXT, 12 16 bits*/
std::string Dui012(const std::array<int, 16>& jreapJtidsFreeText12)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText12);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 013 JREAP/JTIDS FREE TEXT, 13 16 bits*/
std::string Dui013(const std::array<int, 16>& jreapJtidsFreeText13)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText13);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 014 JREAP/JTIDS FREE TEXT, 14 16 bits*/
std::string Dui014(const std::array<int, 16>& jreapJtidsFreeText14)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText14);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 015 JREAP/JTIDS FREE TEXT, 15 16 bits*/
std::string Dui015(const std::array<int, 16>& jreapJtidsFreeText15)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText15);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 016 JREAP/JTIDS FREE TEXT, 16 16 bits*/
std::string Dui016(const std::array<int, 16>& jreapJtidsFreeText16)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText16);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 017 JREAP/JTIDS FREE TEXT, 17 16 bits*/
std::string Dui017(const std::array<int, 16>& jreapJtidsFreeText17)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText17);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 018 JREAP/JTIDS FREE TEXT, 18 16 bits*/
std::string Dui018(const std::array<int, 16>& jreapJtidsFreeText18)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText18);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 019 JREAP/JTIDS FREE TEXT, 19 16 bits*/
std::string Dui019(const std::array<int, 16>& jreapJtidsFreeText19)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText19);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 020 JREAP/JTIDS FREE TEXT, 20 16 bits*/
std::string Dui020(const std::array<int, 16>& jreapJtidsFreeText20)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText20);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 021 JREAP/JTIDS FREE TEXT, 21 16 bits*/
std::string Dui021(const std::array<int, 16>& jreapJtidsFreeText21)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText21);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 022 JREAP/JTIDS FREE TEXT, 22 16 bits*/
std::string Dui022(const std::array<int, 16>& jreapJtidsFreeText22)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText22);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 023 JREAP/JTIDS FREE TEXT, 23 16 bits*/
std::string Dui023(const std::array<int, 16>& jreapJtidsFreeText23)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText23);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 024 JREAP/JTIDS FREE TEXT, 24 16 bits*/
std::string Dui024(const std::array<int, 16>& jreapJtidsFreeText24)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText24);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 025 JREAP/JTIDS FREE TEXT, 25 16 bits*/
std::string Dui025(const std::array<int, 16>& jreapJtidsFreeText25)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText25);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 026 JREAP/JTIDS FREE TEXT, 26 16 bits*/
std::string Dui026(const std::array<int, 16>& jreapJtidsFreeText26)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText26);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 027 JREAP/JTIDS FREE TEXT, 27 16 bits*/
std::string Dui027(const std::array<int, 16>& jreapJtidsFreeText27)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText27);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 028 JREAP/JTIDS FREE TEXT, 28 16 bits*/
std::string Dui028(const std::array<int, 16>& jreapJtidsFreeText28)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText28);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 029 JREAP/JTIDS FREE TEXT, 29 16 bits*/
std::string Dui029(const std::array<int, 16>& jreapJtidsFreeText29)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText29);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
/* DFI 3030 DUI 030 JREAP/JTIDS FREE TEXT, 30 16 bits*/
std::string Dui030(const std::array<int, 16>& jreapJtidsFreeText30)
{
    std::array<int, 16> outputArray = converter(jreapJtidsFreeText30);
    std::string output = "";
    for (std::size_t i = 0; i < outputArray.size(); i++)
    {
        output.append(std::to_string(outputArray[i]));
    }
    return output;
}
}
