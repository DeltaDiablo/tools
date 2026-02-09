
#include "raylib.h"
#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include "JreapCHeads.h"


// Helper: Convert comma-separated integer string to byte array (8 bytes for JREAP-C header)
std::array<int, 8> intListToByteArray(const std::string& input) {
    std::array<int, 8> arr = {0};
    size_t idx = 0;
    size_t start = 0;
    while (idx < 8 && start < input.length()) {
        size_t end = input.find(',', start);
        std::string numStr = (end == std::string::npos) ? input.substr(start) : input.substr(start, end - start);
        arr[idx] = std::stoi(numStr);
        start = (end == std::string::npos) ? input.length() : end + 1;
        ++idx;
    }
    return arr;
}

int main() {
    // Raylib GUI input only
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "JREAP-C Header Translator");
    SetTargetFPS(60);

    char inputBuffer[256] = "49,1,0,45,0,1,80,68,253,102,0,41,17,115,0,0,0,3,8,8,74,1,112,255,31,128,32,202,133,181,110,105,14,252,255,63,5,0,0,0,0,1,67,0,0";
    std::string headerResult = "";
    bool inputChanged = true;

    while (!WindowShouldClose()) {
        if (inputChanged) {
            std::string inputStr(inputBuffer);
            auto byteArray = intListToByteArray(inputStr);
            headerResult = CommonHeaderConverter(byteArray);
            inputChanged = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Enter comma-separated array (first 8 bytes used):", 20, 20, 20, DARKGRAY);
        DrawText(inputBuffer, 20, 60, 20, BLACK);
        DrawRectangleLines(18, 58, 760, 30, GRAY);
        DrawText("JREAP-C Header Translation:", 20, 110, 20, DARKGRAY);
        DrawText(headerResult.c_str(), 20, 140, 18, BLUE);

        // Input handling
        int key = GetCharPressed();
        if (key > 0 && key != KEY_ENTER && key != KEY_BACKSPACE) {
            int len = strlen(inputBuffer);
            if (len < 255) {
                inputBuffer[len] = (char)key;
                inputBuffer[len + 1] = '\0';
                inputChanged = true;
            }
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            int len = strlen(inputBuffer);
            if (len > 0) {
                inputBuffer[len - 1] = '\0';
                inputChanged = true;
            }
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}