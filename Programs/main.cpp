#include <algorithm>
#include <iostream>
#include <vector>

void displayVec(const std::vector<int> &v) {
    for (const auto ele : v) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void displayArray(int arr[], int size) {
    for (int i{0}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int array[5] {1, 5, 3, 4, 2};
    displayArray(array, 5);
    std::sort(array, array + 5);
    displayArray(array, 5);
    std::sort(array, array + 5, std::greater<>());
    displayArray(array, 5);

    std::vector<int> vec {1, 5, 3, 4, 2};
    displayVec(vec);
    std::sort(vec.begin(), vec.end());
    displayVec(vec);
    std::sort(vec.begin(), vec.end(), std::greater<>());
    displayVec(vec);
    return 0;
}
