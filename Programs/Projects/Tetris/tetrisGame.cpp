#include "tetrisGame.h"
#include <cstdlib>
#include <iostream>

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
    // 3: O-Piece (Square)
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

const int WallKickTests[5][2] = {
    {0, 0},   // Test 0: No shift
    {+1, 0},  // Test 1: Right 1
    {-1, 0},  // Test 2: Left 1
    {+2, 0},  // Test 3: Right 2 (for I-Piece edge cases)
    {-2, 0}   // Test 4: Left 2 (for I-Piece edge cases)
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
    cout << "\nScore: " << Score << endl;
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
    if (CurrentPieceId == 3) {
        return;
    }

    int NextRotationState = (RotationState + 1) % 4;

    int OriginalPiece[4][4];
    int TempPiece[4][4] {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    // Backup the Original Shape and calculate the Rotated Shape into TempPiece
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            OriginalPiece[y][x] = ActivePiece[y][x];
            if (OriginalPiece[y][x] == 1) {
                int n_py = x;
                int n_px = 3 - y;

                TempPiece[n_py][n_px] = 1;
            }
        }
    }
    // Temporarily swap TempPiece into ActivePiece for collision testing
    for (int y{0}; y < 4; ++y) {
        for (int x{0}; x < 4; ++x) {
            ActivePiece[y][x] = TempPiece[y][x];
        }
    }
    // Check Collision and Finalize
    bool bRotationSuccess = false;

    for (int i{0}; i < 5; ++i) {
        int TestX = CurrentX + WallKickTests[i][0];
        int TestY = CurrentY + WallKickTests[i][1];

        if (CheckCollision(TestY, TestX) == false) {
            CurrentX = TestX;
            CurrentY = TestY;

            RotationState = NextRotationState;
            bRotationSuccess = true;
            break;
        }
    }
    if (bRotationSuccess == false) {
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

void LockPieceAndContinueGame(bool & bGameOver) {
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (ActivePiece[py][px] == 1) {
                if (CurrentY + py >= 0) {
                    GAME_BOARD[CurrentY + py][CurrentX + px] = 1;
                }
            }
        }
    }
    // Line Clearing Logic
    for (int y{BOARD_HEIGHT - 1}; y >= 0; --y) {
        bool bLineFull = true;
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            if (GAME_BOARD[y][x] == 0) {
                bLineFull = false;
                break;
            }
        }
        if (bLineFull) {
            for (int k{y}; k > 0; --k ) {
                for (int x{0}; x < BOARD_WIDTH; ++x) {
                    GAME_BOARD[k][x] = GAME_BOARD[k-1][x];
                }
            }
            for (int x{0}; x < BOARD_WIDTH; ++x) {
                GAME_BOARD[0][x] = 0;
            }
            Score += 10;
            ++y;
        }
    }
    CurrentPieceId = GetRandomPieceID();
    CopyActivePiece(CurrentPieceId);

    CurrentY = -2;
    CurrentX = (BOARD_WIDTH / 2) - 2;

    if (CheckCollision(CurrentY, CurrentX)) {
        bGameOver = true;
    }
}