/*
 Print name n times
*/

#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n) {
    if (i > n) {
        return;
    }
    cout << "Ajay S" << endl;
    printName(i+1, n);
}

int main() {
    int n{5};
    printName(1, n);

    return 0;
}