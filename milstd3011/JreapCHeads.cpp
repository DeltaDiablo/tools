#include <iostream>
#include <array>
#include <cmath>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "milstd3011/dfiset3008.h"
#include "milstd3011/dfiset3028.h"

namespace {
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
}
/* THE JREAP APPLICATION HEADER IS USED WITH MEDIA THAT PROVIDE OSI TRANSPORT 
 * LAYER FUNCTIONALITY THIS IS AH.0
 */
std::string CommonHeaderConverter(std::array<int, 10> byteArray)
{
	// declare the output string
	std::string output = "";
	// split the first byte out
	int firstByte = byteArray[0];
	// get the first four bits from the first byte
	int headerType = (firstByte >> 4) & 0x0F;
	if (headerType == 1)
	{
		output = "ATP JREAP-A \n";
	}
	else if (headerType == 2)
	{
		output = "PTP JREAP-B \n";
	}
	else if (headerType == 3)
	{
		output = "JREAP-C \n";
	}
	else
	{
		output = "Unknown Header Type\n";
	}
	return output;
}
const std::string JreapApplicationHeader0(std::array<int, 10> byteArray)
{
	// declare the output string

	std::string output = "";

	// split the first byte out

	int firstByte = byteArray[0];

	// get the first four bits from the first byte

	int headerType = (firstByte >> 4) & 0x0F;

	if (headerType == 1)
	{
		output = "ATP JREAP-A \n";
	}
	else if (headerType == 2)
	{
		output = "PTP JREAP-B \n";
	}
	else if (headerType == 3)
	{
		output = "JREAP-C \n";
		}
	else
	{
		output = "Undefined";
	}

	return output;
}



/* the header type is a 4 bit unsigned integer identifying the type of JREAP message
 * 0 Undefined
 * 1 ATP JREAP-A
 * 2 PTP JREAP-B
 * 3 Application JREAP-C
 */
const std::string HeaderType(std::array<int, 4> headerType)
{
	int headerTypeInt = 0;
	for (int i = 0; i < 4; i++)
	{
		headerTypeInt += headerType[i] * std::pow(2, 3 - i);
	}
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

	std::string binaryset = "";
	for (std::size_t i = 0; i < headerType.size(); i++)
	{
		binaryset.append(std::to_string(headerType[i]));
	}

	output = output + " ///-> " + binaryset;

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
const std::string MessageType(std::array<int, 4> messageType)
{
	int messageTypeInt = 0;
	for (int i = 0; i < 4; i++)
	{
		messageTypeInt += messageType[i] * std::pow(2, 3 - i);
	}
	std::string output = "";
	switch (messageTypeInt)
	{
	case 0:
		output = "Management";
		break;
	case 1:
		output = "JREAP J-Series";
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
	case 15:
		output = "Reserved";
		break;
	default:
		output = "Undefined";
		break;
	}

	std::string binaryset = "";
	for (std::size_t i = 0; i < messageType.size(); i++)
	{
		binaryset.append(std::to_string(messageType[i]));
	}

	output = output + " ///-> " + binaryset;
	return output;
}

/* The TransmissionTimeReferenceFlag is a boolean
 * 0 means this track does not correspond to the time of transmission
 * 1 means it does correspond to the time of transmission
 */
const std::string TransmissionTimeReferenceFlag(std::array<int, 1> transmissionTimeReferenceFlag)
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

const std::string Spare(std::array<int, 3> spare)
{
	int spareInt = 0;
	for (int i = 0; i < 3; i++)
	{
		spareInt += spare[i] * std::pow(2, 2 - i);
	}
	std::string output = std::to_string(spareInt);

	std::string binaryset = "";
	for (std::size_t i = 0; i < spare.size(); i++)
	{
		binaryset.append(std::to_string(spare[i]));
	}

	output = output + " ///-> " + binaryset;
	return output;
}

/* the Application Protocol Version is a 4 bit unsigned integer
 * 0 is illegal
 * the higher the number the higher the version
 */
const std::string ApplicationProtocolVersion(std::array<int, 4> applicationProtocolVersion)
{
	int applicationProtocolVersionInt = 0;
	for (int i = 0; i < 4; i++)
	{
		applicationProtocolVersionInt += applicationProtocolVersion[i] * std::pow(2, 3 - i);
	}
	std::string output = "";
	if (applicationProtocolVersionInt > 0)
	{
		output = std::to_string(applicationProtocolVersionInt);
	}
	else
	{
		output = "Illegal";
	}

	std::string binaryset = "";
	for (std::size_t i = 0; i < applicationProtocolVersion.size(); i++)
	{
		binaryset.append(std::to_string(applicationProtocolVersion[i]));
	}

	output = output + " ///-> " + binaryset;
	return output;
}

/* Time Accuracy is a 4 bit unsigned integer
 * the higher the number the lower the accuracy
 */
const std::string TimeAccuracy(std::array<int, 4> timeAccuracy)
{
	int timeAccuracyInt = 0;
	for (int i = 0; i < 4; i++)
	{
		timeAccuracyInt += timeAccuracy[i] * std::pow(2, 3 - i);
	}
	std::string binaryset = "";
	for (std::size_t i = 0; i < timeAccuracy.size(); i++)
	{
		binaryset.append(std::to_string(timeAccuracy[i]));
	}

	std::string output = "";
	output = std::to_string(timeAccuracyInt) + " ///-> " + binaryset;

	return output;
}

/* Application Block Message Length is a 16 bit unsigned integer
 * ==========================================================
 * 16 bit unsigned integer
 * 0 to 65535
 * ==========================================================
 */
const std::string ApplicationBlockMessageLength(std::array<int, 16> applicationBlockMessageLength)
{
	int applicationBlockMessageLengthInt = 0;
	for (int i = 0; i < 16; i++)
	{
		applicationBlockMessageLengthInt += applicationBlockMessageLength[i] * std::pow(2, 15 - i);
	}

	std::string binary = "";
	for (std::size_t i = 0; i < applicationBlockMessageLength.size(); i++)
	{
		binary.append(std::to_string(applicationBlockMessageLength[i]));
	}

	std::string output = "";
	output = std::to_string(applicationBlockMessageLengthInt) + " ///-> " + binary;
	return output;
}

/* JRE Sender ID is a 16 bit unsigned octal integer
 * ==========================================================
 * 16 bit unsigned integer
 * 0 to 177777 octal
 * ==========================================================
 */
const std::string JreSenderID(std::array<int, 16> jreSenderID)
{
	int jreSenderIDInt = 0;
	for (int i = 0; i < 16; i++)
	{
		jreSenderIDInt += jreSenderID[i] * std::pow(2, 15 - i);
	}
	// convert the int to octal
	int octal = 0;
	int i = 1;
	while (jreSenderIDInt != 0)
	{
		octal += (jreSenderIDInt % 8) * i;
		jreSenderIDInt /= 8;
		i *= 10;
	}

	std::string binary = "";
	for (std::size_t i = 0; i < jreSenderID.size(); i++)
	{
		binary.append(std::to_string(jreSenderID[i]));
	}
	std::string output = "";
	output = std::to_string(octal) + " ///-> " + binary;
	return output;
}

/* Time Accuracy is a 4 bit unsigned integer
 * the higher the number the lower the accuracy
 */
const std::string TimeAccuracyReporting(std::array<int, 4> timeAccuracy)
{
	int timeAccuracyInt = 0;
	for (int i = 0; i < 4; i++)
	{
		timeAccuracyInt += timeAccuracy[i] * std::pow(2, 3 - i);
	}

	std::string binary = "";
	for (std::size_t i = 0; i < timeAccuracy.size(); i++)
	{
		binary.append(std::to_string(timeAccuracy[i]));
	}

	std::string output = std::to_string(timeAccuracyInt) + " ///-> " + binary;

	return output;
}

/* Data valid time is an unsigned 28 bit integer
 * this is the time in seconds since 00:00:00 UTC
 */
const std::string DataValidTime(std::array<int, 28> dataValidTime)
{
	int dataValidTimeInt = 0;
	for (std::size_t i = 0; i < 28; i++)
	{
		dataValidTimeInt += dataValidTime[i] * std::pow(2, 27 - i);
	}

	std::string binary = "";
	for (std::size_t i = 0; i < dataValidTime.size(); i++)
	{
		binary.append(std::to_string(dataValidTime[i]));
	}
	std::string output = std::to_string(dataValidTimeInt) + " ///-> " + binary;
	return output;
}

std::string ProcessJreapApplicationMessage(const std::array<int, 65>& byteArray, std::size_t byteCount, bool strictAbml)
{
	if (byteCount < 10)
	{
		return "Invalid input: AH.0 requires at least 10 bytes for the application header.";
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

	std::ostringstream out;
	out << "AH.0 decode\n";
	out << "Header Type: " << HeaderType(headerTypeBits) << "\n";
	out << "Message Type: " << MessageType(messageTypeBits) << "\n";
	out << "Transmission Time Reference Flag: " << TransmissionTimeReferenceFlag(transmissionTimeFlagBits) << "\n";
	out << "Spare: " << Spare(spareBits) << "\n";
	out << "Application Protocol Version: " << ApplicationProtocolVersion(appProtocolVersionBits) << "\n";
	out << "Application Block Message Length: " << ApplicationBlockMessageLength(appBlockMessageLengthBits) << "\n";
	out << "JRE Sender ID: " << JreSenderID(jreSenderIdBits) << "\n";
	out << "Time Accuracy: " << TimeAccuracyReporting(timeAccuracyBits) << "\n";
	out << "Data Valid Time: " << DataValidTime(dataValidTimeBits) << "\n";

	if (headerTypeValue != 3)
	{
		out << "Dispatch: not an application header (AH.0).";
		return out.str();
	}

	std::size_t payloadBytes = 0;
	if (byteCount > 10)
	{
		payloadBytes = byteCount - 10;
	}

	const std::size_t declaredAbmlBytes = static_cast<std::size_t>(appBlockMessageLengthValue);
	const std::size_t effectivePayloadBytes = std::min(payloadBytes, declaredAbmlBytes);
	const bool abmlMismatch = (payloadBytes != declaredAbmlBytes);

	out << "\nABML consistency\n";
	out << "Declared ABML bytes: " << declaredAbmlBytes << "\n";
	out << "Received payload bytes: " << payloadBytes << "\n";
	if (payloadBytes < declaredAbmlBytes)
	{
		out << "Status: payload truncated by " << (declaredAbmlBytes - payloadBytes) << " byte(s).\n";
	}
	else if (payloadBytes > declaredAbmlBytes)
	{
		out << "Status: extra trailing payload of " << (payloadBytes - declaredAbmlBytes) << " byte(s).\n";
	}
	else
	{
		out << "Status: payload length matches ABML.\n";
	}
	out << "Mode: " << (strictAbml ? "strict" : "lenient") << " ABML validation.\n";

	if (strictAbml && abmlMismatch)
	{
		out << "\nDispatch by Message Type\n";
		out << "ABML mismatch in strict mode: payload decode skipped.";
		out << "\nPayload bytes used for decode: 0";
		out << "\nABML field value: " << appBlockMessageLengthValue;
		return out.str();
	}

	out << "\nDispatch by Message Type\n";
	switch (messageTypeValue)
	{
	case 0:
	{
		out << "Management message detected.";
		if (effectivePayloadBytes >= 1)
		{
			auto subtypeBits = SliceBits<8>(bits, 0);
			for (std::size_t i = 0; i < 8; ++i)
			{
				subtypeBits[i] = (byteArray[10] >> (7 - i)) & 0x01;
			}
			out << "\nManagement Subtype: " << dfi3008::Dui002(subtypeBits);
		}
		else
		{
			out << "\nNo payload bytes available to decode management subtype.";
		}
		break;
	}
	case 1:
	{
		out << "JREAP J-Series message detected.";
		std::size_t payloadBits = effectivePayloadBytes * 8;
		if (payloadBits < 16)
		{
			out << "\nInsufficient payload for J-Series word decode (need at least 16 bits).";
			break;
		}

		std::array<int, 16> word1{};
		for (std::size_t i = 0; i < 16; ++i)
		{
			std::size_t sourceBit = i;
			std::size_t sourceByte = 10 + (sourceBit / 8);
			std::size_t bitInByte = sourceBit % 8;
			word1[i] = (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
		}
		out << "\nJ-Series Word 1: " << dfi3028::Dui001(word1);

		if (payloadBits >= 32)
		{
			std::array<int, 16> word2{};
			for (std::size_t i = 0; i < 16; ++i)
			{
				std::size_t sourceBit = 16 + i;
				std::size_t sourceByte = 10 + (sourceBit / 8);
				std::size_t bitInByte = sourceBit % 8;
				word2[i] = (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
			}
			out << "\nJ-Series Word 2: " << dfi3028::Dui002(word2);
		}

		if (payloadBits >= 48)
		{
			std::array<int, 16> word3{};
			for (std::size_t i = 0; i < 16; ++i)
			{
				std::size_t sourceBit = 32 + i;
				std::size_t sourceByte = 10 + (sourceBit / 8);
				std::size_t bitInByte = sourceBit % 8;
				word3[i] = (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
			}
			out << "\nJ-Series Word 3: " << dfi3028::Dui003(word3);
		}

		if (payloadBits >= 64)
		{
			std::array<int, 16> word4{};
			for (std::size_t i = 0; i < 16; ++i)
			{
				std::size_t sourceBit = 48 + i;
				std::size_t sourceByte = 10 + (sourceBit / 8);
				std::size_t bitInByte = sourceBit % 8;
				word4[i] = (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
			}
			out << "\nJ-Series Word 4: " << dfi3028::Dui004(word4);
		}

		if (payloadBits >= 70)
		{
			std::array<int, 6> word5{};
			for (std::size_t i = 0; i < 6; ++i)
			{
				std::size_t sourceBit = 64 + i;
				std::size_t sourceByte = 10 + (sourceBit / 8);
				std::size_t bitInByte = sourceBit % 8;
				word5[i] = (byteArray[sourceByte] >> (7 - bitInByte)) & 0x01;
			}
			out << "\nJ-Series Word 5: " << dfi3028::Dui005(word5);
		}

		break;
	}
	case 2:
		out << "JTIDS/MIDS free text (coded) detected.";
		break;
	case 3:
		out << "JTIDS/MIDS free text (uncoded) detected.";
		break;
	case 4:
		out << "Variable Message Format (VMF) detected.";
		break;
	case 5:
		out << "LINK 22 detected.";
		break;
	case 6:
		out << "CMF IBS detected.";
		break;
	default:
		out << "Unsupported/undefined AH.0 message type " << messageTypeValue << ".";
		break;
	}

	out << "\nPayload bytes used for decode: " << effectivePayloadBytes;
	out << "\nABML field value: " << appBlockMessageLengthValue;

	return out.str();
}