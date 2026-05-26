#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    int studentId;
    std::string studentName;
    std::string email;
    std::vector<std::string> enrolledCourses;
    double gpa;

public:
    Student(int id, const std::string& name, const std::string& email);
    
    // Getters
    int getStudentId() const;
    std::string getStudentName() const;
    std::string getEmail() const;
    std::vector<std::string> getEnrolledCourses() const;
    double getGPA() const;
    int getCourseCount() const;
    
    // Course operations
    bool enrollInCourse(const std::string& courseCode);
    bool removeFromCourse(const std::string& courseCode);
    bool isEnrolledInCourse(const std::string& courseCode) const;
    
    // GPA operations
    void setGPA(double newGPA);
    
    // Display
    void displayStudent() const;
};

#endif // STUDENT_H
