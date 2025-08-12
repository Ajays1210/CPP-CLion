#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void display(vector<string> &str) {
    for(auto &s : str) {
        cout << s << " ";
    }
    cout << endl;
}

void change(vector<string> &str) {
    for(auto &s : str) {
        s = "Fanny";
    }
    cout << endl;
}

int main() {
    vector<string> stooges {"Larry", "Max", "Jim"};

    //display
    for(auto const &s : stooges) {
        cout << s << " ";
    }
    cout << endl;

    for(auto &s : stooges) {
        s = "Maximus";
    }

    display(stooges);
    change(stooges);
    display(stooges);

    return 0;
}