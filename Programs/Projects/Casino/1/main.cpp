#include <iostream>
#include <ctime>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int secretNum {0}, guess {0}, totalAmt {500}, bet {0};
    char playAgain;

    srand(time(0));

    cout << "Welcome to the Casino number guessing game!" << endl;
    do {
        cout << "You have: $" << totalAmt << endl;

        do {
            cout << "Enter the bet amount: ";
            cin >> bet;

            if (bet <= 0 || bet > totalAmt) {
                cout << "Invalid bet amount!. Please enter again" << endl;
            }
        }while (bet <= 0 || bet > totalAmt);

        secretNum = rand() % 10 + 1;
        do {
            cout << "Make a guess from 1 to 10: ";
            cin >> guess;

            if (guess < 1 || guess > 10) {
                cout << "Out of range!. Please enter valid number" << endl;
            }
        }while (guess < 1 || guess > 10);

        if (guess == secretNum) {
            cout << "You won!" << endl;
            cout << "Secret number is: " << secretNum << endl;
            if (totalAmt + bet > 500) {
                cout << "Max balance reached!"  << endl;
                totalAmt = 500;
            } else {
                totalAmt += bet;
                cout << "Amount won! Balance is: " << totalAmt << endl;
            }
        } else if (guess > secretNum) {
            cout << "Too High!" << endl;
            totalAmt -= bet;
            cout << "Amount lost! Balance is: " << totalAmt << endl;
        } else {
            cout << "Too low!" << endl;
            totalAmt -= bet;
            cout << "Amount lost! Balance is: " << totalAmt << endl;
        }
        if (totalAmt > 0) {
            cout << "Wanna play again (Y/N)? ";
            cin >> playAgain;
        } else {
            cout << "Game Over!" << endl;
            playAgain = 'N';
        }
    }while ((playAgain == 'Y' || playAgain == 'y') && totalAmt > 0 );

    cout << "Thank you for playing!";
    return 0;
}