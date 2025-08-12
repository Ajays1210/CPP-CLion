//
// Created by ajays on 26-06-2025.
//DEFNITION
//

#include "Account1.h"

void Account1::setName1(string n) {
    name = n;
}

string Account1::getName1() {
    return name;
}

void Account1::setBalance1(double bal) {
    balance = bal;
}

double Account1::getBalance1() {
    return balance;
}

bool Account1::deposit1(double bal) {
    if(bal > 0) {
        balance += bal;
        return true;
    } else {
        return false;
    }
}

bool Account1::withdraw1(double bal) {
    if(balance >= bal) {
        balance -= bal;
        return true;
    } else {
        return false;
    }
}