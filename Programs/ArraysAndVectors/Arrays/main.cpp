#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int testScores[3] {0};
    cout << "Test score at index 0: " << testScores[0] << endl;
    cout << "Test score at index 1: " << testScores[1] << endl;
    cout << "Test score at index 2: " << testScores[2] << endl;

    cout << "Enter three test scores: " << endl;

    cin >> testScores[0];
    cin >> testScores[1];
    cin >> testScores[2];
    // cin >> testScores[3];     Out of Bounds

    cout << "Test score at index 0: " << testScores[0] << endl;
    cout << "Test score at index 1: " << testScores[1] << endl;
    cout << "Test score at index 2: " << testScores[2] << endl;

    cout << "Values after assigning" << endl;

    testScores[0] = 92;
    testScores[1] = 86;
    testScores[2] = 75;

    cout << "Test score at index 0: " << testScores[0] << endl;
    cout << "Test score at index 1: " << testScores[1] << endl;
    cout << "Test score at index 2: " << testScores[2] << endl;
    // cout << "Test score at index 3: " << testScores[3] << endl; - Out of Bounds

    cout << "Multi-Dimensional Array" << endl;

    int testScores2[3][2] {
        {45,2},
        {62,1},
        {85,3}
    };

    cout << "Test score2 index at (0,0): " << testScores2[0][0] << endl;
    cout << "Test score2 index at (0,1): " << testScores2[0][1] << endl;
    cout << "Test score2 index at (1,0): " << testScores2[1][0] << endl;
    cout << "Test score2 index at (1,1): " << testScores2[1][1] << endl;
    cout << "Test score2 index at (2,0): " << testScores2[2][0] << endl;
    cout << "Test score2 index at (2,1): " << testScores2[2][1] << endl;

    return 0;
}