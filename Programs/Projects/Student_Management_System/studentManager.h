#ifndef STUDENTMANAGEMENTSYSTEM_STUDENTMANAGER_H
#define STUDENTMANAGEMENTSYSTEM_STUDENTMANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {
private:
    std::vector<Student> students;
    int nextId; // To auto-generate student IDs

    // Helper function to find a student by ID. Returns -1 if not found.
    int findStudentIndex(int id);

public:
    // Constructor
    StudentManager();

    // Core functionalities
    void addStudent();
    void displayAllStudents();
    void updateStudent();
    void deleteStudent();

    // Main application loop
    void run();
};

#endif //STUDENTMANAGEMENTSYSTEM_STUDENTMANAGER_H