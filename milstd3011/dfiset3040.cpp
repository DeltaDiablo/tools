#include <array>
#include <string>

namespace dfi3040 {
//repeated code for DFI 3040
//dui listings
/* NO STATEMENT                                    0 */
/* INITIAL ENTRY                                   1 */
/* RTT A                                           2 */
/* RTT B                                           3 */
/* NETWORK MANAGEMENT                              4 */
/* PPLI AND STATUS GROUP A                         5 */
/* PPLI AND STATUS GROUP B                         6 */
/* SURVEILLANCE                                    7 */
/* MISSION MANAGEMENT/WEAPONS COORDINATION         8 */
/* CONTROL                                         9 */
/* ELECTRONIC WARFARE                              10 */
/* IMAGE TRANSFER                                  11 */
/* VOICE GROUP A                                   12 */
/* VOICE GROUP B                                   13 */
/* PARTICIPATION GROUPS 14-18                      14-18 */
/* NONC2 JU-TO-NONC2 JU A                          19 */
/* NONC2 JU-TO-NONC2 JU B                          20 */
/* BMD OPERATIONS                                  21 */
/* COMPOSITE A                                     22 */
/* COMPOSITE B                                     23 */
/* PARTICIPATION GROUPS 24-26                      24-26 */
/* JOINT NET PPLI                                  27 */
/* DISTRIBUTED NETWORK MANAGEMENT                  28 */
/* RESIDUAL MESSAGES                               29 */
/* IJMS POSITION AND STATUS                        30 */
/* OTHER IJMS                                      31 */
/* PARTICIPATION GROUPS 32-509                     32-509 */
/* NET CONTROL NEEDLINE                            510 */
/* NET STATUS NEEDLINE                             511 */
//create the list of DIs listed above for refernce in the code below

std::string GroupResponse(const std::array<int, 9>& bitsforGroupResponse){
    //convert the of 0s and 1s  to an integer
    int groupResponseInt = 0;
    for (size_t i = 0; i < bitsforGroupResponse.size(); ++i) {
        groupResponseInt <<= 1; // Shift left to make room for the next bit
        groupResponseInt |= bitsforGroupResponse[i]; // Add the current bit
    }
    //check the integer value and return the corresponding string
    switch (groupResponseInt) {
        case 0: return "NO STATEMENT //->" + std::to_string(groupResponseInt);
        case 1: return "INITIAL ENTRY //->" + std::to_string(groupResponseInt);
        case 2: return "RTT A //->" + std::to_string(groupResponseInt);
        case 3: return "RTT B //->" + std::to_string(groupResponseInt);
        case 4: return "NETWORK MANAGEMENT //->" + std::to_string(groupResponseInt);
        case 5: return "PPLI AND STATUS GROUP A //->" + std::to_string(groupResponseInt);
        case 6: return "PPLI AND STATUS GROUP B //->" + std::to_string(groupResponseInt);
        case 7: return "SURVEILLANCE //->" + std::to_string(groupResponseInt);
        case 8: return "MISSION MANAGEMENT/WEAPONS COORDINATION //->" + std::to_string(groupResponseInt);
        case 9: return "CONTROL //->" + std::to_string(groupResponseInt);
        case 10: return "ELECTRONIC WARFARE //->" + std::to_string(groupResponseInt);
        case 11: return "IMAGE TRANSFER //->" + std::to_string(groupResponseInt);
        case 12: return "VOICE GROUP A //->" + std::to_string(groupResponseInt);
        case 13: return "VOICE GROUP B //->" + std::to_string(groupResponseInt);
        case 14: return "PARTICIPATION GROUPS 14-18 //->" + std::to_string(groupResponseInt);
        case 19: return "NONC2 JU-TO-NONC2 JU A //->" + std::to_string(groupResponseInt);
        case 20: return "NONC2 JU-TO-NONC2 JU B //->" + std::to_string(groupResponseInt);
        case 21: return "BMD OPERATIONS //->" + std::to_string(groupResponseInt);
        case 22: return "COMPOSITE A //->" + std::to_string(groupResponseInt);
        case 23: return "COMPOSITE B //->" + std::to_string(groupResponseInt);
        case 24: return "PARTICIPATION GROUPS 24-26 //->" + std::to_string(groupResponseInt);
        case 27: return "JOINT NET PPLI //->" + std::to_string(groupResponseInt);
        case 28: return "DISTRIBUTED NETWORK MANAGEMENT //->" + std::to_string(groupResponseInt);
        case 29: return "RESIDUAL MESSAGES //->" + std::to_string(groupResponseInt);
        case 30: return "IJMS POSITION AND STATUS //->" + std::to_string(groupResponseInt);
        case 31: return "OTHER IJMS //->" + std::to_string(groupResponseInt);
        default:
            if (groupResponseInt >= 32 && groupResponseInt <= 509) {
                return "PARTICIPATION GROUPS 32-509 //->" + std::to_string(groupResponseInt);
            } else if (groupResponseInt == 510) {
                return "NET CONTROL NEEDLINE //->" + std::to_string(groupResponseInt);
            } else if (groupResponseInt == 511) {
                return "NET STATUS NEEDLINE //->" + std::to_string(groupResponseInt);
            } else {
                return "INVALID GROUP RESPONSE //->" + std::to_string(groupResponseInt); // Handle invalid cases
            }
    }
}


//end repeated code for DFI 3040

/* DFI 3040 DUI 001 JTIDS/MIDS PARTICIPATION GROUP*/
std::string Dui001(const std::array<int, 9>& jtidsMidsParticipationGroup){
    return GroupResponse(jtidsMidsParticipationGroup);
}
/* DFI 3040 DUI 002 NETWORK PARTICIPATION GROUP*/
std::string Dui002(const std::array<int, 9>& networkParticipationGroup){
    return GroupResponse(networkParticipationGroup);
}
/* DFI 3040 DUI 003 NETWORK PARTICIPATION GROUP TO FILTER*/
std::string Dui003(const std::array<int, 9>& networkParticipationGroupToFilter){
    return GroupResponse(networkParticipationGroupToFilter);
}
}
