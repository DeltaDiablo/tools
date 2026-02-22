#include <iostream>
#include <array>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "milstd3011/dfiset3008.h"
#include "milstd3011/dfiset3007.h"
#include "milstd3011/dfiset3006.h"
#include "milstd3011/dfiset3001.h"
#include "milstd3011/dfiset3002.h"
#include "milstd3011/dfiset3003.h"
#include "milstd3011/dfiset3012.h"
#include "milstd3011/dfiset3014.h"
#include "milstd3011/dfiset3015.h"
#include "milstd3011/dfiset3016.h"
#include "milstd3011/dfiset3017.h"
#include "milstd3011/dfiset3020.h"
#include "milstd3011/dfiset3021.h"
#include "milstd3011/dfiset3025.h"
#include "milstd3011/dfiset3027.h"
#include "milstd3011/dfiset3028.h"
#include "milstd3011/dfiset3029.h"
#include "milstd3011/dfiset3030.h"
#include "milstd3011/dfiset3032.h"
#include "milstd3011/dfiset3033.h"
#include "milstd3011/dfiset3034.h"
#include "milstd3011/dfiset3035.h"
#include "milstd3011/dfiset3036.h"
#include "milstd3011/dfiset3039.h"
#include "milstd3011/dfiset3040.h"
#include "milstd3011/dfiset3045.h"
#include "milstd3011/dfiset3044.h"
#include "milstd3011/jreap_field_refs.h"

namespace {
using jreap_field_refs::FieldMeta;
using namespace jreap_field_refs;

inline void AppendField(std::ostringstream& out, const FieldMeta& field, const std::string& value)
{
	out << field.label << ": " << value << "\n";
}

template <std::size_t N>
std::array<int, N> SliceBits(const std::array<int, 80>& bits, std::size_t start)
{
	std::array<int, N> out{};
	for (std::size_t i = 0; i < N; ++i)
	{
		out[i] = bits[start + i];
	}
	return out;
}

template <std::size_t N>
int BitsToUInt(const std::array<int, N>& bits)
{
	int value = 0;
	for (std::size_t i = 0; i < N; ++i)
	{
		value = (value << 1) | bits[i];
	}
	return value;
}

template <std::size_t N>
std::string BitsToBinaryString(const std::array<int, N>& bits)
{
	std::string binary;
	binary.reserve(N);
	for (std::size_t i = 0; i < N; ++i)
	{
		binary.push_back(bits[i] ? '1' : '0');
	}
	return binary;
}

}
/* the header type is a 4 bit unsigned integer identifying the type of JREAP message
 * 0 Undefined
 * 1 ATP JREAP-A
 * 2 PTP JREAP-B
 * 3 Application JREAP-C
 */
std::string HeaderType(const std::array<int, 4>& headerType)
{
	const int headerTypeInt = BitsToUInt(headerType);
	std::string output = "";
	switch (headerTypeInt)
	{
	case 0:
		output = "Undefined";
		break;
	case 1:
		output = "ATP JREAP-A";
		break;
	case 2:
		output = "PTP JREAP-B";
		break;
	case 3:
		output = "Application JREAP-C";
		break;
	default:
		output = "Undefined";
		break;
	}

	output = output + " ///-> " + BitsToBinaryString(headerType);

	return output;
}

/* the message type is a 4 bit unsigned integer identifying the type of message format
 * 0 Management
 * 1 JREAP J-Series
 * 2 JTIDS FREE TEXT (CODED)
 * 3 JTIDS FREE TEXT (UNCODED)
 * 4 Variable Message Format
 * 5 LINK 22
 * 6 Common Message Format IBS
 * 15 Reserved
 */
std::string MessageType(const std::array<int, 4>& messageType)
{
	const int messageTypeInt = BitsToUInt(messageType);
	std::string output = "";
	switch (messageTypeInt)
	{
	case 0:
		output = "Management";
		break;
	case 1:
		output = "X1.0 (JREAP J-Series)";
		break;
	case 2:
		output = "JTIDS FREE TEXT (CODED)";
		break;
	case 3:
		output = "JTIDS FREE TEXT (UNCODED)";
		break;
	case 4:
		output = "Variable Message Format";
		break;
	case 5:
		output = "LINK 22";
		break;
	case 6:
		output = "Common Message Format IBS";
		break;
	case 7:
		output = "X7.0 (NPG Assignment)";
		break;
	case 15:
		output = "Reserved";
		break;
	default:
		output = "Undefined";
		break;
	}

	output = output + " ///-> " + BitsToBinaryString(messageType);
	return output;
}

/* The TransmissionTimeReferenceFlag is a boolean
 * 0 means this track does not correspond to the time of transmission
 * 1 means it does correspond to the time of transmission
 */
std::string TransmissionTimeReferenceFlag(const std::array<int, 1>& transmissionTimeReferenceFlag)
{
	if (transmissionTimeReferenceFlag[0] == 1)
	{
		return "Corresponds to time of transmission ///-> 1";
	}
	else
	{
		return "Does not correspond to time of transmission ///-> 0";
	}
}

std::string Spare(const std::array<int, 3>& spare)
{
	std::string output = std::to_string(BitsToUInt(spare));
	output = output + " ///-> " + BitsToBinaryString(spare);
	return output;
}

/* the Application Protocol Version is a 4 bit unsigned integer
 * 0 is illegal
 * the higher the number the higher the version
 */
std::string ApplicationProtocolVersion(const std::array<int, 4>& applicationProtocolVersion)
{
	const int applicationProtocolVersionInt = BitsToUInt(applicationProtocolVersion);
	std::string output = "";
	if (applicationProtocolVersionInt > 0)
	{
		output = std::to_string(applicationProtocolVersionInt);
	}
	else
	{
		output = "Illegal";
	}

	output = output + " ///-> " + BitsToBinaryString(applicationProtocolVersion);
	return output;
}

/* Application Block Message Length is a 16 bit unsigned integer
 * ==========================================================
 * 16 bit unsigned integer
 * 0 to 65535
 * ==========================================================
 */
std::string ApplicationBlockMessageLength(const std::array<int, 16>& applicationBlockMessageLength)
{
	const int applicationBlockMessageLengthInt = BitsToUInt(applicationBlockMessageLength);
	std::string output = std::to_string(applicationBlockMessageLengthInt) + " ///-> " + BitsToBinaryString(applicationBlockMessageLength);
	return output;
}

/* JRE Sender ID is a 16 bit unsigned octal integer
 * ==========================================================
 * 16 bit unsigned integer
 * 0 to 177777 octal
 * ==========================================================
 */
std::string JreSenderID(const std::array<int, 16>& jreSenderID)
{
	int jreSenderIDInt = BitsToUInt(jreSenderID);
	// convert the int to octal
	int octal = 0;
	int i = 1;
	while (jreSenderIDInt != 0)
	{
		octal += (jreSenderIDInt % 8) * i;
		jreSenderIDInt /= 8;
		i *= 10;
	}

	std::string output = std::to_string(octal) + " ///-> " + BitsToBinaryString(jreSenderID);
	return output;
}

/* Time Accuracy is a 4 bit unsigned integer
 * the higher the number the lower the accuracy
 */
std::string TimeAccuracyReporting(const std::array<int, 4>& timeAccuracy)
{
	std::string output = std::to_string(BitsToUInt(timeAccuracy)) + " ///-> " + BitsToBinaryString(timeAccuracy);

	return output;
}

/* Data valid time is an unsigned 28 bit integer
 * this is the time in seconds since 00:00:00 UTC
 */
std::string DataValidTime(const std::array<int, 28>& dataValidTime)
{
	const int dataValidTimeInt = BitsToUInt(dataValidTime);
	std::string output = std::to_string(dataValidTimeInt) + " ///-> " + BitsToBinaryString(dataValidTime);
	return output;
}

namespace jreap_internal {

std::string ProcessJreapApplicationMessage(const std::array<int, 512>& byteArray, std::size_t byteCount, bool strictAbml)
{
	if (byteCount < 9)
	{
		return "Invalid input: need at least 9 bytes for FSMGH.3 or 10 bytes for AH.0.";
	}

	if (byteCount < 10)
	{
		return "Invalid input: need at least 10 bytes for AH.0 decode.";
	}

	std::array<int, 10> ahBytes{};
	for (std::size_t i = 0; i < 10; ++i)
	{
		ahBytes[i] = byteArray[i] & 0xFF;
	}

	std::array<int, 80> bits{};
	for (std::size_t i = 0; i < 10; ++i)
	{
		for (std::size_t j = 0; j < 8; ++j)
		{
			bits[(i * 8) + j] = (ahBytes[i] >> (7 - j)) & 0x01;
		}
	}

	auto headerTypeBits = SliceBits<4>(bits, 0);
	auto messageTypeBits = SliceBits<4>(bits, 4);
	auto transmissionTimeFlagBits = SliceBits<1>(bits, 8);
	auto spareBits = SliceBits<3>(bits, 9);
	auto appProtocolVersionBits = SliceBits<4>(bits, 12);
	auto appBlockMessageLengthBits = SliceBits<16>(bits, 16);
	auto jreSenderIdBits = SliceBits<16>(bits, 32);
	auto timeAccuracyBits = SliceBits<4>(bits, 48);
	auto dataValidTimeBits = SliceBits<28>(bits, 52);

	const int headerTypeValue = BitsToUInt(headerTypeBits);
	const int messageTypeValue = BitsToUInt(messageTypeBits);
	const int appBlockMessageLengthValue = BitsToUInt(appBlockMessageLengthBits);
	const bool forceAhForX7 = (headerTypeValue == 3) && (messageTypeValue == 7);
	const bool looksLikeAh0 =
		((headerTypeValue == 3) &&
		 (appBlockMessageLengthValue >= 10) &&
		 (appBlockMessageLengthValue <= static_cast<int>(byteCount + 4))) ||
		forceAhForX7;

	if (!looksLikeAh0)
	{
		return "Input did not match AH.0 framing. Full-stack X1.1 decode is temporarily disabled.";
	}

	std::ostringstream out;
	out << kSectionApplicationHeader << "\n";
	AppendField(out, kAh0HeaderType, HeaderType(headerTypeBits));
	AppendField(out, kAh0MessageType, MessageType(messageTypeBits));
	AppendField(out, kAh0TransmissionTimeRef, TransmissionTimeReferenceFlag(transmissionTimeFlagBits));
	AppendField(out, kAh0Spare, Spare(spareBits));
	AppendField(out, kAh0ProtocolVersion, ApplicationProtocolVersion(appProtocolVersionBits));
	AppendField(out, kAh0Abml, ApplicationBlockMessageLength(appBlockMessageLengthBits));
	AppendField(out, kAh0SenderId, JreSenderID(jreSenderIdBits));
	AppendField(out, kAh0TimeAccuracy, TimeAccuracyReporting(timeAccuracyBits));
	AppendField(out, kAh0DataValidTime, DataValidTime(dataValidTimeBits));

	if (headerTypeValue != 3)
	{
		out << kDispatchNotApplicationHeader;
		return out.str();
	}

	constexpr std::size_t ah0HeaderBytes = 10;
	const std::size_t receivedTotalBytes = byteCount;
	const std::size_t receivedPayloadBytes = (byteCount > ah0HeaderBytes) ? (byteCount - ah0HeaderBytes) : 0;

	const std::size_t declaredAbmlBytes = static_cast<std::size_t>(appBlockMessageLengthValue);
	const std::size_t declaredPayloadBytes = (declaredAbmlBytes > ah0HeaderBytes) ? (declaredAbmlBytes - ah0HeaderBytes) : 0;
	const std::size_t effectivePayloadBytes = std::min(receivedPayloadBytes, declaredPayloadBytes);
	const bool abmlMismatch = (receivedTotalBytes != declaredAbmlBytes);

	out << "\n" << kSectionAbmlConsistency << "\n";
	out << kAbmlDeclaredBytesLabel << ": " << declaredAbmlBytes << "\n";
	out << kAbmlReceivedPayloadBytesLabel << ": " << receivedTotalBytes << "\n";
	if (receivedTotalBytes < declaredAbmlBytes)
	{
		out << kAbmlStatusTruncatedPrefix << (declaredAbmlBytes - receivedTotalBytes) << " byte(s).\n";
	}
	else if (receivedTotalBytes > declaredAbmlBytes)
	{
		out << kAbmlStatusTrailingPrefix << (receivedTotalBytes - declaredAbmlBytes) << " byte(s).\n";
	}
	else
	{
		out << kAbmlStatusMatch << "\n";
	}
	out << kAbmlModeLabel << ": " << (strictAbml ? "strict" : "lenient") << " ABML validation.\n";

	if (strictAbml && abmlMismatch)
	{
		out << "\n" << kSectionDispatchByMessageType << "\n";
		out << kDispatchStrictAbmlMismatch;
		out << "\n" << kAbmlPayloadBytesUsedLabel << ": 0";
		out << "\n" << kAbmlFieldValueLabel << ": " << appBlockMessageLengthValue;
		return out.str();
	}

	out << "\n" << kSectionDispatchByMessageType << "\n";
	switch (messageTypeValue)
	{
	case 0:
	{
		out << kDispatchManagementDetected;
		if (effectivePayloadBytes >= 1)
		{
			auto subtypeBits = SliceBits<8>(bits, 0);
			for (std::size_t i = 0; i < 8; ++i)
			{
				subtypeBits[i] = (byteArray[10] >> (7 - i)) & 0x01;
			}
			out << "\n" << kDispatchManagementSubtypeLabel << ": " << dfi3008::Dui002(subtypeBits);
		}
		else
		{
			out << "\n" << kDispatchNoManagementSubtype;
		}
		break;
	}
	case 1:
	{
		out << kDispatchX10Detected;
		std::size_t payloadBits = effectivePayloadBytes * 8;
		constexpr std::size_t x1SectionBits = 136;
		const std::size_t sectionCount = payloadBits / x1SectionBits;
		const std::size_t trailingBits = payloadBits % x1SectionBits;

		if (sectionCount == 0)
		{
			out << "\n" << kDispatchX100Decode;
			out << "\nNo complete X1.0 section available (need 136 bits, received " << payloadBits << ").";
			break;
		}

		auto getPayloadBit = [&](std::size_t payloadBitIndex) -> int
		{
			std::size_t sourceByte = 10 + (payloadBitIndex / 8);
			std::size_t bitInByte = payloadBitIndex % 8;
			return (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
		};

		auto readBits = [&](auto& target, std::size_t startBit)
		{
			for (std::size_t i = 0; i < target.size(); ++i)
			{
				target[i] = getPayloadBit(startBit + i);
			}
		};

		for (std::size_t sectionIndex = 0; sectionIndex < sectionCount; ++sectionIndex)
		{
			const std::size_t baseBit = sectionIndex * x1SectionBits;

			std::array<int, 16> jreSourceTrackNumber{};
			std::array<int, 16> jSeriesMessageSequenceNumber{};
			std::array<int, 1> relayFlag{};
			std::array<int, 1> acknowledgementRequestFlag{};
			std::array<int, 1> x1SpareBit{};
			std::array<int, 13> dataAge{};
			std::array<int, 4> x1SpareNibble{};
			std::array<int, 12> numberOfJWords{};
			std::array<int, 16> jSeriesWord1{};
			std::array<int, 16> jSeriesWord2{};
			std::array<int, 16> jSeriesWord3{};
			std::array<int, 16> jSeriesWord4{};
			std::array<int, 2> x1Spare2Bits{};
			std::array<int, 6> jSeriesWord5{};

			readBits(jreSourceTrackNumber, baseBit + 0);
			readBits(jSeriesMessageSequenceNumber, baseBit + 16);
			readBits(relayFlag, baseBit + 32);
			readBits(acknowledgementRequestFlag, baseBit + 33);
			readBits(x1SpareBit, baseBit + 34);
			readBits(dataAge, baseBit + 35);
			readBits(x1SpareNibble, baseBit + 48);
			readBits(numberOfJWords, baseBit + 52);
			readBits(jSeriesWord1, baseBit + 64);
			readBits(jSeriesWord2, baseBit + 80);
			readBits(jSeriesWord3, baseBit + 96);
			readBits(jSeriesWord4, baseBit + 112);
			readBits(x1Spare2Bits, baseBit + 128);
			readBits(jSeriesWord5, baseBit + 130);

			out << "\n\n" << kDispatchJstnSectionPrefix << (sectionIndex + 1);
			out << "\n" << kX10Jstn.label << ": " << dfi3027::Dui003(jreSourceTrackNumber);
			out << "\n" << kX10Sequence.label << ": " << dfi3032::Dui003(jSeriesMessageSequenceNumber);
			out << "\n" << kX10Relay.label << ": " << dfi3002::Dui009(relayFlag);
			out << "\n" << kX10AckReq.label << ": " << dfi3002::Dui003(acknowledgementRequestFlag);
			out << "\n" << kX10Spare1.label << ": " << BitsToUInt(x1SpareBit);
			out << "\n" << kX10DataAge.label << ": " << dfi3003::Dui003(dataAge);
			out << "\n" << kX10Spare4.label << ": " << BitsToUInt(x1SpareNibble);
			out << "\n" << kX10JWords.label << ": " << dfi3033::Dui005(numberOfJWords);
			out << "\n" << kX10Word1.label << ": " << dfi3028::Dui001(jSeriesWord1);
			out << "\n" << kX10Word2.label << ": " << dfi3028::Dui002(jSeriesWord2);
			out << "\n" << kX10Word3.label << ": " << dfi3028::Dui003(jSeriesWord3);
			out << "\n" << kX10Word4.label << ": " << dfi3028::Dui004(jSeriesWord4);
			out << "\n" << kX10Spare2.label << ": " << BitsToUInt(x1Spare2Bits);
			out << "\n" << kX10Word5.label << ": " << dfi3028::Dui005(jSeriesWord5);
		}

		if (trailingBits > 0)
		{
			out << "\n\n" << kDispatchX10TrailingBitsPrefix << trailingBits;
		}

		break;
	}
	case 2:
	{
		out << kDispatchTextCoded;
		const std::size_t payloadBits = effectivePayloadBytes * 8;
		constexpr std::size_t x20Bits = 264;
		const std::size_t sectionCount = payloadBits / x20Bits;
		const std::size_t trailingBits = payloadBits % x20Bits;

		if (sectionCount == 0)
		{
			out << "\n" << kDispatchX200Decode;
			out << "\nNo complete X2.0 block available (need 264 bits, received " << payloadBits << ").";
			break;
		}

		auto getPayloadBit = [&](std::size_t payloadBitIndex) -> int
		{
			std::size_t sourceByte = 10 + (payloadBitIndex / 8);
			std::size_t bitInByte = payloadBitIndex % 8;
			return (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
		};

		auto readBits = [&](auto& target, std::size_t startBit)
		{
			for (std::size_t i = 0; i < target.size(); ++i)
			{
				target[i] = getPayloadBit(startBit + i);
			}
		};

		for (std::size_t sectionIndex = 0; sectionIndex < sectionCount; ++sectionIndex)
		{
			const std::size_t baseBit = sectionIndex * x20Bits;

			std::array<int, 16> jreSourceTrackNumber{};
			std::array<int, 9> participationGroup{};
			std::array<int, 7> numberOfBlocks{};
			std::array<int, 16> freeText1{};
			std::array<int, 16> freeText2{};
			std::array<int, 16> freeText3{};
			std::array<int, 16> freeText4{};
			std::array<int, 16> freeText5{};
			std::array<int, 16> freeText6{};
			std::array<int, 16> freeText7{};
			std::array<int, 16> freeText8{};
			std::array<int, 16> freeText9{};
			std::array<int, 16> freeText10{};
			std::array<int, 16> freeText11{};
			std::array<int, 16> freeText12{};
			std::array<int, 16> freeText13{};
			std::array<int, 16> freeText14{};
			std::array<int, 7> spare7{};
			std::array<int, 1> freeText16Bit{};

			readBits(jreSourceTrackNumber, baseBit + 0);
			readBits(participationGroup, baseBit + 16);
			readBits(numberOfBlocks, baseBit + 25);
			readBits(freeText1, baseBit + 32);
			readBits(freeText2, baseBit + 48);
			readBits(freeText3, baseBit + 64);
			readBits(freeText4, baseBit + 80);
			readBits(freeText5, baseBit + 96);
			readBits(freeText6, baseBit + 112);
			readBits(freeText7, baseBit + 128);
			readBits(freeText8, baseBit + 144);
			readBits(freeText9, baseBit + 160);
			readBits(freeText10, baseBit + 176);
			readBits(freeText11, baseBit + 192);
			readBits(freeText12, baseBit + 208);
			readBits(freeText13, baseBit + 224);
			readBits(freeText14, baseBit + 240);
			readBits(spare7, baseBit + 256);
			readBits(freeText16Bit, baseBit + 263);

			out << "\n\n" << kDispatchX20SectionPrefix << (sectionIndex + 1);
			out << "\n" << kX20Jstn.label << ": " << dfi3027::Dui003(jreSourceTrackNumber);
			out << "\n" << kX20Npg.label << ": " << dfi3040::Dui001(participationGroup);
			out << "\n" << kX20Blocks.label << ": " << dfi3033::Dui004(numberOfBlocks);
			out << "\nJREAP/JTIDS Free Text, 1: " << dfi3030::Dui001(freeText1);
			out << "\nJREAP/JTIDS Free Text, 2: " << dfi3030::Dui002(freeText2);
			out << "\nJREAP/JTIDS Free Text, 3: " << dfi3030::Dui003(freeText3);
			out << "\nJREAP/JTIDS Free Text, 4: " << dfi3030::Dui004(freeText4);
			out << "\nJREAP/JTIDS Free Text, 5: " << dfi3030::Dui005(freeText5);
			out << "\nJREAP/JTIDS Free Text, 6: " << dfi3030::Dui006(freeText6);
			out << "\nJREAP/JTIDS Free Text, 7: " << dfi3030::Dui007(freeText7);
			out << "\nJREAP/JTIDS Free Text, 8: " << dfi3030::Dui008(freeText8);
			out << "\nJREAP/JTIDS Free Text, 9: " << dfi3030::Dui009(freeText9);
			out << "\nJREAP/JTIDS Free Text, 10: " << dfi3030::Dui010(freeText10);
			out << "\nJREAP/JTIDS Free Text, 11: " << dfi3030::Dui011(freeText11);
			out << "\nJREAP/JTIDS Free Text, 12: " << dfi3030::Dui012(freeText12);
			out << "\nJREAP/JTIDS Free Text, 13: " << dfi3030::Dui013(freeText13);
			out << "\nJREAP/JTIDS Free Text, 14: " << dfi3030::Dui014(freeText14);
			out << "\nSpare (7 bits): " << BitsToUInt(spare7) << " ///-> " << BitsToBinaryString(spare7);
			out << "\nJREAP/JTIDS Free Text, 16 (1 bit): " << BitsToUInt(freeText16Bit) << " ///-> " << BitsToBinaryString(freeText16Bit);
		}

		if (trailingBits > 0)
		{
			out << "\n\n" << kDispatchX20TrailingBitsPrefix << trailingBits;
		}
		break;
	}
		break;
	case 3:
	{
		out << kDispatchTextUncoded;
		const std::size_t payloadBits = effectivePayloadBytes * 8;
		constexpr std::size_t x30Bits = 512;
		const std::size_t sectionCount = payloadBits / x30Bits;
		const std::size_t trailingBits = payloadBits % x30Bits;

		if (sectionCount == 0)
		{
			out << "\n" << kDispatchX300Decode;
			out << "\nNo complete X3.0 block available (need 512 bits, received " << payloadBits << ").";
			break;
		}

		auto getPayloadBit = [&](std::size_t payloadBitIndex) -> int
		{
			std::size_t sourceByte = 10 + (payloadBitIndex / 8);
			std::size_t bitInByte = payloadBitIndex % 8;
			return (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
		};

		auto readBits = [&](auto& target, std::size_t startBit)
		{
			for (std::size_t i = 0; i < target.size(); ++i)
			{
				target[i] = getPayloadBit(startBit + i);
			}
		};

		for (std::size_t sectionIndex = 0; sectionIndex < sectionCount; ++sectionIndex)
		{
			const std::size_t baseBit = sectionIndex * x30Bits;

			std::array<int, 16> jreSourceTrackNumber{};
			std::array<int, 9> participationGroup{};
			std::array<int, 7> numberOfBlocks{};
			std::array<int, 16> freeText1{};
			std::array<int, 16> freeText2{};
			std::array<int, 16> freeText3{};
			std::array<int, 16> freeText4{};
			std::array<int, 16> freeText5{};
			std::array<int, 16> freeText6{};
			std::array<int, 16> freeText7{};
			std::array<int, 16> freeText8{};
			std::array<int, 16> freeText9{};
			std::array<int, 16> freeText10{};
			std::array<int, 16> freeText11{};
			std::array<int, 16> freeText12{};
			std::array<int, 16> freeText13{};
			std::array<int, 16> freeText14{};
			std::array<int, 16> freeText15{};
			std::array<int, 16> freeText16{};
			std::array<int, 16> freeText17{};
			std::array<int, 16> freeText18{};
			std::array<int, 16> freeText19{};
			std::array<int, 16> freeText20{};
			std::array<int, 16> freeText21{};
			std::array<int, 16> freeText22{};
			std::array<int, 16> freeText23{};
			std::array<int, 16> freeText24{};
			std::array<int, 16> freeText25{};
			std::array<int, 16> freeText26{};
			std::array<int, 16> freeText27{};
			std::array<int, 16> freeText28{};
			std::array<int, 16> freeText29{};
			std::array<int, 16> freeText30{};

			readBits(jreSourceTrackNumber, baseBit + 0);
			readBits(participationGroup, baseBit + 16);
			readBits(numberOfBlocks, baseBit + 25);
			readBits(freeText1, baseBit + 32);
			readBits(freeText2, baseBit + 48);
			readBits(freeText3, baseBit + 64);
			readBits(freeText4, baseBit + 80);
			readBits(freeText5, baseBit + 96);
			readBits(freeText6, baseBit + 112);
			readBits(freeText7, baseBit + 128);
			readBits(freeText8, baseBit + 144);
			readBits(freeText9, baseBit + 160);
			readBits(freeText10, baseBit + 176);
			readBits(freeText11, baseBit + 192);
			readBits(freeText12, baseBit + 208);
			readBits(freeText13, baseBit + 224);
			readBits(freeText14, baseBit + 240);
			readBits(freeText15, baseBit + 256);
			readBits(freeText16, baseBit + 272);
			readBits(freeText17, baseBit + 288);
			readBits(freeText18, baseBit + 304);
			readBits(freeText19, baseBit + 320);
			readBits(freeText20, baseBit + 336);
			readBits(freeText21, baseBit + 352);
			readBits(freeText22, baseBit + 368);
			readBits(freeText23, baseBit + 384);
			readBits(freeText24, baseBit + 400);
			readBits(freeText25, baseBit + 416);
			readBits(freeText26, baseBit + 432);
			readBits(freeText27, baseBit + 448);
			readBits(freeText28, baseBit + 464);
			readBits(freeText29, baseBit + 480);
			readBits(freeText30, baseBit + 496);

			out << "\n\n" << kDispatchX30SectionPrefix << (sectionIndex + 1);
			out << "\n" << kX20Jstn.label << ": " << dfi3027::Dui003(jreSourceTrackNumber);
			out << "\n" << kX20Npg.label << ": " << dfi3040::Dui001(participationGroup);
			out << "\n" << kX20Blocks.label << ": " << dfi3033::Dui004(numberOfBlocks);
			out << "\nJREAP/JTIDS Free Text, 1: " << dfi3030::Dui001(freeText1);
			out << "\nJREAP/JTIDS Free Text, 2: " << dfi3030::Dui002(freeText2);
			out << "\nJREAP/JTIDS Free Text, 3: " << dfi3030::Dui003(freeText3);
			out << "\nJREAP/JTIDS Free Text, 4: " << dfi3030::Dui004(freeText4);
			out << "\nJREAP/JTIDS Free Text, 5: " << dfi3030::Dui005(freeText5);
			out << "\nJREAP/JTIDS Free Text, 6: " << dfi3030::Dui006(freeText6);
			out << "\nJREAP/JTIDS Free Text, 7: " << dfi3030::Dui007(freeText7);
			out << "\nJREAP/JTIDS Free Text, 8: " << dfi3030::Dui008(freeText8);
			out << "\nJREAP/JTIDS Free Text, 9: " << dfi3030::Dui009(freeText9);
			out << "\nJREAP/JTIDS Free Text, 10: " << dfi3030::Dui010(freeText10);
			out << "\nJREAP/JTIDS Free Text, 11: " << dfi3030::Dui011(freeText11);
			out << "\nJREAP/JTIDS Free Text, 12: " << dfi3030::Dui012(freeText12);
			out << "\nJREAP/JTIDS Free Text, 13: " << dfi3030::Dui013(freeText13);
			out << "\nJREAP/JTIDS Free Text, 14: " << dfi3030::Dui014(freeText14);
			out << "\nJREAP/JTIDS Free Text, 15: " << dfi3030::Dui015(freeText15);
			out << "\nJREAP/JTIDS Free Text, 16: " << dfi3030::Dui016(freeText16);
			out << "\nJREAP/JTIDS Free Text, 17: " << dfi3030::Dui017(freeText17);
			out << "\nJREAP/JTIDS Free Text, 18: " << dfi3030::Dui018(freeText18);
			out << "\nJREAP/JTIDS Free Text, 19: " << dfi3030::Dui019(freeText19);
			out << "\nJREAP/JTIDS Free Text, 20: " << dfi3030::Dui020(freeText20);
			out << "\nJREAP/JTIDS Free Text, 21: " << dfi3030::Dui021(freeText21);
			out << "\nJREAP/JTIDS Free Text, 22: " << dfi3030::Dui022(freeText22);
			out << "\nJREAP/JTIDS Free Text, 23: " << dfi3030::Dui023(freeText23);
			out << "\nJREAP/JTIDS Free Text, 24: " << dfi3030::Dui024(freeText24);
			out << "\nJREAP/JTIDS Free Text, 25: " << dfi3030::Dui025(freeText25);
			out << "\nJREAP/JTIDS Free Text, 26: " << dfi3030::Dui026(freeText26);
			out << "\nJREAP/JTIDS Free Text, 27: " << dfi3030::Dui027(freeText27);
			out << "\nJREAP/JTIDS Free Text, 28: " << dfi3030::Dui028(freeText28);
			out << "\nJREAP/JTIDS Free Text, 29: " << dfi3030::Dui029(freeText29);
			out << "\nJREAP/JTIDS Free Text, 30: " << dfi3030::Dui030(freeText30);
		}

		if (trailingBits > 0)
		{
			out << "\n\n" << kDispatchX30TrailingBitsPrefix << trailingBits;
		}
		break;
	}
		break;
	case 4:
		out << kDispatchVmfDetected;
		break;
	case 5:
		out << kDispatchLink22Detected;
		break;
	case 6:
		out << kDispatchCmfIbsDetected;
		break;
	case 7:
	{
		out << kDispatchX70Detected;
		const std::size_t payloadBits = effectivePayloadBytes * 8;
		constexpr std::size_t x70SectionBits = 184;
		const std::size_t sectionCount = payloadBits / x70SectionBits;
		const std::size_t trailingBits = payloadBits % x70SectionBits;

		if (sectionCount == 0)
		{
			out << "\n" << kDispatchX700Decode;
			out << "\nNo complete X7.0 section available (need 184 bits, received " << payloadBits << ").";
			break;
		}

		auto getPayloadBit = [&](std::size_t payloadBitIndex) -> int
		{
			std::size_t sourceByte = 10 + (payloadBitIndex / 8);
			std::size_t bitInByte = payloadBitIndex % 8;
			return (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
		};

		auto readBits = [&](auto& target, std::size_t startBit)
		{
			for (std::size_t i = 0; i < target.size(); ++i)
			{
				target[i] = getPayloadBit(startBit + i);
			}
		};

		for (std::size_t sectionIndex = 0; sectionIndex < sectionCount; ++sectionIndex)
		{
			const std::size_t baseBit = sectionIndex * x70SectionBits;

			std::array<int, 16> jreSourceTrackNumber{};
			std::array<int, 16> jSeriesMessageSequenceNumber{};
			std::array<int, 1> relayFlag{};
			std::array<int, 1> acknowledgementRequestFlag{};
			std::array<int, 1> x7SpareBit{};
			std::array<int, 13> dataAge{};
			std::array<int, 4> x7SpareNibble{};
			std::array<int, 12> numberOfJWords{};
			std::array<int, 16> sourceLinkDesignator{};
			std::array<int, 16> transmitLinkDesignator{};
			std::array<int, 9> networkParticipationGroup{};
			std::array<int, 7> x7Spare7Bits{};
			std::array<int, 16> jSeriesWord1{};
			std::array<int, 16> jSeriesWord2{};
			std::array<int, 16> jSeriesWord3{};
			std::array<int, 16> jSeriesWord4{};
			std::array<int, 2> x7Spare2Bits{};
			std::array<int, 6> jSeriesWord5{};

			readBits(jreSourceTrackNumber, baseBit + 0);
			readBits(jSeriesMessageSequenceNumber, baseBit + 16);
			readBits(relayFlag, baseBit + 32);
			readBits(acknowledgementRequestFlag, baseBit + 33);
			readBits(x7SpareBit, baseBit + 34);
			readBits(dataAge, baseBit + 35);
			readBits(x7SpareNibble, baseBit + 48);
			readBits(numberOfJWords, baseBit + 52);
			readBits(sourceLinkDesignator, baseBit + 64);
			readBits(transmitLinkDesignator, baseBit + 80);
			readBits(networkParticipationGroup, baseBit + 96);
			readBits(x7Spare7Bits, baseBit + 105);
			readBits(jSeriesWord1, baseBit + 112);
			readBits(jSeriesWord2, baseBit + 128);
			readBits(jSeriesWord3, baseBit + 144);
			readBits(jSeriesWord4, baseBit + 160);
			readBits(x7Spare2Bits, baseBit + 176);
			readBits(jSeriesWord5, baseBit + 178);

			out << "\n\n" << kDispatchX70SectionPrefix << (sectionIndex + 1);
			out << "\n" << kX10Jstn.label << ": " << dfi3027::Dui003(jreSourceTrackNumber);
			out << "\n" << kX10Sequence.label << ": " << dfi3032::Dui003(jSeriesMessageSequenceNumber);
			out << "\n" << kX10Relay.label << ": " << dfi3002::Dui009(relayFlag);
			out << "\n" << kX10AckReq.label << ": " << dfi3002::Dui003(acknowledgementRequestFlag);
			out << "\n" << kX10Spare1.label << ": " << BitsToUInt(x7SpareBit);
			out << "\n" << kX10DataAge.label << ": " << dfi3003::Dui003(dataAge);
			out << "\n" << kX10Spare4.label << ": " << BitsToUInt(x7SpareNibble);
			out << "\n" << kX10JWords.label << ": " << dfi3033::Dui005(numberOfJWords);
			out << "\n" << kX70SourceLinkDesignator.label << ": " << dfi3021::Dui003(sourceLinkDesignator);
			out << "\n" << kX70TransmitLinkDesignator.label << ": " << dfi3021::Dui004(transmitLinkDesignator);
			out << "\n" << kX70Npg.label << ": " << dfi3040::Dui001(networkParticipationGroup);
			out << "\n" << kX70Spare7.label << ": " << BitsToUInt(x7Spare7Bits) << " ///-> " << BitsToBinaryString(x7Spare7Bits);
			out << "\n" << kX10Word1.label << ": " << dfi3028::Dui001(jSeriesWord1);
			out << "\n" << kX10Word2.label << ": " << dfi3028::Dui002(jSeriesWord2);
			out << "\n" << kX10Word3.label << ": " << dfi3028::Dui003(jSeriesWord3);
			out << "\n" << kX10Word4.label << ": " << dfi3028::Dui004(jSeriesWord4);
			out << "\n" << kX10Spare2.label << ": " << BitsToUInt(x7Spare2Bits);
			out << "\n" << kX10Word5.label << ": " << dfi3028::Dui005(jSeriesWord5);
		}

		if (trailingBits > 0)
		{
			out << "\n\n" << kDispatchX70TrailingBitsPrefix << trailingBits;
		}
		break;
	}
	default:
		out << kDispatchUnsupportedPrefix << messageTypeValue << ".";
		break;
	}

	out << "\n" << kAbmlPayloadBytesUsedLabel << ": " << effectivePayloadBytes;
	out << "\n" << kAbmlFieldValueLabel << ": " << appBlockMessageLengthValue;

	return out.str();
}

}