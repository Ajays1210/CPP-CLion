#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void passByReference1(int &num);
void passByReference2(string &str);
void printVector1(vector<string> &v1);
void printVector2(const vector<string> &v2);
void passByReference3(vector<string> &v);

int main() {
    int num {1000};
    cout << "Before pass by reference: " << num << endl;
    passByReference1(num);
    cout << "After pass by reference: " << num << endl;

    string s1{"Ajay"};
    cout << "\nBefore pass by reference: " << s1 << endl;
    passByReference2(s1);
    cout << "After pass by reference; " << s1 << endl;

    vector<string> names {"Max", "Ajay", "Sen"};
    printVector1(names);
    passByReference3(names);
    printVector1(names);

    printVector2(names);
    passByReference3(names);
    printVector2(names);

    return 0;
}

void passByReference1(int &num) {
    num = 100;
}

void passByReference2(string &str) {
    str = "Changed to Ajay\n";
}

void printVector1(vector<string> &v1) {
    for(size_t i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << " ";
    }
}

void printVector2(const vector<string> &v2) {
    for(auto i: v2) {
        cout << i << " ";
    }
    cout << endl;
}

void passByReference3(vector<string> &v) {
    v.clear();
}