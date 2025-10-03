#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string &s) {
    if (i >= s.length()/2) {
        return true;
    }
    if (s[i] != s[s.length() - i - 1]) {
        return false;
    }
    return(isPalindrome(i+1, s));
}

bool isPali(const string &s) {
    size_t start {0};
    size_t end {s.length() -1};

    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main() {
    string s1 {"MADAM"};
    string s2 {"Ajay"};
    cout << boolalpha;

    cout << isPalindrome(0, s1) << endl;
    cout << isPalindrome(0, s2) << endl;

    cout << isPali(s1) << endl;
    cout << isPali(s2) << endl;

    return 0;
}