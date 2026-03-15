#include "raylib.h"
#include <iostream>
#include <array>
#include <cctype>
#include <sstream>
#include <vector>
#include "ByteToBits.h"
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
#include "milstd6016/messageProcessorJ01C21.h"
#include "milstd6016/messageProcessorJ00E0.h"
#include "milstd6016/messageProcessorJ01E0.h"
#include "milstd6016/messageProcessorJ03E0.h"
#include "milstd6016/messageProcessorJ04E0.h"
#include "milstd6016/messageProcessorJ07E0.h"
#include "milstd6016/messageProcessorJ10E0.h"
#include "milstd6016/messageProcessorJ11E0.h"
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
        bits += ByteToBinaryConverter(bytes[index], false);
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

    const int declaredAbml = ((bytes[2] & 0xFF) << 8) | (bytes[3] & 0xFF);
    const int receivedPayload = static_cast<int>(bytes.size()) - 10;
    int effectivePayload = declaredAbml;
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

    std::ostringstream context;
    context << "JREAP AH.0 detected (HeaderType=3, MessageType=1). "
            << "ABML=" << declaredAbml << " byte(s), payload used=" << effectivePayload << " byte(s).";
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
    bytes.push_back(0x09);
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

    wordBits = wordBits.substr(0, 70);

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

    const int wordFormat = BitsToUInt(ExtractFieldBits(wordBits, 0, 1));
    const int label = BitsToUInt(ExtractFieldBits(wordBits, 2, 6));
    const int sublabel = BitsToUInt(ExtractFieldBits(wordBits, 7, 9));

    std::string decoded;
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
    else if (wordFormat == 1 && label == 1)
    {
        decoded = milstd6016::ProcessJ00C1MessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 2)
    {
        decoded = milstd6016::ProcessJ03C2MessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 3)
    {
        decoded = milstd6016::ProcessJ06C3MessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 4)
    {
        decoded = milstd6016::ProcessJ06C4MessageBits(wordBits);
    }
    else if (wordFormat == 1 && label == 21)
    {
        decoded = milstd6016::ProcessJ01C21MessageBits(wordBits);
    }
    else if (wordFormat == 2)
    {
        decoded = milstd6016::ProcessJ00E0MessageBits(wordBits);
    }
    else
    {
        std::ostringstream output;
        output << "Unsupported MIL-STD-6016 word for toolbox decoder. "
               << "Detected WORD FORMAT=" << wordFormat
               << ", LABEL=" << label
               << ", SUBLABEL=" << sublabel << ".";
        decoded = output.str();
    }

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
    InitWindow(3000, 800, "Binary Tools");
    int btnX, btnY, btnW, btnH;
    bool mouseOverBtn;
    int inputBoxX = 10, inputBoxY = 40, inputBoxW = 800, inputBoxH = 40;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Move input/output UI closer to the top
        DrawRectangle(inputBoxX, inputBoxY, inputBoxW, inputBoxH, (Color){30,30,30,255});
        DrawRectangleLines(inputBoxX, inputBoxY, inputBoxW, inputBoxH, YELLOW);
        DrawText("Paste MIL-STD-6016 bits, JREAP CSV, or type TEST J0.0I:", inputBoxX, inputBoxY - 30, 22, DARKGRAY);
        std::string modeText = std::string("Input Mode: ") + InputModeLabel(inputMode) + "  (F1 AUTO, F2 JREAP, F3 RAW-6016)";
        DrawText(modeText.c_str(), inputBoxX + inputBoxW + 20, inputBoxY - 30, 20, DARKGRAY);
        DrawText(input.c_str(), inputBoxX + 10, inputBoxY + 10, 22, RAYWHITE);

        // Draw a submit button
        btnX = inputBoxX + inputBoxW + 20;
        btnY = inputBoxY;
        btnW = 120;
        btnH = inputBoxH;
        mouseOverBtn = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)btnX, (float)btnY, (float)btnW, (float)btnH});
        DrawRectangle(btnX, btnY, btnW, btnH, mouseOverBtn ? ORANGE : DARKGRAY);
        DrawRectangleLines(btnX, btnY, btnW, btnH, YELLOW);
        DrawText("Submit", btnX + 20, btnY + 10, 22, RAYWHITE);

        // Draw the output string below the input area
        if (!output.empty()) {
            DrawText("Header Translation:", 10, inputBoxY + inputBoxH + 20, 22, DARKGRAY);
            // Split output into lines and draw each with extra spacing
            int y = inputBoxY + inputBoxH + 50;
            int lineSpacing = 32; // More space between lines
            size_t start = 0;
            while (start < output.length()) {
                size_t end = output.find('\n', start);
                std::string line = (end == std::string::npos) ? output.substr(start) : output.substr(start, end - start);
                DrawText(line.c_str(), 10, y, 22, BLUE);
                y += lineSpacing;
                if (end == std::string::npos) break;
                start = end + 1;
            }
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


            input.clear(); // clear input only once after submit
        }
        EndDrawing();
    }
}

            