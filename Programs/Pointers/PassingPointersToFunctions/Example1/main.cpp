#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void doubleValue(int *intPtr) {
     *intPtr *= 2;
}

int main() {
    int num {10};
    doubleValue(&num);

    cout << num << endl;

    cout << "-------------------------------------" << endl;

    num = 10;
    int *numPtr {&num};
    doubleValue(numPtr);

    cout << num << endl;
}