#include <iostream>
#include <string>

using std::cout;
using std::endl;

template <typename T>
T min(T a, T b) {
    return (a < b)? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    cout << a << " " << b << endl;
}

template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a{100};
    int b{200};

    cout << a << ", " << b << endl;
    mySwap(a, b);
    cout << a << ", " << b << endl;

    cout << min<int> (5, 3) << endl;
    cout << min(5, 3) << endl;
    cout << min(3.5, 6.8) << endl;
    cout << min('A', 'B') << endl;
    cout << min(5+5*2, 3+7) << endl;

    func<int> (4, 5.2);
    func(4, 5.2);
    func<char, double> ('A', 12.4);
    func('A', 12.4);
    func(1000, "Test");
    func(2000, std::string{"Max"});

    return 0;
}
