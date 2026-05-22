#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>
#include <memory>

class StudentManager {
private:
    std::vector<std::shared_ptr<Student>> students;
    int nextId;

    // Private helper methods
    std::shared_ptr<Student> findStudentById(int id);
    bool studentExists(int id) const;

public:
    // Constructor
    StudentManager();

    // Student management
    void addStudent(const std::string& name, const std::string& email);
    bool removeStudent(int id);
    std::shared_ptr<Student> getStudent(int id);

    // Grade management
    bool addGradeToStudent(int id, double grade);
    bool removeLastGradeFromStudent(int id);

    // Retrieval and display
    void displayAllStudents() const;
    void displayStudentDetails(int id) const;
    double getClassAverage() const;
    std::shared_ptr<Student> getTopStudent() const;

    // Statistics
    int getStudentCount() const;
    void displayStatistics() const;

    // File operations
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};

#endif // STUDENT_MANAGER_H
