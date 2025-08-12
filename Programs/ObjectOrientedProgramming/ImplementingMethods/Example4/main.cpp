#include "example.h"
#include <iostream>

int main() {
    // Test the functions
    std::cout << "3 + 4 = " << addNumbers(3, 4) << std::endl;
    printMessage();
    std::cout << "The magic number is: " << getMagicNumber() << std::endl;

    return 0;
}