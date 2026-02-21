#include <string>
#include <array>

namespace dfi3018 {
// DFI 3018 NUMBER OF DESIGNATORS
// DATA STANDARD USAGE: JREAP
//
// DUI 001 - NUMBER OF DESIGNATORS SUPPORTED [8 BIT] (NDS)
//           Indicates the number of links that the JRE processor is supporting.
//           Applicability: X0.13.0
//
// DUI 002 - TOTAL NUMBER OF ACTIVE DESIGNATORS [8 BIT] (TND)
//           Indicates the number of links active for this JRE processor.
//           Applicability: X0.12.0
//
// Data Values:
//   0              - No statement
//   1 through 255  - Number of designators

std::string Dui001(const std::array<int, 8>& numberOfDesignatorsSupported);
std::string Dui002(const std::array<int, 8>& totalNumberOfActiveDesignators);
}
