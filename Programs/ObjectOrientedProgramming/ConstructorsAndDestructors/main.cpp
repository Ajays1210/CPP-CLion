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
    void setName(string n);

    Player() {
        cout << "No args constructor called" << endl;
    }

    Player(string n) {
        cout << "One arg constructor called" << endl;
    }

    Player(string n, int h) {
        cout << "Two args constructor called" << endl;
    }

    Player(string n, int h, int x) {
        cout << "Three args constructor called" << endl;
    }

    ~Player() {
        cout << "Destructor called " << name << endl;
    }
};

void Player::setName(string n) {
    name = n;
}

int main() { {
        Player p1;
        p1.setName("Max");
    } {
        Player p2("Test1");
        p2.setName("Sen");
        Player p3("Test2", 100);
        p3.setName("Rox");
        Player p4("Test3", 100, 10);
        p4.setName("Ren");
    }

    Player *enemy = new Player("Test4", 1000, 500);
    enemy->setName("Tom");

    delete enemy;
    return 0;
}
