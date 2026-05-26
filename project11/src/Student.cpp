#include "Student.h"
#include <iostream>
#include <algorithm>

Student::Student(int id, const std::string& name, const std::string& email)
    : studentId(id), studentName(name), email(email), gpa(0.0) {}

int Student::getStudentId() const {
    return studentId;
}

std::string Student::getStudentName() const {
    return studentName;
}

std::string Student::getEmail() const {
    return email;
}

std::vector<std::string> Student::getEnrolledCourses() const {
    return enrolledCourses;
}

double Student::getGPA() const {
    return gpa;
}

int Student::getCourseCount() const {
    return enrolledCourses.size();
}

bool Student::enrollInCourse(const std::string& courseCode) {
    if (!isEnrolledInCourse(courseCode)) {
        enrolledCourses.push_back(courseCode);
        return true;
    }
    return false;
}

bool Student::removeFromCourse(const std::string& courseCode) {
    auto it = std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode);
    if (it != enrolledCourses.end()) {
        enrolledCourses.erase(it);
        return true;
    }
    return false;
}

bool Student::isEnrolledInCourse(const std::string& courseCode) const {
    return std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) != enrolledCourses.end();
}

void Student::setGPA(double newGPA) {
    if (newGPA >= 0.0 && newGPA <= 4.0) {
        gpa = newGPA;
    }
}

void Student::displayStudent() const {
    std::cout << "Student ID: " << studentId << std::endl;
    std::cout << "Name: " << studentName << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
    std::cout << "Enrolled Courses: " << enrolledCourses.size() << std::endl;
}
