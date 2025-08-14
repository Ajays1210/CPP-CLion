#include <iostream>
#include <ctime>
#include <random>

using std::cout;
using std::cin;
using std::endl;

enum class Choice {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

Choice getPlayerChoice() {
    int choice {0};

    do {
        cout << "Enter your choice (1 is ROCK, 2 is PAPER, 3 is SCISSORS): ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid input! Please choose 1, 2 or 3" << endl;
        }
    }while (choice < 1 || choice > 3);

    return static_cast<Choice> (choice);
}

Choice getComputerChoice() {
    int choice = rand() % 3 + 1;
    return static_cast<Choice>(choice);
}

void determineWinner(Choice playerChoiceVal, Choice computerChoiceVal) {
    if (playerChoiceVal == computerChoiceVal) {
        cout << "It's a TIE!" << endl;
    } else if(playerChoiceVal == Choice::ROCK && computerChoiceVal == Choice::SCISSORS ||
              playerChoiceVal == Choice::PAPER && computerChoiceVal == Choice::ROCK ||
              playerChoiceVal == Choice::SCISSORS && computerChoiceVal == Choice::PAPER) {
        cout << "You Win!" << endl;
    } else {
        cout << "Computer Wins!" << endl;
    }
}

int main() {
    Choice playerChoice, computerChoice;
    char playAgain;

    srand(time(0));

    cout << "Welcome to ROCK, PAPER, SCISSORS game" << endl;
    do {
        playerChoice = getPlayerChoice();
        computerChoice = getComputerChoice();
        determineWinner(playerChoice, computerChoice);

        cout << "Play Again (Y/N) ?: ";
        cin >> playAgain;
    }while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing! Have a nice day.";
    return 0;
}
