#include <string>
#include <array>

// DFI 3016: DATA
// DATA STANDARD USAGE: JREAP
//
// DUI NAME                           EXPLANATION                           APPLICABILITY
// 001 APPLICATION DATA               DATA PAYLOAD TRANSMITTED IN THE       X0.0.0
//     [32 BIT] (APPDATA)             JREAP ECHO MESSAGE.
//
// 002 DATA WORDS                     INDICATES NUMBER OF 9 BYTE DATA       FSMGH.3
//     [10 BIT] (DW)                  WORDS TO FOLLOW.
//
// 003 TRANSPORT DATA WORD COUNT, 1   IN ONE BYTE INCREMENTS.               FSTBH.A.NP.0
//     [16 BIT] (TDWC1)                                                     FSTBH.A.NC.0
//                                                                           FSTBH.B.0
//
// 004 TRANSPORT DATA WORD COUNT, 2   INDICATES THE NUMBER OF BYTES THAT    FSTBH.A.NP.0
//     [16 BIT] (TDWC2)               ARE CONTAINED IN THE TRANSPORT AND    FSTBH.A.NC.0
//                                    DATA PORTIONS OF A PACKET.
//
// 005 TRANSPORT DATA WORD COUNT, 3   INDICATES THE NUMBER OF BYTES THAT    FSTBH.A.NP.0
//     [16 BIT] (TDWC3)               ARE CONTAINED IN THE TRANSPORT AND    FSTBH.A.NC.0
//                                    DATA PORTIONS OF A PACKET.
//
// DATA ITEMS:
// DUI 001: 0 through 4294967295
// DUI 002: 0 (ILLEGAL), 1-165 (NUMERIC), 166-1023 (UNDEFINED)
// DUI 003-005: 0 (NO STATEMENT), 1-65535 (BYTES)

std::string Dui001(const std::array<int, 32>& applicationData);
std::string Dui002(const std::array<int, 10>& dataWords);
std::string Dui003(const std::array<int, 16>& transportDataWordCount1);
std::string Dui004(const std::array<int, 16>& transportDataWordCount2);
std::string Dui005(const std::array<int, 16>& transportDataWordCount3);