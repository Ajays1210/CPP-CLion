#include<iostream>
#include<string>

using std::string;

class Player {
private:
    string name;
    int health;
    int xp;

public:
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

// Player::Player() {
//     name = "Default";
//     health = 100;
//     xp = 10;
// }

Player::Player() : name{0}, health{100}, xp{10} {       //constructor initialization list

}

// Player::Player(string nameVal) {
//     name = nameVal;
//     health = 100;
//     xp = 10;
// }

Player::Player(string nameVal) : name{nameVal}, health{100}, xp{10} {

}

// Player::Player(string nameVal, int healthVal, int xpVal) {
//     name= nameVal;
//     health = healthVal;
//     xp = xpVal;
// }

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {

}

int main() {
    Player p1;
    Player p2("Max");
    Player p3("Sen", 100,10);

    return 0;
}