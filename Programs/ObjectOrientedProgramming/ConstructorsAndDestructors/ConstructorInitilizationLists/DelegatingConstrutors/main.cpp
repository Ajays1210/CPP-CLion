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
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

Player::Player(string nameVal, int healthVal, int xpVal)
    : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three args constructor" << endl;
}

Player::Player()
    : Player{"Default", 100, 10} {
    cout << "No args constructor" << endl;
}

Player::Player(string nameVal)
    : Player{nameVal, 100, 10} {
    cout << "One arg constructor" << endl;
}

int main() {
    Player noArgConst;
      Player twoArgConst("Max");
    Player threeArgConst("Sen", 100, 10);
    return 0;
}