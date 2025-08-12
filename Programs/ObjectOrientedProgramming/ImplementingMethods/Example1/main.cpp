#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Account1 {
private:
    string name;
    double balance;

public:
    void setBalance(double bal) {
        balance = bal;
    }

    double getBalance() {
        return balance;
    }

    //METHODS DEFINED INSIDE CLASS
    void setName(string n);
    string getName();
    bool deposit(double bal);
    bool withdraw(double bal);
};
//Methods declared ouside teh class
void Account1::setName(string n) {
    name = n;
}

string Account1::getName() {
    return name;
}

bool Account1::deposit(double bal) {
    if(bal > 0) {
        balance += bal;
        return true;
    } else {
        return false;
    }
}

bool Account1::withdraw(double bal) {
    if(balance >= bal) {
        balance -= bal;
        return true;
    } else {
        return false;
    }
}

int main() {

    Account1 userAcc;
    userAcc.setName("Max's Account");
    cout << userAcc.getName() << endl;

    userAcc.setBalance(2500);
    cout << userAcc.getBalance() << endl;

    if (userAcc.deposit(2500)) {
        cout << "Deposit Success...";
        cout << userAcc.getBalance() << endl;
    } else {
        cout << "Deposit Failed!" << endl;
    }

    if (userAcc.withdraw(500)) {
        cout << "Withdraw Success..." << endl;
        cout << userAcc.getBalance() << endl;
    } else {
        cout << "Withdraw Failed!" << endl;
    }

    if (userAcc.withdraw(10000)) {
        cout << "Withdraw Success..." << endl;
        cout << userAcc.getBalance() << endl;
    } else {
        cout << "Withdraw Failed!" << endl;
    }

    return 0;
}