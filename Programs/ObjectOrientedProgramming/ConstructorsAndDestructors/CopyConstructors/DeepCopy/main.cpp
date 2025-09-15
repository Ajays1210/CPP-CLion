#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Deep {
private:
    int *pointerToInteger;

public:
    void setData(int value) { *pointerToInteger = value; }
    int getData() { return *pointerToInteger; }

    Deep(int initValue);
    Deep(const Deep &source);
    ~Deep();
};

Deep::Deep(int initValue) {
    pointerToInteger = new int;
    *pointerToInteger = initValue;
    cout << "Regular constructor called" << endl;
}

Deep::Deep(const Deep &source) : pointerToInteger{new int{*source.pointerToInteger}} {          //initialization list
// Deep::Deep(const Deep &source) : Deep(*source.pointerToInteger) {                            //Delegation
    // pointerToInteger = new int;                                                              //Normal method
    // *pointerToInteger = *source.pointerToInteger;
    cout << "Deep copy constructor called" << endl;
}

Deep::~Deep() {
    delete pointerToInteger;
    cout << "Destructor called" << endl;
}

void display(Deep object) {
    cout << object.getData() << endl;
}

int main() {
    Deep obj1(100);
    display(obj1);
    Deep obj2(obj1);
    obj2.setData(200);

    display(obj2);

    return 0;
}