#include <array>
#include <string>

namespace dfi3028 {
// THESE SIX FIELDS (BITS 64 – 135) ARE THE J-SERIES MESSAGE WORD GROUP
// (5.5.1) AND ARE REPEATED FOR THE NUMBER OF WORDS SPECIFIED IN THE
// NUMBER OF J WORDS FIELD (BITS 52 – 63). THESE FIVE FIELDS FORM A J-
// SERIES MESSAGE WORD GROUP AND SHALL BE CONCATENATED TO FORM A SINGLE,
// LARGER FIELD AS SHOWN IN FIGURE BELOW
// Byte Bit |15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00| bit byte
//  01    15 |08|09|10|11|12|13|14|15|00|01|02|03|04|05|06|07| 00   00
//  03    31 |24|25|26|27|28|29|30|31|16|17|18|19|20|21|22|23| 16   02
//  05    47 |40|41|42|43|44|45|46|47|32|33|34|35|36|37|38|39| 32   04
//  07    63 |56|57|58|59|60|61|62|63|48|49|50|51|52|53|54|55| 48   06
//                                   |64|65|66|67|68|69|70|71| 64   08

std::string Dui001(const std::array<int, 16>& jreapJSeriesMessageWord1);
std::string Dui002(const std::array<int, 16>& jreapJSeriesMessageWord2);
std::string Dui003(const std::array<int, 16>& jreapJSeriesMessageWord3);
std::string Dui004(const std::array<int, 16>& jreapJSeriesMessageWord4);
std::string Dui005(const std::array<int, 6>& jreapJSeriesMessageWord5);
}
