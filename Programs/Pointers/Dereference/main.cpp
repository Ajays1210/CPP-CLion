#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    int num {10};
    int *numPtr {&num};
    cout << *numPtr << endl << endl;

    double highTemp {100.7};
    double lowTemp {40.2};
    double *tempPtr {&highTemp};

    cout  << tempPtr << endl;
    cout << *tempPtr << endl;
    tempPtr = &lowTemp;
    cout << *tempPtr << endl << endl;

    string myName {"Ajay"};
    string *str = &myName;
    cout << *str << endl;
    myName = "Changed to AJAY";
    cout << *str << endl;
    *str = "Again Changed to Ajay";
    cout << *str << endl << endl;

    vector<string> names {"Larry", "Adam", "John"};
    vector<string> *vecPtr {nullptr};

    vecPtr = &names;
    cout << (*vecPtr).at(0) << endl;

    for(auto name: *vecPtr) {
        cout << name << " ";
    }
    cout << endl;
    return 0;
}