#include <array>
#include <string>

namespace dfi3033 {
std::string Dui001(const std::array<int, 8>& count);
std::string Dui002(const std::array<int, 8>& fragmentNumber);
std::string Dui003(const std::array<int, 8>& totalFragments);
std::string Dui004(const std::array<int, 7>& numberOfBlocks);
std::string Dui005(const std::array<int, 12>& numberOfJWords);
}
