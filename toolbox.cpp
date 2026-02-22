#include "raylib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "milstd3011/jreaplib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    std::string input = "";
    std::string output = "";
    int jSeriesScrollLines = 0;
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

        // Draw compact output layout: AH.0 on the left, ABML on the right, J-Series below
        if (!output.empty()) {
            DrawText("Message Translation:", 10, inputBoxY + inputBoxH + 20, 22, DARKGRAY);

            std::vector<std::string> lines;
            size_t start = 0;
            while (start <= output.length()) {
                size_t end = output.find('\n', start);
                if (end == std::string::npos) {
                    lines.push_back(output.substr(start));
                    break;
                }
                lines.push_back(output.substr(start, end - start));
                start = end + 1;
            }

            auto findLineIndex = [&](const std::string& key) -> int {
                for (size_t i = 0; i < lines.size(); ++i) {
                    if (lines[i].find(key) != std::string::npos) {
                        return static_cast<int>(i);
                    }
                }
                return -1;
            };

            const int ahIndex = findLineIndex("Application Header (AH.0)");
            const int fstbhIndex = findLineIndex("FSTBH.A.NC.0");
            const int fsmghIndex = findLineIndex("Full Stack Message Group Header (FSMGH.3)");
            const int abmlIndex = findLineIndex("ABML consistency");
            const int fsConsistencyIndex = findLineIndex("Full Stack consistency");
            const int dispatchIndex = findLineIndex("Dispatch by Message Type");

            int headerIndex = -1;
            if (ahIndex >= 0) headerIndex = ahIndex;
            else if (fstbhIndex >= 0) headerIndex = fstbhIndex;
            else headerIndex = fsmghIndex;
            const int validationIndex = (abmlIndex >= 0) ? abmlIndex : fsConsistencyIndex;

            const bool hasStructuredSections =
                (headerIndex >= 0) && (validationIndex > headerIndex) && (dispatchIndex > validationIndex);

            const int contentTop = inputBoxY + inputBoxH + 50;
            const int outputFontSize = 18;
            const int lineSpacing = 22;

            auto drawLines = [&](const std::vector<std::string>& source, int x, int y, Color color) -> int {
                int currentY = y;
                for (const std::string& line : source) {
                    if (!line.empty()) {
                        DrawText(line.c_str(), x, currentY, outputFontSize, color);
                    }
                    currentY += lineSpacing;
                }
                return currentY;
            };

            if (hasStructuredSections) {
                std::vector<std::string> headerLines(lines.begin() + headerIndex, lines.begin() + validationIndex);
                std::vector<std::string> abmlLines(lines.begin() + validationIndex, lines.begin() + dispatchIndex);
                std::vector<std::string> jSeriesLines(lines.begin() + dispatchIndex, lines.end());

                const int sidePadding = 10;
                const int sectionGap = 40;
                const int availableWidth = GetScreenWidth() - (sidePadding * 2);
                const int columnWidth = (availableWidth - sectionGap) / 2;
                const int leftX = sidePadding;
                const int rightX = sidePadding + columnWidth + sectionGap;

                int leftBottom = drawLines(headerLines, leftX, contentTop, BLUE);
                int rightBottom = drawLines(abmlLines, rightX, contentTop, DARKBLUE);

                const int jSeriesTop = std::max(leftBottom, rightBottom) + 12;
                const int viewportBottom = GetScreenHeight() - 12;
                const int viewportHeight = std::max(0, viewportBottom - jSeriesTop);
                const int visibleLines = std::max(1, viewportHeight / lineSpacing);
                const int maxScrollLines = std::max(0, static_cast<int>(jSeriesLines.size()) - visibleLines);

                const float wheelMove = GetMouseWheelMove();
                if (wheelMove != 0.0f) {
                    jSeriesScrollLines -= static_cast<int>(wheelMove);
                    if (jSeriesScrollLines < 0) jSeriesScrollLines = 0;
                    if (jSeriesScrollLines > maxScrollLines) jSeriesScrollLines = maxScrollLines;
                }

                if (viewportHeight > 0) {
                    BeginScissorMode(leftX, jSeriesTop, availableWidth, viewportHeight);
                    int currentY = jSeriesTop;
                    for (int i = jSeriesScrollLines; i < static_cast<int>(jSeriesLines.size()); ++i) {
                        if (currentY > viewportBottom - lineSpacing) break;
                        if (!jSeriesLines[static_cast<size_t>(i)].empty()) {
                            DrawText(jSeriesLines[static_cast<size_t>(i)].c_str(), leftX, currentY, outputFontSize, MAROON);
                        }
                        currentY += lineSpacing;
                    }
                    EndScissorMode();

                    if (maxScrollLines > 0) {
                        DrawText("Mouse wheel: scroll J-Series details", leftX, viewportBottom - 18, 16, DARKGRAY);
                    }
                }
            } else {
                jSeriesScrollLines = 0;
                drawLines(lines, 10, contentTop, BLUE);
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
            jSeriesScrollLines = 0;


            input.clear(); // clear input only once after submit
        }
        EndDrawing();
    }
}

            