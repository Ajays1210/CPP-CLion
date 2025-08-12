#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double *tempPtr {nullptr};
    size_t size;

    cout << "Enter the size: ";
    cin >> size;
    tempPtr = new double[size];     //Allocates an array of doubles
    // while(true)                  Endless Loop test
    *tempPtr = 50.984;
    *(tempPtr + 1) = 60.48;
    cout << "\n" << *tempPtr << endl;
    cout << "\n" << *(tempPtr + 1) << endl;
    cout << "\n" << tempPtr << endl;

    delete[] tempPtr;

    return 0;

}