#include <iostream>
#include <ctime>
#include <random>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int playerChoice {0};
    int computerChoice {0};
    char playAgain;
    string option1, option2;

    srand(time(0));

    do {
        cout << "Welcome to Rock, Paper, Scissors game!" << endl;
        do {
            cout << "1 is Rock\n2 is Paper\n3 is Scissors\nEnter your choice: ";
            cin >> playerChoice;

            if(playerChoice < 1 || playerChoice > 3) {
                cout << "Invalid choice! Please Enter 1, 2 or 3";
            }
        }while(playerChoice < 1 || playerChoice > 3);

        if(playerChoice == 1) {
            option1 = "Rock";
        } else if(playerChoice == 2) {
            option1 = "Paper";
        } else {
            option1 = "Scissors";
        }
        cout << "You choose " << option1 << endl;

        computerChoice = rand() % 3 + 1;
        if(computerChoice == 1) {
            option2 = "Rock";
        } else if(computerChoice == 2) {
            option2 = "Paper";
        } else {
            option2 = "Scissors";
        }
        cout << "Computer choose: " << option2 << endl;

        if(playerChoice == computerChoice) {
            cout << "It's a TIE!" << endl;
        } else if(playerChoice == 1 && computerChoice == 3 ||
                  playerChoice == 2 && computerChoice == 1 ||
                  playerChoice == 3 && computerChoice == 2) {
            cout << "You Win!" << endl;
        } else {
            cout << "Computer Wins!" << endl;
        }
        cout << "Do you wanna play again (Y/N)?: ";
        cin >> playAgain;
    }while(playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing! Have a nice day.";
    return 0;
}