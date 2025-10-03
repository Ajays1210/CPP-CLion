/*
    1. Print [1 - n] numbers
    2. Print [n - 1] numbers
*/

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i;
    print(i+1, n);
}

void printRev(int i, int n) {
    if (i < 1) {
        return;
    }
    cout << i;
    printRev(i-1, n);
}

//Backtracking
void printRev(int n) {
    if (n < 1) {
        return;
    }
    cout << n << " ";
    printRev(n-1);
}

int main() {
    int n{5};

    print(1, n);
    cout << endl;
    print(1, n);           //Backtracking
    cout << endl;
    printRev(5, n);
    cout << endl;
    printRev(n);        //Backtracking

    return 0;
}