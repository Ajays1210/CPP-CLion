#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int scores[] {100, 95, 89};
    int *scoresPtr {nullptr};

    scoresPtr = scores;

    cout << "Address of scores: " << scores << endl;

    cout << "\nValues of scores using array subscript/index\n";
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nValues of scores using pointer subscript/index\n";
    cout << scoresPtr[0] << endl;
    cout << scoresPtr[1] << endl;
    cout << scoresPtr[2] << endl;

    cout << "\nValues of scores using array offset\n";
    cout << *(scores) << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;

    cout << "\nValues of scores using pointer offset\n";
    cout << *scoresPtr << endl;
    cout << *(scoresPtr + 1) << endl;
    // cout << *scoresPtr + 1 << endl;         //Value arithmetic = dereferences the pointer and adds 1 to it i.e., adds +1 to the original value
    cout << *(scoresPtr + 2) << endl;
    // cout << *scoresPtr + 2 << endl;

    return 0;
}