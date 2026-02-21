#include <array>
#include <string>

namespace dfi3039 {
std::string Dui001(const std::array<int, 16>& messageGroupHeaderCrc);
std::string Dui002(const std::array<int, 16>& transmissionBlockHeaderCrc);
}
