#include "tetrisGame.h"
#include <chrono>
#include <thread>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using Clock = std::chrono::high_resolution_clock;

int main() {
    // Seed the random number generator using the current time, so we get different pieces each run.
    srand(time(0));

    bool bGameStarted {false};
    bool bGameOver {false};

    // --- Game Initialization ---
    // Clear the entire board to start (0 means empty).
    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            GAME_BOARD[y][x] = 0;
        }
    }

    // Set up the first two pieces.
    CurrentPieceId = GetRandomPieceID();
    CopyActivePiece(CurrentPieceId);
    NextPieceId = GetRandomPieceID();

    // Spawn the piece: -2 gives us a crucial buffer of two rows above the visible board.
    // This prevents a Game Over immediately when the stack reaches the top visible row (y=0).
    CurrentY = -2;
    CurrentX = (BOARD_WIDTH / 2) - 2;

    // --- Pre-Game Loop (Logo Screen) ---
    while (!bGameStarted) {
        system("cls");
        DrawLogo(); // Display the title and instructions

        if (_kbhit()) {
            _getch(); // Read the key press
            bGameStarted = true;
        }
        // Give the CPU a break so it doesn't run at 100% just to wait for a keypress.
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // --- Main Game Loop Setup ---
    DrawScreen();
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Short pause before starting
    auto startTime = Clock::now(); // Start the game clock

    // --- Main Game Loop ---
    while (!bGameOver) {
        // 1. Handle Line Clearing Animation
        // If a line was cleared in the previous frame, we pause the game for a moment to
        // show the blink animation before actually deleting the lines.
        if (bLineClearing) {
            for (int i = 0; i < 4; ++i) {
                DrawScreen();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            PerformLineDeletionAndScoring(bGameOver);
            continue; // Skip the rest of the loop to immediately check for the next frame
        }

        // 2. Calculate Delta Time (Time passed since the last frame)
        auto currentTime = Clock::now();
        // Calculate milliseconds passed since the last loop iteration
        long long deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
        startTime = currentTime; // Reset the clock for the next frame

        // Update the input timer to control how fast keys can repeat.
        TimeUntilNextMove -= deltaTime;

        // 3. Handle User Input
        if (_kbhit()) {
            char key = _getch();

            if (key == ' ' || key == 'w') {
                if (key == ' ') {
                    // Hard Drop: Move the piece down instantly until collision.
                    while (CheckCollision(CurrentY + 1, CurrentX) == false) {
                        ++CurrentY;
                    }
                    DrawScreen(); // Draw the dropped piece immediately
                    LockPieceAndContinueGame(bGameOver); // Lock the piece and spawn the next
                }
                if (key == 'w') {
                    // Rotate the piece if possible (W key)
                    RotatePiece();
                }
            }
            else if (TimeUntilNextMove <= 0) {
                // Handle Left, Right, Soft Drop
                bool moved = false;
                if (key == 'a' && CheckCollision(CurrentY, CurrentX - 1) == false) {
                    --CurrentX; moved = true;
                } else if (key == 'd' && CheckCollision(CurrentY, CurrentX + 1) == false) {
                    ++CurrentX; moved = true;
                } else if (key == 's' && CheckCollision(CurrentY + 1, CurrentX) == false) {
                    ++CurrentY; moved = true;
                }

                if (moved) {
                    // Reset the repeat timer if a successful move was made.
                    TimeUntilNextMove = INPUT_REPEAT_MS;
                }
            }
        }

        // 4. Automatic Fall Logic
        TimeUntilNextFall -= deltaTime;

        if (TimeUntilNextFall <= 0) {
            int ny = CurrentY + 1; // Try to move down one row

            if (CheckCollision(ny, CurrentX) == false) {
                CurrentY = ny; // Move is safe, update position
            } else {
                // Collision detected: lock the piece and check for line clears/game over.
                LockPieceAndContinueGame(bGameOver);
            }
            TimeUntilNextFall = FALL_RATE_MS; // Reset the fall timer
        }

        // 5. Draw and Throttle CPU Usage
        DrawScreen();
        // Small sleep to prevent the loop from consuming 100% CPU when waiting for input/time.
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    // --- Game Over Screen ---
    cout << endl << "  G A M E   O V E R !" << endl;
    cout << "  Final Score: " << Score << endl;

    cout << "  Press any key to exit...";
    _getch();
    return 0;
}