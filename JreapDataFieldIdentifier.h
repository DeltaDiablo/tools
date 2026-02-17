// JreapDataFieldIdentifier.h
// Header for DFI (Data Field Identifier) and DUI (Data Use Identifier) combos
// Contains function declarations for DFI/DUI converters

#ifndef JREAPDATAFIELDIDENTIFIER_H
#define JREAPDATAFIELDIDENTIFIER_H

#include <string>
#include <array>

// DFI 3000
std::string dfi3000dui001(std::array<int, 7> percentExceedingLatency);

// DFI 3001
std::string dfi3001dui001(const std::array<int, 7>& transmissionSequenceNumber);
std::string dfi3001dui002(const std::array<int, 7>& transmissionSequenceListCount);

// DFI 3002
std::string dfi3002dui001(const std::array<int, 1>& addDeleteIndicator);
std::string dfi3002dui002(const std::array<int, 1>& activeInactiveFlag);
std::string dfi3002dui003(const std::array<int, 1>& acknowledgementRequestFlag);
std::string dfi3002dui004(const std::array<int, 1>& commandAndControlIndicatorOverride);
std::string dfi3002dui005(const std::array<int, 1>& emergencyIndicatorOverride);
std::string dfi3002dui006(const std::array<int, 1>& forceTellIndicatorOverride);
std::string dfi3002dui007(const std::array<int, 1>& lastPointFlag);
std::string dfi3002dui008(const std::array<int, 1>& rectangleFlag);
std::string dfi3002dui009(const std::array<int, 1>& relayFlag);
std::string dfi3002dui010(const std::array<int, 1>& simulationIndicatorFilterFlag);
std::string dfi3002dui011(const std::array<int, 1>& transmissionTimeReferenceFlag);
std::string dfi3002dui012(const std::array<int, 1>& upperAltitudeLimitFlag);
std::string dfi3002dui013(const std::array<int, 1>& lowerAltitudeLimitFlag);
std::string dfi3002dui014(const std::array<int, 1>& j2820FilterFlag);
std::string dfi3002dui015(const std::array<int, 1>& j28XFilterFlag);
std::string dfi3002dui016(const std::array<int, 1>& specialProcessingIndicatorFilterFlag);
std::string dfi3002dui017(const std::array<int, 1>& typeFilter);
std::string dfi3002dui018(const std::array<int, 1>& geographicFilter);
std::string dfi3002dui019(const std::array<int, 1>& allFilters);
std::string dfi3002dui020(const std::array<int, 1>& alternateNetworkControllerAssignmentFlag);
std::string dfi3002dui021(const std::array<int, 1>& alternateNetworkControllerAssignmentRecognition);

// DFI 3003
std::string Dif3003Dui001(const std::array<int, 8>& ageLimitValue);
std::string Dfi3003Dui002(const std::array<int, 16>& averageReceivedDataMediaLatency);
std::string Dfi3003Dui003(const std::array<int, 13>& dataAge);
std::string Dfi3003Dui004(const std::array<int, 28>& dataValidTime);
std::string Dfi3003Dui005(const std::array<int, 4>& eventTimeAccuracy);
std::string Dfi3003Dui007(const std::array<int, 16>& maximumLatency);
std::string Dfi3003Dui008(const std::array<int, 28>& rxJreReceiveTime);
std::string Dfi3003Dui009(const std::array<int, 28>& txJreTransmitTime);
std::string Dfi3003Dui010(const std::array<int, 28>& rxJreTransmitTime);
std::string Dfi3003Dui011(const std::array<int, 4>& timeAccuracy);
std::string Dfi3003Dui012(const std::array<int, 28>& eventTime);
std::string Dfi3003Dui013(const std::array<int, 10>& intervalTime);
std::string Dfi3003Dui014(const std::array<int, 4>& timeAccuracyR2);
std::string Dfi3003Dui015(const std::array<int, 4>& timeAccuracyT1);
std::string Dfi3003Dui016(const std::array<int, 4>& timeAccuracyT2);

// DFI 3004
std::string Dfi3004Dui001(const std::array<int, 1>& jreNcC);
std::string Dfi3004Dui002(const std::array<int, 1>& rttimeC);
std::string Dfi3004Dui003(const std::array<int, 1>& fixedDelayC);
std::string Dfi3004Dui004(const std::array<int, 1>& eventStrobeC);
std::string Dfi3004Dui005(const std::array<int, 1>& utcC);

// DFI 3005
std::string JreNcP(const std::array<int, 1>& jreNcP);
std::string RttimeP(std::array<int, 1> rttimeP);
std::string FixedDelayP(std::array<int, 1> fixedDelayP);
std::string EventStrobeP(std::array<int, 1> eventStrobeP);
std::string UtcP(std::array<int, 1> utcP);

// DFI 3007
std::string TransmissionBlockHeaderType(std::array<int, 4> transmissionBlockHeaderType);
std::string MessageGroupHeaderType(std::array<int, 2> messageGroupHeaderType);
std::string HeaderType(std::array<int, 4> headerType);

// DFI 3008
std::string MessageType(std::array<int, 4> messageType);
std::string ManagementMessageSubtype(std::array<int, 8> managementMessageSubtype);
std::string FilterMessageType(std::array<int, 8> filterMessageType);

#endif // JREAPDATAFIELDIDENTIFIER_H
