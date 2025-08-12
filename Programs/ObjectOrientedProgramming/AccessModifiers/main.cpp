#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Player {
private:
    string name {"Player"};
    int health {100};
    int xp {10};

public:
    void talk(string textToSay) {
        cout << name << " said " << textToSay << endl;
    }
};

int main() {
    Player hero;
    //hero.name = "Max";
    hero.talk("Hello");


    return 0;
}