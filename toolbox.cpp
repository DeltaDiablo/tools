#include "raylib.h"
#include <iostream>
#include <array>
#include "ByteToBits.h"
#include "JreapCHeads.h"
#include <cmath>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int control = 0;
    std::string input = "";
    std::string output = "";
    InitWindow(3000, 800, "Binary Tools");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Binary Tools", 10, 10, 20, DARKGRAY);
        DrawText("Enter a number between 0 and 255", 10, 40, 20, DARKGRAY);
        DrawText("Number: ", 10, 70, 20, DARKGRAY);
        DrawText(input.c_str(), 100, 70, 20, DARKGRAY);
        DrawText("Binary: ", 10, 100, 20, DARKGRAY);
        DrawText(ByteToBinaryConverter(control, false).c_str(), 200, 100, 20, DARKGRAY);
        DrawText("reversed Binary", 10, 130, 20, DARKGRAY);
        DrawText(ByteToBinaryConverter(control, true).c_str(), 200, 130, 20, DARKGRAY);
        DrawText("Press backspace to clear", 10, 160, 20, DARKGRAY);
        DrawText("Press 0-9 to enter a number", 10, 190, 20, DARKGRAY);

        DrawText("Jreap Header: ", 10, 240, 20, DARKGRAY);
        std::array<int, 10> byteArray = {49, 1, 0, 45, 0, 35, 84, 102, 228, 103};
        std::string byteArrayString = "";
        for (std::size_t i = 0; i < byteArray.size(); i++)
        {
            byteArrayString.append(std::to_string(byteArray[i]) + ",");
        }
        DrawText(byteArrayString.c_str(), 200, 240, 20, DARKGRAY);

        std::array<int, 80> binary = ByteHeaderToBinaryConverter(byteArray, false);

        std::string binaryString = "";
        for (std::size_t i = 0; i < binary.size() - 1; i++)
        {
            binaryString.append(std::to_string(binary[i]));
        }

        DrawText("JREAP-C Header: ", 10, 280, 20, DARKGRAY);
        DrawText(binaryString.c_str(), 200, 280, 20, DARKGRAY);

        DrawText("Negotiated Header:", 900, 320, 20, DARKGRAY);

        DrawText(CommonHeaderConverter(byteArray).c_str(), 1100, 320, 20, DARKGRAY);
        DrawText("Header Type: ", 10, 300, 20, DARKGRAY);

        DrawText(HeaderType({binary[0], binary[1], binary[2], binary[3]}).c_str(), 500, 300, 20, DARKGRAY);

        DrawText("Message Type: ", 10, 340, 20, DARKGRAY);
        DrawText(MessageType({binary[4], binary[5], binary[6], binary[7]}).c_str(), 500, 340, 20, DARKGRAY);

        DrawText("Transmission Time Reference Flag: ", 10, 360, 20, DARKGRAY);
        DrawText(TransmissionTimeReferenceFlag({binary[8]}).c_str(), 500, 360, 20, DARKGRAY);

        DrawText("Spare Bits: ", 10, 380, 20, DARKGRAY);
        DrawText(Spare({binary[9], binary[10], binary[11]}).c_str(), 500, 380, 20, DARKGRAY);

        DrawText("Application Protocol Version: ", 10, 400, 20, DARKGRAY);
        DrawText(ApplicationProtocolVersion({binary[12], binary[13], binary[14], binary[15]}).c_str(), 500, 400, 20, DARKGRAY);

        DrawText("Application Block Message Length: ", 10, 420, 20, DARKGRAY);
        DrawText(ApplicationBlockMessageLength({binary[16], binary[17], binary[18], binary[19], binary[20], binary[21], binary[22], binary[23], binary[24], binary[25], binary[26], binary[27], binary[28], binary[29], binary[30], binary[31]}).c_str(), 500, 420, 20, DARKGRAY);

        DrawText("JRE Sender ID: ", 10, 440, 20, DARKGRAY);
        DrawText(JreSenderID({binary[32], binary[33], binary[34], binary[35], binary[36], binary[37], binary[38], binary[39], binary[40], binary[41], binary[42], binary[43], binary[44], binary[45], binary[46], binary[47]}).c_str(), 500, 440, 20, DARKGRAY);

        DrawText("Time Accuracy Reporting: ", 10, 460, 20, DARKGRAY);
        DrawText(TimeAccuracyReporting({binary[48], binary[49], binary[50], binary[51]}).c_str(), 500, 460, 20, DARKGRAY);

        DrawText("Data Valid Time: ", 10, 480, 20, DARKGRAY);
        DrawText(DataValidTime({binary[52], binary[53], binary[54], binary[55], binary[56], binary[57], binary[58], binary[59], binary[60], binary[61], binary[62], binary[63], binary[64], binary[65], binary[66], binary[67], binary[68], binary[69], binary[70], binary[71], binary[72], binary[73], binary[74], binary[75], binary[76], binary[77], binary[78], binary[79]}).c_str(), 500, 480, 20, DARKGRAY);

        int key = GetCharPressed();

        if ((key >= 32 && key <= 125) && input.length() < 3)
        {
            input += (char)key;
            control = std::stoi(input);
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            input = "";
            control = 0;
        }
        EndDrawing();
    }
}