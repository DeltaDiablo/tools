#include <array>
#include <cmath>
#include <string>

namespace dfi3037 {
//repeated function for Dfi 3037

//end of repeated functions




/* DFI 3037 DUI 001 LABEL, J-SERIES 5 bits*/
std::string Dui001(const std::array<int, 5>& labelJSeries)
{
    int labelValue = 0;
    for (size_t i = 0; i < labelJSeries.size(); ++i) {
        labelValue += labelJSeries[i] * static_cast<int>(std::pow(2, 4 - i));
    }
    switch (labelValue) {
        case 0: return "LABEL, J-SERIES ///-> SYSTEM INFORMATION, EXCHANGE AND NETWORK MANAGEMENT" + std::to_string(labelValue);
        case 1: return "LABEL, J-SERIES ///-> SYSTEM INFORMATION, EXCHANGE AND NETWORK MANAGEMENT"+ std::to_string(labelValue);
        case 2: return "LABEL, J-SERIES ///-> PRECISE PARTICIPANT LOCATION AND IDENTIFICATION (PPLI)"+ std::to_string(labelValue);
        case 3: return "LABEL, J-SERIES ///-> SURVEILLANCE"+ std::to_string(labelValue);
        case 4: return "LABEL, J-SERIES ///-> UNDEFINED"+ std::to_string(labelValue);
        case 5: return "LABEL, J-SERIES ///-> ANTISUBMARINE WARFARE"+ std::to_string(labelValue);
        case 6: return "LABEL, J-SERIES ///-> AMPLIFICATION"+ std::to_string(labelValue);
        case 7: return "LABEL, J-SERIES ///-> INFORMATION MANAGEMENT"+ std::to_string(labelValue);
        case 8: return "LABEL, J-SERIES ///-> INFORMATION MANAGEMENT"+ std::to_string(labelValue);
        case 9: return "LABEL, J-SERIES ///-> WEAPONS COORDINATION AND MANAGEMENT"+ std::to_string(labelValue);
        case 10: return "LABEL, J-SERIES ///-> WEAPONS COORDINATION AND MANAGEMENT"+ std::to_string(labelValue);
        case 11: return "LABEL, J-SERIES ///-> MISSION SUPPORT"+ std::to_string(labelValue);
        case 12: return "LABEL, J-SERIES ///-> CONTROL"+ std::to_string(labelValue);
        case 13: return "LABEL, J-SERIES ///-> PLATFORM AND SYSTEM STATUS"+ std::to_string(labelValue);
        case 14: return "LABEL, J-SERIES ///-> CONTROL"+ std::to_string(labelValue);
        case 15: return "LABEL, J-SERIES ///-> THREAT WARNING"+ std::to_string(labelValue);
        case 16: return "LABEL, J-SERIES ///-> MISSION SUPPORT"+ std::to_string(labelValue);
        case 17: return "LABEL, J-SERIES ///-> MISCELLANEOUS"+ std::to_string(labelValue);
        case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26:
            return "LABEL, J-SERIES ///-> UNDEFINED"+ std::to_string(labelValue);
        case 27: case 28: case 29: case 30:
            return "LABEL, J-SERIES ///-> NATIONAL USE"+ std::to_string(labelValue);
        case 31: return "LABEL, J-SERIES ///-> MISCELLANEOUS"+ std::to_string(labelValue);
        default: return "Illegal LABEL, J-SERIES ///-> " + std::to_string(labelValue);
    }
}
}
