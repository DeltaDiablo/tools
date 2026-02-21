#include "JreapLibrary.h"

#include <array>
#include <algorithm>
#include <cctype>
#include <sstream>

#include "JReapCHeads.h"

namespace jreap {

namespace {

std::string Trim(const std::string& value)
{
    std::size_t start = 0;
    while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start])))
    {
        ++start;
    }

    std::size_t end = value.size();
    while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])))
    {
        --end;
    }

    return value.substr(start, end - start);
}

bool IsIntegerToken(const std::string& token)
{
    if (token.empty())
    {
        return false;
    }

    std::size_t index = 0;
    if (token[0] == '+' || token[0] == '-')
    {
        index = 1;
    }
    if (index >= token.size())
    {
        return false;
    }

    for (; index < token.size(); ++index)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[index])))
        {
            return false;
        }
    }
    return true;
}

std::vector<int> ParseCsvLine(const std::string& csvLine)
{
    std::vector<int> output;
    std::stringstream stream(csvLine);
    std::string token;

    while (std::getline(stream, token, ','))
    {
        std::string cleaned = Trim(token);
        if (!IsIntegerToken(cleaned))
        {
            continue;
        }

        int value = std::stoi(cleaned);
        if (value < 0)
        {
            value = 0;
        }
        if (value > 255)
        {
            value = 255;
        }
        output.push_back(value);
    }

    return output;
}

std::string ExtractBestCsvLine(const std::string& input)
{
    std::stringstream stream(input);
    std::string line;
    std::string bestLine;
    std::size_t bestCommaCount = 0;

    while (std::getline(stream, line))
    {
        const std::size_t commaCount = static_cast<std::size_t>(std::count(line.begin(), line.end(), ','));
        if (commaCount == 0)
        {
            continue;
        }

        bool csvLike = true;
        for (char character : line)
        {
            const bool allowed = std::isdigit(static_cast<unsigned char>(character)) ||
                                 std::isspace(static_cast<unsigned char>(character)) ||
                                 character == ',' || character == '+' || character == '-';
            if (!allowed)
            {
                csvLike = false;
                break;
            }
        }

        if (!csvLike)
        {
            continue;
        }

        if (commaCount > bestCommaCount)
        {
            bestCommaCount = commaCount;
            bestLine = line;
        }
    }

    return bestLine;
}

}

std::vector<int> ParseCsvBytes(const std::string& csvBytes)
{
    const std::string extractedLine = ExtractBestCsvLine(csvBytes);
    if (!extractedLine.empty())
    {
        return ParseCsvLine(extractedLine);
    }

    return ParseCsvLine(csvBytes);
}

std::string DecodeApplicationMessage(const std::vector<int>& bytes, bool strictAbml)
{
    std::array<int, 65> fixedBytes{};
    const std::size_t count = std::min<std::size_t>(bytes.size(), fixedBytes.size());

    for (std::size_t index = 0; index < count; ++index)
    {
        fixedBytes[index] = bytes[index];
    }

    return ProcessJreapApplicationMessage(fixedBytes, count, strictAbml);
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
