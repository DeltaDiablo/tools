#include <array>
#include <string>

namespace dfi3012 {
std::string Dui001(const std::array<int, 16>& applicationBlockMessageLength);
std::string Dui002(const std::array<int, 16>& lengthOfMessage);
std::string Dui003(const std::array<int, 16>& managementMessageLength);
}
