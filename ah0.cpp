//this component should take in an array that can be up to 65 bytes long and convert it to a string
// that can be displayed in raylib. 
//This is for the JREAP-C header fields. 
//The first 10 bytes of the array will be used for the header fields and the rest will be ignored. 
//The first byte will be used to determine the header type and the rest of the bytes will be used to determine the values of the header fields. 
//The output string should be formatted in a way that is easy to read and understand. 
//The output string should also include the binary representation of the header fields for reference. 
//This component should be able to handle any valid JREAP-C header and should return an appropriate message for invalid headers.
#include "JReapCHeads.h"
#include <cmath>
#include <array>
#include <string>
#include <iostream>

/* THE JREAP APPLICATION HEADER IS USED WITH MEDIA THAT PROVIDE OSI TRANSPORT 
 * LAYER FUNCTIONALITY THIS IS AH.0
 */ 

 /* REFERENCE                                  BIT    # 
    DFI/DUI  DATA FIELD DESCRIPTOR         POSITION BITS     RESOLUTION, CODING, ETC               
    3007 003 HEADER TYPE (HT)                 0-  3   4      0011 
    3008 001 MESSAGE TYPE (MT)                4-  7   4 
    3002 011 TRANS. TIME REFERENCE FLAG       8       1  
    3099 003 SPARE (SP)                       9- 11   3 
    3023 001 APPLICATION PROTOCOL VERSION    12- 15   4      0001 
    3012 001 APP. BLOCK MESSAGE LENGTH       16- 31  16 
    3036 001 JRE SENDER ID (JRE SI)          32- 47  16 
    3003 011 TIME ACCURACY (TA)              48- 51   4 
    3003 004 DATA VALID TIME (DVT)           52- 79  28
    */

std::string AH0(std::array<int, 10> byteArray)
{
    std::string output = "";
    // split the first byte out
    int firstByte = byteArray[0];

}
