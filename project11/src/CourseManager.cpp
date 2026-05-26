#include "CourseManager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>

CourseManager::CourseManager() {}

void CourseManager::addCourse(const std::string& code, const std::string& name, int credits, int capacity) {
    courses[code] = std::make_unique<Course>(code, name, credits, capacity);
    std::cout << "Course added successfully!" << std::endl;
}

bool CourseManager::removeCourse(const std::string& courseCode) {
    auto it = courses.find(courseCode);
    if (it != courses.end()) {
        courses.erase(it);
        return true;
    }
    return false;
}

Course* CourseManager::getCourse(const std::string& courseCode) {
    auto it = courses.find(courseCode);
    if (it != courses.end()) {
        return it->second.get();
    }
    return nullptr;
}

void CourseManager::displayAllCourses() const {
    if (courses.empty()) {
        std::cout << "No courses in the system." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Courses ===" << std::endl;
    for (const auto& [code, course] : courses) {
        course->displayCourse();
        std::cout << std::string(40, '-') << std::endl;
    }
}

void CourseManager::addStudent(int id, const std::string& name, const std::string& email) {
    students[id] = std::make_unique<Student>(id, name, email);
    std::cout << "Student added successfully!" << std::endl;
}

bool CourseManager::removeStudent(int studentId) {
    auto it = students.find(studentId);
    if (it != students.end()) {
        students.erase(it);
        return true;
    }
    return false;
}

Student* CourseManager::getStudent(int studentId) {
    auto it = students.find(studentId);
    if (it != students.end()) {
        return it->second.get();
    }
    return nullptr;
}

void CourseManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students in the system." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Students ===" << std::endl;
    for (const auto& [id, student] : students) {
        student->displayStudent();
        std::cout << std::string(40, '-') << std::endl;
    }
}

void CourseManager::addInstructor(const std::string& id, const std::string& name, 
                                   const std::string& department, const std::string& email, 
                                   const std::string& office) {
    instructors[id] = std::make_unique<Instructor>(id, name, department, email, office);
    std::cout << "Instructor added successfully!" << std::endl;
}

bool CourseManager::removeInstructor(const std::string& instructorId) {
    auto it = instructors.find(instructorId);
    if (it != instructors.end()) {
        instructors.erase(it);
        return true;
    }
    return false;
}

Instructor* CourseManager::getInstructor(const std::string& instructorId) {
    auto it = instructors.find(instructorId);
    if (it != instructors.end()) {
        return it->second.get();
    }
    return nullptr;
}

void CourseManager::displayAllInstructors() const {
    if (instructors.empty()) {
        std::cout << "No instructors in the system." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Instructors ===" << std::endl;
    for (const auto& [id, instructor] : instructors) {
        instructor->displayInstructor();
        std::cout << std::string(40, '-') << std::endl;
    }
}

bool CourseManager::enrollStudentInCourse(int studentId, const std::string& courseCode) {
    auto student_it = students.find(studentId);
    auto course_it = courses.find(courseCode);
    
    if (student_it != students.end() && course_it != courses.end()) {
        if (!course_it->second->isFull() && course_it->second->enrollStudent(studentId)) {
            student_it->second->enrollInCourse(courseCode);
            return true;
        }
    }
    return false;
}

bool CourseManager::removeStudentFromCourse(int studentId, const std::string& courseCode) {
    auto student_it = students.find(studentId);
    auto course_it = courses.find(courseCode);
    
    if (student_it != students.end() && course_it != courses.end()) {
        if (course_it->second->removeStudent(studentId)) {
            student_it->second->removeFromCourse(courseCode);
            return true;
        }
    }
    return false;
}

bool CourseManager::assignInstructorToCourse(const std::string& instructorId, const std::string& courseCode) {
    auto instructor_it = instructors.find(instructorId);
    auto course_it = courses.find(courseCode);
    
    if (instructor_it != instructors.end() && course_it != courses.end()) {
        if (instructor_it->second->assignCourse(courseCode)) {
            course_it->second->setInstructor(instructorId);
            return true;
        }
    }
    return false;
}

void CourseManager::addGrade(int studentId, const std::string& courseCode, double marks) {
    if (students.find(studentId) != students.end() && courses.find(courseCode) != courses.end()) {
        grades.push_back(std::make_unique<Grade>(studentId, courseCode, marks));
        std::cout << "Grade added successfully!" << std::endl;
    }
}

void CourseManager::updateGrade(int studentId, const std::string& courseCode, double marks) {
    for (auto& grade : grades) {
        if (grade->getStudentId() == studentId && grade->getCourseCode() == courseCode) {
            grade->setMarks(marks);
            std::cout << "Grade updated successfully!" << std::endl;
            return;
        }
    }
}

double CourseManager::getStudentGPA(int studentId) const {
    auto student_it = students.find(studentId);
    if (student_it == students.end()) return 0.0;
    
    std::vector<double> gpaValues;
    for (const auto& grade : grades) {
        if (grade->getStudentId() == studentId) {
            gpaValues.push_back(Grade::convertLetterToGPA(grade->getLetterGrade()));
        }
    }
    
    if (gpaValues.empty()) return 0.0;
    
    double avgGPA = std::accumulate(gpaValues.begin(), gpaValues.end(), 0.0) / gpaValues.size();
    return avgGPA;
}

void CourseManager::displayStudentGrades(int studentId) const {
    std::cout << "\n=== Grades for Student ID: " << studentId << " ===" << std::endl;
    
    bool found = false;
    for (const auto& grade : grades) {
        if (grade->getStudentId() == studentId) {
            grade->displayGrade();
            std::cout << std::string(40, '-') << std::endl;
            found = true;
        }
    }
    
    if (found) {
        std::cout << "Student GPA: " << std::fixed << std::setprecision(2) 
                 << getStudentGPA(studentId) << std::endl;
    } else {
        std::cout << "No grades found for this student." << std::endl;
    }
}

void CourseManager::displayCourseGrades(const std::string& courseCode) const {
    std::cout << "\n=== Grades for Course: " << courseCode << " ===" << std::endl;
    
    bool found = false;
    for (const auto& grade : grades) {
        if (grade->getCourseCode() == courseCode) {
            grade->displayGrade();
            std::cout << std::string(40, '-') << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No grades found for this course." << std::endl;
    }
}

int CourseManager::getTotalCourses() const {
    return courses.size();
}

int CourseManager::getTotalStudents() const {
    return students.size();
}

int CourseManager::getTotalInstructors() const {
    return instructors.size();
}

void CourseManager::displayCourseStatistics(const std::string& courseCode) const {
    auto it = courses.find(courseCode);
    if (it != courses.end()) {
        std::cout << "\n=== Course Statistics: " << courseCode << " ===" << std::endl;
        it->second->displayCourse();
        
        std::cout << "Average Grade: ";
        std::vector<double> marks;
        for (const auto& grade : grades) {
            if (grade->getCourseCode() == courseCode) {
                marks.push_back(grade->getMarks());
            }
        }
        
        if (!marks.empty()) {
            double avg = std::accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
            std::cout << std::fixed << std::setprecision(2) << avg << std::endl;
        } else {
            std::cout << "No grades recorded" << std::endl;
        }
    }
}

void CourseManager::displayTopStudents(int count) const {
    std::cout << "\n=== Top " << count << " Students ===" << std::endl;
    
    std::vector<std::pair<int, double>> studentGPAs;
    for (const auto& [id, student] : students) {
        double gpa = getStudentGPA(id);
        studentGPAs.push_back({id, gpa});
    }
    
    std::sort(studentGPAs.begin(), studentGPAs.end(), 
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    int limit = std::min(count, static_cast<int>(studentGPAs.size()));
    for (int i = 0; i < limit; ++i) {
        auto student = students.find(studentGPAs[i].first);
        if (student != students.end()) {
            std::cout << i + 1 << ". " << student->second->getStudentName() 
                     << " - GPA: " << std::fixed << std::setprecision(2) 
                     << studentGPAs[i].second << std::endl;
        }
    }
}
