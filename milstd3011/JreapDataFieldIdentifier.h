// jreapdatafieldidentifier.h
// Header for DFI (Data Field Identifier) and DUI (Data Use Identifier) combos
// Contains function declarations for DFI/DUI converters

#ifndef JREAPDATAFIELDIDENTIFIER_H_
#define JREAPDATAFIELDIDENTIFIER_H_

#include <string>
#include <array>

// DFI 3000
std::string Dfi3000Dui001(std::array<int, 7> percentExceedingLatency);

// DFI 3001
std::string Dfi3001Dui001(const std::array<int, 8>& transmissionSequenceNumber);
std::string Dfi3001Dui002(const std::array<int, 7>& transmissionSequenceListCount);

// DFI 3002
std::string Dfi3002Dui001(const std::array<int, 1>& addDeleteIndicator);
std::string Dfi3002Dui002(const std::array<int, 1>& activeInactiveFlag);
std::string Dfi3002Dui003(const std::array<int, 1>& acknowledgementRequestFlag);
std::string Dfi3002Dui004(const std::array<int, 1>& commandAndControlIndicatorOverride);
std::string Dfi3002Dui005(const std::array<int, 1>& emergencyIndicatorOverride);
std::string Dfi3002Dui006(const std::array<int, 1>& forceTellIndicatorOverride);
std::string Dfi3002Dui007(const std::array<int, 1>& lastPointFlag);
std::string Dfi3002Dui008(const std::array<int, 1>& rectangleFlag);
std::string Dfi3002Dui009(const std::array<int, 1>& relayFlag);
std::string Dfi3002Dui010(const std::array<int, 1>& simulationIndicatorFilterFlag);
std::string Dfi3002Dui011(const std::array<int, 1>& transmissionTimeReferenceFlag);
std::string Dfi3002Dui012(const std::array<int, 1>& upperAltitudeLimitFlag);
std::string Dfi3002Dui013(const std::array<int, 1>& lowerAltitudeLimitFlag);
std::string Dfi3002Dui014(const std::array<int, 1>& j2820FilterFlag);
std::string Dfi3002Dui015(const std::array<int, 1>& j28XFilterFlag);
std::string Dfi3002Dui016(const std::array<int, 1>& specialProcessingIndicatorFilterFlag);
std::string Dfi3002Dui017(const std::array<int, 1>& typeFilter);
std::string Dfi3002Dui018(const std::array<int, 1>& geographicFilter);
std::string Dfi3002Dui019(const std::array<int, 1>& allFilters);
std::string Dfi3002Dui020(const std::array<int, 1>& alternateNetworkControllerAssignmentFlag);
std::string Dfi3002Dui021(const std::array<int, 1>& alternateNetworkControllerAssignmentRecognition);

// DFI 3003
std::string Dfi3003Dui001(const std::array<int, 8>& ageLimitValue);
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
std::string Dfi3005Dui001(const std::array<int, 1>& jreNcP);
std::string Dfi3005Dui002(const std::array<int, 1>& rttimeP);
std::string Dfi3005Dui003(const std::array<int, 1>& fixedDelayP);
std::string Dfi3005Dui004(const std::array<int, 1>& eventStrobeP);
std::string Dfi3005Dui005(const std::array<int, 1>& utcP);

// DFI 3007
std::string Dfi3007Dui001(const std::array<int, 4>& transmissionBlockHeaderType);
std::string Dfi3007Dui002(const std::array<int, 2>& messageGroupHeaderType);
std::string Dfi3007Dui003(const std::array<int, 4>& headerType);

// DFI 3008
std::string Dfi3008Dui001(const std::array<int, 4>& messageType);
std::string Dfi3008Dui002(const std::array<int, 8>& managementMessageSubtype);
std::string Dfi3008Dui003(const std::array<int, 8>& filterMessageType);
std::string Dfi3008Dui004(const std::array<int, 8>& requestedFilterMessageType);

// Legacy compatibility aliases
std::string JreNcP(const std::array<int, 1>& jreNcP);
std::string RttimeP(std::array<int, 1> rttimeP);
std::string FixedDelayP(std::array<int, 1> fixedDelayP);
std::string EventStrobeP(std::array<int, 1> eventStrobeP);
std::string UtcP(std::array<int, 1> utcP);
std::string TransmissionBlockHeaderType(std::array<int, 4> transmissionBlockHeaderType);
std::string MessageGroupHeaderType(std::array<int, 2> messageGroupHeaderType);
std::string HeaderType(std::array<int, 4> headerType);
std::string MessageType(std::array<int, 4> messageType);
std::string ManagementMessageSubtype(std::array<int, 8> managementMessageSubtype);
std::string FilterMessageType(std::array<int, 8> filterMessageType);

// DFI 3057-3066, 3080-3087, 3099-3140 declarations are maintained directly in the implementation unit.

#endif // JREAPDATAFIELDIDENTIFIER_H_
