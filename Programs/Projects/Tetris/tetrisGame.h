//
// Created by ajays on 19-10-2025.
//

#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <iostream>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
extern int GAME_BOARD[20][10];

extern int CurrentY;
extern int CurrentX;

extern int IPiece[4][4];
extern int OPiece[4][4];
extern int TPiece[4][4];
extern int JPiece[4][4];
extern int LPiece[4][4];
extern int SPiece[4][4];
extern int ZPiece[4][4];

bool CheckCollision(int n_y, int n_x);
void DrawScreen();

#endif //TETRISGAME_H
