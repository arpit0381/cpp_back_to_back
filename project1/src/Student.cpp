#include "../include/Student.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
........................///////////////////////
Student::Student(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email), gpa(0.0) {}

Student::~Student() {
    // Cleanup if needed
}

// Getters
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getEmail() const {
    return email;
}

std::vector<double> Student::getGrades() const {
    return grades;
}

double Student::getGPA() const {
    return gpa;
}

// Setters
void Student::setName(const std::string& newName) {
    if (!newName.empty()) {
        name = newName;
    }
}

void Student::setEmail(const std::string& newEmail) {
    if (!newEmail.empty()) {
        email = newEmail;
    }
}

// Grade management
void Student::addGrade(double grade) {
    if (isValidGrade(grade)) {
        grades.push_back(grade);
        calculateGPA();
    }
}

void Student::removeLastGrade() {
    if (!grades.empty()) {
        grades.pop_back();
        calculateGPA();
    }
}

double Student::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

bool Student::isValidGrade(double grade) const {
    return grade >= 0.0 && grade <= 100.0;
}

void Student::calculateGPA() {
    if (grades.empty()) {
        gpa = 0.0;
        return;
    }

    double average = getAverageGrade();
    
    // Convert to 4.0 scale
    if (average >= 90) gpa = 4.0;
    else if (average >= 80) gpa = 3.0;
    else if (average >= 70) gpa = 2.0;
    else if (average >= 60) gpa = 1.0;
    else gpa = 0.0;
}

void Student::displayInfo() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Number of Grades: " << grades.size() << "\n";
    
    if (!grades.empty()) {
        std::cout << "Average Grade: " << getAverageGrade() << "\n";
        std::cout << "GPA: " << gpa << "\n";
    } else {
        std::cout << "No grades recorded yet.\n";
    }
}
