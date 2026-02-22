#include "jreaplib.h"

#include <array>
#include <algorithm>
#include <cctype>

#include <cstddef>

namespace jreap_internal {
std::string ProcessJreapApplicationMessage(const std::array<int, 512>& byteArray, std::size_t byteCount, bool strictAbml);
}

namespace jreap {

namespace {

bool IsAllowedCsvCharacter(char character)
{
    return std::isdigit(static_cast<unsigned char>(character)) ||
           std::isspace(static_cast<unsigned char>(character)) ||
           character == ',' || character == '+' || character == '-';
}

bool TryParseClampedByteToken(const std::string& text, std::size_t tokenStart, std::size_t tokenEnd, int& value)
{
    while (tokenStart < tokenEnd && std::isspace(static_cast<unsigned char>(text[tokenStart])))
    {
        ++tokenStart;
    }
    while (tokenEnd > tokenStart && std::isspace(static_cast<unsigned char>(text[tokenEnd - 1])))
    {
        --tokenEnd;
    }

    if (tokenStart >= tokenEnd)
    {
        return false;
    }

    int sign = 1;
    if (text[tokenStart] == '+' || text[tokenStart] == '-')
    {
        sign = (text[tokenStart] == '-') ? -1 : 1;
        ++tokenStart;
    }

    if (tokenStart >= tokenEnd)
    {
        return false;
    }

    long long magnitude = 0;
    for (std::size_t index = tokenStart; index < tokenEnd; ++index)
    {
        const unsigned char character = static_cast<unsigned char>(text[index]);
        if (!std::isdigit(character))
        {
            return false;
        }

        if (magnitude < 1000000000LL)
        {
            magnitude = (magnitude * 10) + static_cast<long long>(character - '0');
        }
    }

    long long signedValue = magnitude;
    if (sign < 0)
    {
        signedValue = -signedValue;
    }

    if (signedValue < 0)
    {
        value = 0;
    }
    else if (signedValue > 255)
    {
        value = 255;
    }
    else
    {
        value = static_cast<int>(signedValue);
    }

    return true;
}

std::vector<int> ParseCsvLineRange(const std::string& csvLine, std::size_t start, std::size_t end)
{
    std::vector<int> output;
    const std::size_t commaCount = static_cast<std::size_t>(std::count(csvLine.begin() + start, csvLine.begin() + end, ','));
    output.reserve(commaCount + 1);

    std::size_t tokenStart = start;
    while (tokenStart <= end)
    {
        std::size_t tokenEnd = csvLine.find(',', tokenStart);
        if (tokenEnd == std::string::npos || tokenEnd > end)
        {
            tokenEnd = end;
        }

        int parsedValue = 0;
        if (TryParseClampedByteToken(csvLine, tokenStart, tokenEnd, parsedValue))
        {
            output.push_back(parsedValue);
        }

        if (tokenEnd == end)
        {
            break;
        }

        tokenStart = tokenEnd + 1;
    }

    return output;
}

bool FindBestCsvLineRange(const std::string& input, std::size_t& bestStart, std::size_t& bestEnd)
{
    bool found = false;
    std::size_t lineStart = 0;
    std::size_t bestCommaCount = 0;

    for (std::size_t index = 0; index <= input.size(); ++index)
    {
        const bool atLineEnd = (index == input.size()) || (input[index] == '\n');
        if (!atLineEnd)
        {
            continue;
        }

        const std::size_t lineEnd = index;
        std::size_t commaCount = 0;
        bool csvLike = true;
        for (std::size_t i = lineStart; i < lineEnd; ++i)
        {
            const char character = input[i];
            if (!IsAllowedCsvCharacter(character))
            {
                csvLike = false;
                break;
            }

            if (character == ',')
            {
                ++commaCount;
            }
        }

        if (csvLike && commaCount > bestCommaCount)
        {
            bestCommaCount = commaCount;
            bestStart = lineStart;
            bestEnd = lineEnd;
            found = true;
        }

        lineStart = index + 1;
    }

    return found;
}

}

std::vector<int> ParseCsvBytes(const std::string& csvBytes)
{
    std::size_t bestStart = 0;
    std::size_t bestEnd = 0;
    if (FindBestCsvLineRange(csvBytes, bestStart, bestEnd))
    {
        return ParseCsvLineRange(csvBytes, bestStart, bestEnd);
    }

    return ParseCsvLineRange(csvBytes, 0, csvBytes.size());
}

std::string DecodeApplicationMessage(const std::vector<int>& bytes, bool strictAbml)
{
    std::array<int, 512> fixedBytes{};
    const std::size_t count = std::min<std::size_t>(bytes.size(), fixedBytes.size());

    for (std::size_t index = 0; index < count; ++index)
    {
        fixedBytes[index] = bytes[index];
    }

    return jreap_internal::ProcessJreapApplicationMessage(fixedBytes, count, strictAbml);
}

std::string DecodeApplicationMessageCsv(const std::string& csvBytes, bool strictAbml)
{
    const std::vector<int> parsed = ParseCsvBytes(csvBytes);
    if (parsed.empty())
    {
        return "No byte array found. Paste a comma-separated byte line (example: 49,1,0,45,...).";
    }

    return DecodeApplicationMessage(parsed, strictAbml);
}

}
