//
// Created by ajays on 26-06-2025.
//DECLARATION
//

#ifndef ACCOUNT1_H
#define ACCOUNT1_H

#include <string>
using std::string;


class Account1 {
private:
    string name;
    double balance;

public:
    void setName1(string n);
    string getName1();
    void setBalance1(double bal);
    double getBalance1();
    bool deposit1(double bal);
    bool withdraw1(double bal);
};

#endif //ACCOUNT1_H
