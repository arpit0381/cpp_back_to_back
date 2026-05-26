#include "Instructor.h"
#include <iostream>
#include <algorithm>

Instructor::Instructor(const std::string& id, const std::string& name, 
                       const std::string& department, const std::string& email, 
                       const std::string& office)
    : instructorId(id), instructorName(name), department(department), 
      email(email), officeLocation(office) {}

std::string Instructor::getInstructorId() const {
    return instructorId;
}

std::string Instructor::getInstructorName() const {
    return instructorName;
}

std::string Instructor::getDepartment() const {
    return department;
}

std::string Instructor::getEmail() const {
    return email;
}

std::string Instructor::getOfficeLocation() const {
    return officeLocation;
}

std::vector<std::string> Instructor::getAssignedCourses() const {
    return assignedCourses;
}

int Instructor::getCourseCount() const {
    return assignedCourses.size();
}

bool Instructor::assignCourse(const std::string& courseCode) {
    if (!isAssignedTo(courseCode)) {
        assignedCourses.push_back(courseCode);
        return true;
    }
    return false;
}

bool Instructor::removeCourse(const std::string& courseCode) {
    auto it = std::find(assignedCourses.begin(), assignedCourses.end(), courseCode);
    if (it != assignedCourses.end()) {
        assignedCourses.erase(it);
        return true;
    }
    return false;
}

bool Instructor::isAssignedTo(const std::string& courseCode) const {
    return std::find(assignedCourses.begin(), assignedCourses.end(), courseCode) != assignedCourses.end();
}

void Instructor::displayInstructor() const {
    std::cout << "Instructor ID: " << instructorId << std::endl;
    std::cout << "Name: " << instructorName << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Office: " << officeLocation << std::endl;
    std::cout << "Assigned Courses: " << assignedCourses.size() << std::endl;
}
