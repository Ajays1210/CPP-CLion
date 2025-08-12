#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a{10};
    int b{20};
    int *aPtr{&a};
    int *bPtr{&b};

    cout << "a value before swap: " << a << endl;
    cout << "b value before swap: " << b << endl;

    swap(&a, &b);

    cout << "a value after swap: " << a << endl;
    cout << "b value after swap: " << b << endl;

    swap(aPtr, bPtr);

    cout << "a value after swap: " << a << endl;
    cout << "b value after swap: " << b << endl;

    return 0;
}