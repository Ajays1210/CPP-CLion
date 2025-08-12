#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    int num{10};
    cout << "Value of num: " << num << endl;
    cout << "Size of num: " << sizeof(num) << endl;
    cout << "Address of num: " << &num << endl;

    int *p;
    cout << "\nValue of p: " << p << endl;
    cout << "Size of p: " << sizeof(p) << endl;
    cout << "Address of p: " << &p << endl;

    p = nullptr;
    cout << "Value of p: " << p << endl;

    int *p1 {nullptr};
    char *p2 {nullptr};
    double *p3 {nullptr};
    string *p4 {nullptr};
    vector<string> *p5 {nullptr};

    cout << "\nSize of int p1: " << sizeof(p1) << endl;
    cout << "Size of char p2: " << sizeof(p2) << endl;
    cout << "Size of double p3: " << sizeof(p3) << endl;
    cout << "Size of string p4: " << sizeof(p4) << endl;
    cout << "Size of vector p5: " << sizeof(p5) << endl;

    return 0;
}
