//
// Created by ajays on 19-10-2025.
//
// This file holds all the shared variables and function prototypes

#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <vector>

// --- Game Board Dimensions ---
constexpr int BOARD_WIDTH  = 10; // 10 columns wide
constexpr int BOARD_HEIGHT = 20; // 20 rows tall
extern int GAME_BOARD[BOARD_HEIGHT][BOARD_WIDTH]; // The actual grid where pieces are locked

// --- Timing and Speed Settings ---
constexpr long long FALL_RATE_MS    = 1000; // Time (ms) before a piece automatically falls one row
constexpr long long INPUT_REPEAT_MS = 50;   // Delay (ms) for key repetition (A/D/S)
extern long long TimeUntilNextFall;         // Countdown for the next auto-fall
extern long long TimeUntilNextMove;         // Countdown for the next repeated input movement

// --- Current Piece State ---
extern int CurrentY;              // Vertical position of the active piece (Y-coordinate)
extern int CurrentX;              // Horizontal position of the active piece (X-coordinate)
extern int CurrentPieceId;        // ID (0-6) of the piece currently being controlled
extern int RotationState;         // Current rotation state (0-3)
extern int ActivePiece[4][4];     // The 4x4 array representing the current piece's shape

// --- Next Piece, Score, and Level ---
extern int NextPieceId;           // ID of the piece coming up next
extern int Score;
extern int LinesCleared;
extern int Level;

// --- Line Clearing Flow Control ---
extern bool bLineClearing;                   // Flag: true when a line has been cleared and the game is animating/pausing
extern std::vector<int> ClearedLines;        // Stores the row indices of lines that need to be deleted

// --- Function Prototypes (What the game can do) ---
void DrawLogo();                             // Shows the title screen
void DrawScreen();                           // Redraws the entire console game board and side panel
bool CheckCollision(int n_y, int n_x);       // Checks if a piece at (n_y, n_x) conflicts with the board or walls
void RotatePiece();                          // Rotates the active piece, using Wall Kick rules
int GetRandomPieceID();                      // Gets a random piece ID (0-6)
void CopyActivePiece(int pieceID);           // Loads a new piece shape into ActivePiece
void LockPieceAndContinueGame(bool & bGameOver); // Locks the current piece, checks for line clears, and spawns next piece
void PerformLineDeletionAndScoring(bool & bGameOver); // Deletes cleared lines, scores points, and spawns the next piece

#endif // TETRISGAME_H
