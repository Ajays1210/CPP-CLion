#include "tetrisGame.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int GAME_BOARD[BOARD_HEIGHT][BOARD_WIDTH];

int CurrentY = -2;
int CurrentX = (BOARD_WIDTH / 2) - 2;

int Score = 0;
int CurrentPieceId = 0;
int RotationState = 0;

int ActivePiece[4][4];

int AllShapes[7][4][4] {
    // 0: I-Piece
    {{0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0} },
    // 1: J-Piece
    {{1,0,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0} },
    // 2: L-Piece
    {{0,0,1,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0} },
    // 3: O-Piece (Square)
    {{0,1,1,0},
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0} },
    // 4: S-Piece
    {{0,1,1,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0} },
    // 5: T-Piece
    {{0,1,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0} },
    // 6: Z-Piece
    {{1,1,0,0},
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0} }
};

void DrawScreen() {
    system("cls");
   for (int y{0}; y < BOARD_HEIGHT; ++y) {
       cout <<"<!";

       for (int x{0}; x < BOARD_WIDTH; ++x) {
           if (GAME_BOARD[y][x] == 1) {
               cout << "[]";
               continue;
           }
           bool isPieceBlock = false;

           for (int py{0}; py < 4; ++py) {
               for (int px{0}; px < 4; ++px) {

                   if (ActivePiece[py][px] == 1) {
                       int y_on_board = CurrentY + py;
                       int x_on_board = CurrentX + px;

                       if (y == y_on_board && x == x_on_board) {
                           isPieceBlock = true;
                           //break;
                           goto end_piece_check;
                       }
                   }
               }
               // if (isPieceBlock) break; --- This will also work
               //but goto is better
           }
           end_piece_check:;
           if (isPieceBlock) {
               cout << "[]";
           } else {
               cout << " .";
           }
       }
       cout <<"!>";
       cout << endl;
   }
    cout << "<!====================!>" << endl;
    cout << R"(  \/\/\/\/\/\/\/\/\/\/)" << endl;
    cout << "Score: " << Score << endl;
}

bool CheckCollision(int n_y, int n_x) {
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (ActivePiece[py][px] == 1) {
                // Collision with the Left Wall || Collision with the Floor || Collision with the Right Wall)
                if (n_x + px < 0 || (n_y + py) >= BOARD_HEIGHT || n_x + px >= BOARD_WIDTH) {
                    return true;
                }
                if (n_y + py >= 0 && GAME_BOARD[n_y +py][n_x + px] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void RotatePiece() {
    int OriginalPiece[4][4];
    int TempPiece[4][4] {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // Backup the Original Shape
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            OriginalPiece[y][x] = ActivePiece[y][x];
        }
    }
    // Calculate the Rotated Shape
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (OriginalPiece[py][px] == 1) {
                int n_py = px;
                int n_px = 3 - py;

                TempPiece[n_py][n_px] = 1;
            }
        }
    }
    // Temporary Swap (for Collision Check)
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            ActivePiece[y][x] = TempPiece[y][x];
        }
    }
    // Check Collision and Finalize
    if (CheckCollision(CurrentY, CurrentX)) {
        for (int y{0}; y < 4; ++y) {
            for (int x{0}; x < 4; ++x) {
                 ActivePiece[y][x] = OriginalPiece[y][x];
            }
        }
    }
}

int GetRandomPieceID() {
    return rand() % 7;
}

void CopyActivePiece(const int pieceID) {
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            ActivePiece[y][x] = AllShapes[pieceID][y][x];
        }
    }
}
