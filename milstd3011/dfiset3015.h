#include <string>
#include <array>

/**
 * DFI 3015: CURRENT ERROR RATE
 *
 * DATA STANDARD USAGE: JREAP
 *
 * DUI Definitions:
 *   001 CURRENT ERROR RATE [7 BIT] (CER)
 *       Indicates the current error rate of a remote JRE processor.
 *       Applicability: FSTBH.B.0
 *
 *   002 JRE-NP ERROR RATE [7 BIT] (JNP ER1)
 *       The JRE-NC's current error rate for this JRE-NP.
 *       Applicability: FSTBH.A.NC.0
 *
 *   017 JRE-NC ERROR RATE [7 BIT] (JNC ER)
 *       JRE-NC error rate.
 *       Applicability: FSTBH.A.NP.0
 *
 *   018 ERROR RATE, CURRENT [16 BIT] (ERC)
 *       Indicates the current error rate of a remote JRE processor.
 *       Applicability: X0.14.0
 *
 * Bit Code Explanations:
 *   DUIs 001, 002, 017:
 *     0-126:   Current calculated error rate being reported
 *     127:     Error rate greater than 126
 *
 *   DUI 018:
 *     0-65534: Current calculated error rate being reported
 *     65535:   Error rate greater than 65534
 */
std::string Dui001(const std::array<int, 7>& currentErrorRate);
std::string Dui002(const std::array<int, 7>& jreNpErrorRate);
std::string Dui017(const std::array<int, 7>& jreNcErrorRate);
std::string Dui018(const std::array<int, 16>& errorRateCurrent);