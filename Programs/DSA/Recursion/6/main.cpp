#include <bits/stdc++.h>
using namespace std;

int fibb1 (int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0, b = 1;
    for (int i{2}; i <= n; ++i) {
        int sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}

int fibb2(int n) {
    if (n <= 1) {
        return n;
    }
    return (fibb2(n-1) + fibb2(n-2));
}

int main() {
    int n;
    cin >> n;
    cout << fibb1(n) << endl;
    cout << fibb2(n);
    return 0;
}