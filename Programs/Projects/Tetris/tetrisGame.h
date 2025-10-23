//
// Created by ajays on 19-10-2025.
//

#ifndef TETRISGAME_H
#define TETRISGAME_H

constexpr int BOARD_WIDTH = 10;
constexpr int BOARD_HEIGHT = 20;
extern int GAME_BOARD[BOARD_HEIGHT][BOARD_WIDTH];

extern int CurrentY;
extern int CurrentX;

extern int Score;
extern int CurrentPieceId;
extern int ActivePiece[4][4];
extern int RotationState;

extern int NextPieceId;
extern int LinesCleared;
extern int Level;

void DrawScreen();
bool CheckCollision(int n_y, int n_x);
void RotatePiece();
int GetRandomPieceID();
void CopyActivePiece(int pieceID);
void LockPieceAndContinueGame(bool & bGameOver);

#endif //TETRISGAME_H
