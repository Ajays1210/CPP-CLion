#include <iostream>
#include <string>
#include "Account1.h"

using std::cout;
using std::string;
using std::endl;

int main() {
    Account1 userAcc;
    userAcc.setName1("Maxi's Account");
    cout << userAcc.getName1() << endl;

    userAcc.setBalance1(3500);
    cout << userAcc.getBalance1() << endl;

    if(userAcc.deposit1(2500)) {
        cout << userAcc.getBalance1() << endl;
    } else {
        cout << "Failed!" << endl;
    }
    if(userAcc.withdraw1(1500)) {
        cout << userAcc.getBalance1() << endl;
    } else {
        cout << "Failed!" << endl;
    }

    if(userAcc.withdraw1(7000)) {
        cout << userAcc.getBalance1() << endl;
    } else {
        cout << "Failed!" << endl;
    }
    return 0;
}