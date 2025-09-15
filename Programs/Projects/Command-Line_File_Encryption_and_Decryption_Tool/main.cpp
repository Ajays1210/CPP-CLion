#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;

int main() {
    string fileName = "C:\\Users\\ajays\\OneDrive\\Desktop\\CPP\\CLion\\Programs\\Projects\\Command-Line_File_Encryption_and_Decryption_Tool\\input.txt";
    ifstream inputFile(fileName);

    string fileName1 = "encrypted.txt";
    ofstream outputFile(fileName1);

    if (inputFile && outputFile) {
        cout << "File opened successfully." << endl;

        char ch;
        while (inputFile.get(ch)) {
            // Encrypt the character
            char encrypted_ch = ch + 3;

            outputFile << encrypted_ch;
        }
        inputFile.close();
        outputFile.close();

    } else {
        cout << "Error: Could not open the file " << fileName << endl;
        return 1;
    }

    ifstream inputFile1(fileName1);

    string fileName2 = "decrypted.txt";
    ofstream outputFile1(fileName2);

    if (inputFile1 && outputFile1) {
        cout << "File opened successfully." << endl;

        char ch;
        while (inputFile1.get(ch)) {
            char decrypt_ch = ch - 3;

            outputFile1 << decrypt_ch;
        }
        inputFile1.close();
        outputFile1.close();

    } else {
        cout << "Error: Could not open the file " << fileName1 << endl;
        return 1;
    }

    return 0;
}