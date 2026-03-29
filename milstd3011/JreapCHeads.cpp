#include <iostream>
#include <array>
#include <sstream>
#include <cstddef>
#include <cstdio>
#include <algorithm>
#include "milstd3011/dfiset3000.h"
#include "milstd3011/dfiset3008.h"
#include "milstd3011/dfiset3007.h"
#include "milstd3011/dfiset3006.h"
#include "milstd3011/dfiset3001.h"
#include "milstd3011/dfiset3002.h"
#include "milstd3011/dfiset3003.h"
#include "milstd3011/dfiset3004.h"
#include "milstd3011/dfiset3005.h"
#include "milstd3011/dfiset3012.h"
#include "milstd3011/dfiset3014.h"
#include "milstd3011/dfiset3015.h"
#include "milstd3011/dfiset3016.h"
#include "milstd3011/dfiset3017.h"
#include "milstd3011/dfiset3018.h"
#include "milstd3011/dfiset3019.h"
#include "milstd3011/dfiset3020.h"
#include "milstd3011/dfiset3021.h"
#include "milstd3011/dfiset3022.h"
#include "milstd3011/dfiset3024.h"
#include "milstd3011/dfiset3029.h"
#include "milstd3011/dfiset3025.h"
#include "milstd3011/dfiset3027.h"
#include "milstd3011/dfiset3028.h"
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
		return "Invalid input: need at least 10 bytes for AH.0 decode.";
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

	if (!looksLikeAh0)
	{
		return "Input did not match AH.0 framing. Full-stack X1.1 decode is temporarily disabled.";
	}

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
