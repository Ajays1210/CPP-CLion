#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int scores[] {100, 95, 89, 76, 64, -1};
    int *scoresPtr {scores};

    cout << scores << endl;
    cout << *scores << endl;
    cout << &scores<< endl;
    cout << scoresPtr << endl;
    cout << endl;

    while(*scoresPtr != -1) {
        cout << *scoresPtr << endl;
        scoresPtr++;
    }
    cout << endl;

    scoresPtr = scores;
    while(*scoresPtr != -1)
        cout << *scoresPtr++ << endl;       //Operator precedence from left to right.

    cout << std::boolalpha;

    string s1 {"Max"};
    string s2 {"Jim"};
    string s3 {"Max"};


    string *p1 {&s1};
    string *p2 {&s2};
    string *p3 {&s3};
    string *p4 {&s1};

    cout << s1 << " = " << s2 << " " << (s1 == s2) << endl;
    cout << s1 << " = " << s3 << " " << (s1 == s3) << endl;

    cout << *p1 << " = " << *p2 << " " << (*p1 == *p2) << endl;
    cout << *p1 << " = " << *p4 << " " << (*p1 == *p4) << endl;
    cout << *p1 << " = " << *p3 << " " << (*p1 == *p3) << endl;

    char name[] {"Frank"};
    char *charPtr1 = &name[0];
    char *charPtr2 = &name[3];

    cout << *charPtr2 << " is " << charPtr2 - charPtr1 << " letters away from " << *charPtr1 << endl;

    return 0;
}