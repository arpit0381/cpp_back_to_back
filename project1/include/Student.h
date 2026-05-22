#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    int id;
    std::string name;
    std::string email;
    std::vector<double> grades;
    double gpa;

    // Private helper method
    void calculateGPA();

public:
    // Constructor and Destructor
    Student(int id, const std::string& name, const std::string& email);
    ~Student();

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::vector<double> getGrades() const;
    double getGPA() const;

    // Setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);

    // Grade management
    void addGrade(double grade);
    void removeLastGrade();
    double getAverageGrade() const;

    // Display information
    void displayInfo() const;

    // Validation
    bool isValidGrade(double grade) const;
};

#endif // STUDENT_H
