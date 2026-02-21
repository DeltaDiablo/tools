#include <iostream>
#include <array>
#include <string>

namespace dfi3002 {
std::string dui001(const std::array<int, 7>& percentExceedingLatency);
std::string dui002(const std::array<int, 8>& transmissionSequenceNumber);
std::string dui003(const std::array<int, 7>& transmissionSequenceListCount);
std::string Dui001(const std::array<int, 1>& addDeleteIndicator);
std::string Dui002(const std::array<int, 1>& activeInactiveFlag);
std::string Dui003(const std::array<int, 1>& acknowledgementRequestFlag);
std::string Dui004(const std::array<int, 1>& commandAndControlIndicatorOverride);
std::string Dui005(const std::array<int, 1>& emergencyIndicatorOverride);
std::string Dui006(const std::array<int, 1>& forceTellIndicatorOverride);
std::string Dui007(const std::array<int, 1>& lastPointFlag);
std::string Dui008(const std::array<int, 1>& rectangleFlag);
std::string Dui009(const std::array<int, 1>& relayFlag);
std::string Dui010(const std::array<int, 1>& simulationIndicatorFilterFlag);
std::string Dui011(const std::array<int, 1>& transmissionTimeReferenceFlag);
std::string Dui012(const std::array<int, 1>& upperAltitudeLimitFlag);
std::string Dui013(const std::array<int, 1>& lowerAltitudeLimitFlag);
std::string Dui014(const std::array<int, 1>& j2820FilterFlag);
std::string Dui015(const std::array<int, 1>& j28XFilterFlag);
std::string Dui016(const std::array<int, 1>& specialProcessingIndicatorFilterFlag);
std::string Dui017(const std::array<int, 1>& typeFilter);
std::string Dui018(const std::array<int, 1>& geographicFilter);
std::string Dui019(const std::array<int, 1>& allFilters);
std::string Dui020(const std::array<int, 1>& alternateNetworkControllerAssignmentFlag);
std::string Dui021(const std::array<int, 1>& alternateNetworkControllerAssignmentRecognition);
}
