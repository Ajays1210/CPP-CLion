//Passing arrays to function

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArray(int arr[], size_t size);
void setArray(int arr[], size_t size, int value);

int main() {
    int numbers[] {100, 54, 98, 43, 78};
    printArray(numbers, 5);
    setArray(numbers, 5, 100);
    printArray(numbers, 5);

    return 0;
}

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void setArray(int arr[], size_t size, int value) {
    for(size_t i = 0; i < size; ++i) {
        arr[i] = value;
    }
}