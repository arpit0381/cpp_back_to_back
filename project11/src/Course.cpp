#include "Course.h"
#include <iostream>
#include <algorithm>

Course::Course(const std::string& code, const std::string& name, int credits, int capacity)
    : courseCode(code), courseName(name), credits(credits), 
      maxCapacity(capacity), enrolledStudents(0) {}

std::string Course::getCourseCode() const {
    return courseCode;
}

std::string Course::getCourseName() const {
    return courseName;
}

int Course::getCredits() const {
    return credits;
}

int Course::getMaxCapacity() const {
    return maxCapacity;
}

int Course::getEnrolledStudents() const {
    return enrolledStudents;
}

std::string Course::getInstructorId() const {
    return instructorId;
}

std::vector<int> Course::getStudentIds() const {
    return studentIds;
}

void Course::setInstructor(const std::string& id) {
    instructorId = id;
}

bool Course::enrollStudent(int studentId) {
    if (enrolledStudents < maxCapacity && !isStudentEnrolled(studentId)) {
        studentIds.push_back(studentId);
        enrolledStudents++;
        return true;
    }
    return false;
}

bool Course::removeStudent(int studentId) {
    auto it = std::find(studentIds.begin(), studentIds.end(), studentId);
    if (it != studentIds.end()) {
        studentIds.erase(it);
        enrolledStudents--;
        return true;
    }
    return false;
}

bool Course::isStudentEnrolled(int studentId) const {
    return std::find(studentIds.begin(), studentIds.end(), studentId) != studentIds.end();
}

bool Course::isFull() const {
    return enrolledStudents >= maxCapacity;
}

void Course::displayCourse() const {
    std::cout << "Course Code: " << courseCode << std::endl;
    std::cout << "Course Name: " << courseName << std::endl;
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "Capacity: " << maxCapacity << std::endl;
    std::cout << "Enrolled Students: " << enrolledStudents << std::endl;
    if (!instructorId.empty()) {
        std::cout << "Instructor ID: " << instructorId << std::endl;
    }
}
