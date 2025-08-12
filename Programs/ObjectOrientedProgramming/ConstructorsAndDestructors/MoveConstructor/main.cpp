#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Move {
private:
    int *data;

public:
    void setData(int dVal) { *data = dVal; }
    int getData() { return *data; }

    Move(int d);
    Move(const Move &source);
    Move(Move &&source);
    ~Move();
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor called for " << *data << endl;
}
Move::Move(const Move &source)
    : data{new int{*source.data}} {
// Move::Move(const Move &source) : Move(*source.data) {
    // *data = 200;                                                        //dont modify copy constructor this is for learning purpose
    cout << "Copy constructor called " << endl;
}

//Move constructor
Move::Move(Move &&source)
    : data{source.data} {
    source.data  = nullptr;
    cout << "Move constructor called for " << *data << endl;
}

Move::~Move() {
    if (data != nullptr)
        cout << "Destructor called for " << *data << endl;
    else
        cout << "Destructor called for nullptr" << endl;

    delete data;
}

int main() {
    vector<Move> vec;
    vec.push_back(Move(10));

    return 0;
}