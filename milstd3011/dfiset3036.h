#include <array>
#include <string>

namespace dfi3036 {
std::string Dfi3036Dui001(const std::array<int, 16>& jreSenderId);
std::string Dfi3036Dui002(const std::array<int, 16>& jreSenderId1);
std::string Dfi3036Dui003(const std::array<int, 16>& jreSenderId2);
std::string Dfi3036Dui004(const std::array<int, 16>& jreSenderId3);
std::string Dfi3036Dui005(const std::array<int, 16>& jreNetworkParticipant);
std::string Dfi3036Dui020(const std::array<int, 16>& destinationAddress);
std::string Dfi3036Dui021(const std::array<int, 16>& originatingJSeriesJreSenderId);
std::string Dfi3036Dui022(const std::array<int, 16>& linkInterfaceUnit);
}
