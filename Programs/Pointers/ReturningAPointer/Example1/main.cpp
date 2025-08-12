#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int *largest(int *ptr1, int *ptr2) {
    if (*ptr1 > *ptr2)
        return ptr1;
    else
        return ptr2;
}

int main() {
    int a{100};
    int b{200};

    int *largestPtr {nullptr};
    largestPtr = largest(&a, &b);

    cout << "Largest is: " << *largestPtr << endl;

    return 0;
}