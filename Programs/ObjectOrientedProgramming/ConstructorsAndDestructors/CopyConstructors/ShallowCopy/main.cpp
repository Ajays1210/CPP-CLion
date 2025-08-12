#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Shallow {
private:
    int *data;

public:
    void setData(int dataVal) { *data = dataVal; }
    int getData() {return *data; }

    // This is the default constructor user-defined since there is no zero args constructor
    Shallow(int d) {
        data = new int;
        *data = d;
        cout << "Constructor called" << endl;
    }

    Shallow(const Shallow &source) : data{source.data} {                  //Initialization
    // Shallow(const Shallow &source) : Shallow(*source.data) {           //Delegation
        data = source.data;
        cout << "Copy constructor called" << endl;
    }
    ~Shallow() {
        delete data;
        cout << "Destructor Called..." << endl;
    }
};

void display(Shallow s) {
    cout << s.getData() << endl;
}

int main() {
    Shallow obj1{100};
    display(obj1);

    Shallow obj2{obj1};
    obj2.setData(1000);
    
    return 0;
}