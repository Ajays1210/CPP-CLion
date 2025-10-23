#include "tetrisGame.h"
#include <cstdlib>
#include <iostream>
#include <vector>

// Note: These definitions were mainly for screen alignment, but we don't use them in the C++ logic.
#define CONSOLE_WIDTH 80
#define DISPLAY_WIDTH 44

using std::cout;
using std::endl;
using std::vector;

// === GLOBAL VARIABLE DEFINITIONS ===
// These variables are declared as 'extern' in the header and defined here.
int GAME_BOARD[BOARD_HEIGHT][BOARD_WIDTH];

int CurrentY = -2; // Start pieces off the screen to give the player a buffer.
int CurrentX = (BOARD_WIDTH / 2) - 2; // Start pieces roughly centered.

int Score = 0;
int CurrentPieceId = 0;
int RotationState = 0;
int ActivePiece[4][4];
int NextPieceId = 0;
int LinesCleared = 0;
int Level = 0;
long long TimeUntilNextFall = FALL_RATE_MS;
long long TimeUntilNextMove = 0;
bool bLineClearing = false;
std::vector<int> ClearedLines;

// All the 7 standard Tetris shapes (I, J, L, O, S, T, Z) defined as 4x4 blocks.
int AllShapes[7][4][4] {
    // 0: I-Piece (Line)
    {{0,0,0,0},
     {0,0,0,0},
     {1,1,1,1},
     {0,0,0,0} },
    // 1: J-Piece
    {{0,0,0,0},
     {1,0,0,0},
     {1,1,1,0},
     {0,0,0,0} },
    // 2: L-Piece
    {{0,0,0,0},
     {0,0,1,0},
     {1,1,1,0},
     {0,0,0,0} },
    // 3: O-Piece (Square) - Does not rotate using standard methods
    {{0,0,0,0},
     {0,1,1,0},
     {0,1,1,0},
     {0,0,0,0} },
    // 4: S-Piece
    {{0,0,0,0},
     {0,1,1,0},
     {1,1,0,0},
     {0,0,0,0} },
    // 5: T-Piece
    {{0,0,0,0},
     {0,1,0,0},
     {1,1,1,0},
     {0,0,0,0} },
    // 6: Z-Piece
    {{0,0,0,0},
     {1,1,0,0},
     {0,1,1,0},
     {0,0,0,0} }
};

// These are the offset tests used for the Super Rotation System (SRS) "Wall Kick" feature.
// This allows pieces to rotate even if they are next to a wall or another block.
const int WallKickTests[5][2] = {
    {0, 0},   // Test 0: No shift (just try the rotation)
    {+1, 0},  // Test 1: Try shifting 1 unit right
    {-1, 0},  // Test 2: Try shifting 1 unit left
    {+2, 0},  // Test 3: Try shifting 2 units right (mostly for the I-Piece)
    {-2, 0}   // Test 4: Try shifting 2 units left (mostly for the I-Piece)
};

// === FUNCTION DEFINITIONS ===

/**
 * @brief Clears the console and draws the entire game state.
 * This includes the main board, the active piece, the side panel (score, next piece), and walls.
 */
void DrawScreen() {
    static int blinkCounter = 0;
    system("cls"); // Clear the console for a fresh draw

    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        cout << "<!"; // Draw the Left Wall

        // 1. DETERMINE IF CURRENT ROW IS BLINKING (for line clear animation)
        bool isBlinkingLine = false;
        if (bLineClearing) {
            for (int lineY : ClearedLines) {
                if (lineY == y) {
                    isBlinkingLine = true;
                    break;
                }
            }
        }

        // 2. INNER LOOP: DRAW COLUMNS (x-axis)
        for (int x{0}; x < BOARD_WIDTH; ++x) {

            // Priority 1: BLINKING LINE (The line disappears/reappears during animation)
            if (isBlinkingLine) {
                if (blinkCounter % 2 == 0) {
                    cout << "##"; // Blink Frame 1: Solid block
                } else {
                    cout << "  "; // Blink Frame 2: Empty space
                }
            }
            // Priority 2: LOCKED BLOCK (A piece that has landed)
            else if (GAME_BOARD[y][x] == 1) {
               cout << "[]";
            }
            // Priority 3: ACTIVE PIECE OR EMPTY SPACE
            else {
                bool isPieceBlock = false;

                // Check every block of the 4x4 active piece array
                for (int py{0}; py < 4; ++py) {
                    for (int px{0}; px < 4; ++px) {
                        if (ActivePiece[py][px] == 1) {
                           int y_on_board = CurrentY + py;
                           int x_on_board = CurrentX + px;

                           // If the active piece block is on the current board spot (y, x)
                           if (y == y_on_board && x == x_on_board) {
                               isPieceBlock = true;
                               goto end_piece_check; // Found it, jump out of the nested loops
                           }
                        }
                    }
                }
                end_piece_check:;

                if (isPieceBlock) {
                    cout << "[]"; // Draw the active piece block
                } else {
                    cout << " ."; // Draw an empty space/dot
                }
            }
        }

        // 3. RIGHT WALL AND SIDE PANEL
        cout << "!>"; // Draw the Right Wall

        // Draw the information panel to the side of the board
        if (y == 0) {
            cout << "   LINES CLEARED: " << LinesCleared;
        } else if (y == 1) {
            cout << "   LEVEL: " << Level;
        } else if (y == 2) {
            cout << "   SCORE: " << Score;
        } else if (y >= 4 && y <= 8) {
            // Draw the "Next Piece" preview
            int py = y - 4; // Adjust y to fit into the 4x4 piece array

            if (py >= 0 && py < 4) {
                cout << "      ";
                for (int px = 0; px < 4; ++px) {
                    if (AllShapes[NextPieceId][py][px] == 1) {
                        cout << "[]";
                    } else {
                        cout << "  ";
                    }
                }
            }
        }
        // Draw instructions
        else if (y == 9) {
            cout << "   INSTRUCTIONS:";
        } else if (y == 10) {
            cout << "       A: LEFT";
        } else if (y == 11) {
            cout << "       D: RIGHT";
        } else if (y == 12) {
            cout << "       W: ROTATE";
        } else if (y == 13) {
            cout << "       S: SOFT DROP";
        } else if (y == 14) {
            cout << "       SPACE: HARD DROP";
        }
        cout << endl; // End the console line (for the current row)
    }

    // 4. ANIMATION COUNTER & BOTTOM BORDER
    if (bLineClearing) {
        blinkCounter++; // Only increment during line clear animation
    }

    cout << "<!====================!>" << endl; // Bottom border
    cout << R"(  \/\/\/\/\/\/\/\/\/\/)" << endl; // Decorative base
}

/**
 * @brief Checks if the active piece collides with anything at a proposed new location (n_y, n_x).
 * @param n_y The proposed new Y position.
 * @param n_x The proposed new X position.
 * @return True if a collision occurs (wall or locked block), false otherwise.
 */
bool CheckCollision(int n_y, int n_x) {
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (ActivePiece[py][px] == 1) { // Only check if there's an actual block in the piece
                // 1. Check for wall/floor collisions
                if (n_x + px < 0 ||               // Left Wall
                    (n_y + py) >= BOARD_HEIGHT || // Floor
                    n_x + px >= BOARD_WIDTH) {    // Right Wall
                    return true;
                }

                // 2. Check for collision with an already locked block on the game board
                // We must make sure y is >= 0 before checking GAME_BOARD to prevent out-of-bounds access
                if (n_y + py >= 0 && GAME_BOARD[n_y +py][n_x + px] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief Rotates the active piece 90 degrees clockwise and applies Wall Kick tests.
 */
void RotatePiece() {
    if (CurrentPieceId == 3) {
        return; // The Square (O-Piece) doesn't need rotation
    }

    int NextRotationState = (RotationState + 1) % 4;

    int OriginalPiece[4][4];
    int TempPiece[4][4] { {0} }; // Initialize rotated shape to all zeros

    // 1. Calculate the Rotated Shape (90 degrees clockwise transformation)
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            OriginalPiece[y][x] = ActivePiece[y][x]; // Save the original shape
            if (OriginalPiece[y][x] == 1) {
                int n_py = x;     // New Y comes from old X
                int n_px = 3 - y; // New X comes from 3 - old Y

                TempPiece[n_py][n_px] = 1;
            }
        }
    }

    // 2. Temporarily apply the rotation for collision testing
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            ActivePiece[y][x] = TempPiece[y][x];
        }
    }

    // 3. Apply Wall Kick Tests
    bool bRotationSuccess = false;

    for (int i{0}; i < 5; ++i) { // Check the 5 defined kick tests
        int TestX = CurrentX + WallKickTests[i][0];
        int TestY = CurrentY + WallKickTests[i][1];

        if (CheckCollision(TestY, TestX) == false) {
            // Found a valid place!
            CurrentX = TestX;
            CurrentY = TestY;

            RotationState = NextRotationState;
            bRotationSuccess = true;
            break;
        }
    }

    // 4. Revert if all tests fail
    if (bRotationSuccess == false) {
        // Restore the Original Shape if rotation couldn't find a clear spot
        for (int y{0}; y < 4; ++y) {
            for (int x{0}; x < 4; ++x) {
                ActivePiece[y][x] = OriginalPiece[y][x];
            }
        }
    }
}

/**
 * @brief Returns a random piece ID (0 through 6).
 */
int GetRandomPieceID() {
    return rand() % 7;
}

/**
 * @brief Copies the shape data for the given pieceID into the ActivePiece array.
 */
void CopyActivePiece(const int pieceID) {
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            ActivePiece[y][x] = AllShapes[pieceID][y][x];
        }
    }
}

/**
 * @brief Locks the current piece onto the game board, checks for line clears, and spawns the next piece.
 * @param bGameOver Reference to the main game over flag.
 */
void LockPieceAndContinueGame(bool & bGameOver) {
    // 1. Lock the piece onto the GAME_BOARD
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (ActivePiece[py][px] == 1) {
                // Only write to the board if the block is on or below row 0
                if (CurrentY + py >= 0) {
                    GAME_BOARD[CurrentY + py][CurrentX + px] = 1;
                }
            }
        }
    }

    // 2. Scan for full lines to clear
    ClearedLines.clear();
    for (int y{BOARD_HEIGHT - 1}; y >= 0; --y) {
        bool bLineFull = true;

        for (int x{0}; x < BOARD_WIDTH; ++x) {
            if (GAME_BOARD[y][x] == 0) {
                bLineFull = false;
                break;
            }
        }
        if (bLineFull) {
            ClearedLines.push_back(y);
        }
    }

    // 3. Determine next step
    if (!ClearedLines.empty()) {
        bLineClearing = true; // Start the animation phase
    } else {
        // No lines cleared, so immediately spawn the next piece.
        CurrentPieceId = NextPieceId;
        CopyActivePiece(CurrentPieceId);

        NextPieceId = GetRandomPieceID();

        // Spawn position: Y=-2 for the crucial game-over buffer
        CurrentY = -2;
        CurrentX = (BOARD_WIDTH / 2) - 2;

        // Check for immediate Game Over right after spawning
        if (CheckCollision(CurrentY, CurrentX)) {
            bGameOver = true;
        }
    }
}

/**
 * @brief Deletes the lines marked for clearing, shifts the board down, updates the score, and spawns the next piece.
 * @param bGameOver Reference to the main game over flag.
 */
void PerformLineDeletionAndScoring(bool & bGameOver) {
    int lines_deleted_count = 0;

    // 1. Delete and Shift Lines
    for (int y_to_clear : ClearedLines) {
        // Shift all rows above the cleared row down by one
        for (int k{y_to_clear}; k > 0; --k ) {
            for (int x{0}; x < BOARD_WIDTH; ++x) {
                GAME_BOARD[k][x] = GAME_BOARD[k-1][x];
            }
        }

        // Make sure the top row (row 0) is now empty
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            GAME_BOARD[0][x] = 0;
        }

        lines_deleted_count++;
    }

    // 2. Scoring Update
    if (lines_deleted_count > 0) {
        // Simple scoring: 10 points per line cleared
        Score += 10 * lines_deleted_count;
        LinesCleared += lines_deleted_count;

        // --- LEVEL LOGIC IMPLEMENTATION (Lines cleared increases level, which increases speed) ---
        // Level up every 10 lines cleared.
        if (LinesCleared / 10 > Level) {
            Level = LinesCleared / 10;

            // Calculate new, faster fall rate: Base (1000ms) - (Level * 100ms)
            long long new_fall_rate = FALL_RATE_MS - (Level * 100);

            // Cap the speed to ensure it's not too fast (e.g., minimum 100ms)
            if (new_fall_rate < 100) {
                new_fall_rate = 100;
            }

            // Update the global fall timer to the new speed
            TimeUntilNextFall = new_fall_rate;
        }
    }

    // 3. Spawn the Next Piece (since line clearing is done)
    CurrentPieceId = NextPieceId;
    CopyActivePiece(CurrentPieceId);

    NextPieceId = GetRandomPieceID();

    // Spawn position: Y=-2 for the crucial game-over buffer
    CurrentY = -2;
    CurrentX = (BOARD_WIDTH / 2) - 2;

    // Final check for Game Over
    if (CheckCollision(CurrentY, CurrentX)) {
        bGameOver = true;
    }

    // 4. Reset flow control flags
    bLineClearing = false;
    ClearedLines.clear();
}

/**
 * @brief Draws the initial start screen logo and instructions.
 */
void DrawLogo() {
    cout << endl << endl << endl;
    cout << "   ======  ======  ======  ======  ======  ======" << endl;
    cout << "     ||    ||        ||    ||  ||    ||    ||" << endl;
    cout << "     ||    ======    ||    ======    ||    ======" << endl;
    cout << "     ||    ||        ||    || \\\\     ||        ||" << endl;
    cout << "     ||    ======    ||    ||  \\\\  ======  ======" << endl;
    cout << endl <<"                            MADE USING MODERN C++" << endl;
    cout << endl << endl;
    cout << "   CONTROLS:" << endl;
    cout << "       A: LEFT" << endl;
    cout << "       D: RIGHT" << endl;
    cout << "       W: ROTATE" << endl;; // Note: Double semicolon here, but it's harmless.
    cout << "       S: SOFT DROP" << endl;
    cout << "       SPACE: HARD DROP" << endl;
    cout << endl << "   PRESS ANY KEY TO START..." << endl;
}
