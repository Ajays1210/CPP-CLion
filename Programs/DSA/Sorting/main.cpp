#include <iostream>
#include <vector>
//#include <algorithm> // Required for std::swap

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    // Outer loop iterates through the entire array, defining the unsorted section
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        int min_idx = i;

        // Inner loop finds the actual minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the element at the current position 'i'
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    std::vector<int> numbers = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(numbers);

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}