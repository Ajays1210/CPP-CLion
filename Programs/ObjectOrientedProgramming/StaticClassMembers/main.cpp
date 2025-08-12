#include <iostream>
#include "Player.h"
using std::cout;
using std::endl;

void displayActivePlayers() {
    cout << "Active player objects: " << Player::getNumPlayers() << endl;
}

int main() {
    displayActivePlayers();
    Player player1("Hero", 100,10);
    displayActivePlayers();

    {
        Player player2("NPC", 9999, 99);
        displayActivePlayers();
    }
    displayActivePlayers();

    Player *enemy = new Player("Enemy1", 1000, 10);
    displayActivePlayers();
    delete enemy;
    displayActivePlayers();

    return 0;
}