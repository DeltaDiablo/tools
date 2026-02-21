#include <array>
#include <string>

namespace dfi3021 {
/* DATA STANDARD USAGE: JREAP
 *
 * DUI NAME                           EXPLANATION                              APPLICABILITY
 *
 * 001 LINK DESIGNATOR TO FILTER      THE UNIQUE DESIGNATOR OF THE JRE         X0.10.2  X0.10.3  X0.10.4
 *     [16 BIT] (DTF)                 LINK OR TDL NETWORK THIS FILTER          X0.10.5  X0.10.6  X0.10.7
 *                                    WILL APPLY TO.                           X0.10.8  X0.10.9  X0.10.10
 *                                                                              X0.10.11 X0.10.12 X0.10.13
 *
 * 002 LINK DESIGNATOR                THE UNIQUE DESIGNATOR FOR EACH OF A      X0.10.1  X0.10.0  X0.12.0
 *     [16 BIT]                       JRE PROCESSOR'S CAPABLE JRE LINKS        X0.13.0  X0.14.0
 *                                    OR TDL NETWORKS
 *
 * 003 SOURCE LINK DESIGNATOR         THE DESIGNATOR OF THE JRE LINK OR        X0.10.14 X7.0.0   X7.1.0
 *     [16 BIT]                       TDL NETWORK THE DATA ORIGINATED FROM.
 *
 * 004 TRANSMIT LINK DESIGNATOR       THE DESIGNATOR OF THE JRE LINK OR        X7.0.0   X7.1.0
 *     [16 BIT]                       TDL NETWORK ON WHICH THE DATA IS
 *                                    TO BE TRANSMITTED.
 *
 * DATA ITEM                           BIT CODE                                 EXPLANATION
 *
 * ----- FOR DUIS 001 - 004 -----
 *
 * NO STATEMENT                        0
 * ASSIGNED DESIGNATOR                 1 THROUGH 65535                          UNIQUE NUMERIC DESIGNATOR
 *                                                                               ASSIGNED TO A JRE LINK
 *                                                                               OR TDL NETWORK.
 */

std::string Dui001(const std::array<int, 16>& linkDesignatorToFilter);
std::string Dui002(const std::array<int, 16>& linkDesignator);
std::string Dui003(const std::array<int, 16>& sourceLinkDesignator);
std::string Dui004(const std::array<int, 16>& transmitLinkDesignator);
}
