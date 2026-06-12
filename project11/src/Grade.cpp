#include "Grade.h"
#include <iostream>
#include <iomanip>
//start of the code.........
.....................
...........................
........
Grade::Grade(int studentId, const std::string& courseCode, double marks)
    : studentId(studentId), courseCode(courseCode), marks(marks) {
    letterGrade = calculateLetterGrade();
}

int Grade::getStudentId() const {
    return studentId;
}

std::string Grade::getCourseCode() const {
    return courseCode;
}

double Grade::getMarks() const {
    return marks;
}

char Grade::getLetterGrade() const {
    return letterGrade;
}

void Grade::setMarks(double newMarks) {
    if (newMarks >= 0 && newMarks <= 100) {
        marks = newMarks;
        letterGrade = calculateLetterGrade();
    }
}

char Grade::calculateLetterGrade() {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

double Grade::convertLetterToGPA(char letter) {
    switch (letter) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

void Grade::displayGrade() const {
    std::cout << "Student ID: " << studentId << std::endl;
    std::cout << "Course Code: " << courseCode << std::endl;
    std::cout << "Marks: " << std::fixed << std::setprecision(2) << marks << std::endl;
    std::cout << "Grade: " << letterGrade << std::endl;
}
// end of the line
