#include <string>
#include <array>
#include <cmath>

namespace dfi3020 {
/*
 * 3020 CONTROL/RESPONSE
 *
 * DATA STANDARD USAGE: JREAP
 *
 * DUI 001 - CONTROL/RESPONSE INDICATOR, 1 [8 BIT] (CR1)
 *   USED TO REQUEST A PARTICULAR ACTION IN AN ORIGINAL MANAGEMENT MESSAGE
 *   TRANSMISSION, OR TO RESPOND TO A PRIOR TRANSMISSION.
 *   DI VALUES FROM 0-127 INDICATE ORIGINAL MESSAGES.
 *   VALUES 128-255 ARE USED FOR RESPONSES TO ORIGINAL MESSAGES.
 *   APPLICABILITY: X0.0.0, X0.2.0
 *
 * DUI 002 - CONTROL/RESPONSE INDICATOR, 2 [8 BIT] (CR2)
 *   APPLICABILITY: X0.1.0
 *
 * DUI 003 - CONTROL/RESPONSE INDICATOR, 3 [8 BIT] (CR3)
 *   APPLICABILITY: X0.3.0, X0.4.0
 *
 * ... (additional DUI entries follow same pattern)
 *
 * BIT CODES FOR DUI 001:
 *   0     - QUERY
 *   1-2   - ILLEGAL
 *   3-127 - UNDEFINED (RESERVED FOR ADDITIONAL CONTROL CODES)
 *   128-129 - ILLEGAL
 *   130   - CANTPRO
 *   131   - REPORT
 *   132-133 - ILLEGAL
 *   134-191 - UNDEFINED (RESERVED FOR PROCESSOR RESPONSE CODES)
 *   192-197 - ILLEGAL
 *   198-255 - UNDEFINED (RESERVED FOR OPERATOR RESPONSE CODES)
 */

// repeatable components for DFI 3020

int GetControlResponseIndicator(const std::array<int, 8> &binary)
{
    int decimalValue = 0;
    for (size_t i = 0; i < binary.size(); ++i)
    {
        decimalValue += binary[i] * std::pow(2, binary.size() - 1 - i);
    }
    return decimalValue;
}

// end repeatable components for DFI 3020

/* DFI 3020 DUI 001 CONTROL/RESPONSE INDICATOR, 1*/
std::string Dui001(const std::array<int, 8> &controlResponseIndicator1)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator1);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0:
        return "QUERY";
    case 1 ... 2:
        return "ILLEGAL //-> " + decimal;
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 129:
        return "ILLEGAL //-> " + decimal;
    case 130:
        return "CANTPRO";
    case 131:
        return "REPORT";
    case 132 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "UNDEFINED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 002 CONTROL/RESPONSE INDICATOR, 2*/
std::string Dui002(const std::array<int, 8> &controlResponseIndicator2)
{
    // FOR DUI 002
    // 0: QUERY - Request information from JRE processor(s)
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-129: ILLEGAL
    // 130: CANTPRO - Processor cannot process query or command
    // 131-132: ILLEGAL
    // 133: REJECT - Command has been rejected
    // 134-191: RESERVED - Additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Additional operator response codes
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator2);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0:
        return "QUERY";
    case 1:
        return "COMMAND";
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 129:
        return "ILLEGAL //-> " + decimal;
    case 130:
        return "CANTPRO";
    case 131 ... 132:
        return "ILLEGAL //-> " + decimal;
    case 133:
        return "REJECT";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 003 CONTROL/RESPONSE INDICATOR, 3*/
std::string Dui003(const std::array<int, 8> &controlResponseIndicator3)
{
    // FOR DUI 003
    // 0-1: ILLEGAL
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator3);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0 ... 1:
        return "ILLEGAL";
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 004 CONTROL/RESPONSE INDICATOR, 4*/
std::string Dui004(const std::array<int, 8> &controlResponseIndicator4)
{
    // FOR DUI 004
    // 0: ILLEGAL
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-129: ILLEGAL
    // 130: CANTPRO - Processor cannot process query or command
    // 131: ILLEGAL
    // 132: ACCEPT - Command has been accepted
    // 133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator4);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0:
        return "ILLEGAL //-> " + decimal;
    case 1:
        return "COMMAND";
    case 2:
        return "ILLEGAL";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 129:
        return "ILLEGAL //-> " + decimal;
    case 130:
        return "CANTPRO";
    case 131:
        return "ILLEGAL";
    case 132:
        return "ACCEPT";
    case 133:
        return "ILLEGAL";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 005 CONTROL/RESPONSE INDICATOR, 5*/
std::string Dui005(const std::array<int, 8> &controlResponseIndicator5)
{
    // FOR DUI 005
    // 0-1: ILLEGAL
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128: ACK - Acknowledge receipt of a management message
    // 129: NACK - Negatively acknowledge receipt of a management message fragment
    // 130: CANTPRO - Processor cannot process query or command
    // 131-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-193: ILLEGAL
    // 194: UNSTAFFED - No operator present
    // 195: NOT SUPPORTED - Does not support operator acknowledgment
    // 196: TIMEOUT - Operator did not reply within timeout interval
    // 197: OPERATOR RECEIPT - Message has been displayed to operator
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator5);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0 ... 1:
        return "ILLEGAL //-> " + decimal;
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED";
    case 128:
        return "ACK";
    case 129:
        return "NACK";
    case 130:
        return "CANTPRO";
    case 131 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 193:
        return "ILLEGAL //-> " + decimal;
    case 194:
        return "UNSTAFFED";
    case 195:
        return "NOT SUPPORTED";
    case 196:
        return "TIMEOUT";
    case 197:
        return "OPERATOR RECEIPT";
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 006 CONTROL/RESPONSE INDICATOR, 6*/
std::string Dui006(const std::array<int, 8> &controlResponseIndicator6)
{
    // FOR DUI 006
    // 0: ILLEGAL
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128: ACK - Acknowledge receipt of a management message
    // 129-131: ILLEGAL
    // 132: ACCEPT - Command has been accepted
    // 133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator6);
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0:
        return "ILLEGAL";
    case 1:
        return "COMMAND";
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128:
        return "ACK";
    case 129 ... 131:
        return "ILLEGAL //-> " + decimal;
    case 132:
        return "ACCEPT";
    case 133:
        return "ILLEGAL";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 007 CONTROL/RESPONSE INDICATOR, 7*/
std::string Dui007(const std::array<int, 8> &controlResponseIndicator7)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator7);
    // FOR DUI 007
    // 0: QUERY - Request information from JRE processor(s)
    // 1-2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    std::string decimal = std::to_string(decimalValue);
    switch (decimalValue)
    {
    case 0:
        return "QUERY";
    case 1 ... 2:
        return "ILLEGAL";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 008 CONTROL/RESPONSE INDICATOR, 8*/
std::string Dui008(const std::array<int, 8> &controlResponseIndicator8)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator8);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 008
    // 0-2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-130: ILLEGAL
    // 131: REPORT - Used by the JRE processor to report information requested by a query
    // 132-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    switch (decimalValue)
    {
    case 0 ... 2:
        return "ILLEGAL //-> " + decimal;
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 130:
        return "ILLEGAL //-> " + decimal;
    case 131:
        return "REPORT";
    case 132 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 009 CONTROL/RESPONSE INDICATOR, 9*/
std::string Dui009(const std::array<int, 8> &controlResponseIndicator9)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator9);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 009
    // 0: ILLEGAL
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-130: ILLEGAL
    // 131: REPORT - Used by JRE processor to report information requested by a query
    // 132-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    switch (decimalValue)
    {
    case 0:
        return "ILLEGAL";
    case 1:
        return "COMMAND";
    case 2:
        return "ILLEGAL";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 130:
        return "ILLEGAL //-> " + decimal;
    case 131:
        return "REPORT";
    case 132 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 010 CONTROL/RESPONSE INDICATOR, 10*/
std::string Dui010(const std::array<int, 8> &controlResponseIndicator10)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator10);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 010
    // 0: QUERY - Request information from JRE processor(s)
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128: ACK - Acknowledge receipt of a management message
    // 129: ILLEGAL
    // 130: CANTPRO - Processor cannot process query or command
    // 131: REPORT - JRE processor reports information requested by a query
    // 132: ACCEPT - Command has been accepted
    // 133: REJECT - Command has been rejected
    // 134-191: RESERVED - Additional processor response codes
    // 192: ILLEGAL
    // 193: CANTCO - Operator received message but cannot comply
    // 194-197: ILLEGAL
    // 198-255: UNDEFINED - Additional operator response codes
    switch (decimalValue)
    {
    case 0:
        return "QUERY";
    case 1:
        return "COMMAND";
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128:
        return "ACK";
    case 129:
        return "ILLEGAL";
    case 130:
        return "CANTPRO";
    case 131:
        return "REPORT";
    case 132:
        return "ACCEPT";
    case 133:
        return "REJECT";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192:
        return "ILLEGAL //-> " + decimal;
    case 193:
        return "CANTCO";
    case 194 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 011 CONTROL/RESPONSE INDICATOR, 11*/
std::string Dui011(const std::array<int, 8> &controlResponseIndicator11)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator11);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 011
    // 0-2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128: ACK - Acknowledge receipt of a management message
    // 129: NACK - Negatively acknowledge receipt of a management message fragment
    // 130: CANTPRO - Processor cannot process query or command
    // 131: ILLEGAL
    // 132: ACCEPT - Command has been accepted
    // 133: REJECT - Command has been rejected
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192: WILCO - Operator received message and will comply
    // 193: CANTCO - Operator received message but cannot comply
    // 194: UNSTAFFED - No operator present
    // 195: ILLEGAL
    // 196: TIMEOUT - Operator did not reply within timeout interval
    // 197: OPERATOR RECEIPT - Message has been displayed to operator
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    switch (decimalValue)
    {
    case 0 ... 2:
        return "ILLEGAL //-> " + decimal;
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128:
        return "ACK";
    case 129:
        return "NACK";
    case 130:
        return "CANTPRO";
    case 131:
        return "ILLEGAL";
    case 132:
        return "ACCEPT";
    case 133:
        return "REJECT";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192:
        return "WILCO";
    case 193:
        return "CANTCO";
    case 194:
        return "UNSTAFFED";
    case 195:
        return "ILLEGAL //-> " + decimal;
    case 196:
        return "TIMEOUT";
    case 197:
        return "OPERATOR RECEIPT";
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 012 CONTROL/RESPONSE INDICATOR, 12*/
std::string Dui012(const std::array<int, 8> &controlResponseIndicator12)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator12);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 012
    // 0-1: ILLEGAL
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-129: ILLEGAL
    // 130: CANTPRO - Processor cannot process query or command
    // 131-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    switch (decimalValue)
    {
    case 0 ... 1:
        return "ILLEGAL //-> " + decimal;
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 129:
        return "ILLEGAL //-> " + decimal;
    case 130:
        return "CANTPRO";
    case 131 ... 133:
        return "ILLEGAL //-> " + decimal;
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL //-> " + decimal;
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 013 CONTROL/RESPONSE INDICATOR, 13*/
std::string Dui013(const std::array<int, 8> &controlResponseIndicator13)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator13);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 013
    // 0: ILLEGAL
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: ILLEGAL
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128-129: ILLEGAL
    // 130: CANTPRO - Processor cannot process query or command
    // 131-133: ILLEGAL
    // 134-191: RESERVED - Reserved for additional processor response codes
    // 192-197: ILLEGAL
    // 198-255: UNDEFINED - Reserved for additional operator response codes
    switch (decimalValue)
    {
    case 0:
        return "ILLEGAL";
    case 1:
        return "COMMAND";
    case 2:
        return "ILLEGAL";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128 ... 129:
        return "ILLEGAL";
    case 130:
        return "CANTPRO";
    case 131 ... 133:
        return "ILLEGAL";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192 ... 197:
        return "ILLEGAL";
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
/* DFI 3020 DUI 014 CONTROL/RESPONSE INDICATOR*/
std::string Dui014(const std::array<int, 8> &controlResponseIndicator)
{
    int decimalValue = GetControlResponseIndicator(controlResponseIndicator);
    std::string decimal = std::to_string(decimalValue);
    // FOR DUI 014
    // 0: QUERY - Request information from JRE processor(s)
    // 1: COMMAND - Direct JRE processor(s) to take action
    // 2: INFORMATION - Transmit data other than query or command
    // 3-127: UNDEFINED - Reserved for additional control codes
    // 128: ACK - Acknowledge receipt of a management message
    // 129: NACK - Negatively acknowledge receipt of a management message fragment
    // 130: CANTPRO - Processor cannot process query or command
    // 131: REPORT - JRE processor reports information requested by a query
    // 132: ACCEPT - Command has been accepted
    // 133: REJECT - Command has been rejected
    // 134-191: RESERVED - Additional processor response codes
    // 192: WILCO - Operator received message and will comply
    // 193: CANTCO - Operator received message but cannot comply
    // 194: UNSTAFFED - No operator present
    // 195: NOT SUPPORTED - Does not support operator acknowledgment
    // 196: TIMEOUT - Operator did not reply within timeout interval
    // 197: OPERATOR RECEIPT - Message has been displayed to operator
    // 198-255: UNDEFINED - Additional operator response codes
    switch (decimalValue)
    {
    case 0:
        return "QUERY";
    case 1:
        return "COMMAND";
    case 2:
        return "INFORMATION";
    case 3 ... 127:
        return "UNDEFINED //-> " + decimal;
    case 128:
        return "ACK";
    case 129:
        return "NACK";
    case 130:
        return "CANTPRO";
    case 131:
        return "REPORT";
    case 132:
        return "ACCEPT";
    case 133:
        return "REJECT";
    case 134 ... 191:
        return "RESERVED //-> " + decimal;
    case 192:
        return "WILCO";
    case 193:
        return "CANTCO";
    case 194:
        return "UNSTAFFED";
    case 195:
        return "NOT SUPPORTED";
    case 196:
        return "TIMEOUT";
    case 197:
        return "OPERATOR RECEIPT";
    case 198 ... 255:
        return "UNDEFINED //-> " + decimal;
    default:
        return "UNDEFINED //-> " + decimal;
    }
}
}
