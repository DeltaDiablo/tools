#include "raylib.h"
#include <iostream>
#include <array>
#include "ByteToBits.h"
#include "milstd3011/JReapCHeads.h"
#include "milstd3011/JreapLibrary.h"
#include <cmath>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    std::string input = "";
    std::string output = "";
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
        DrawText("Paste JTIDS/JREAP block or comma-separated bytes:", inputBoxX, inputBoxY - 30, 22, DARKGRAY);
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
            output = jreap::DecodeApplicationMessageCsv(input, true);


            input.clear(); // clear input only once after submit
        }
        EndDrawing();
    }
}

            