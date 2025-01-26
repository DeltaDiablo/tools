#include <array>
#include <string>

template <size_t N>
int BinaryToDigitConverter(const std::array<int, N>& binary, int arrLength = 0);

template <size_t N>
int BinaryArrayToInt(const std::array<int, N>& arr);

template <size_t N>
int BinaryArrayToOctal(const std::array<int, N>& arr);

std::array<int,8> ByteToBinaryConverterDigits(int control, bool reverse=false);

std::string ByteToBinaryConverter(int byte,bool reverse);

std::string ByteArrayToBinaryConverter(std::array<int, 45> byteArray, bool reverse);

std::array<int,80> ByteHeaderToBinaryConverter(std::array<int,10> byteArray, bool reverse);
