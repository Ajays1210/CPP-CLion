#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Player {
private:
    string name;
    int health;
    int xp;

public:
    string getName() { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }

    Player(string nameVal = "Default", int healthVal = 100, int xpVal = 0);
    Player(const Player &source);
    ~Player();
};
//Regular Constructor
Player::Player(string nameVal, int healthVal, int xpVal)
    : name {nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three args constructor for " + name << endl;
}

//Copy constructor
Player::Player(const Player &source) : name{source.name}, health{source.health}, xp{source.xp} {
// Player::Player(const Player &source)
//     : Player(source.name, source.health, source.xp) {              // Delegat constructor
    cout << "Copy constructor for " << source.name << endl;
}

//Destructor
Player::~Player() {
    cout << "Destructor called" << endl;
}

void display(Player p) {
    cout << "Name: " << p.getName() << endl;
    cout << "Health: " << p.getHealth() << endl;
    cout << "XP: " << p.getXp() << endl;
}

int main() {
    Player empty;
    display(empty);

    return 0;
}
