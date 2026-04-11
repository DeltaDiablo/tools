#include "raylib.h"
#include <iostream>
#include <array>
#include <cctype>
#include <sstream>
#include <vector>
#include "ByteToBits.h"
#include "milstd3011/jreaplib.h"
#include "milstd6016/messageProcessorJ00I.h"
#include "milstd6016/messageProcessorJ01I.h"
#include "milstd6016/messageProcessorJ02I.h"
#include "milstd6016/messageProcessorJ03I.h"
#include "milstd6016/messageProcessorJ04I.h"
#include "milstd6016/messageProcessorJ05I.h"
#include "milstd6016/messageProcessorJ06I.h"
#include "milstd6016/messageProcessorJ07I.h"
#include "milstd6016/messageProcessorJ10I.h"
#include "milstd6016/messageProcessorJ11I.h"
#include "milstd6016/messageProcessorJ12I.h"
#include "milstd6016/messageProcessorJ13I.h"
#include "milstd6016/messageProcessorJ14I.h"
#include "milstd6016/messageProcessorJ15I.h"
#include "milstd6016/messageProcessorJ16I.h"
#include "milstd6016/messageProcessorJ20I.h"
#include "milstd6016/messageProcessorJ20E0.h"
#include "milstd6016/messageProcessorJ20C1.h"
#include "milstd6016/messageProcessorJ20C2.h"
#include "milstd6016/messageProcessorJ20C3.h"
#include "milstd6016/messageProcessorJ22I.h"
#include "milstd6016/messageProcessorJ22E0.h"
#include "milstd6016/messageProcessorJ22C1.h"
#include "milstd6016/messageProcessorJ22C2.h"
#include "milstd6016/messageProcessorJ22C3.h"
#include "milstd6016/messageProcessorJ22C5.h"
#include "milstd6016/messageProcessorJ23I.h"
#include "milstd6016/messageProcessorJ23E0.h"
#include "milstd6016/messageProcessorJ23C1.h"
#include "milstd6016/messageProcessorJ23C2.h"
#include "milstd6016/messageProcessorJ23C3.h"
#include "milstd6016/messageProcessorJ24I.h"
#include "milstd6016/messageProcessorJ24E0.h"
#include "milstd6016/messageProcessorJ24C1.h"
#include "milstd6016/messageProcessorJ24C2.h"
#include "milstd6016/messageProcessorJ24C3.h"
#include "milstd6016/messageProcessorJ25I.h"
#include "milstd6016/messageProcessorJ25E0.h"
#include "milstd6016/messageProcessorJ25C1.h"
#include "milstd6016/messageProcessorJ25C3.h"
#include "milstd6016/messageProcessorJ25C4.h"
#include "milstd6016/messageProcessorJ26I.h"
#include "milstd6016/messageProcessorJ26E0.h"
#include "milstd6016/messageProcessorJ26C1.h"
#include "milstd6016/messageProcessorJ26C3.h"
#include "milstd6016/messageProcessorJ00C1.h"
#include "milstd6016/messageProcessorJ03C1.h"
#include "milstd6016/messageProcessorJ03C2.h"
#include "milstd6016/messageProcessorJ04C1.h"
#include "milstd6016/messageProcessorJ04C2.h"
#include "milstd6016/messageProcessorJ06C1.h"
#include "milstd6016/messageProcessorJ06C2.h"
#include "milstd6016/messageProcessorJ06C3.h"
#include "milstd6016/messageProcessorJ06C4.h"
#include "milstd6016/messageProcessorJ11C1.h"
#include "milstd6016/messageProcessorJ11C2.h"
#include "milstd6016/messageProcessorJ15C1.h"
#include "milstd6016/messageProcessorJ01C21.h"
#include "milstd6016/messageProcessorJ00E0.h"
#include "milstd6016/messageProcessorJ01E0.h"
#include "milstd6016/messageProcessorJ03E0.h"
#include "milstd6016/messageProcessorJ04E0.h"
#include "milstd6016/messageProcessorJ07E0.h"
#include "milstd6016/messageProcessorJ10E0.h"
#include "milstd6016/messageProcessorJ11E0.h"
#include "milstd6016/messageProcessorJ12E0.h"
#include "milstd6016/messageProcessorJ12E1.h"
#include "milstd6016/messageProcessorJ13E0.h"
#include "milstd6016/messageProcessorJ14E0.h"
#include "milstd6016/messageProcessorJ15E0.h"
#include "milstd6016/messageProcessorJ16E0.h"
#include <cmath>

namespace {

enum class InputMode
{
    Auto,
    Jreap,
    Raw6016
};

const char* InputModeLabel(InputMode mode)
{
    switch (mode)
    {
    case InputMode::Jreap:
        return "JREAP";
    case InputMode::Raw6016:
        return "RAW-6016";
    case InputMode::Auto:
    default:
        return "AUTO";
    }
}

std::string Trim(const std::string& value)
{
    std::size_t start = 0;
    while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start])) != 0)
    {
        ++start;
    }

    std::size_t end = value.size();
    while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])) != 0)
    {
        --end;
    }

    return value.substr(start, end - start);
}

bool IsBinaryLike(const std::string& input)
{
    bool hasBinaryDigit = false;
    for (char c : input)
    {
        if (c == '0' || c == '1')
        {
            hasBinaryDigit = true;
            continue;
        }

        if (std::isspace(static_cast<unsigned char>(c)) != 0 || c == '_' || c == '-')
        {
            continue;
        }

        return false;
    }

    return hasBinaryDigit;
}

std::string SanitizeBinaryBits(const std::string& input)
{
    std::string bits;
    bits.reserve(input.size());
    for (char c : input)
    {
        if (c == '0' || c == '1')
        {
            bits.push_back(c);
        }
    }
    return bits;
}

bool TryParseCsvBytes(const std::string& input, std::vector<int>& bytes)
{
    std::stringstream stream(input);
    std::string token;
    bytes.clear();

    while (std::getline(stream, token, ','))
    {
        token = Trim(token);
        if (token.empty())
        {
            continue;
        }

        std::stringstream tokenStream(token);
        int value = -1;
        tokenStream >> value;
        if (!tokenStream || !tokenStream.eof() || value < 0 || value > 255)
        {
            bytes.clear();
            return false;
        }

        bytes.push_back(value);
    }

    return !bytes.empty();
}

std::string JoinCsvBytes(const std::vector<int>& bytes)
{
    std::ostringstream output;
    for (std::size_t index = 0; index < bytes.size(); ++index)
    {
        if (index != 0)
        {
            output << ',';
        }
        output << bytes[index];
    }
    return output.str();
}

std::string BytesToBitString(const std::vector<int>& bytes)
{
    std::string bits;
    bits.reserve(bytes.size() * 8);
    for (std::size_t index = 0; index < bytes.size(); ++index)
    {
        bits += ByteToBinaryConverter(bytes[index], true);
    }
    return bits;
}

std::string ExtractFieldBits(const std::string& msbToLsbBits, int lowBit, int highBit)
{
    const std::size_t width = static_cast<std::size_t>(highBit - lowBit + 1);
    const std::size_t start = msbToLsbBits.size() - 1 - static_cast<std::size_t>(highBit);
    return msbToLsbBits.substr(start, width);
}

int BitsToUInt(const std::string& bits)
{
    int value = 0;
    for (char bit : bits)
    {
        value <<= 1;
        if (bit == '1')
        {
            value |= 1;
        }
    }
    return value;
}

enum class ContinuationWordChoice
{
    J00C1,
    J15C1,
    J20C1,
    J20C2,
    J20C3,
    J22C1,
    J23C1,
    J25C1
};

enum class Label2ContinuationWordChoice
{
    J03C2,
    J22C2,
    J23C2
};

enum class Label3ContinuationWordChoice
{
    J06C3,
    J22C3,
    J23C3
};

enum class Label4ContinuationWordChoice
{
    J06C4,
    J25C4
};

ContinuationWordChoice SelectContinuationWord(const std::string& wordBits)
{
    const int minute = BitsToUInt(ExtractFieldBits(wordBits, 7, 12));
    const int second = BitsToUInt(ExtractFieldBits(wordBits, 13, 18));
    const int millisecond = BitsToUInt(ExtractFieldBits(wordBits, 19, 28));
    const bool hasNonZeroTime = (minute != 0) || (second != 0) || (millisecond != 0);
    const bool c3TimePlausible = (minute < 60) && (second < 60) && (millisecond < 1000);
    if (c3TimePlausible && hasNonZeroTime)
    {
        return ContinuationWordChoice::J20C3;
    }

    const int voiceCallSign = BitsToUInt(ExtractFieldBits(wordBits, 21, 44));
    const int flightLeadTrack = BitsToUInt(ExtractFieldBits(wordBits, 45, 59));
    const int controlChannel = BitsToUInt(ExtractFieldBits(wordBits, 60, 66));
    if ((voiceCallSign != 0 && flightLeadTrack != 0) || (voiceCallSign != 0 && controlChannel != 0))
    {
        return ContinuationWordChoice::J20C2;
    }

    const int j25VoiceCallSign = BitsToUInt(ExtractFieldBits(wordBits, 9, 32));
    const int j25LandPlatform = BitsToUInt(ExtractFieldBits(wordBits, 33, 38));
    const int j25LandActivity = BitsToUInt(ExtractFieldBits(wordBits, 39, 45));
    const int j25VoiceChannel = BitsToUInt(ExtractFieldBits(wordBits, 46, 58));
    const int j25ControlChannel = BitsToUInt(ExtractFieldBits(wordBits, 59, 65));
    if ((j25VoiceCallSign != 0 || j25VoiceChannel != 0 || j25ControlChannel != 0) &&
        (j25LandPlatform != 0 || j25LandActivity != 0))
    {
        return ContinuationWordChoice::J25C1;
    }

    const int j22PlatformAndActivity = BitsToUInt(ExtractFieldBits(wordBits, 37, 49));
    const int j22SpareTail = BitsToUInt(ExtractFieldBits(wordBits, 50, 69));
    if (j22PlatformAndActivity != 0 && j22SpareTail == 0)
    {
        const int modeI = BitsToUInt(ExtractFieldBits(wordBits, 8, 12));
        const int modeII = BitsToUInt(ExtractFieldBits(wordBits, 13, 24));
        const int modeIII = BitsToUInt(ExtractFieldBits(wordBits, 25, 36));
        if (modeI == 0 && modeII == 0 && modeIII == 0)
        {
            return ContinuationWordChoice::J23C1;
        }

        return ContinuationWordChoice::J22C1;
    }

    const int j00c1SpareTail = BitsToUInt(ExtractFieldBits(wordBits, 41, 69));
    if (j00c1SpareTail != 0)
    {
        const int modePayload = BitsToUInt(ExtractFieldBits(wordBits, 8, 36));
        const int missionCorrelator = BitsToUInt(ExtractFieldBits(wordBits, 61, 68));
        if (modePayload != 0 || missionCorrelator != 0)
        {
            return ContinuationWordChoice::J20C1;
        }

        return ContinuationWordChoice::J15C1;
    }

    return ContinuationWordChoice::J00C1;
}

Label2ContinuationWordChoice SelectLabel2ContinuationWord(const std::string& wordBits)
{
    const int j03c2SpareTail = BitsToUInt(ExtractFieldBits(wordBits, 27, 69));
    if (j03c2SpareTail == 0)
    {
        return Label2ContinuationWordChoice::J03C2;
    }

    const int j22SpareTail = BitsToUInt(ExtractFieldBits(wordBits, 63, 69));
    if (j22SpareTail != 0)
    {
        return Label2ContinuationWordChoice::J23C2;
    }

    return Label2ContinuationWordChoice::J22C2;
}

Label3ContinuationWordChoice SelectLabel3ContinuationWord(const std::string& wordBits)
{
    const int j23Tail = BitsToUInt(ExtractFieldBits(wordBits, 63, 69));
    if (j23Tail != 0)
    {
        return Label3ContinuationWordChoice::J23C3;
    }

    const int effectiveMinute = BitsToUInt(ExtractFieldBits(wordBits, 41, 46));
    const int effectiveHour = BitsToUInt(ExtractFieldBits(wordBits, 47, 51));
    const bool j06TimePlausible = (effectiveMinute < 60) && (effectiveHour < 24);

    if (!j06TimePlausible)
    {
        return Label3ContinuationWordChoice::J22C3;
    }

    const int j22ReferencePoint = BitsToUInt(ExtractFieldBits(wordBits, 39, 62));
    const int j22SpareTail = BitsToUInt(ExtractFieldBits(wordBits, 63, 69));
    if (j22ReferencePoint != 0 && j22SpareTail == 0)
    {
        return Label3ContinuationWordChoice::J22C3;
    }

    return Label3ContinuationWordChoice::J06C3;
}

Label4ContinuationWordChoice SelectLabel4ContinuationWord(const std::string& wordBits)
{
    const int spare1 = BitsToUInt(ExtractFieldBits(wordBits, 7, 9));
    const int spare2 = BitsToUInt(ExtractFieldBits(wordBits, 30, 32));
    const int spareTail = BitsToUInt(ExtractFieldBits(wordBits, 54, 69));
    const int latitude = BitsToUInt(ExtractFieldBits(wordBits, 10, 29));
    const int longitude = BitsToUInt(ExtractFieldBits(wordBits, 33, 53));
    if (spare1 == 0 && spare2 == 0 && spareTail == 0 && (latitude != 0 || longitude != 0))
    {
        return Label4ContinuationWordChoice::J25C4;
    }

    return Label4ContinuationWordChoice::J06C4;
}

std::string DescribeJSeriesWordFromSubheader(int wordFormat, int label, int sublabel)
{
    if (wordFormat == 0 && label == 0 && sublabel == 0)
    {
        return "J0.0I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 1)
    {
        return "J0.1I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 2)
    {
        return "J0.2I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 3)
    {
        return "J0.3I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 4)
    {
        return "J0.4I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 5)
    {
        return "J0.5I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 6)
    {
        return "J0.6I";
    }
    if (wordFormat == 0 && label == 0 && sublabel == 7)
    {
        return "J0.7I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 0)
    {
        return "J1.0I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 1)
    {
        return "J1.1I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 2)
    {
        return "J1.2I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 3)
    {
        return "J1.3I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 4)
    {
        return "J1.4I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 5)
    {
        return "J1.5I";
    }
    if (wordFormat == 0 && label == 1 && sublabel == 6)
    {
        return "J1.6I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 0)
    {
        return "J2.0I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 2)
    {
        return "J2.2I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 3)
    {
        return "J2.3I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 4)
    {
        return "J2.4I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 5)
    {
        return "J2.5I";
    }
    if (wordFormat == 0 && label == 2 && sublabel == 6)
    {
        return "J2.6I";
    }
    if (wordFormat == 1 && label == 1)
    {
        return "J0.0C1 / J1.5C1 / J2.0C1 / J2.0C2 / J2.0C3 / J2.2C1 / J2.3C1 / J2.4C1 / J2.5C1 / J2.6C1 (ambiguous C-word)";
    }
    if (wordFormat == 1 && label == 2)
    {
        return "J0.3C2 / J2.2C2 / J2.3C2 / J2.4C2 (ambiguous C-word)";
    }
    if (wordFormat == 1 && label == 3)
    {
        return "J0.6C3 / J2.2C3 / J2.3C3 / J2.4C3 / J2.5C3 / J2.6C3 (ambiguous C-word)";
    }
    if (wordFormat == 1 && label == 5)
    {
        return "J2.2C5";
    }
    if (wordFormat == 1 && label == 4)
    {
        return "J0.6C4 / J2.5C4 (ambiguous C-word)";
    }
    if (wordFormat == 1 && label == 21)
    {
        return "J0.1C21";
    }
    if (wordFormat == 2 && label == 0 && sublabel == 0)
    {
        return "J0.0E0";
    }
    if (wordFormat == 2 && label == 0 && sublabel == 1)
    {
        return "J0.1E0";
    }
    if (wordFormat == 2 && label == 0 && sublabel == 3)
    {
        return "J0.3E0";
    }
    if (wordFormat == 2 && label == 0 && sublabel == 4)
    {
        return "J0.4E0";
    }
    if (wordFormat == 2 && label == 0 && sublabel == 7)
    {
        return "J0.7E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 0)
    {
        return "J1.0E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 1)
    {
        return "J1.1E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 2)
    {
        return "J1.2E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 3)
    {
        return "J1.3E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 4)
    {
        return "J1.4E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 5)
    {
        return "J1.5E0";
    }
    if (wordFormat == 2 && label == 1 && sublabel == 6)
    {
        return "J1.6E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 0)
    {
        return "J2.0E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 2)
    {
        return "J2.2E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 3)
    {
        return "J2.3E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 4)
    {
        return "J2.4E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 5)
    {
        return "J2.5E0";
    }
    if (wordFormat == 2 && label == 2 && sublabel == 6)
    {
        return "J2.6E0";
    }
    if (wordFormat == 2)
    {
        return "Unknown E0 word";
    }

    if (wordFormat == 1)
    {
        return "Unknown C-word";
    }

    if (wordFormat == 0)
    {
        return "Unknown I-word";
    }

    return "Unknown/unsupported J-series word";
}

bool TryGetWordBits(const std::string& input, std::string& wordBits)
{
    if (IsBinaryLike(input))
    {
        wordBits = SanitizeBinaryBits(input);
        return wordBits.size() >= 70;
    }

    std::vector<int> bytes;
    if (!TryParseCsvBytes(input, bytes))
    {
        return false;
    }

    wordBits = BytesToBitString(bytes);
    return wordBits.size() >= 70;
}

bool TryExtractJreapJSeriesPayloadBits(const std::string& input, std::string& payloadBits, std::string& info)
{
    std::vector<int> bytes;
    if (!TryParseCsvBytes(input, bytes))
    {
        return false;
    }

    if (bytes.size() < 10)
    {
        return false;
    }

    const int firstByte = bytes[0] & 0xFF;
    const int headerType = (firstByte >> 4) & 0x0F;
    const int messageType = firstByte & 0x0F;
    if (headerType != 3 || messageType != 1)
    {
        return false;
    }

    const int transmissionTimeReferenceFlag = (bytes[1] >> 7) & 0x01;
    const int appProtocolVersion = bytes[1] & 0x0F;
    const int declaredAbmlTotal = ((bytes[2] & 0xFF) << 8) | (bytes[3] & 0xFF);
    const int senderId = ((bytes[4] & 0xFF) << 8) | (bytes[5] & 0xFF);
    const int timeAccuracy = (bytes[6] >> 4) & 0x0F;
    const int dataValidTime = ((bytes[6] & 0x0F) << 24) |
                              ((bytes[7] & 0xFF) << 16) |
                              ((bytes[8] & 0xFF) << 8) |
                              (bytes[9] & 0xFF);
    const int receivedTotal = static_cast<int>(bytes.size());
    const int receivedPayload = receivedTotal - 10;
    int declaredPayload = declaredAbmlTotal - 10;
    if (declaredPayload < 0)
    {
        declaredPayload = 0;
    }

    int effectivePayload = declaredPayload;
    if (effectivePayload > receivedPayload)
    {
        effectivePayload = receivedPayload;
    }
    if (effectivePayload < 0)
    {
        effectivePayload = 0;
    }

    std::vector<int> payloadBytes;
    payloadBytes.reserve(static_cast<std::size_t>(effectivePayload));
    for (int index = 0; index < effectivePayload; ++index)
    {
        payloadBytes.push_back(bytes[10 + static_cast<std::size_t>(index)] & 0xFF);
    }

    payloadBits = BytesToBitString(payloadBytes);

    int wordFormat = -1;
    int label = -1;
    int sublabel = -1;
    if (payloadBits.size() >= 10)
    {
        wordFormat = BitsToUInt(ExtractFieldBits(payloadBits, 0, 1));
        label = BitsToUInt(ExtractFieldBits(payloadBits, 2, 6));
        sublabel = BitsToUInt(ExtractFieldBits(payloadBits, 7, 9));
    }

    std::ostringstream context;
    context << "JREAP AH.0 detected"
            << "\nAH.0 Header Type: " << headerType
            << "\nAH.0 Message Type: " << messageType
            << "\nAH.0 Transmission Time Reference Flag: " << transmissionTimeReferenceFlag
            << "\nAH.0 Application Protocol Version: " << appProtocolVersion
            << "\nAH.0 Application Block Message Length (ABML total bytes): " << declaredAbmlTotal
            << "\nAH.0 Received total bytes: " << receivedTotal
            << "\nAH.0 JRE Sender ID: " << senderId
            << "\nAH.0 Time Accuracy: " << timeAccuracy
            << "\nAH.0 Data Valid Time: " << dataValidTime
            << "\nAH.0 Payload used: " << effectivePayload << " byte(s)";

    if (wordFormat >= 0)
    {
        const std::string guessedWord = DescribeJSeriesWordFromSubheader(wordFormat, label, sublabel);
        context << "\nJ-Series Subheader (Word 1)"
                << "\n  WORD FORMAT: " << wordFormat
                << "\n  LABEL: " << label
            << "\n  SUBLABEL: " << sublabel
            << "\n  Message Guess: " << guessedWord;
    }
    else
    {
        context << "\nJ-Series Subheader (Word 1): unavailable (payload shorter than 10 bits).";
    }

    info = context.str();

    return payloadBits.size() >= 70;
}

std::string BuildJreapTestJ00IMessageCsv()
{
    std::vector<int> bytes;
    bytes.reserve(19);

    bytes.push_back(0x31);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x13);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);

    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);
    bytes.push_back(0x00);

    return JoinCsvBytes(bytes);
}

std::string DecodeMilStd6016Word(const std::string& input, InputMode mode)
{
    std::string normalizedInput = Trim(input);
    std::vector<int> csvBytes;
    if (TryParseCsvBytes(normalizedInput, csvBytes))
    {
        std::string jreapOutput = jreap::DecodeApplicationMessageCsv(normalizedInput, false);

        std::string payloadBits;
        std::string jreapContext;
        if (!TryExtractJreapJSeriesPayloadBits(normalizedInput, payloadBits, jreapContext))
        {
            return jreapOutput;
        }

        const std::size_t fullWordCount = payloadBits.size() / 70;
        const std::size_t trailingBits = payloadBits.size() % 70;
        if (fullWordCount == 0)
        {
            return jreapOutput;
        }

        std::ostringstream combined;
        combined << jreapOutput;
        combined << "\n\nMIL-STD-6016 processing";
        combined << "\nPacked J-series words detected: " << fullWordCount;

        for (std::size_t wordIndex = 0; wordIndex < fullWordCount; ++wordIndex)
        {
            const std::string oneWordBits = payloadBits.substr(wordIndex * 70, 70);
            const std::string decodedWord = DecodeMilStd6016Word(oneWordBits, InputMode::Raw6016);

            combined << "\n\n[J-Word " << (wordIndex + 1) << "]\n";
            combined << decodedWord;
        }

        if (trailingBits > 0)
        {
            combined << "\n\nNote: " << trailingBits
                     << " trailing payload bit(s) were not decoded because MIL-STD-6016 words are 70 bits each.";
        }

        return combined.str();
    }

    std::string jreapContext;
    std::string sourceLabel;
    std::string wordBits;
    std::string forcedWord;

    if (normalizedInput.size() > 7)
    {
        const std::string prefix = normalizedInput.substr(0, 7);
        if (prefix == "J0.0E0:" || prefix == "j0.0e0:")
        {
            forcedWord = "J0.0E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.1E0:" || prefix == "j0.1e0:")
        {
            forcedWord = "J0.1E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.1C21" || prefix == "j0.1c21")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J0.1C21";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J0.3C1:" || prefix == "j0.3c1:")
        {
            forcedWord = "J0.3C1";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.3E0:" || prefix == "j0.3e0:")
        {
            forcedWord = "J0.3E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.4E0:" || prefix == "j0.4e0:")
        {
            forcedWord = "J0.4E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.7E0:" || prefix == "j0.7e0:")
        {
            forcedWord = "J0.7E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.0E0:" || prefix == "j1.0e0:")
        {
            forcedWord = "J1.0E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.1E0:" || prefix == "j1.1e0:")
        {
            forcedWord = "J1.1E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.2E0:" || prefix == "j1.2e0:")
        {
            forcedWord = "J1.2E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.2E1:" || prefix == "j1.2e1:")
        {
            forcedWord = "J1.2E1";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.3E0:" || prefix == "j1.3e0:")
        {
            forcedWord = "J1.3E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.4E0:" || prefix == "j1.4e0:")
        {
            forcedWord = "J1.4E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.5E0:" || prefix == "j1.5e0:")
        {
            forcedWord = "J1.5E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.6E0:" || prefix == "j1.6e0:")
        {
            forcedWord = "J1.6E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.2I:" || prefix == "j1.2i:")
        {
            forcedWord = "J1.2I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.3I:" || prefix == "j1.3i:")
        {
            forcedWord = "J1.3I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.4I:" || prefix == "j1.4i:")
        {
            forcedWord = "J1.4I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.5C1" || prefix == "j1.5c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J1.5C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J1.5I:" || prefix == "j1.5i:")
        {
            forcedWord = "J1.5I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.6I:" || prefix == "j1.6i:")
        {
            forcedWord = "J1.6I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.0I:" || prefix == "j2.0i:")
        {
            forcedWord = "J2.0I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.0E0:" || prefix == "j2.0e0:")
        {
            forcedWord = "J2.0E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.0C1" || prefix == "j2.0c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.0C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.0C2" || prefix == "j2.0c2")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.0C2";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.0C3" || prefix == "j2.0c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.0C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.2I:" || prefix == "j2.2i:")
        {
            forcedWord = "J2.2I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.2E0:" || prefix == "j2.2e0:")
        {
            forcedWord = "J2.2E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.2C1" || prefix == "j2.2c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.2C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.2C2" || prefix == "j2.2c2")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.2C2";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.2C3" || prefix == "j2.2c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.2C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.2C5" || prefix == "j2.2c5")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.2C5";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.3I:" || prefix == "j2.3i:")
        {
            forcedWord = "J2.3I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.3E0:" || prefix == "j2.3e0:")
        {
            forcedWord = "J2.3E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.3C1" || prefix == "j2.3c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.3C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.3C2" || prefix == "j2.3c2")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.3C2";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.3C3" || prefix == "j2.3c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.3C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.4I:" || prefix == "j2.4i:")
        {
            forcedWord = "J2.4I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.4E0:" || prefix == "j2.4e0:")
        {
            forcedWord = "J2.4E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.4C1" || prefix == "j2.4c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.4C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.4C2" || prefix == "j2.4c2")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.4C2";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.4C3" || prefix == "j2.4c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.4C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.5I:" || prefix == "j2.5i:")
        {
            forcedWord = "J2.5I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.5E0:" || prefix == "j2.5e0:")
        {
            forcedWord = "J2.5E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.5C1" || prefix == "j2.5c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.5C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.5C3" || prefix == "j2.5c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.5C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.5C4" || prefix == "j2.5c4")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.5C4";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.6I:" || prefix == "j2.6i:")
        {
            forcedWord = "J2.6I";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.6E0:" || prefix == "j2.6e0:")
        {
            forcedWord = "J2.6E0";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J2.6C1" || prefix == "j2.6c1")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.6C1";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J2.6C3" || prefix == "j2.6c3")
        {
            if (normalizedInput.size() > 8 && normalizedInput[7] == ':')
            {
                forcedWord = "J2.6C3";
                normalizedInput = Trim(normalizedInput.substr(8));
            }
        }
        else if (prefix == "J0.4C1:" || prefix == "j0.4c1:")
        {
            forcedWord = "J0.4C1";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.4C2:" || prefix == "j0.4c2:")
        {
            forcedWord = "J0.4C2";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.6C1:" || prefix == "j0.6c1:")
        {
            forcedWord = "J0.6C1";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J0.6C2:" || prefix == "j0.6c2:")
        {
            forcedWord = "J0.6C2";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.1C1:" || prefix == "j1.1c1:")
        {
            forcedWord = "J1.1C1";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
        else if (prefix == "J1.1C2:" || prefix == "j1.1c2:")
        {
            forcedWord = "J1.1C2";
            normalizedInput = Trim(normalizedInput.substr(7));
        }
    }

    if (normalizedInput == "TEST J0.0I" || normalizedInput == "test j0.0i")
    {
        normalizedInput = BuildJreapTestJ00IMessageCsv();
        sourceLabel = "JREAP test message (J0.0I)";
    }

    if (mode == InputMode::Jreap)
    {
        if (!TryExtractJreapJSeriesPayloadBits(normalizedInput, wordBits, jreapContext))
        {
            return "JREAP mode expects a full JREAP AH.0 J-Series CSV message (HeaderType=3, MessageType=1).";
        }

        if (sourceLabel.empty())
        {
            sourceLabel = "JREAP input";
        }
    }
    else if (mode == InputMode::Raw6016)
    {
        if (!TryGetWordBits(normalizedInput, wordBits))
        {
            return "RAW-6016 mode expects either a 70-bit MIL-STD-6016 word or comma-separated payload bytes.";
        }
    }
    else
    {
        if (TryExtractJreapJSeriesPayloadBits(normalizedInput, wordBits, jreapContext))
        {
            if (sourceLabel.empty())
            {
                sourceLabel = "JREAP input";
            }
        }
        else if (!TryGetWordBits(normalizedInput, wordBits))
        {
            return "Unable to parse input. Provide a full JREAP CSV message or a 70-bit MIL-STD-6016 word/bytes.";
        }
    }

    if (!jreapContext.empty())
    {
        const std::size_t fullWordCount = wordBits.size() / 70;
        const std::size_t trailingBits = wordBits.size() % 70;

        if (fullWordCount > 1)
        {
            std::ostringstream multiWordOutput;
            if (!sourceLabel.empty())
            {
                multiWordOutput << "Source: " << sourceLabel;
            }
            if (!jreapContext.empty())
            {
                if (!sourceLabel.empty())
                {
                    multiWordOutput << "\n";
                }
                multiWordOutput << jreapContext;
            }
            multiWordOutput << "\n\nDecoded J-Series Words: " << fullWordCount;
            if (!forcedWord.empty())
            {
                multiWordOutput << "\nDecode mode: forced " << forcedWord << " for each word";
            }

            for (std::size_t wordIndex = 0; wordIndex < fullWordCount; ++wordIndex)
            {
                const std::string oneWordBits = wordBits.substr(wordIndex * 70, 70);
                std::string decodedWord;
                if (forcedWord.empty())
                {
                    decodedWord = DecodeMilStd6016Word(oneWordBits, InputMode::Raw6016);
                }
                else
                {
                    decodedWord = DecodeMilStd6016Word(forcedWord + ":" + oneWordBits, InputMode::Raw6016);
                }

                multiWordOutput << "\n\n[Word " << (wordIndex + 1) << "]\n";
                multiWordOutput << decodedWord;
            }

            if (trailingBits > 0)
            {
                multiWordOutput << "\n\nNote: " << trailingBits
                                << " trailing payload bit(s) were not decoded because MIL-STD-6016 words are 70 bits each.";
            }

            return multiWordOutput.str();
        }
    }

    wordBits = wordBits.substr(0, 70);

    const int wordFormat = BitsToUInt(ExtractFieldBits(wordBits, 0, 1));
    const int label = BitsToUInt(ExtractFieldBits(wordBits, 2, 6));
    const int sublabel = BitsToUInt(ExtractFieldBits(wordBits, 7, 9));

    if (!forcedWord.empty())
    {
        std::cerr << "[decode-route] wf=" << wordFormat
                  << " label=" << label
                  << " sublabel=" << sublabel
                  << " selected=" << forcedWord
                  << " mode=forced"
                  << std::endl;
    }

    if (forcedWord == "J0.0E0")
    {
        return milstd6016::ProcessJ00E0MessageBits(wordBits);
    }
    if (forcedWord == "J0.1E0")
    {
        return milstd6016::ProcessJ01E0MessageBits(wordBits);
    }
    if (forcedWord == "J0.1C21")
    {
        return milstd6016::ProcessJ01C21MessageBits(wordBits);
    }
    if (forcedWord == "J0.3C1")
    {
        return milstd6016::ProcessJ03C1MessageBits(wordBits);
    }
    if (forcedWord == "J0.3E0")
    {
        return milstd6016::ProcessJ03E0MessageBits(wordBits);
    }
    if (forcedWord == "J0.4E0")
    {
        return milstd6016::ProcessJ04E0MessageBits(wordBits);
    }
    if (forcedWord == "J0.7E0")
    {
        return milstd6016::ProcessJ07E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.0E0")
    {
        return milstd6016::ProcessJ10E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.1E0")
    {
        return milstd6016::ProcessJ11E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.2E0")
    {
        return milstd6016::ProcessJ12E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.2E1")
    {
        return milstd6016::ProcessJ12E1MessageBits(wordBits);
    }
    if (forcedWord == "J1.3E0")
    {
        return milstd6016::ProcessJ13E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.4E0")
    {
        return milstd6016::ProcessJ14E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.5E0")
    {
        return milstd6016::ProcessJ15E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.6E0")
    {
        return milstd6016::ProcessJ16E0MessageBits(wordBits);
    }
    if (forcedWord == "J1.2I")
    {
        return milstd6016::ProcessJ12IMessageBits(wordBits);
    }
    if (forcedWord == "J1.3I")
    {
        return milstd6016::ProcessJ13IMessageBits(wordBits);
    }
    if (forcedWord == "J1.4I")
    {
        return milstd6016::ProcessJ14IMessageBits(wordBits);
    }
    if (forcedWord == "J1.5C1")
    {
        return milstd6016::ProcessJ15C1MessageBits(wordBits);
    }
    if (forcedWord == "J1.5I")
    {
        return milstd6016::ProcessJ15IMessageBits(wordBits);
    }
    if (forcedWord == "J1.6I")
    {
        return milstd6016::ProcessJ16IMessageBits(wordBits);
    }
    if (forcedWord == "J2.0I")
    {
        return milstd6016::ProcessJ20IMessageBits(wordBits);
    }
    if (forcedWord == "J2.0E0")
    {
        return milstd6016::ProcessJ20E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.0C1")
    {
        return milstd6016::ProcessJ20C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.0C2")
    {
        return milstd6016::ProcessJ20C2MessageBits(wordBits);
    }
    if (forcedWord == "J2.0C3")
    {
        return milstd6016::ProcessJ20C3MessageBits(wordBits);
    }
    if (forcedWord == "J2.2I")
    {
        return milstd6016::ProcessJ22IMessageBits(wordBits);
    }
    if (forcedWord == "J2.2E0")
    {
        return milstd6016::ProcessJ22E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.2C1")
    {
        return milstd6016::ProcessJ22C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.2C2")
    {
        return milstd6016::ProcessJ22C2MessageBits(wordBits);
    }
    if (forcedWord == "J2.2C3")
    {
        return milstd6016::ProcessJ22C3MessageBits(wordBits);
    }
    if (forcedWord == "J2.2C5")
    {
        return milstd6016::ProcessJ22C5MessageBits(wordBits);
    }
    if (forcedWord == "J2.3I")
    {
        return milstd6016::ProcessJ23IMessageBits(wordBits);
    }
    if (forcedWord == "J2.3E0")
    {
        return milstd6016::ProcessJ23E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.3C1")
    {
        return milstd6016::ProcessJ23C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.3C2")
    {
        return milstd6016::ProcessJ23C2MessageBits(wordBits);
    }
    if (forcedWord == "J2.3C3")
    {
        return milstd6016::ProcessJ23C3MessageBits(wordBits);
    }
    if (forcedWord == "J2.4I")
    {
        return milstd6016::ProcessJ24IMessageBits(wordBits);
    }
    if (forcedWord == "J2.4E0")
    {
        return milstd6016::ProcessJ24E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.4C1")
    {
        return milstd6016::ProcessJ24C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.4C2")
    {
        return milstd6016::ProcessJ24C2MessageBits(wordBits);
    }
    if (forcedWord == "J2.4C3")
    {
        return milstd6016::ProcessJ24C3MessageBits(wordBits);
    }
    if (forcedWord == "J2.5I")
    {
        return milstd6016::ProcessJ25IMessageBits(wordBits);
    }
    if (forcedWord == "J2.5E0")
    {
        return milstd6016::ProcessJ25E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.5C1")
    {
        return milstd6016::ProcessJ25C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.5C3")
    {
        return milstd6016::ProcessJ25C3MessageBits(wordBits);
    }
    if (forcedWord == "J2.5C4")
    {
        return milstd6016::ProcessJ25C4MessageBits(wordBits);
    }
    if (forcedWord == "J2.6I")
    {
        return milstd6016::ProcessJ26IMessageBits(wordBits);
    }
    if (forcedWord == "J2.6E0")
    {
        return milstd6016::ProcessJ26E0MessageBits(wordBits);
    }
    if (forcedWord == "J2.6C1")
    {
        return milstd6016::ProcessJ26C1MessageBits(wordBits);
    }
    if (forcedWord == "J2.6C3")
    {
        return milstd6016::ProcessJ26C3MessageBits(wordBits);
    }
    if (forcedWord == "J0.4C1")
    {
        return milstd6016::ProcessJ04C1MessageBits(wordBits);
    }
    if (forcedWord == "J0.4C2")
    {
        return milstd6016::ProcessJ04C2MessageBits(wordBits);
    }
    if (forcedWord == "J0.6C1")
    {
        return milstd6016::ProcessJ06C1MessageBits(wordBits);
    }
    if (forcedWord == "J0.6C2")
    {
        return milstd6016::ProcessJ06C2MessageBits(wordBits);
    }
    if (forcedWord == "J1.1C1")
    {
        return milstd6016::ProcessJ11C1MessageBits(wordBits);
    }
    if (forcedWord == "J1.1C2")
    {
        return milstd6016::ProcessJ11C2MessageBits(wordBits);
    }

    std::string decoded;
    std::string selectedProcessor = DescribeJSeriesWordFromSubheader(wordFormat, label, sublabel);
    if (wordFormat == 0 && label == 0 && sublabel == 0)
    {
        decoded = milstd6016::ProcessJ00IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 1)
    {
        decoded = milstd6016::ProcessJ01IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 2)
    {
        decoded = milstd6016::ProcessJ02IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 3)
    {
        decoded = milstd6016::ProcessJ03IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 4)
    {
        decoded = milstd6016::ProcessJ04IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 5)
    {
        decoded = milstd6016::ProcessJ05IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 6)
    {
        decoded = milstd6016::ProcessJ06IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 0 && sublabel == 7)
    {
        decoded = milstd6016::ProcessJ07IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 0)
    {
        decoded = milstd6016::ProcessJ10IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 1)
    {
        decoded = milstd6016::ProcessJ11IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 2)
    {
        decoded = milstd6016::ProcessJ12IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 3)
    {
        decoded = milstd6016::ProcessJ13IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 4)
    {
        decoded = milstd6016::ProcessJ14IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 5)
    {
        decoded = milstd6016::ProcessJ15IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 1 && sublabel == 6)
    {
        decoded = milstd6016::ProcessJ16IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 0)
    {
        decoded = milstd6016::ProcessJ20IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 2)
    {
        decoded = milstd6016::ProcessJ22IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 3)
    {
        decoded = milstd6016::ProcessJ23IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 4)
    {
        decoded = milstd6016::ProcessJ24IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 5)
    {
        decoded = milstd6016::ProcessJ25IMessageBits(wordBits);
    }
    else if (wordFormat == 0 && label == 2 && sublabel == 6)
    {
        decoded = milstd6016::ProcessJ26IMessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 1)
    {
        const ContinuationWordChoice continuationWord = SelectContinuationWord(wordBits);
        if (continuationWord == ContinuationWordChoice::J20C3)
        {
            selectedProcessor = "J2.0C3";
            decoded = milstd6016::ProcessJ20C3MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J20C2)
        {
            selectedProcessor = "J2.0C2";
            decoded = milstd6016::ProcessJ20C2MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J20C1)
        {
            selectedProcessor = "J2.0C1";
            decoded = milstd6016::ProcessJ20C1MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J15C1)
        {
            selectedProcessor = "J1.5C1";
            decoded = milstd6016::ProcessJ15C1MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J22C1)
        {
            selectedProcessor = "J2.2C1";
            decoded = milstd6016::ProcessJ22C1MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J23C1)
        {
            selectedProcessor = "J2.3C1";
            decoded = milstd6016::ProcessJ23C1MessageBits(wordBits);
        }
        else if (continuationWord == ContinuationWordChoice::J25C1)
        {
            selectedProcessor = "J2.5C1";
            decoded = milstd6016::ProcessJ25C1MessageBits(wordBits);
        }
        else
        {
            selectedProcessor = "J0.0C1";
            decoded = milstd6016::ProcessJ00C1MessageBits(wordBits);
        }
    }
    else if (wordFormat == 1 && label == 2)
    {
        const Label2ContinuationWordChoice continuationWord = SelectLabel2ContinuationWord(wordBits);
        if (continuationWord == Label2ContinuationWordChoice::J22C2)
        {
            selectedProcessor = "J2.2C2";
            decoded = milstd6016::ProcessJ22C2MessageBits(wordBits);
        }
        else if (continuationWord == Label2ContinuationWordChoice::J23C2)
        {
            selectedProcessor = "J2.3C2";
            decoded = milstd6016::ProcessJ23C2MessageBits(wordBits);
        }
        else
        {
            selectedProcessor = "J0.3C2";
            decoded = milstd6016::ProcessJ03C2MessageBits(wordBits);
        }
    }
    else if (wordFormat == 1 && label == 3)
    {
        const Label3ContinuationWordChoice continuationWord = SelectLabel3ContinuationWord(wordBits);
        if (continuationWord == Label3ContinuationWordChoice::J22C3)
        {
            selectedProcessor = "J2.2C3";
            decoded = milstd6016::ProcessJ22C3MessageBits(wordBits);
        }
        else if (continuationWord == Label3ContinuationWordChoice::J23C3)
        {
            selectedProcessor = "J2.3C3";
            decoded = milstd6016::ProcessJ23C3MessageBits(wordBits);
        }
        else
        {
            selectedProcessor = "J0.6C3";
            decoded = milstd6016::ProcessJ06C3MessageBits(wordBits);
        }
    }
    else if (wordFormat == 1 && label == 5)
    {
        decoded = milstd6016::ProcessJ22C5MessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 4)
    {
        const Label4ContinuationWordChoice continuationWord = SelectLabel4ContinuationWord(wordBits);
        if (continuationWord == Label4ContinuationWordChoice::J25C4)
        {
            selectedProcessor = "J2.5C4";
            decoded = milstd6016::ProcessJ25C4MessageBits(wordBits);
        }
        else
        {
            selectedProcessor = "J0.6C4";
            decoded = milstd6016::ProcessJ06C4MessageBits(wordBits);
        }
    }
    else if (wordFormat == 1 && label == 21)
    {
        decoded = milstd6016::ProcessJ01C21MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 0)
    {
        decoded = milstd6016::ProcessJ10E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 1)
    {
        decoded = milstd6016::ProcessJ11E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 2)
    {
        decoded = milstd6016::ProcessJ12E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 3)
    {
        decoded = milstd6016::ProcessJ13E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 4)
    {
        decoded = milstd6016::ProcessJ14E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 5)
    {
        decoded = milstd6016::ProcessJ15E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 1 && sublabel == 6)
    {
        decoded = milstd6016::ProcessJ16E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 0)
    {
        decoded = milstd6016::ProcessJ20E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 2)
    {
        decoded = milstd6016::ProcessJ22E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 3)
    {
        decoded = milstd6016::ProcessJ23E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 4)
    {
        decoded = milstd6016::ProcessJ24E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 5)
    {
        decoded = milstd6016::ProcessJ25E0MessageBits(wordBits);
    }
    else if (wordFormat == 2 && label == 2 && sublabel == 6)
    {
        decoded = milstd6016::ProcessJ26E0MessageBits(wordBits);
    }
    else if (wordFormat == 2)
    {
        selectedProcessor = "J0.0E0";
        decoded = milstd6016::ProcessJ00E0MessageBits(wordBits);
    }
    else
    {
        selectedProcessor = "Unsupported";
        std::ostringstream output;
        output << "Unsupported MIL-STD-6016 word for messageInterpreterViewPanel decoder. "
               << "Detected WORD FORMAT=" << wordFormat
               << ", LABEL=" << label
               << ", SUBLABEL=" << sublabel << ".";
        decoded = output.str();
    }

    std::cerr << "[decode-route] wf=" << wordFormat
              << " label=" << label
              << " sublabel=" << sublabel
              << " selected=" << selectedProcessor
              << " mode=auto"
              << std::endl;

    if (sourceLabel.empty())
    {
        return decoded;
    }

    std::ostringstream prefixed;
    prefixed << "Source: " << sourceLabel;
    if (!jreapContext.empty())
    {
        prefixed << "\n" << jreapContext;
    }
    prefixed << "\n\n" << decoded;
    return prefixed.str();
}

}

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    std::string input = "";
    std::string output = "";
    InputMode inputMode = InputMode::Auto;
    InitWindow(1600, 900, "messageInterpreterViewPanel");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    int btnX, btnY, btnW, btnH;
    bool mouseOverBtn;
    float outputScrollOffset = 0.0f;
    int jSeriesScrollLines = 0;
    bool isDraggingScrollbar = false;
    float scrollbarDragOffset = 0.0f;
    int inputBoxX = 10, inputBoxY = 40, inputBoxW = 800, inputBoxH = 40;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Move input/output UI closer to the top
        DrawRectangle(inputBoxX, inputBoxY, inputBoxW, inputBoxH, (Color){30,30,30,255});
        DrawRectangleLines(inputBoxX, inputBoxY, inputBoxW, inputBoxH, YELLOW);
        DrawText("Paste MIL-STD-6016 bits, JREAP CSV, or type TEST J0.0I:", inputBoxX, inputBoxY - 30, 22, DARKGRAY);
        const int rightInfoX = inputBoxX + inputBoxW + 20;
        std::string modeText = std::string("Input Mode: ") + InputModeLabel(inputMode) + "  (F1 AUTO, F2 JREAP, F3 RAW-6016)";
        DrawText(modeText.c_str(), rightInfoX, inputBoxY - 30, 20, DARKGRAY);
        DrawText("Close with the window X or Alt+F4", rightInfoX, inputBoxY - 5, 18, DARKGRAY);
        DrawText("Press Enter or click Submit", rightInfoX, inputBoxY + 18, 18, DARKGRAY);
        DrawText(input.c_str(), inputBoxX + 10, inputBoxY + 10, 22, RAYWHITE);

        // Draw a submit button
        btnX = inputBoxX + inputBoxW + 20;
        btnY = inputBoxY + inputBoxH + 10;
        btnW = 120;
        btnH = inputBoxH;
        mouseOverBtn = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)btnX, (float)btnY, (float)btnW, (float)btnH});
        DrawRectangle(btnX, btnY, btnW, btnH, mouseOverBtn ? ORANGE : DARKGRAY);
        DrawRectangleLines(btnX, btnY, btnW, btnH, YELLOW);
        DrawText("Submit", btnX + 20, btnY + 10, 22, RAYWHITE);

        // Draw the output string below the input area in a scrollable panel
        int outputBoxX = 10;
        int outputBoxY = std::max(inputBoxY + inputBoxH, btnY + btnH) + 50;
        int outputBoxW = GetScreenWidth() - 20;
        int outputBoxH = GetScreenHeight() - outputBoxY - 10;
        DrawText("Header Translation:", outputBoxX, inputBoxY + inputBoxH + 20, 22, DARKGRAY);
        DrawRectangle(outputBoxX, outputBoxY, outputBoxW, outputBoxH, (Color){245, 245, 245, 255});
        DrawRectangleLines(outputBoxX, outputBoxY, outputBoxW, outputBoxH, LIGHTGRAY);

        std::vector<std::string> outputLines;
        bool renderedStructuredOutput = false;
        if (!output.empty())
        {
            size_t start = 0;
            while (start <= output.length())
            {
                size_t end = output.find('\n', start);
                if (end == std::string::npos)
                {
                    outputLines.push_back(output.substr(start));
                    break;
                }

                outputLines.push_back(output.substr(start, end - start));
                start = end + 1;

                if (start == output.length())
                {
                    outputLines.push_back("");
                    break;
                }
            }

            auto findLineIndex = [&](const std::string& key) -> int {
                for (size_t i = 0; i < outputLines.size(); ++i) {
                    if (outputLines[i].find(key) != std::string::npos) {
                        return static_cast<int>(i);
                    }
                }
                return -1;
            };

            const int ahIndex = findLineIndex("Application Header (AH.0)");
            const int fstbhIndex = findLineIndex("FSTBH.A.NC.0");
            const int fsmghIndex = findLineIndex("Full Stack Message Group Header (FSMGH.3)");
            const int abmlIndex = findLineIndex("ABML consistency");
            const int fsConsistencyIndex = findLineIndex("Full Stack consistency");
            const int dispatchIndex = findLineIndex("Dispatch by Message Type");

            int headerIndex = -1;
            if (ahIndex >= 0) headerIndex = ahIndex;
            else if (fstbhIndex >= 0) headerIndex = fstbhIndex;
            else headerIndex = fsmghIndex;
            const int validationIndex = (abmlIndex >= 0) ? abmlIndex : fsConsistencyIndex;

            const bool hasStructuredSections =
                (headerIndex >= 0) && (validationIndex > headerIndex) && (dispatchIndex > validationIndex);

            const int contentTop = inputBoxY + inputBoxH + 50;
            const int outputFontSize = 18;
            const int lineSpacing = 22;

            auto drawLines = [&](const std::vector<std::string>& source, int x, int y, Color color) -> int {
                int currentY = y;
                for (const std::string& line : source) {
                    if (!line.empty()) {
                        DrawText(line.c_str(), x, currentY, outputFontSize, color);
                    }
                    currentY += lineSpacing;
                }
                return currentY;
            };

            if (hasStructuredSections) {
                renderedStructuredOutput = true;
                std::vector<std::string> headerLines(outputLines.begin() + headerIndex, outputLines.begin() + validationIndex);
                std::vector<std::string> abmlLines(outputLines.begin() + validationIndex, outputLines.begin() + dispatchIndex);
                std::vector<std::string> jSeriesLines(outputLines.begin() + dispatchIndex, outputLines.end());

                const int sidePadding = 10;
                const int sectionGap = 40;
                const int availableWidth = GetScreenWidth() - (sidePadding * 2);
                const int columnWidth = (availableWidth - sectionGap) / 2;
                const int leftX = sidePadding;
                const int rightX = sidePadding + columnWidth + sectionGap;

                int leftBottom = drawLines(headerLines, leftX, contentTop, BLUE);
                int rightBottom = drawLines(abmlLines, rightX, contentTop, DARKBLUE);

                const int jSeriesTop = std::max(leftBottom, rightBottom) + 12;
                const int viewportBottom = GetScreenHeight() - 12;
                const int viewportHeight = std::max(0, viewportBottom - jSeriesTop);
                const int visibleLines = std::max(1, viewportHeight / lineSpacing);
                const int maxScrollLines = std::max(0, static_cast<int>(jSeriesLines.size()) - visibleLines);

                const float wheelMove = GetMouseWheelMove();
                if (wheelMove != 0.0f) {
                    jSeriesScrollLines -= static_cast<int>(wheelMove);
                    if (jSeriesScrollLines < 0) jSeriesScrollLines = 0;
                    if (jSeriesScrollLines > maxScrollLines) jSeriesScrollLines = maxScrollLines;
                }

                if (viewportHeight > 0) {
                    BeginScissorMode(leftX, jSeriesTop, availableWidth, viewportHeight);
                    int currentY = jSeriesTop;
                    for (int i = jSeriesScrollLines; i < static_cast<int>(jSeriesLines.size()); ++i) {
                        if (currentY > viewportBottom - lineSpacing) break;
                        if (!jSeriesLines[static_cast<size_t>(i)].empty()) {
                            DrawText(jSeriesLines[static_cast<size_t>(i)].c_str(), leftX, currentY, outputFontSize, MAROON);
                        }
                        currentY += lineSpacing;
                    }
                    EndScissorMode();

                    if (maxScrollLines > 0) {
                        DrawText("Mouse wheel: scroll J-Series details", leftX, viewportBottom - 18, 16, DARKGRAY);
                    }
                }
            } else {
                jSeriesScrollLines = 0;
            }
        }

        if (!renderedStructuredOutput)
        {
            const int lineSpacing = 30;
            const int outputPadding = 8;
            const int viewportHeight = outputBoxH - (2 * outputPadding);
            int totalContentHeight = static_cast<int>(outputLines.size()) * lineSpacing;
            float maxScroll = static_cast<float>(totalContentHeight - viewportHeight);
            if (maxScroll < 0.0f)
            {
                maxScroll = 0.0f;
            }

            const Vector2 mousePos = GetMousePosition();
            const bool mouseOverOutput = CheckCollisionPointRec(mousePos, (Rectangle){
                static_cast<float>(outputBoxX),
                static_cast<float>(outputBoxY),
                static_cast<float>(outputBoxW),
                static_cast<float>(outputBoxH)
            });

            const int scrollbarTrackWidth = 10;
            const int scrollbarMargin = 4;
            const int scrollbarX = outputBoxX + outputBoxW - scrollbarTrackWidth - scrollbarMargin;
            const int scrollbarY = outputBoxY + scrollbarMargin;
            const int scrollbarH = outputBoxH - (2 * scrollbarMargin);

            int thumbY = scrollbarY;
            int thumbHeight = scrollbarH;
            if (maxScroll > 0.0f)
            {
                const int minThumbHeight = 24;
                thumbHeight = static_cast<int>((static_cast<float>(viewportHeight) / static_cast<float>(totalContentHeight)) * static_cast<float>(scrollbarH));
                if (thumbHeight < minThumbHeight)
                {
                    thumbHeight = minThumbHeight;
                }
                if (thumbHeight > scrollbarH)
                {
                    thumbHeight = scrollbarH;
                }

                const float thumbTravel = static_cast<float>(scrollbarH - thumbHeight);
                if (thumbTravel > 0.0f)
                {
                    thumbY = scrollbarY + static_cast<int>((outputScrollOffset / maxScroll) * thumbTravel);
                }
            }

            const Rectangle scrollbarTrack = {
                static_cast<float>(scrollbarX),
                static_cast<float>(scrollbarY),
                static_cast<float>(scrollbarTrackWidth),
                static_cast<float>(scrollbarH)
            };
            const Rectangle scrollbarThumb = {
                static_cast<float>(scrollbarX),
                static_cast<float>(thumbY),
                static_cast<float>(scrollbarTrackWidth),
                static_cast<float>(thumbHeight)
            };
            const bool mouseOverScrollbar = CheckCollisionPointRec(mousePos, scrollbarTrack);

            if (mouseOverOutput || mouseOverScrollbar)
            {
                outputScrollOffset -= GetMouseWheelMove() * static_cast<float>(lineSpacing);
                if (IsKeyPressed(KEY_PAGE_DOWN)) outputScrollOffset += static_cast<float>(viewportHeight);
                if (IsKeyPressed(KEY_PAGE_UP)) outputScrollOffset -= static_cast<float>(viewportHeight);
                if (IsKeyPressed(KEY_HOME)) outputScrollOffset = 0.0f;
                if (IsKeyPressed(KEY_END)) outputScrollOffset = maxScroll;
                if (IsKeyPressed(KEY_DOWN)) outputScrollOffset += static_cast<float>(lineSpacing);
                if (IsKeyPressed(KEY_UP)) outputScrollOffset -= static_cast<float>(lineSpacing);
            }

            if (maxScroll > 0.0f)
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePos, scrollbarThumb))
                {
                    isDraggingScrollbar = true;
                    scrollbarDragOffset = mousePos.y - static_cast<float>(thumbY);
                }

                if (isDraggingScrollbar)
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    {
                        const float maxThumbTop = static_cast<float>(scrollbarY + scrollbarH - thumbHeight);
                        float desiredThumbTop = mousePos.y - scrollbarDragOffset;
                        if (desiredThumbTop < static_cast<float>(scrollbarY)) desiredThumbTop = static_cast<float>(scrollbarY);
                        if (desiredThumbTop > maxThumbTop) desiredThumbTop = maxThumbTop;

                        const float thumbTravel = static_cast<float>(scrollbarH - thumbHeight);
                        if (thumbTravel > 0.0f)
                        {
                            const float normalized = (desiredThumbTop - static_cast<float>(scrollbarY)) / thumbTravel;
                            outputScrollOffset = normalized * maxScroll;
                        }
                    }
                    else
                    {
                        isDraggingScrollbar = false;
                    }
                }
            }
            else
            {
                isDraggingScrollbar = false;
            }

            if (outputScrollOffset < 0.0f)
            {
                outputScrollOffset = 0.0f;
            }
            if (outputScrollOffset > maxScroll)
            {
                outputScrollOffset = maxScroll;
            }

            if (!output.empty())
            {
                BeginScissorMode(outputBoxX + 1, outputBoxY + 1, outputBoxW - 2, outputBoxH - 2);
                int y = outputBoxY + outputPadding - static_cast<int>(outputScrollOffset);
                for (std::size_t index = 0; index < outputLines.size(); ++index)
                {
                    DrawText(outputLines[index].c_str(), outputBoxX + outputPadding, y, 22, BLUE);
                    y += lineSpacing;
                }
                EndScissorMode();
            }
            else
            {
                DrawText("No output yet. Submit a message to decode.", outputBoxX + outputPadding, outputBoxY + outputPadding, 20, GRAY);
            }

            DrawRectangle(scrollbarX, scrollbarY, scrollbarTrackWidth, scrollbarH, (Color){225, 225, 225, 255});

            if (maxScroll > 0.0f)
            {
                DrawRectangle(scrollbarX, thumbY, scrollbarTrackWidth, thumbHeight, (Color){140, 140, 140, 255});
            }
            else
            {
                DrawRectangle(scrollbarX, scrollbarY, scrollbarTrackWidth, scrollbarH, (Color){190, 190, 190, 255});
            }

            DrawText("Mouse wheel to scroll output", outputBoxX + outputBoxW - 280, outputBoxY - 28, 18, DARKGRAY);
        }

        int key = GetCharPressed();
        // Allow large pasted samples
        if ((key >= 32 && key <= 125) && input.length() < 12000)
        {
            input += (char)key;
        }
        if (IsKeyPressed(KEY_BACKSPACE) && !input.empty())
        {
            input.pop_back();
        }
        // Clipboard paste (Ctrl+V)
        if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsKeyPressed(KEY_V)) {
            const char* clip = GetClipboardText();
            if (clip) {
                input += clip;
                if (input.length() > 12000) input = input.substr(0, 12000);
            }
        }

        if (IsKeyPressed(KEY_F1))
        {
            inputMode = InputMode::Auto;
        }
        if (IsKeyPressed(KEY_F2))
        {
            inputMode = InputMode::Jreap;
        }
        if (IsKeyPressed(KEY_F3))
        {
            inputMode = InputMode::Raw6016;
        }

        // Handle submit button click

        
        // Handle submit button click
        bool submitted = false;
        if (mouseOverBtn && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            submitted = true;
        }
        // Also allow Enter key
        if (IsKeyPressed(KEY_ENTER)) {
            submitted = true;
        }
        if (submitted) {
            output = DecodeMilStd6016Word(input, inputMode);
            if (Trim(output).empty())
            {
                output = "Decoder returned no text for this input.";
            }
            outputScrollOffset = 0.0f;


            input.clear(); // clear input only once after submit
        }
        EndDrawing();
    }
}

            