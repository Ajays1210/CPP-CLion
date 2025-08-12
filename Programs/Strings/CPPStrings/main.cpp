#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string s0;
    string s1 {"Ajay"};
    string s2 {"Beymax"};
    string s4;

    // cout << "Enter a string(and): ";
    // cin >> s0;
    // cout << s0 << endl;;
    //
    // s0 = "AND";
    // cout << endl;
    //
    // s4 = s1 + " " + s0 + " " + s2;
    // cout << s4 << endl;
    //
    // cout << std::boolalpha;
    //
    // cout << s1 << " = " << s2 << " is " << (s1 == s2) << endl;
    // cout << s1 << " = " << s1 << " is " << (s1 == s1) << endl;

    cout << "Enter a sentence: ";
    getline(cin, s4);
    cout << s4 << endl;

    cout << s4.substr(0, 4) << endl;
    cout << s4.substr(5, 2) << endl;
    cout << s4.substr(8, 4) << endl;
    cout << s4.substr(1, 2) << endl;

    // s4.erase(0, 6);
    // cout << s4;

    string word;
    cout << "Enter the secret word: ";
    cin >> word;

    size_t position = s4.find(word);
    if(position != string::npos) {
        cout << "The word found at: " << position;
    } else {
        cout << "Word not found" << endl;
    }

    return 0;
}