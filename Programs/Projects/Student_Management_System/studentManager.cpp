#include "StudentManager.h"
#include <iostream>
#include <limits> // Required for numeric_limits

StudentManager::StudentManager() {
    nextId = 1; // Start student IDs from 1
}

void StudentManager::addStudent() {
    std::string name, major;
    std::cout << "\nEnter Student Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::getline(std::cin, name);

    std::cout << "Enter Student Major: ";
    std::getline(std::cin, major);

    students.emplace_back(nextId, name, major);
    std::cout << "\nStudent added successfully with ID: " << nextId << std::endl;
    nextId++;
}

void StudentManager::displayAllStudents() {
    if (students.empty()) {
        std::cout << "\nNo student records found." << std::endl;
        return;
    }

    std::cout << "\n--- List of All Students ---\n" << std::endl;
    for (const auto& student : students) {
        student.display();
    }
    std::cout << "\n----------------------------\n" << std::endl;
}

int StudentManager::findStudentIndex(int id) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return i; // Return the index of the student
        }
    }
    return -1; // Return -1 if not found
}

void StudentManager::updateStudent() {
    int id;
    std::cout << "\nEnter the ID of the student to update: ";
    std::cin >> id;

    int index = findStudentIndex(id);
    if (index != -1) {
        std::string newName, newMajor;
        std::cout << "Enter new name for student " << id << ": ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newName);

        std::cout << "Enter new major for student " << id << ": ";
        std::getline(std::cin, newMajor);

        students[index].setName(newName);
        students[index].setMajor(newMajor);

        std::cout << "\nStudent record updated successfully." << std::endl;
    } else {
        std::cout << "\nStudent with ID " << id << " not found." << std::endl;
    }
}

void StudentManager::deleteStudent() {
    int id;
    std::cout << "\nEnter the ID of the student to delete: ";
    std::cin >> id;

    int index = findStudentIndex(id);
    if (index != -1) {
        students.erase(students.begin() + index);
        std::cout << "\nStudent record deleted successfully." << std::endl;
    } else {
        std::cout << "\nStudent with ID " << id << " not found." << std::endl;
    }
}

void StudentManager::run() {
    int choice;
    do {
        std::cout << "\n===== Student Management System =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Delete Student\n";
        std::cout << "5. Exit\n";
        std::cout << "=====================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Input validation
        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                std::cout << "\nExiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "\nInvalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
}