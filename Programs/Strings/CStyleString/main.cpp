#include <iostream>
#include <cstring>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

int main() {
    char firstName[10];
    char lastName[10];
    char fullName[20];
    char temp[50];

    // cout << firstName;
    cout << "Enter First name: ";
    cin >> firstName;

    cout << "\nEnter Last name: ";
    cin >> lastName;

    cout << "\nHello " << firstName << " your first name has: " << strlen(firstName) << " characters" << endl;
    cout << "And your last name has: " << strlen(lastName) << " characters" << endl;

    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);

    cout << "\nYour full name is: " << fullName << endl;
    //
    // cout << "------------------------------------------" << endl;
    //
    // cout << "Enter your full name: ";
    // cin >> fullName;
    //
    // cout << "Your full name is: " << fullName << endl;
    //
    // // cout << "Enter your full name again: ";
    // // cin.getline(fullName, 50);
    // //
    // // cout << "Again your full name is: " << fullName << endl;

    cout << "------------------------------------------" << endl;

    strcpy(temp, fullName);
    if(strcmp(temp, fullName) == 0) {
        cout << temp << " and " << fullName << " are same" << endl;
    }

    for (size_t i {0}; i < strlen(fullName); ++i) {
        if (isalpha(fullName[i]))
            fullName[i] = toupper(fullName[i]);
    }
    cout << "Your full name converted to: " << fullName << endl;

    if(strcmp(temp, fullName) == 0) {
        cout << temp << " and " << fullName << " are same" << endl;
    }
    else {
        cout << temp << " and " << fullName << " are differnt" << endl;
    }

    cout << "Result of comparing " << temp << " and " << fullName << " : " << strcmp(temp, fullName) << endl;
    cout << "Result of comparing " << fullName << " and " << temp << " : " << strcmp(fullName, temp);

    return 0;
}