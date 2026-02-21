#include <array>
#include <string>

namespace dfi3032 {
std::string Dui001(const std::array<int, 16>& messageSequenceNumber);
std::string Dui002(const std::array<int, 16>& originatingMessageSequenceNumber);
std::string Dui003(const std::array<int, 16>& jSeriesMessageSequenceNumber);
std::string Dui004(const std::array<int, 16>& originatingJSeriesMessageSequenceNumber);
std::string Dui005(const std::array<int, 16>& networkParticipationGroup);
}
