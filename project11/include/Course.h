#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course {
private:
    std::string courseCode;
    std::string courseName;
    int credits;
    int maxCapacity;
    int enrolledStudents;
    std::string instructorId;
    std::vector<int> studentIds;

public:
    Course(const std::string& code, const std::string& name, int credits, int capacity);
    
    // Getters
    std::string getCourseCode() const;
    std::string getCourseName() const;
    int getCredits() const;
    int getMaxCapacity() const;
    int getEnrolledStudents() const;
    std::string getInstructorId() const;
    std::vector<int> getStudentIds() const;
    
    // Setters
    void setInstructor(const std::string& instructorId);
    
    // Student operations
    bool enrollStudent(int studentId);
    bool removeStudent(int studentId);
    bool isStudentEnrolled(int studentId) const;
    bool isFull() const;
    
    // Display
    void displayCourse() const;
};

#endif // COURSE_H
