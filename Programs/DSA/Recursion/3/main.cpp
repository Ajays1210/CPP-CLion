/*
 Print sum of N numbers
  1. Parameterized way
  2. Functional way
*/

#include<bits/stdc++.h>
using namespace std;

int parameterisedSum(int n, int sum) {
    if (n < 1) {
        return sum;
    }
    return parameterisedSum(n-1, sum+n);
}

int functionalSum(int n) {
    if (n <  1) {
        return 0;
    }
    return n + functionalSum(n-1);
}

void factPara(int n, int result) {
    if (n == 0) {
        cout << result << endl;
        return;
    }
    factPara(n-1, result * n);
}

int factFun(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * factFun(n-1);
}

int main() {
    int n{3};
    cout << parameterisedSum(n, 0) << endl;
    cout << functionalSum(n) << endl;
    factPara(n, 1);
    cout << endl;
    cout << factFun(n);

    return 0;
}