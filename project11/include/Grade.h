#ifndef GRADE_H
#define GRADE_H

#include <string>

class Grade {
private:
    int studentId;
    std::string courseCode;
    double marks;
    char letterGrade;

public:
    Grade(int studentId, const std::string& courseCode, double marks);
    
    // Getters
    int getStudentId() const;
    std::string getCourseCode() const;
    double getMarks() const;
    char getLetterGrade() const;
    
    // Setters
    void setMarks(double newMarks);
    
    // Grade calculation
    char calculateLetterGrade();
    static double convertLetterToGPA(char letter);
    
    // Display
    void displayGrade() const;
};

#endif // GRADE_H
