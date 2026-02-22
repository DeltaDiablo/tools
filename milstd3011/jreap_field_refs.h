#ifndef JREAP_FIELD_REFS_H_
#define JREAP_FIELD_REFS_H_

namespace jreap_field_refs {

struct FieldMeta
{
    const char* label;
    const char* specRef;
};

constexpr FieldMeta kAh0HeaderType{"Header Type", "AH.0 bits 0-3"};
constexpr FieldMeta kAh0MessageType{"Message Type", "AH.0 bits 4-7"};
constexpr FieldMeta kAh0TransmissionTimeRef{"Transmission Time Reference Flag", "AH.0 bit 8 / DFI3002 DUI011"};
constexpr FieldMeta kAh0Spare{"Spare", "AH.0 bits 9-11"};
constexpr FieldMeta kAh0ProtocolVersion{"Application Protocol Version", "AH.0 bits 12-15"};
constexpr FieldMeta kAh0Abml{"Application Block Message Length", "AH.0 bits 16-31 / DFI3012 DUI001"};
constexpr FieldMeta kAh0SenderId{"JRE Sender ID", "AH.0 bits 32-47"};
constexpr FieldMeta kAh0TimeAccuracy{"Time Accuracy", "AH.0 bits 48-51 / DFI3003 DUI011"};
constexpr FieldMeta kAh0DataValidTime{"Data Valid Time", "AH.0 bits 52-79 / DFI3003 DUI004"};

constexpr FieldMeta kX10Jstn{"JRE Source Track Number", "DFI3027 DUI003"};
constexpr FieldMeta kX10Sequence{"J-Series Message Sequence Number", "DFI3032 DUI003"};
constexpr FieldMeta kX10Relay{"Relay Flag", "DFI3002 DUI009"};
constexpr FieldMeta kX10AckReq{"Acknowledgement Request Flag", "DFI3002 DUI003"};
constexpr FieldMeta kX10Spare1{"Spare (1 bit)", "Reserved"};
constexpr FieldMeta kX10DataAge{"Data Age", "DFI3003 DUI003"};
constexpr FieldMeta kX10Spare4{"Spare (4 bits)", "Reserved"};
constexpr FieldMeta kX10JWords{"Number of J-Words", "DFI3033 DUI005"};
constexpr FieldMeta kX10Word1{"JREAP J-Series Message Word 1", "DFI3028 DUI001"};
constexpr FieldMeta kX10Word2{"JREAP J-Series Message Word 2", "DFI3028 DUI002"};
constexpr FieldMeta kX10Word3{"JREAP J-Series Message Word 3", "DFI3028 DUI003"};
constexpr FieldMeta kX10Word4{"JREAP J-Series Message Word 4", "DFI3028 DUI004"};
constexpr FieldMeta kX10Spare2{"Spare (2 bits)", "Reserved"};
constexpr FieldMeta kX10Word5{"JREAP J-Series Message Word 5", "DFI3028 DUI005"};

constexpr const char* kSectionApplicationHeader = "Application Header (AH.0)";
constexpr const char* kSectionAbmlConsistency = "ABML consistency";
constexpr const char* kSectionDispatchByMessageType = "Dispatch by Message Type";

constexpr const char* kDispatchNotApplicationHeader = "Dispatch: not an application header (AH.0).";
constexpr const char* kDispatchStrictAbmlMismatch = "ABML mismatch in strict mode: payload decode skipped.";

constexpr const char* kAbmlDeclaredBytesLabel = "Declared ABML bytes";
constexpr const char* kAbmlReceivedPayloadBytesLabel = "Received payload bytes (incl. AH.0 header)";
constexpr const char* kAbmlStatusTruncatedPrefix = "Status: payload truncated by ";
constexpr const char* kAbmlStatusTrailingPrefix = "Status: extra trailing payload of ";
constexpr const char* kAbmlStatusMatch = "Status: payload length matches ABML.";
constexpr const char* kAbmlModeLabel = "Mode";
constexpr const char* kAbmlPayloadBytesUsedLabel = "Payload bytes used for decode";
constexpr const char* kAbmlFieldValueLabel = "ABML field value";

constexpr const char* kDispatchManagementDetected = "Management message detected.";
constexpr const char* kDispatchManagementSubtypeLabel = "Management Subtype";
constexpr const char* kDispatchNoManagementSubtype = "No payload bytes available to decode management subtype.";
constexpr const char* kDispatchX10Detected = "X1.0 message detected.";
constexpr const char* kDispatchX100Decode = "X1.0.0 decode";
constexpr const char* kDispatchJstnSectionPrefix = "J-Series Messages For JSTN ";
constexpr const char* kDispatchX10TrailingBitsPrefix = "Trailing payload bits not forming a full X1.0 section: ";
constexpr const char* kDispatchTextCoded = "JTIDS/MIDS free text (coded) detected.";
constexpr const char* kDispatchTextUncoded = "JTIDS/MIDS free text (uncoded) detected.";
constexpr const char* kDispatchVmfDetected = "Variable Message Format (VMF) detected.";
constexpr const char* kDispatchLink22Detected = "LINK 22 detected.";
constexpr const char* kDispatchCmfIbsDetected = "CMF IBS detected.";
constexpr const char* kDispatchUnsupportedPrefix = "Unsupported/undefined AH.0 message type ";

} // namespace jreap_field_refs

#endif // JREAP_FIELD_REFS_H_
