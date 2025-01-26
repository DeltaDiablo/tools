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
std::string CommonHeaderConverter(std::array<int, 10> byteArray);
std::string HeaderType(std::array<int, 4> headerType);
std::string MessageType(std::array<int, 4> messageType);
std::string TransmissionTimeReferenceFlag(std::array<int, 1> transmissionTimeReferenceFlag);
std::string Spare(std::array<int, 3> spare);
std::string ApplicationProtocolVersion(std::array<int, 4> applicationProtocolVersion);
std::string ApplicationBlockMessageLength(std::array<int, 16> applicationBlockMessageLength);
std::string JreSenderID(std::array<int, 16> jreSenderID);
std::string TimeAccuracyReporting(std::array<int, 4> timeAccuracy);
std::string DataValidTime(std::array<int, 28> dataValidTime);
