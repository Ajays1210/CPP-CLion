#include "person.h"
#include <iostream>

Person::Person(const std::string& name, int age) 
    : name(name), age(age) {}

void Person::introduce() const {
    std::cout << "Hello! I'm " << name 
              << " and I'm " << age << " years old.\n";
}