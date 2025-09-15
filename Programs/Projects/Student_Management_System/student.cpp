#include "Student.h"
#include <iostream>

// Constructor implementation
Student::Student(int id, std::string name, std::string major) {
    this->id = id;
    this->name = name;
    this->major = major;
}

// Getter implementations
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getMajor() const {
    return major;
}

// Setter implementations
void Student::setName(const std::string& newName) {
    this->name = newName;
}

void Student::setMajor(const std::string& newMajor) {
    this->major = newMajor;
}

// Display method implementation
void Student::display() const {
    std::cout << "  ID: " << id
              << "\t | Name: " << name
              << "\t | Major: " << major << std::endl;
}