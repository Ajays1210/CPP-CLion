#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double gradePoint {0.0}, totalGradePoint {0.0}, cgpa {0.0};
    int numberOfCourses {0}, creditHours {0}, totalCreditHours {0};

    cout << "Enter the number of courses: ";
    cin >> numberOfCourses;

    // while(numberOfCourses) {
    for(int i = 0; i < numberOfCourses; ++i) {

        // double tempGP {0.0};
        cout << "\nEnter the credit hour(s) and for this course: ";
        cin >> creditHours;
        cout << "\nEnter the grade point(s) for this course: ";
        cin >> gradePoint;

        totalGradePoint += (creditHours * gradePoint);
        // totalGradePoint += tempGP;
        totalCreditHours += creditHours;
        // cout << "Total credit point for this course is: " << tempGP << endl;
        // --numberOfCourses;
    }

    if(totalCreditHours <= 0) {
        cout << "No courses to calculate";
    } else {
        cgpa = totalGradePoint / totalCreditHours;
        cout << "\nYour CGPA is: " << cgpa << endl;
    }

    return 0;
}