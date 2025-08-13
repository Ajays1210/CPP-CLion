#include <iostream>
#include <ctime>
#include <random>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int choice{0}, playerChoice {0}, computerChoice {0};
    char rematch;
    srand(time(0));
    do {
        cout << "New Game? (Y/N) ";
        cin >> rematch;
        do {
            cout << "Enter your choice 1 for Rock, 2 for Paper, 3 for Scissors: ";
            cin >> choice;
            if(choice < 1 ||choice > 3) {
                cout << "Invalid input" << endl;
            } else {
                playerChoice = choice;
            }
        }while(choice < 1 ||choice > 3);

        computerChoice = rand() % 3 +1;
        cout << "Computer choice: " << computerChoice << endl;

        if(playerChoice == computerChoice) {
            cout << "Its a TIE!" << endl;
        } else if(playerChoice == 1 && computerChoice == 3 ||
                  playerChoice == 2 && computerChoice == 1 ||
                  playerChoice == 3 && computerChoice == 2) {
            cout << "Player wins!" << endl;
                  } else {
                      cout << "computer wins" << endl;
                  }
    }while(rematch == 'Y' || rematch == 'y');
    return 0;
}