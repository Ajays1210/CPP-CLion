#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int *intPtr {nullptr};
    intPtr = new int;

    cout << intPtr << endl;
    cout << *intPtr << endl;
    *intPtr = 100;

    cout  << intPtr << endl;
    cout << *intPtr << endl;
    delete intPtr;

    return 0;

}