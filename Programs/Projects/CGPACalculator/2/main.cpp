#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Course {
public:
    int creditHours;
    double gradePoint;

    Course(int cHVal, double gPVal);
};

Course::Course(int cHVal, double gPVal)
    :creditHours(cHVal), gradePoint(gPVal) {
}

int main() {
    int noOfCourses {0}, currentCreditHours {0}, totalCreditHours {0};
    double currentGradePoint {0.0}, totalGradePoint {0.0};
    vector<Course> courseObj;

    cout << "Enter the number of courses: ";
    cin >> noOfCourses;

    for(int i {0}; i < noOfCourses; ++i) {
        cout << "Enter the Credit Hours for course " << i + 1 << " : ";
        cin >> currentCreditHours;
        cout << "\nEnter the Grade Point: " << i + 1 << " : ";
        cin >> currentGradePoint;

        Course newCourse(currentCreditHours, currentGradePoint);
        courseObj.push_back(newCourse);
    }

    for(auto obj : courseObj) {
        totalCreditHours += obj.creditHours;
        totalGradePoint += (obj.creditHours * obj.gradePoint);
    }
    if(totalCreditHours == 0) {
        cout << "No courses to calculate!";
    } else {
        cout << "\nYour CGPA is: " << (totalGradePoint/totalCreditHours);
    }
    return 0;
}