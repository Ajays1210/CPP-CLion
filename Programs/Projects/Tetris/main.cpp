#include "tetrisGame.h"
#include <chrono>
#include <thread>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std:: endl;

int main() {
    srand(time(0));

    bool bGameOver {false};
    //Accessing [ROW][COLUMN] = Mathematically y for height & x for width
    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            GAME_BOARD[y][x] = 0;
        }
    }
    CurrentPieceId = GetRandomPieceID();
    CopyActivePiece(CurrentPieceId);
    CurrentY = -2;
    CurrentX = (BOARD_WIDTH / 2) - 2;

    DrawScreen();

    while (!bGameOver) {
        for (int i{0}; i < 10; ++i) {
            if (_kbhit()) {
                char key = _getch();
                // Left Collision Check
                if (key == 'a' && CheckCollision(CurrentY, CurrentX - 1) == false) {
                    --CurrentX;
                }
                // Right Collision Check
                if (key == 'd' && CheckCollision(CurrentY, CurrentX + 1) == false) {
                    ++CurrentX;
                }
                if (key == 's' && CheckCollision(CurrentY + 1, CurrentX) == false) {
                    ++CurrentY;
                }
                if (key == ' ') {
                    while (CheckCollision(CurrentY + 1, CurrentX) == false) {
                        ++CurrentY;
                    }
                }
                if (key == 'w') {
                    RotatePiece();
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        // Automatic Fall and Collision Check
        int ny = CurrentY + 1;
        if (CheckCollision(ny, CurrentX) == false) {
            CurrentY = ny;
        } else {

            for (int py{0}; py < 4; ++py) {
                for (int px{0}; px < 4; ++px) {
                    if (ActivePiece[py][px] == 1) {
                        GAME_BOARD[CurrentY + py][CurrentX+ px] = 1;
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
        DrawScreen();
    }

    return 0;
}
