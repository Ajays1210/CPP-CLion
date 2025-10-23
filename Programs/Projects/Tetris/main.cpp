#include "tetrisGame.h"
#include <chrono>
#include <thread>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std:: endl;
using Clock = std::chrono::high_resolution_clock;

int main() {
    srand(time(0));

    bool bGameStarted {false};
    bool bGameOver {false};
    //Accessing [ROW][COLUMN] = Mathematically y for height & x for width
    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            GAME_BOARD[y][x] = 0;
        }
    }
    CurrentPieceId = GetRandomPieceID();
    CopyActivePiece(CurrentPieceId);
    NextPieceId = GetRandomPieceID();

    CurrentY = 0;
    CurrentX = (BOARD_WIDTH / 2) - 2;

    DrawScreen();

    while (!bGameStarted) {
        system("cls");
        cout << endl << endl << endl;
        cout << "           T E T R I S" << endl;
        cout << "           R25 - C++ Console" << endl;
        cout << endl << endl;

        cout << "   Controls: A/D/S (Move), W (Rotate), SPACE (Drop)" << endl;
        cout << endl << "           P R E S S   A N Y   K E Y   T O   S T A R T. . ." << endl;

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
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
        // Automatic Fall and Collision Check
        int ny = CurrentY + 1;
        if (CheckCollision(ny, CurrentX) == false) {
            CurrentY = ny;
        } else {
            LockPieceAndContinueGame(bGameOver);
        }
        DrawScreen();
    }
    cout << endl << "  G A M E   O V E R !" << endl;
    cout << "  Final Score: " << Score << endl;

    cout << "  Press any key to exit...";
    _getch();
    return 0;
}
