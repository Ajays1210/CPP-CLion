#include <iostream>
#include <ctime>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int getValidBet(int totalMoney) {
    int bet;
    cout << "Available balance: "  << totalMoney << endl;
    do {
        cout << "Enter the bet amount: ";
        cin >> bet;
        if (bet > totalMoney || bet <= 0) {
            cout << "Invalid input! Try again" << endl;
        }
    }while (bet > totalMoney || bet <= 0);
    return bet;
}

int getValidGuess() {
    int guess;
    do {
        cout << "Enter the guess: ";
        cin >>guess;
        if (guess < 1 || guess > 10) {
            cout << "Invalid input! Please enter b/w 1 and 10" << endl;
        }
    }while (guess < 1 || guess > 10);

    return guess;
}

void playRound(int &totalMoney, int bet, int guess) {
    int secretNumber {rand() % 10 +1};
    if (guess == secretNumber) {
        cout << "Congrats you won!" << endl;
        cout << "Secret NUmber is: " << secretNumber << endl;
        if (totalMoney + bet > 500) {
            cout << "Max balance reached!" << endl;
            totalMoney = 500;
        } else {
            totalMoney += bet;
        }
    } else if (guess > secretNumber) {
        cout << "Too High!" << endl;
        totalMoney -= bet;
    } else {
        cout << "Too Low!" << endl;
        totalMoney -= bet;
    }
    cout << "Balance: " << totalMoney << endl;
}

int main() {
    int bet;
    int guess;
    int totalMoney {500};
    char playAgain;

    srand(time(0));

    cout << "Welcome to casino game!" << endl;
    do {
        bet = getValidBet(totalMoney);
        guess = getValidGuess();
        playRound(totalMoney, bet, guess);

        if (totalMoney <= 0) {
            cout << "Game Over! Out of money" << endl;
            playAgain = 'N';
        } else {
            cout << "Wanna continue(Y/N) ?";
            cin >> playAgain;
        }
    }while ((playAgain == 'Y' || playAgain == 'y') && totalMoney > 0);
    cout << "Thank you for playing!" << endl;
    return 0;
}