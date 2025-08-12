#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Player {
public:
    string name;
    int health;
    int xp;

    void talk(string textToSay) {
        cout << name << " say's " << textToSay << endl;
    }

    bool isDead();
};

class Account1 {
public:
    string name;
    double balance;

    bool deposit(double bal) {
        balance += bal;
        cout << bal << " deposited to balance" << endl;
        return true;  // Added return
    }

    bool withdraw(double bal) {
        if (balance >= bal) {  // Added safety check
            balance -= bal;
            cout << bal << " withdrawn from balance" << endl;
            return true;
        }
        cout << "Insufficient funds" << endl;
        return false;
    }
};

int main() {
    Player hero;
    hero.name = "Max";
    hero.health = 100;
    hero.xp = 10;

    hero.talk("hi");

    Player *enemy = new Player;
    (*enemy).name = "Igris";
    (*enemy).health = 1000;
    enemy->xp = 50000;

    enemy->talk("I will destroy you!");

    delete enemy;

    Account1 heroAcc;
    heroAcc.name = "Max's Account";
    heroAcc.balance = 10000.0;

    heroAcc.deposit(1000.0);
    heroAcc.withdraw(500.0);

    Account1 *enemyAcc = new Account1;
    (*enemyAcc).name = "Axix";
    enemyAcc->balance = 15000;

    (*enemyAcc).deposit(5000.0);
    enemyAcc->withdraw(1000);

    delete enemyAcc;
    return 0;
}
