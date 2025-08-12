#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int *createArray(size_t size, int initValue = 0) {
    int *arrayEle = new int[size];
    for (size_t i{0}; i < size; ++i) {
        *(arrayEle + i) = initValue;
    }
    return arrayEle;
}

void display(const int *const array, size_t size) {
    for (size_t i{}; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    size_t size{};
    int initValue{};

    cout << "Enter the size you want to allocate in the memory: ";
    cin >> size;
    cout << "\nEnter the value you want to initialize each element: ";
    cin >> initValue;

    int *myArray {nullptr};
    myArray = createArray(size, initValue);

    display(myArray,size);

    delete[] myArray;
    // myArray = nullptr;

    return 0;
}