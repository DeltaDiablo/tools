#include <string>
#include <array>

namespace dfi3017 {
/*
 * DFI 3017: NUMBER OF ADDRESSES
 * Definition: The number of IU addresses.
 * 
 * Data Standard Usage: JREAP
 * 
 * DUI Details:
 * 
 * DUI 001: NUMBER DESTINATION ADDRESSES [8 BIT]
 *   Specifies the number of destination addresses contained in this subheader.  
 *   Data Item Values:
 *     BROADCAST: 0
 *     Addresses: 1 through 255
 * 
 * DUI 002: NUMBER ADDRESSES THIS DESIGNATOR [8 BIT]
 *   The total number of IU numbers (up to 255) associated with the link
 *   being reported by this particular designator. Used to determine message length.
 *   Data Item Values: 0 through 255 addresses
 * 
 * DUI 003: NUMBER DESTINATION ADDRESSES, NON-ZERO [8 BIT]
 *   Specifies the number of destination addresses contained in this subheader.
 *   Data Item Values:
 *     ILLEGAL: 0
 *     Addresses: 1 through 255
 */

std::string Dui001(const std::array<int, 8>& numberDestinationAddresses);
std::string Dui002(const std::array<int, 8>& numberAddressesThisDesignator);
std::string Dui003(const std::array<int, 8>& numberDestinationAddressesNonZero);
}
