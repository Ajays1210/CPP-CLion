#include<bits/stdc++.h>
using namespace std;

int countNum(int num, const int arr[], int n) {
    int count {0};
    for (int i{0}; i<n; ++i) {
        if (num == arr[i]) {
            ++count;
        }
    }
    return count;
}

int main() {
    int arr[5] {1, 5, 2, 1, 5};
    cout << countNum(1, arr, 5);

    return 0;
}