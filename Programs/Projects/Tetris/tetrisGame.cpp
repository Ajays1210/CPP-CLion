#include "tetrisGame.h"
#include <cstdlib>      // For system("cls")
#include <iostream>     // For console output
#include <cstring>      // For memcpy (efficient array copy)
#include <algorithm>    // For std::all_of, std::find, std::copy

using std::cout;
using std::endl;
using std::vector;

// --- Static Data Definitions (Defined once for the class) ---

const int TetrisGame::AllShapes[NUM_PIECES][4][4] {
    // PieceType::I (0)
    {{0,0,0,0}, {0,0,0,0}, {1,1,1,1}, {0,0,0,0} },
    // PieceType::J (1)
    {{0,0,0,0}, {1,0,0,0}, {1,1,1,0}, {0,0,0,0} },
    // PieceType::L (2)
    {{0,0,0,0}, {0,0,1,0}, {1,1,1,0}, {0,0,0,0} },
    // PieceType::O (3)
    {{0,0,0,0}, {0,1,1,0}, {0,1,1,0}, {0,0,0,0} },
    // PieceType::S (4)
    {{0,0,0,0}, {0,1,1,0}, {1,1,0,0}, {0,0,0,0} },
    // PieceType::T (5)
    {{0,0,0,0}, {0,1,0,0}, {1,1,1,0}, {0,0,0,0} },
    // PieceType::Z (6)
    {{0,0,0,0}, {1,1,0,0}, {0,1,1,0}, {0,0,0,0} }
};

// Standard Super Rotation System (SRS) Wall Kick Tests (simple subset)
const int TetrisGame::WallKickTests[5][2] = {
    {0, 0}, {+1, 0}, {-1, 0}, {+2, 0}, {-2, 0}
};

// --- Constructor (RAII Principle for Randomness) ---
/**
 * @brief Initializes the game board and sets up the random number generator.
 */
TetrisGame::TetrisGame() {
    // MODERN C++: Use std::random_device for a non-deterministic seed (RAII).
    std::random_device rd;
    randomEngine.seed(rd());

    // Initialize the game board to all zeros
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        // STL: Use std::fill for clean array initialization.
        std::fill(gameBoard[y], gameBoard[y] + BOARD_WIDTH, 0);
    }

    // Initial piece spawn setup
    nextPieceId = getRandomPieceID();
    currentPieceId = getRandomPieceID();
    copyActivePiece(currentPieceId);
}

// --- Private Helper Methods Implementation ---

/**
 * @brief Shuffles the piece ID integers in the PieceBag using a modern, reliable engine.
 * Demonstrates use of C++ <random> and std::shuffle.
 */
void TetrisGame::shuffleBag() {
    // MODERN C++: Use std::shuffle with the member random engine (std::mt19937)
    std::shuffle(pieceBag.begin(), pieceBag.end(), randomEngine);
}

/**
 * @brief Returns the next piece ID using the 7-Bag Randomizer system.
 */
PieceType TetrisGame::getRandomPieceID() {
    if (pieceBag.empty()) {
        // Fill the bag with all 7 PieceType enums (7-Bag system)
        pieceBag.push_back(PieceType::I);
        pieceBag.push_back(PieceType::J);
        pieceBag.push_back(PieceType::L);
        pieceBag.push_back(PieceType::O);
        pieceBag.push_back(PieceType::S);
        pieceBag.push_back(PieceType::T);
        pieceBag.push_back(PieceType::Z);
        shuffleBag();
    }

    PieceType nextId = pieceBag.back();
    pieceBag.pop_back();
    return nextId;
}

/**
 * @brief Copies the shape data for the given pieceID into the activePiece array.
 */
void TetrisGame::copyActivePiece(const PieceType pieceID) {
    // Convert enum class back to int index for array access
    int index = static_cast<int>(pieceID);
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            activePiece[y][x] = AllShapes[index][y][x];
        }
    }
    rotationState = 0; // Reset rotation state on new piece spawn
}

// === Public Methods Implementation ===

/**
 * @brief Clears the console and draws the entire game state.
 */
void TetrisGame::drawScreen() {
    // Static counter for line-clearing blink animation
    // Static variables persist across function calls, essential for animation state.
    static int blinkCounter = 0;
    system("cls"); // Clears the command line screen (Windows specific)

    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        cout << "<!";

        // Check if the current row is marked for blinking/clearing
        bool isBlinkingLine = false;
        if (bLineClearing) {
            // STL: std::find checks for existence of 'y' in the clearedLines vector
            isBlinkingLine = std::find(clearedLines.begin(), clearedLines.end(), y) != clearedLines.end();
        }

        for (int x{0}; x < BOARD_WIDTH; ++x) {

            // Priority 1: LINE BLINK ANIMATION
            if (isBlinkingLine) {
                // Blink effect: On the "on" frame (even counter), show a solid hash block '##'.
                // The '##' is repeated for every block across the line, forming the visual hash line.
                cout << (blinkCounter % 2 == 0 ? "##" : "  ");
            }
            // Priority 2: LOCKED BLOCK
            else if (gameBoard[y][x] == 1) {
               cout << "[]";
            }
            // Priority 3: ACTIVE PIECE OR EMPTY SPACE
            else {
                bool isPieceBlock = false;

                // Check if the active piece occupies this spot
                for (int py{0}; py < 4; ++py) {
                    for (int px{0}; px < 4; ++px) {
                        if (activePiece[py][px] == 1) {
                           int y_on_board = currentY + py;
                           int x_on_board = currentX + px;

                           if (y == y_on_board && x == x_on_board) {
                               isPieceBlock = true;
                               break; // Break inner (px) loop
                           }
                        }
                    }
                    if (isPieceBlock) break; // Break outer (py) loop
                }

                if (isPieceBlock) {
                    cout << "[]";
                } else {
                    cout << " .";
                }
            }
        }

        // 3. RIGHT WALL AND SIDE PANEL
        cout << "!>";

        // Draw the information panel to the side of the board
        int nextIdIndex = static_cast<int>(nextPieceId);

        if (y == 0) {
            cout << "   LINES CLEARED: " << linesCleared;
        } else if (y == 1) {
            cout << "   LEVEL: " << level;
        } else if (y == 2) {
            cout << "   SCORE: " << score;
        } else if (y >= 4 && y <= 8) {
            // Draw the "Next Piece" preview
            int py = y - 4;

            if (py >= 0 && py < 4) {
                cout << "      ";
                for (int px = 0; px < 4; ++px) {
                    if (AllShapes[nextIdIndex][py][px] == 1) {
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
        cout << endl;
    }

    // Increment the counter only when line clearing is active
    if (bLineClearing) {
        blinkCounter++;
    }

    cout << "<!====================!>" << endl;
    cout << R"(  \/\/\/\/\/\/\/\/\/\/)" << endl;
}

/**
 * @brief Checks if the active piece collides with anything at a proposed new location (n_y, n_x).
 */
bool TetrisGame::checkCollision(int n_y, int n_x) {
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (activePiece[py][px] == 1) {
                // 1. Check for wall/floor collisions
                if (n_x + px < 0 ||
                    (n_y + py) >= BOARD_HEIGHT ||
                    n_x + px >= BOARD_WIDTH) {
                    return true;
                }
                // 2. Check for collision with an already locked block on the game board
                // Only check board if block is on screen (y >= 0)
                if (n_y + py >= 0 && n_y + py < BOARD_HEIGHT && gameBoard[n_y +py][n_x + px] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief Moves the current piece by the given delta (dx, dy).
 * @param dx Change in X position (e.g., -1 for left).
 * @param dy Change in Y position (e.g., +1 for down).
 * @return True if the move was successful, false if a collision occurred.
 */
bool TetrisGame::movePiece(int dx, int dy) {
    int n_x = currentX + dx;
    int n_y = currentY + dy;

    if (!checkCollision(n_y, n_x)) {
        currentX = n_x;
        currentY = n_y;
        return true;
    }
    return false;
}

/**
 * @brief Instantly drops the current piece to the lowest possible position and locks it.
 */
void TetrisGame::hardDrop(bool &bGameOver) {
    // Move the piece down repeatedly until a collision is detected.
    while (movePiece(0, 1)) {
        // The piece is successfully moved down one step.
    }

    // Once movePiece returns false (collision), lock the piece into the board.
    lockPieceAndContinueGame(bGameOver);
}

/**
 * @brief Rotates the active piece 90 degrees clockwise and applies Wall Kick tests.
 */
void TetrisGame::rotatePiece() {
    // O-Piece (PieceType::O) is static and does not rotate.
    if (currentPieceId == PieceType::O) {
        return;
    }

    int nextRotationState = (rotationState + 1) % 4;

    int originalPiece[4][4];
    int tempPiece[4][4] { {0} };

    // 1. Calculate the Rotated Shape
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            originalPiece[y][x] = activePiece[y][x];
            if (originalPiece[y][x] == 1) {
                int n_py = x;
                int n_px = 3 - y;
                tempPiece[n_py][n_px] = 1;
            }
        }
    }

    // 2. Temporarily apply the rotation for collision testing
    // Use C-style array copy (memcpy) for efficient, fixed-size 2D array replacement
    memcpy(activePiece, tempPiece, sizeof(activePiece));

    // 3. Apply Wall Kick Tests (Super Rotation System - SRS)
    bool bRotationSuccess = false;
    for (int i{0}; i < 5; ++i) {
        int TestX = currentX + WallKickTests[i][0];
        int TestY = currentY + WallKickTests[i][1];

        if (checkCollision(TestY, TestX) == false) {
            currentX = TestX;
            currentY = TestY;
            rotationState = nextRotationState;
            bRotationSuccess = true;
            break;
        }
    }

    // 4. Revert if all tests fail
    if (bRotationSuccess == false) {
        // Revert to original piece shape
        memcpy(activePiece, originalPiece, sizeof(originalPiece));
    }
}

/**
 * @brief Locks the current piece onto the game board, checks for line clears, and spawns the next piece.
 */
void TetrisGame::lockPieceAndContinueGame(bool & bGameOver) {
    // 1. Lock the piece onto the gameBoard
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (activePiece[py][px] == 1) {
                // Only lock blocks that are visible on the main board (Y >= 0)
                if (currentY + py >= 0 && currentY + py < BOARD_HEIGHT) {
                    gameBoard[currentY + py][currentX + px] = 1;
                }
            }
        }
    }

    // 2. Scan for full lines to clear
    clearedLines.clear();
    for (int y{BOARD_HEIGHT - 1}; y >= 0; --y) {
        // MODERN C++: std::all_of checks if every block in the row is 1 (filled).
        if (std::all_of(gameBoard[y], gameBoard[y] + BOARD_WIDTH, [](int block){ return block == 1; })) {
            clearedLines.push_back(y);
        }
    }

    // 3. Determine next step
    if (!clearedLines.empty()) {
        // Set the flag to true to start the blinking animation
        bLineClearing = true;
    } else {
        // No lines cleared, spawn the next piece.
        currentPieceId = nextPieceId;
        copyActivePiece(currentPieceId);

        nextPieceId = getRandomPieceID();

        currentY = -2;
        currentX = (BOARD_WIDTH / 2) - 2;

        // Final check for Game Over
        if (checkCollision(currentY, currentX)) {
            bGameOver = true;
        }
    }
}

/**
 * @brief Deletes the lines marked for clearing, shifts the board down, updates the score, and spawns the next piece.
 */
void TetrisGame::performLineDeletionAndScoring(bool & bGameOver) {
    const int lines_cleared_count = clearedLines.size();
    int target_row = BOARD_HEIGHT - 1;

    // 1. Delete and Shift Lines (Two-pointer approach for robust, multi-line clearing)
    for (int source_row = BOARD_HEIGHT - 1; source_row >= 0; --source_row) {
        // STL: Check if the current row is marked for clearing.
        const bool is_full = std::find(clearedLines.begin(), clearedLines.end(), source_row) != clearedLines.end();

        if (!is_full) {
            // This is a partial line. Copy it down to the target_row.
            // STL: Use std::copy to move the entire row of data efficiently.
            std::copy(gameBoard[source_row], gameBoard[source_row] + BOARD_WIDTH, gameBoard[target_row]);
            target_row--;
        }
        // If it is a full line, we skip it (deleting it) and target_row remains the same.
    }

    // Fill the empty rows created at the top (from row 0 up to target_row) with zeros.
    while (target_row >= 0) {
        // STL: Use std::fill to zero out the entire row efficiently.
        std::fill(gameBoard[target_row], gameBoard[target_row] + BOARD_WIDTH, 0);
        target_row--;
    }


    // 2. Scoring Update
    if (lines_cleared_count > 0) {
        // Simple scoring: 10 points per line cleared
        score += 10 * lines_cleared_count;
        linesCleared += lines_cleared_count;

        // --- LEVEL LOGIC IMPLEMENTATION ---
        if (linesCleared / 10 > level) {
            level = linesCleared / 10;
            // Use 'auto' for cleaner type deduction
            auto new_fall_rate = FALL_RATE_MS - (level * 100);

            if (new_fall_rate < 100) {
                new_fall_rate = 100;
            }

            timeUntilNextFall = new_fall_rate;
        }
    }

    // 3. Spawn the Next Piece
    currentPieceId = nextPieceId;
    copyActivePiece(currentPieceId);

    nextPieceId = getRandomPieceID();

    currentY = -2;
    currentX = (BOARD_WIDTH / 2) - 2;

    if (checkCollision(currentY, currentX)) {
        bGameOver = true;
    }

    // 4. Reset flow control flags
    bLineClearing = false;
    clearedLines.clear();
}
