#pragma once

#include <vector>
#include <random>
#include <chrono>

// Define board dimensions
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int NUM_PIECES = 7;
const long long FALL_RATE_MS = 1000; // Base fall rate in milliseconds

// Modern C++: Use enum class for type safety
enum class PieceType {
    I = 0, J, L, O, S, T, Z
};

class TetrisGame {
public:
    // --- Constructor and Public Accessors ---
    TetrisGame();
    long long getFallRate() const { return timeUntilNextFall; }
    int getScore() const { return score; }
    int getLevel() const { return level; }
    int getLinesCleared() const { return linesCleared; }
    bool isLineClearing() const { return bLineClearing; }

    // --- Core Game Loop Methods ---
    void drawScreen();
    void rotatePiece();
    bool movePiece(int dx, int dy);

    // FIX: Added the missing hardDrop declaration
    void hardDrop(bool &bGameOver);

    void lockPieceAndContinueGame(bool &bGameOver);
    void performLineDeletionAndScoring(bool &bGameOver);

private:
    // --- Game State ---
    int gameBoard[BOARD_HEIGHT][BOARD_WIDTH] {};
    int activePiece[4][4] {};

    // Current piece position and rotation
    int currentX = (BOARD_WIDTH / 2) - 2;
    int currentY = -2;
    int rotationState = 0; // 0, 1, 2, 3

    PieceType currentPieceId;
    PieceType nextPieceId;

    // Scoring and Level
    int score = 0;
    int level = 0;
    int linesCleared = 0;
    long long timeUntilNextFall = FALL_RATE_MS;
    bool bLineClearing = false;

    // STL containers for line clearing and randomizer
    std::vector<int> clearedLines;
    std::vector<PieceType> pieceBag; // 7-Bag randomizer

    // Modern C++: Random number generator engine
    std::mt19937 randomEngine;

    // --- Static Piece Data ---
    static const int AllShapes[NUM_PIECES][4][4];
    static const int WallKickTests[5][2];

    // --- Private Helper Methods ---
    bool checkCollision(int n_y, int n_x);
    void copyActivePiece(const PieceType pieceID);
    PieceType getRandomPieceID();
    void shuffleBag();
};
