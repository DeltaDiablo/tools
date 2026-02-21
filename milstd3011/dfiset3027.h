#include <array>
#include <string>

namespace dfi3027 {
std::string Dui003(const std::array<int, 16>& jreSourceTrackNumber);
std::string Dui001(const std::array<int, 15>& sourceTrackNumber);
std::string Dui002(const std::array<int, 15>& secondaryTrackNumber);
}
