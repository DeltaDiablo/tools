#include <string>
#include <array>

namespace dfi3053 {
// 001 NO STATEMENT (NS)
std::string Dui001(const std::array<int, 1>& noStatement);
// 002 COMBAT AIR PATROL (CAP)
std::string Dui002(const std::array<int, 1>& combatAirPatrol);
// 003 AIRBORNE EARLY WARNING (AEW)
std::string Dui003(const std::array<int, 1>& airborneEarlyWarning);
// 004 ANTISUBMARINE WARFARE FIXED WING (ASW FW)
std::string Dui004(const std::array<int, 1>& antisubmarineWarfareFixedWing);
// 005 ANTISUBMARINE WARFARE HELICOPTER (ASW HEL)
std::string Dui005(const std::array<int, 1>& antisubmarineWarfareHelicopter);
//06 REPLENISHMENT (RPL)
std::string Dui006(const std::array<int, 1>& replenishment);
// 007 STRIKE INITIAL POINT (STK IP)
std::string Dui007(const std::array<int, 1>& strikeInitialPoint);
// 008 TACAN (TAC)
std::string Dui008(const std::array<int, 1>& tacan);
// 009 TANKER (TKR)
std::string Dui009(const std::array<int, 1>& tanker);
// 010 ORBIT, RACE TRACK (ORB RT)
std::string Dui010(const std::array<int, 1>& orbitRaceTrack);
// 011 ORBIT, FIGURE EIGHT (ORB F8)
std::string Dui011(const std::array<int, 1>& orbitFigureEight);

// 012 ORBIT, RANDOM CLOSED (ORB RC)
std::string Dui012(const std::array<int, 1>& orbitRandomClosed);

// 013 ORBIT POINT (ORB PT)
std::string Dui013(const std::array<int, 1>& orbitPoint);
// 014 PT3, AMP13 (PT3 A13)
std::string Dui014(const std::array<int, 1>& pt3Amp13);
// 015 PT3, AMP14 (PT3 A14)
std::string Dui015(const std::array<int, 1>& pt3Amp14);
// 016 PT3, AMP15 (PT3 A15)
std::string Dui016(const std::array<int, 1>& pt3Amp15);
}
