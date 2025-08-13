#include <iostream>
#include<ctime>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int playerChoice {0};
    int computerChoice {0};
    char playAgain;

    do {
        cout << "Welcome to Rock, Paper, Scissors game!" << endl;
        do {
            cout << "1 is Rock\n2 is Paper\n3 is Scissors\nEnter your choice: ";
            cin >> playerChoice;

            if(playerChoice < 1 || playerChoice > 3) {
                cout << "Invalid choice! Please Enter 1, 2 or 3";
            }
        }while(playerChoice < 1 || playerChoice > 3);

        computerChoice = rand() % 3 + 1;
        cout << "Computer choose: " << computerChoice << endl;

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