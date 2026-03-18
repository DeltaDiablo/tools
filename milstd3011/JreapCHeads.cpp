#include <iostream>
#include <array>
#include <cmath>
#include <sstream>
#include <cstddef>
#include <cstdio>
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

std::string ProcessJWordPayload(const std::array<int, 65>& byteArray, std::size_t byteCount, std::size_t offset = 0)
{
	std::ostringstream out;
	out << "J-Series Message Payload\n";
	out << "Total bytes: " << byteCount << "\n";

	// Parse as 9-byte jwords
	std::size_t jwordCount = byteCount / 9;
	std::size_t remainingBytes = byteCount % 9;

	out << "Number of 9-byte jwords: " << jwordCount << "\n";
	if (remainingBytes > 0)
	{
		out << "Remaining bytes: " << remainingBytes << "\n";
	}
	out << "\n";

	// Display each jword
	for (std::size_t wordIdx = 0; wordIdx < jwordCount; ++wordIdx)
	{
		out << "JWord " << (wordIdx + 1) << " (bytes " << (offset + wordIdx * 9) << "-" << (offset + wordIdx * 9 + 8) << "):\n";
		out << "  Hex: ";
		
		// Show hex representation
		for (std::size_t byteIdx = 0; byteIdx < 9; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (wordIdx * 9) + byteIdx;
			unsigned char byteVal = static_cast<unsigned char>(byteArray[globalByteIdx] & 0xFF);
			char hexBuf[4];
			snprintf(hexBuf, sizeof(hexBuf), "%02X", byteVal);
			out << hexBuf;
			if (byteIdx < 8) out << " ";
		}
		out << "\n";

		// Show decimal representation
		out << "  Dec: ";
		for (std::size_t byteIdx = 0; byteIdx < 9; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (wordIdx * 9) + byteIdx;
			int byteVal = byteArray[globalByteIdx] & 0xFF;
			out << byteVal;
			if (byteIdx < 8) out << " ";
		}
		out << "\n";

		// Show binary representation
		out << "  Bin: ";
		for (std::size_t byteIdx = 0; byteIdx < 9; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (wordIdx * 9) + byteIdx;
			unsigned char byteVal = static_cast<unsigned char>(byteArray[globalByteIdx] & 0xFF);
			for (int bitIdx = 7; bitIdx >= 0; --bitIdx)
			{
				out << ((byteVal >> bitIdx) & 0x01);
			}
			if (byteIdx < 8) out << " ";
		}
		out << "\n\n";
	}

	// Handle remaining bytes
	if (remainingBytes > 0)
	{
		out << "Remaining bytes (< 9 bytes):\n";
		out << "  Hex: ";
		for (std::size_t byteIdx = 0; byteIdx < remainingBytes; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (jwordCount * 9) + byteIdx;
			unsigned char byteVal = static_cast<unsigned char>(byteArray[globalByteIdx] & 0xFF);
			char hexBuf[4];
			snprintf(hexBuf, sizeof(hexBuf), "%02X", byteVal);
			out << hexBuf;
			if (byteIdx < remainingBytes - 1) out << " ";
		}
		out << "\n";

		out << "  Dec: ";
		for (std::size_t byteIdx = 0; byteIdx < remainingBytes; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (jwordCount * 9) + byteIdx;
			int byteVal = byteArray[globalByteIdx] & 0xFF;
			out << byteVal;
			if (byteIdx < remainingBytes - 1) out << " ";
		}
		out << "\n";

		out << "  Bin: ";
		for (std::size_t byteIdx = 0; byteIdx < remainingBytes; ++byteIdx)
		{
			std::size_t globalByteIdx = offset + (jwordCount * 9) + byteIdx;
			unsigned char byteVal = static_cast<unsigned char>(byteArray[globalByteIdx] & 0xFF);
			for (int bitIdx = 7; bitIdx >= 0; --bitIdx)
			{
				out << ((byteVal >> bitIdx) & 0x01);
			}
			if (byteIdx < remainingBytes - 1) out << " ";
		}
		out << "\n";
	}

	return out.str();
}

std::string ProcessJreapApplicationMessage(const std::array<int, 65>& byteArray, std::size_t byteCount, bool strictAbml)
{
	// Always require at least 10 bytes for AH.0 header
	if (byteCount < 10)
	{
		return "Invalid input: AH.0 requires at least 10 bytes for the application header.";
	}

	// Parse AH.0 header (first 10 bytes)
	std::array<int, 10> ahBytes{};
	for (std::size_t i = 0; i < 10; ++i)
	{
		ahBytes[i] = byteArray[i] & 0xFF;
	}

	// Convert first 10 bytes to bits (80 bits total)
	std::array<int, 80> bits{};
	for (std::size_t i = 0; i < 10; ++i)
	{
		for (std::size_t j = 0; j < 8; ++j)
		{
			bits[(i * 8) + j] = (ahBytes[i] >> (7 - j)) & 0x01;
		}
	}

	// Extract AH.0 fields
	auto headerTypeBits = SliceBits<4>(bits, 0);
	auto messageTypeBits = SliceBits<4>(bits, 4);
	auto transmissionTimeFlagBits = SliceBits<1>(bits, 8);
	auto spareBits = SliceBits<3>(bits, 9);
	auto appProtocolVersionBits = SliceBits<4>(bits, 12);
	auto appBlockMessageLengthBits = SliceBits<16>(bits, 16);
	auto jreSenderIdBits = SliceBits<16>(bits, 32);
	auto timeAccuracyBits = SliceBits<4>(bits, 48);
	auto dataValidTimeBits = SliceBits<28>(bits, 52);

	// Calculate ABML value to determine number of jwords
	const int abmlValue = BitsToUInt(appBlockMessageLengthBits);
	const std::size_t jwordCount = abmlValue / 9;
	const std::size_t remainingBytes = abmlValue % 9;

	std::ostringstream out;
	out << "AH.0 JREAP Application Header\n";
	out << "Header Type: " << HeaderType(headerTypeBits) << "\n";
	out << "Message Type: " << MessageType(messageTypeBits) << "\n";
	out << "Transmission Time Reference Flag: " << TransmissionTimeReferenceFlag(transmissionTimeFlagBits) << "\n";
	out << "Spare: " << Spare(spareBits) << "\n";
	out << "Application Protocol Version: " << ApplicationProtocolVersion(appProtocolVersionBits) << "\n";
	out << "Application Block Message Length: " << ApplicationBlockMessageLength(appBlockMessageLengthBits) << " bytes\n";
	out << "  -> Number of 9-byte J-Words: " << jwordCount << "\n";
	if (remainingBytes > 0)
	{
		out << "  -> Remaining bytes: " << remainingBytes << "\n";
	}
	out << "JRE Sender ID: " << JreSenderID(jreSenderIdBits) << "\n";
	out << "Time Accuracy: " << TimeAccuracyReporting(timeAccuracyBits) << "\n";
	out << "Data Valid Time: " << DataValidTime(dataValidTimeBits) << "\n";

	// Now handle J-Series payload (remaining bytes after AH.0 header)
	if (byteCount > 10)
	{
		out << "\n" << ProcessJWordPayload(byteArray, byteCount - 10, 10);
	}
	else
	{
		out << "\nNo J-Series payload (only AH.0 header provided).";
	}

	return out.str();
}
