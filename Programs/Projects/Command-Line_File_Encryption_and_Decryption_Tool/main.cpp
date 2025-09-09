#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main() {
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if (inputFile) {
        cout << "File opened successfully." << endl;
    } else {
        cout << "Error: Could not open the file " << fileName << endl;
        return 1;
    }
}