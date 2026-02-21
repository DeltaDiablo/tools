#include <array>
#include <string>

namespace dfi3030 {
/*
*THESE THIRTY FIELDS (16 BITS LONG EACH) ARE THE JREAP/JTIDS FREE TEXT FIELDS (5.5.2) AND
*SHALL BE CONCATENATED TOGETHER TO FORM A SINGLE 472 BIT FREE TEXT DATA BLOCK AS SHOWN BELOW
* AND ARE REPEATED FOR THE NUMBER OF BLOCKS SPECIFIED IN THE NUMBER OF BLOCKS FIELD (3033 001).
* Byte  Bit  15  14  13  12  11  10 09 08 07 06 05 04 03 02 01 00   Bit  Byte 
*  01   15   08  09  10  11  12  13 14 15 00 01 02 03 04 05 06 07   00    00 
*  03   31   24  25  26  27  28  29 30 31 16 17 18 19 20 21 22 23   16    02
*/
std::string Dui001(const std::array<int, 16>& jreapJtidsFreeText1);
std::string Dui002(const std::array<int, 16>& jreapJtidsFreeText2);
std::string Dui003(const std::array<int, 16>& jreapJtidsFreeText3);
std::string Dui004(const std::array<int, 16>& jreapJtidsFreeText4);
std::string Dui005(const std::array<int, 16>& jreapJtidsFreeText5);
std::string Dui006(const std::array<int, 16>& jreapJtidsFreeText6);
std::string Dui007(const std::array<int, 16>& jreapJtidsFreeText7);
std::string Dui008(const std::array<int, 16>& jreapJtidsFreeText8);
std::string Dui009(const std::array<int, 16>& jreapJtidsFreeText9);
std::string Dui010(const std::array<int, 16>& jreapJtidsFreeText10);
std::string Dui011(const std::array<int, 16>& jreapJtidsFreeText11);
std::string Dui012(const std::array<int, 16>& jreapJtidsFreeText12);
std::string Dui013(const std::array<int, 16>& jreapJtidsFreeText13);
std::string Dui014(const std::array<int, 16>& jreapJtidsFreeText14);
std::string Dui015(const std::array<int, 16>& jreapJtidsFreeText15);
std::string Dui016(const std::array<int, 16>& jreapJtidsFreeText16);
std::string Dui017(const std::array<int, 16>& jreapJtidsFreeText17);
std::string Dui018(const std::array<int, 16>& jreapJtidsFreeText18);
std::string Dui019(const std::array<int, 16>& jreapJtidsFreeText19);
std::string Dui020(const std::array<int, 16>& jreapJtidsFreeText20);
std::string Dui021(const std::array<int, 16>& jreapJtidsFreeText21);
std::string Dui022(const std::array<int, 16>& jreapJtidsFreeText22);
std::string Dui023(const std::array<int, 16>& jreapJtidsFreeText23);
std::string Dui024(const std::array<int, 16>& jreapJtidsFreeText24);
std::string Dui025(const std::array<int, 16>& jreapJtidsFreeText25);
std::string Dui026(const std::array<int, 16>& jreapJtidsFreeText26);
std::string Dui027(const std::array<int, 16>& jreapJtidsFreeText27);
std::string Dui028(const std::array<int, 16>& jreapJtidsFreeText28);
std::string Dui029(const std::array<int, 16>& jreapJtidsFreeText29);
std::string Dui030(const std::array<int, 16>& jreapJtidsFreeText30);
}
