#ifndef STUDENTMANAGEMENTSYSTEM_STUDENT_H
#define STUDENTMANAGEMENTSYSTEM_STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    std::string major;

public:
    // Constructor
    Student(int id, std::string name, std::string major);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getMajor() const;

    // Setters
    void setName(const std::string& newName);
    void setMajor(const std::string& newMajor);

    // Display method
    void display() const;
};

#endif //STUDENTMANAGEMENTSYSTEM_STUDENT_H