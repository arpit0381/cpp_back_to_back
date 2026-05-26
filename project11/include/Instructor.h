#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>

class Instructor {
private:
    std::string instructorId;
    std::string instructorName;
    std::string department;
    std::string email;
    std::vector<std::string> assignedCourses;
    std::string officeLocation;

public:
    Instructor(const std::string& id, const std::string& name, 
               const std::string& department, const std::string& email, 
               const std::string& office);
    
    // Getters
    std::string getInstructorId() const;
    std::string getInstructorName() const;
    std::string getDepartment() const;
    std::string getEmail() const;
    std::string getOfficeLocation() const;
    std::vector<std::string> getAssignedCourses() const;
    int getCourseCount() const;
    
    // Course operations
    bool assignCourse(const std::string& courseCode);
    bool removeCourse(const std::string& courseCode);
    bool isAssignedTo(const std::string& courseCode) const;
    
    // Display
    void displayInstructor() const;
};

#endif // INSTRUCTOR_H
