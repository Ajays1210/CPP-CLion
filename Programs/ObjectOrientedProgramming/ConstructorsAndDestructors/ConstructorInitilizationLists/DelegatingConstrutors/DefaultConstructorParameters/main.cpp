#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Player {
private:
    string name;
    int health;
    int xp;

public:
    Player(string nameVal = "Default", int healthVal = 100, int xpVal = 10); // Here
};

Player::Player(string nameVal, int healthVal, int xpVal)
    : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three arg constructor called" << endl;
}

int main() {
    Player p1;
    Player p2("Max");
    Player p3("Sen", 10);
    Player p4("Chi", 100,10);

    return 0;
}