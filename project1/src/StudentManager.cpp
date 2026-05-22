#include "../include/StudentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

StudentManager::StudentManager() : nextId(1) {}

void StudentManager::addStudent(const std::string& name, const std::string& email) {
    auto student = std::make_shared<Student>(nextId++, name, email);
    students.push_back(student);
    std::cout << "✓ Student added successfully with ID: " << student->getId() << "\n";
}

bool StudentManager::removeStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const std::shared_ptr<Student>& s) { return s->getId() == id; });
    
    if (it != students.end()) {
        students.erase(it);
        std::cout << "✓ Student removed successfully.\n";
        return true;
    }
    std::cout << "✗ Student not found.\n";
    return false;
}

std::shared_ptr<Student> StudentManager::getStudent(int id) {
    return findStudentById(id);
}

std::shared_ptr<Student> StudentManager::findStudentById(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const std::shared_ptr<Student>& s) { return s->getId() == id; });
    
    return (it != students.end()) ? *it : nullptr;
}

bool StudentManager::studentExists(int id) const {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const std::shared_ptr<Student>& s) { return s->getId() == id; });
    
    return it != students.end();
}

bool StudentManager::addGradeToStudent(int id, double grade) {
    auto student = findStudentById(id);
    if (student) {
        student->addGrade(grade);
        std::cout << "✓ Grade added successfully.\n";
        return true;
    }
    std::cout << "✗ Student not found.\n";
    return false;
}

bool StudentManager::removeLastGradeFromStudent(int id) {
    auto student = findStudentById(id);
    if (student) {
        student->removeLastGrade();
        std::cout << "✓ Last grade removed successfully.\n";
        return true;
    }
    std::cout << "✗ Student not found.\n";
    return false;
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students in the system.\n";
        return;
    }
    
    std::cout << "\n========== ALL STUDENTS ==========\n";
    for (const auto& student : students) {
        std::cout << "ID: " << student->getId() 
                  << " | Name: " << student->getName() 
                  << " | Email: " << student->getEmail() << "\n";
    }
    std::cout << "==================================\n";
}

void StudentManager::displayStudentDetails(int id) const {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const std::shared_ptr<Student>& s) { return s->getId() == id; });
    
    if (it != students.end()) {
        (*it)->displayInfo();
    } else {
        std::cout << "✗ Student not found.\n";
    }
}

double StudentManager::getClassAverage() const {
    if (students.empty()) {
        return 0.0;
    }
    
    double totalAverage = 0.0;
    int countWithGrades = 0;
    
    for (const auto& student : students) {
        if (!student->getGrades().empty()) {
            totalAverage += student->getAverageGrade();
            countWithGrades++;
        }
    }
    
    return countWithGrades > 0 ? totalAverage / countWithGrades : 0.0;
}

std::shared_ptr<Student> StudentManager::getTopStudent() const {
    if (students.empty()) {
        return nullptr;
    }
    
    return *std::max_element(students.begin(), students.end(),
        [](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b) {
            return a->getGPA() < b->getGPA();
        });
}

int StudentManager::getStudentCount() const {
    return students.size();
}

void StudentManager::displayStatistics() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n========== CLASS STATISTICS ==========\n";
    std::cout << "Total Students: " << getStudentCount() << "\n";
    std::cout << "Class Average: " << getClassAverage() << "\n";
    
    auto topStudent = getTopStudent();
    if (topStudent) {
        std::cout << "Top Student: " << topStudent->getName() 
                  << " (GPA: " << topStudent->getGPA() << ")\n";
    }
    std::cout << "======================================\n";
}

bool StudentManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "✗ Failed to open file for writing.\n";
        return false;
    }
    
    file << students.size() << "\n";
    for (const auto& student : students) {
        file << student->getId() << "|" << student->getName() << "|" 
             << student->getEmail();
        
        auto grades = student->getGrades();
        for (double grade : grades) {
            file << "|" << grade;
        }
        file << "\n";
    }
    
    file.close();
    std::cout << "✓ Data saved successfully.\n";
    return true;
}

bool StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "✗ Failed to open file for reading.\n";
        return false;
    }
    
    students.clear();
    int count;
    file >> count;
    file.ignore();
    
    for (int i = 0; i < count; ++i) {
        std::string line;
        std::getline(file, line);
        
        std::stringstream ss(line);
        int id;
        std::string name, email, gradeStr;
        
        ss >> id;
        ss.ignore();
        std::getline(ss, name, '|');
        std::getline(ss, email, '|');
        
        auto student = std::make_shared<Student>(id, name, email);
        
        while (std::getline(ss, gradeStr, '|')) {
            if (!gradeStr.empty()) {
                student->addGrade(std::stod(gradeStr));
            }
        }
        
        students.push_back(student);
        if (id >= nextId) nextId = id + 1;
    }
    
    file.close();
    std::cout << "✓ Data loaded successfully.\n";
    return true;
}
