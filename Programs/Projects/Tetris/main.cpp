#include "tetrisGame.h"
#include <chrono>
#include <thread>
#include <conio.h>

using std::cout;
using std:: endl;

int main() {
    bool bGameOver {false};
    //Accessing [ROW][COLUMN] = Mathematically y for height & x for width
    for (int y{0}; y < BOARD_HEIGHT; ++y) {
        for (int x{0}; x < BOARD_WIDTH; ++x) {
            GAME_BOARD[y][x] = 0;
        }
    }
    DrawScreen();

    while (!bGameOver) {
        for (int i{0}; i < 10; ++i) {
            if (_kbhit()) {
                char key = _getch();

                if (key == 'a' && CheckCollision(CurrentY, CurrentX - 1) == false) {
                    --CurrentX;
                }
                if (key == 'd' && CheckCollision(CurrentY, CurrentX + 1) == false) {
                    ++CurrentX;
                }
                if (key == 's' && CheckCollision(CurrentY + 1, CurrentX) == false) {
                    ++CurrentY;
                }
                if (key == 'w') {
                    while (CheckCollision(CurrentY + 1, CurrentX) == false) {
                        ++CurrentY;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        int ny = CurrentY + 1;
        if (CheckCollision(ny, CurrentX) == false) {
            CurrentY = ny;

        } else {
            for (int py{0}; py < 4; ++py) {
                for (int px{0}; px < 4; ++px) {
                    if (IPiece[py][px] == 1) {
                        GAME_BOARD[CurrentY + py][CurrentX+ px] = 1;
                    }
                }
            }
            CurrentY = -2;
            CurrentX = (BOARD_WIDTH / 2) - 1;

            if (CheckCollision(CurrentY, CurrentX)) {
                bGameOver = true;
            }
        }
        DrawScreen();
    }

    return 0;
}
