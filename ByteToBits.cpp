#include <iostream>
#include <array>
#include <string>
#include <math.h>
#include <bits/algorithmfwd.h>

int binarySize = 8;

// take in any array of binary digits and convert it to an integer
template <size_t N>
int BinaryToDigitConverter(const std::array<int, N> &binary)
{
	int value = 0;
	for (size_t i = 0; i < binary.size(); ++i)
	{
		value += binary[i] * std::pow(2, binary.size() - 1 - i);
	}
	return value;
}

// converts binary integer array with various lengths to integer value
template <size_t N>
int BinaryArrayToInt(const std::array<int, N> &arr)
{
	int value = 0;
	for (size_t i = 0; i < N; ++i)
	{
		value += arr[i] * std::pow(2, N - 1 - i);
	}
	return value;
}

// create a function that converts a binary array to an octal value
template <size_t N>
int BinaryArrayToOctal(const std::array<int, N> &arr)
{
	int value = 0;
	for (size_t i = 0; i < N; ++i)
	{
		value += arr[i] * std::pow(8, N - 1 - i);
	}
	return value;
}

const std::array<int, 8> ByteToBinaryConverterDigits(int control, bool reverse = false)
{
	std::array<int, 8> binaryControl;

	for (size_t i = 0; i < 8; i++)
	{
		if (control == 0)
		{
			binaryControl[i] = 0;
		}
		else
		{
			bool response = control % 2;
			binaryControl[i] = response;
			control = control / 2;
		}
	}
	// if the reverse flag is set to true, then reverse the array
	if (!reverse)
	{
		std::array<int, 8> revbinaryControl;
		for (int i = 0; i < 8; i++)
		{
			revbinaryControl[i] = binaryControl[7 - i];
		}
		binaryControl = revbinaryControl;
	}

	return binaryControl;
}

const std::string ByteToBinaryConverter(int control, bool reverse)
{

	int binaryControl[binarySize];
	std::string output = "";
	for (int i = 0; i < binarySize; i++)
	{
		bool response = control % 2;
		binaryControl[i] = response;
		control = control / 2;
	}
	if (reverse)
	{
		for (int i = 0; i < binarySize; i++)
		{
			output.append(std::to_string(binaryControl[i]));
		}
	}
	else
	{
		for (int i = (binarySize - 1); i >= 0; i--)
		{
			output.append(std::to_string(binaryControl[i]));
		}
	}
	return output;
}

const std::string ByteArrayToBinaryConverter(std::array<int, 45> byteArray, bool reverse)
{
	std::string output = "";

	if (!reverse)
	{
		for (int i = 0; i < binarySize; i++)
		{
			output.append(
				ByteToBinaryConverter(byteArray[i], reverse));
		}
	}
	else
	{
		for (int i = (binarySize - 1); i >= 0; i--)
		{
			output.append(
				ByteToBinaryConverter(byteArray[i], reverse));
		}
	}

	return output;
}

const std::array<int, 80> ByteHeaderToBinaryConverter(std::array<int, 10> byteArray, bool reverse)
{
	std::array<int, 80> binaryArray;
	// convert each byte to a binary array and add it to the binary array
	for (int i = 0; i < 10; i++)
	{
		std::array<int, 8> binary = ByteToBinaryConverterDigits(byteArray[i], reverse);
		// add each binary digit to the binary array
		for (int j = 0; j < 8; j++)
		{
			binaryArray[(i * 8) + j] = binary[j];
		}
	}

	return binaryArray;
}
