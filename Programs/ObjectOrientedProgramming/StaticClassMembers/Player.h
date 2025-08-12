//
// Created by ajays on 06-07-2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using std::string;

class Player {
private:
    static int numPlayers;
    string name;
    int health;
    int xp;

public:
    string getName() { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }

    Player(string nameVal = "Default", int healthVal = 100, int xpVal = 10);
    Player(const Player &source);
    ~Player();

    static int getNumPlayers();
};

#endif //PLAYER_H
