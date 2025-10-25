#include "tetrisGame.h"
#include <iostream>
#include <chrono>       // For game timing
#include <thread>       // For sleep function
#include <conio.h>      // For _kbhit() and _getch() (non-blocking console input)

using namespace std::chrono_literals; // Enables the use of 100ms, 10ms, etc.
using std::cout;
using std::endl;

/**
 * @brief The main function runs the Tetris game loop.
 * It handles input, game timing (fall rate), drawing, and game state transitions.
 */
int main() {
    // Instantiate the TetrisGame object, demonstrating Object-Oriented approach (OOP)
    TetrisGame game;
    bool bGameOver = false;

    // Use C++ <chrono> for high-resolution timing
    auto last_fall_time = std::chrono::steady_clock::now();

    // Set up initial draw before the loop starts
    game.drawScreen();

    while (!bGameOver) {

        // --- 1. HANDLE USER INPUT ---
        if (_kbhit()) {
            // Read the character without blocking the thread
            char input = _getch();

            switch (tolower(input)) {
                case 'a': // Move Left
                    game.movePiece(-1, 0);
                    break;
                case 'd': // Move Right
                    game.movePiece(1, 0);
                    break;
                case 's': // Soft Drop (Move Down Faster)
                    // Allows the piece to move down one step instantly
                    if (!game.movePiece(0, 1)) {
                        // If soft drop collides, lock the piece immediately
                        game.lockPieceAndContinueGame(bGameOver);
                    }
                    break;
                case 'w': // Rotate Piece
                    game.rotatePiece();
                    break;
                case ' ': // Hard Drop (Instantly drops and locks the piece)
                    // Calls the new hardDrop logic
                    game.hardDrop(bGameOver);
                    break;
                case 'q': // Quit Game
                    bGameOver = true;
                    break;
            }
        }

        // --- 2. HANDLE AUTOMATIC FALL / GAME TIMING ---
        auto now = std::chrono::steady_clock::now();
        // Calculate the time elapsed since the last automatic fall
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_fall_time);

        // Check if enough time has passed based on the current level's fall rate
        if (elapsed.count() >= game.getFallRate()) {

            // Attempt to move the piece down by one unit
            if (!game.movePiece(0, 1)) {
                // If the move failed (collision at the bottom/with another block)
                game.lockPieceAndContinueGame(bGameOver);
            }
            last_fall_time = now; // Reset the fall timer
        }

        // --- 3. HANDLE LINE CLEARING AND ANIMATION ---
        if (game.isLineClearing()) {
            // Pause execution briefly (150ms) to show the line blinking animation
            std::this_thread::sleep_for(150ms);
            // Perform the deletion, shifting, and score update
            game.performLineDeletionAndScoring(bGameOver);
        }

        // --- 4. REDRAW SCREEN ---
        // Redraw the screen after input, movement, or game state changes
        game.drawScreen();

        // Pause briefly to keep the loop rate smooth and CPU usage low (approx 100 FPS cap)
        std::this_thread::sleep_for(10ms);
    } // End of game loop

    // --- GAME OVER SEQUENCE ---
    system("cls");
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "!!!       G A M E   O V E R       !!!" << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "Final Score: " << game.getScore() << endl;
    cout << "Lines Cleared: " << game.getLinesCleared() << endl;
    cout << "Final Level: " << game.getLevel() << endl;

    // Wait for user confirmation before closing the console
    cout << "\nPress any key to exit...";
    _getch();

    return 0;
}
