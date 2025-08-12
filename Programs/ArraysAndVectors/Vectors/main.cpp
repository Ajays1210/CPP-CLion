#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector <int> numbers;                           // Empty Vector
    vector <char> name(5);                       // 5 spaces initialized to zero
    vector <char> myName {'A', 'J', 'A', 'Y'};      // Automatically created 4 spaces

    cout << "Output using array syntax/Index method" << endl;
    cout << "Vector myName at index 0: " << myName[0] << endl;
    cout << "Vector myName at index 1: " << myName[1] << endl;
    cout << "Vector myName at index 2: " << myName[2] << endl;
    cout << "Vector myName at index 3: " << myName[3] << endl;

    cout << "\nOutput using vector method" << endl;
    cout << "Vector myName at index 0: " << myName.at(0) << endl;
    cout << "Vector myName at index 1: " << myName.at(1) << endl;
    cout << "Vector myName at index 2: " << myName.at(2) << endl;
    cout << "Vector myName at index 3: " << myName.at(3) << endl;

    cout << "Enter three letters" << endl;
    cin >> name.at(0);
    cin >> name.at(1);
    cin >> name.at(2);

    cout << "Vector name at index 0: " << name.at(0) << endl;
    cout << "Vector name at index 1: " << name.at(1) << endl;
    cout << "Vector name at index 2: " << name.at(2) << endl;
    cout << "Vector name at index 3: " << name.at(3) << endl;
    cout << "Vector name at index 4: " << name.at(4) << endl;

    numbers.push_back(52);
    numbers.push_back(46);
    numbers.push_back(32);

    cout << "Updated numbers vector" << endl;
    cout << "Vector numbers at index 0: " << numbers.at(0) << endl;
    cout << "Vector numbers at index 1: " << numbers.at(1) << endl;
    cout << "Vector numbers at index 2: " << numbers.at(2) << endl;
    // cout << "Vector numbers at index 2: " << numbers.at(10) << endl;     Out of Bounds

    cout << "Size of vector numbers: " << numbers.size() << endl;
    cout << "Size of vector name: " << name.size() << endl;
    cout << "Size of vector myName: " << myName.size() << endl;

    return 0;
}