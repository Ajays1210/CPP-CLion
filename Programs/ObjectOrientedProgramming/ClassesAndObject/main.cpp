#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Player {
    //attributes
    string name {"test"};
    int health {100};
    int xp {0};

    //methods
    void talk(string);
    bool isDead();
};

class Account1 {
    //attributes
    string name {"testAcc"};
    double balance {10000};

    //methods
    bool deposit(double);
    bool withdraw(double);
};

int main() {
    Account1 heroAcc;
    Account1 npcAcc;

    Player hero;
    Player npc;

    Player players[] {hero, npc};

    vector<Player> playerVec {hero};
    playerVec.push_back(npc);

    Player *enemy = {nullptr};
    enemy = new Player;

    delete enemy;

    return 0;
}
