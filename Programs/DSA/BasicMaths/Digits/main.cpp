#include<bits/stdc++.h>
using namespace std;

int countDigits1 (int n) {
    cout << "Number of digits is: ";
    int count {0};
    while (n > 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int countDigits2 (int n) {
    cout << "Number of digits is: ";
    int count = static_cast<int>(log10(n)) + 1;
    return count;
}

int sumOfDigits(int n) {
    cout << "Sum of digits is: ";
    int count{0};
    int sum{0};
    while (n > 0) {
        int lastDigit = n % 10;
        n = n / 10;
        ++count;
        sum += lastDigit;
    }
    return sum;
}

int revNum(int n) {
    int count{0};
    int dupNum = n;
    int revNum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
        ++count;
    }
    // To check for palindrome
    if (revNum == dupNum) {
        cout << "Num is palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
    cout << "Reverse of number is: ";

    return revNum;
} //Reverse of number + Palindrome check

void armstrongNum (int n) {
    int count{0};
    int dupNum = n;
    int sum{0};
    while (n > 0) {
        int lastDigit = n % 10;
        sum += lastDigit * lastDigit * lastDigit;
        n = n / 10;
        ++count;
    }
    if (sum == dupNum) {
        cout << "Yes! it's Armstrong Number" << endl;
    } else {
        cout << "No! not a Armstrong Number" << endl;
    }
}

void printAllDivisors1 (int n) {
    cout << "List of divisors: ";
    for (int i{1}; i <= n; ++i) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printAllDivisors2 (int n) {
    cout << "List of divisors: ";
    vector<int> v;
    for (int i{1}; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != (n / i)) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto ele : v) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    cout << countDigits1(n) << endl;
    cout << countDigits2(n) << endl;
    cout << sumOfDigits(n) << endl;
    cout << revNum(n) << endl;
    armstrongNum(n);
    printAllDivisors1(n);
    printAllDivisors2(n);

    return 0;
}