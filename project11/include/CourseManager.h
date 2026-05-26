#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include "Course.h"
#include "Student.h"
#include "Instructor.h"
#include "Grade.h"
#include <vector>
#include <map>
#include <memory>

class CourseManager {
private:
    std::map<std::string, std::unique_ptr<Course>> courses;
    std::map<int, std::unique_ptr<Student>> students;
    std::map<std::string, std::unique_ptr<Instructor>> instructors;
    std::vector<std::unique_ptr<Grade>> grades;

public:
    CourseManager();
    
    // Course operations
    void addCourse(const std::string& code, const std::string& name, int credits, int capacity);
    bool removeCourse(const std::string& courseCode);
    Course* getCourse(const std::string& courseCode);
    void displayAllCourses() const;
    
    // Student operations
    void addStudent(int id, const std::string& name, const std::string& email);
    bool removeStudent(int studentId);
    Student* getStudent(int studentId);
    void displayAllStudents() const;
    
    // Instructor operations
    void addInstructor(const std::string& id, const std::string& name, 
                       const std::string& department, const std::string& email, 
                       const std::string& office);
    bool removeInstructor(const std::string& instructorId);
    Instructor* getInstructor(const std::string& instructorId);
    void displayAllInstructors() const;
    
    // Enrollment operations
    bool enrollStudentInCourse(int studentId, const std::string& courseCode);
    bool removeStudentFromCourse(int studentId, const std::string& courseCode);
    
    // Instructor assignment
    bool assignInstructorToCourse(const std::string& instructorId, const std::string& courseCode);
    
    // Grade operations
    void addGrade(int studentId, const std::string& courseCode, double marks);
    void updateGrade(int studentId, const std::string& courseCode, double marks);
    double getStudentGPA(int studentId) const;
    void displayStudentGrades(int studentId) const;
    void displayCourseGrades(const std::string& courseCode) const;
    
    // Statistics
    int getTotalCourses() const;
    int getTotalStudents() const;
    int getTotalInstructors() const;
    void displayCourseStatistics(const std::string& courseCode) const;
    void displayTopStudents(int count = 5) const;
};

#endif // COURSEMANAGER_H
