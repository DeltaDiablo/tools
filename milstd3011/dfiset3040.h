#include <array>
#include <string>

namespace dfi3040 {
/* DFI 3040 DUI 001 JTIDS/MIDS PARTICIPATION GROUP*/
std::string Dui001(const std::array<int, 9>& jtidsMidsParticipationGroup);
/* DFI 3040 DUI 002 NETWORK PARTICIPATION GROUP*/
std::string Dui002(const std::array<int, 9>& networkParticipationGroup);
/* DFI 3040 DUI 003 NETWORK PARTICIPATION GROUP TO FILTER*/
std::string Dui003(const std::array<int, 9>& networkParticipationGroupToFilter);
}
