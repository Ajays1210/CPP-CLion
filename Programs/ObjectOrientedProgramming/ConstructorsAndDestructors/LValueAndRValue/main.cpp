#include <iostream>

using std::cout;
using std::endl;

int func(int &num) {
    cout << "L value function called " << num << endl;
    return num;
}
int func(int &&num) {
    cout << "R value function called " << num << endl;
    return num;
}

int main() {
    int x{100};
    int &lVal = x;
    cout << "L value of x " << lVal << " and x " << x << " are same" << endl;
    cout << "L value address of x " << &lVal << " and &x " << &x << " are same" << endl;

    int &&rVal = 100;
    rVal = 200;
    cout << rVal << endl;

    func(500);
    func(x);

    return 0;
}