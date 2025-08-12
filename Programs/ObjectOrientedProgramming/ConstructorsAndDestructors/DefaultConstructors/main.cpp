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
    void setName(string nameVal) {
        name = nameVal;
    }

    string getName() {
        return name;
    }
    // User defined default constructor
     Player() {
         name = "Default";
         health = 100;
         xp = 10;
     }
    Player(string nameVal, int healthVal, int xpVal) {          //overloaded constructor
        name = nameVal;
        health = healthVal;
        xp = xpVal;
    }

};

int main() {
    Player p1;
    cout << p1.getName() << endl;
    p1.setName("Max");
    cout << p1.getName() << endl;

    Player p2("Test", 100, 10);
    cout << p2.getName() << endl;
    p2.setName("Sen");
    cout << p2.getName() << endl;

    return 0;
}