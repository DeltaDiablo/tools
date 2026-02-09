// Purpose: Header file for JREAP CHeads.cpp
#include <iostream>

/*
 * These are the header fields for Application Headers. This is only for packets that
 * support OSI layer transport by default. Do not confuse these with Full Stack Headers
 *
 *  =============== Application Header Fields ===============
 *  1.)  Header Type                           4 bits
 *  2.)  Message Type                          4 bits
 *  3.)  Transmission Time Reference Flag      1 bit
 *  4.)  Spare                                 3 bits
 *  5.)  Application Protocol Version          4 bits
 *  6.)  Application Block Message Length      16 Bits
 *  7.)  JRE Sender ID                         16 Bits
 *  8.)  Time Accuracy                         4 bits
 *  9.)  Data Valid Time                       28 bits
 *      -----------------------------------------------
 *       Total size                            80 bits
 *  =====================================================
 */

// Only JREAP-C header processing is supported in this application
std::string CommonHeaderConverter(std::array<int, 8> byteArray);
