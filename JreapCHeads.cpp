#include <iostream>
#include <array>
#include <cmath>
/* this function takes in the complete head and returns the common header information
 * the common header information is the first 80 bits of the header
 * the common header information is the same for all JREAP messages
 */
const std::string CommonHeaderConverter(std::array<int, 8> byteArray)
{
	// declare the output string

	std::string output = "";

	// split the first byte out

	int firstByte = byteArray[0];

	// get the first four bits from the first byte

	int firstFourBits = (firstByte >> 4) & 0x0F;

	if (firstFourBits == 1)
	{
		output = "ATP JREAP-A";
	}
	else if (firstFourBits == 2)
	{
		output = "PTP JREAP-B";
	}
	else if (firstFourBits == 3)
	{
		output = "Application JREAP-C " + std::to_string(firstFourBits) + "\n";
		// get the  last four bits from first byte and add to output
		int messageType = firstByte & 0x0F;
		int transmissionTimeReferenceFlag = (byteArray[1] >> 2) & 0x01;
		int spare = (byteArray[1] >> 2) & 0x0F;
		int applicationProtocolVersion = byteArray[1] & 0x0F;
		int applicationBlockMessageLength = (byteArray[2] & 0x0F) << 8 | byteArray[3];
		int jreSenderID = byteArray[4] << 8 | byteArray[5];
		// convert the int to octal
		int jreSenderIDOctal = 0;
		int i = 1;
		int tempJreSenderID = jreSenderID;
		while (tempJreSenderID != 0)
		{
			jreSenderIDOctal += (tempJreSenderID % 8) * i;
			tempJreSenderID /= 8;
			i *= 10;
		}
		jreSenderID = jreSenderIDOctal;
		int timeAccuracy = (byteArray[6] >> 4) & 0x0F;
		int dataValidTime = (byteArray[6] & 0x0F) << 8 | byteArray[7];
		output += "Message Type: " + std::to_string(messageType) + "\n" + "Transmission Time Reference Flag: " + std::to_string(transmissionTimeReferenceFlag) + "\n" + "Spare: " + std::to_string(spare) + "\n" + "Application Protocol Version: " + std::to_string(applicationProtocolVersion) + "\n" + "Application Block Message Length: " + std::to_string(applicationBlockMessageLength) + "\n" + "JRE Sender ID: " + std::to_string(jreSenderID) + "\n" + "Time Accuracy: " + std::to_string(timeAccuracy) + "\n" + "Data Valid Time: " + std::to_string(dataValidTime);
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