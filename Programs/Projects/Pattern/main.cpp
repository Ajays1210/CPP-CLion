#include <iostream>
using std::cout;
using std::endl;

void pattern1(int n) {
    cout << "Pattern 1" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int n) {
    cout << "Pattern 2" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= i; ++j ) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern3(int n) {
    cout << "Pattern 3" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{n}; j >= i; --j) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern4(int n) {
    cout << "Pattern 4" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern5(int n) {
    cout << "Pattern 5" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= i; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern6(int n) {
    cout << "Pattern 6" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n - i + 1; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern7(int n) {
    cout << "Pattern 7" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= i; ++j) {
            cout << i;
        }
        cout << endl;
    }
}

void pattern8(int n) {
    cout << "Pattern 8" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n - i + 1; ++j) {
            cout << i;
        }
        cout << endl;
    }
}

void pattern9(int n) {
    cout << "Pattern 9" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n - i; ++j) {
            cout << " ";
        }
        for (int k{1}; k <= 2 * i - 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n) {
    cout << "Pattern 10" << endl;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= i - 1; ++j) {
            cout << " ";
        }
        for (int k{1}; k <= 2 * (n - i) + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n{5};
    pattern1(n);
}