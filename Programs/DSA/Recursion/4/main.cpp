#include<bits/stdc++.h>
using namespace std;

void revArr1(vector<int> &v) {      // Pass by Reference
    int start = 0;
    int end = v.size() -1;

    for (; start < end; ++start, --end) {
        swap(v.at(start), v.at(end));
    }
    cout << endl;
}

void revArr2(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    for (; start < end; ++start, --end) {
        swap(arr[start], arr[end]);
    }
    cout << endl;
}

void displayVec(vector<int> v) {
    for (auto ele : v) {
        cout << ele << " ";
    }
    cout << endl;
}

void displayArr(int arr[], int size) {
    for (int i{0}; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Slower due to function overhead
void revArr3 (int i, int arr[], int n) {
    if (i >= n/2) {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    revArr3(i+1, arr, n);
}

int main() {
    int n{5};
    int arr1[n];
    vector<int> vec {0, 1, 2, 3, 4, 5};
    int arr[5] {0, 1, 2, 3, 4};

    displayVec(vec);
    revArr1(vec);
    displayVec(vec);

    displayArr(arr, 5);
    revArr2(arr, 5);
    displayArr(arr, 5);

    cout << "Using 1 variable" << endl;
    for (int i=0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    revArr3(0, arr, n);
    for (int i=0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}