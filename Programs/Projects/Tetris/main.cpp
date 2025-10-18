#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using std::cout;
using std:: endl;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
int GAME_BOARD[BOARD_HEIGHT][BOARD_WIDTH];

int CurrentY = -2;
int CurrentX = (BOARD_WIDTH / 2) - 1;

int IPiece[4][4] {     // 1. I-Piece
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
};

bool CheckCollision(int n_y, int n_x) {
    for (int py{0}; py < 4; ++py) {
        for (int px{0}; px < 4; ++px) {
            if (IPiece[py][px] == 1) {
                if ((n_y + py) >= BOARD_HEIGHT || n_x + px >= BOARD_WIDTH || n_x + px < 0) {
                    return true;
                }
                if (n_y + py >= 0 && GAME_BOARD[n_y +py][n_x + px]) {
                    return true;
                }
            }
        }
    }
    return false;
}

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

                   if (IPiece[py][px] == 1) {
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
               //but go to is better
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
}

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
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
