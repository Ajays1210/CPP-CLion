#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void display(vector<string> *v) {
    //(*v).at(0) = "Larry";            const to a pointer don't work => void display(const vector<string> *v)
    for(auto i : *v)
        cout << i << " ";
    //v = nullptr;                     pointer to const don't work here => void display(vector<string> *const v)
}

void display(int *array, int limit) {
    while(*array != limit)
        cout << *array++ << endl;
}

int main() {
    // vector<string> stooges {"Max", "Ben", "Jim"};
    // display(&stooges);

    cout << "-------------------------------" << endl;

    int scores[] {100, 95, 87, 74, -1};
    display(scores, -1);

    return 0;
}