#include "CourseManager.h"
#include <iostream>
#include <iomanip>
// heheh.....
void displayMenu() {
    std::cout << "\n========== University Course Manager ==========" << std::endl;
    std::cout << "--- COURSE MANAGEMENT ---" << std::endl;
    std::cout << "1. Add Course" << std::endl;
    std::cout << "2. Display All Courses" << std::endl;
    std::cout << "3. Remove Course" << std::endl;
    std::cout << "\n--- STUDENT MANAGEMENT ---" << std::endl;
    std::cout << "4. Add Student" << std::endl;
    std::cout << "5. Display All Students" << std::endl;
    std::cout << "6. Remove Student" << std::endl;
    std::cout << "\n--- INSTRUCTOR MANAGEMENT ---" << std::endl;
    std::cout << "7. Add Instructor" << std::endl;
    std::cout << "8. Display All Instructors" << std::endl;
    std::cout << "9. Remove Instructor" << std::endl;
    std::cout << "\n--- ENROLLMENT ---" << std::endl;
    std::cout << "10. Enroll Student in Course" << std::endl;//heheh
    std::cout << "11. Remove Student from Course" << std::endl;
    std::cout << "12. Assign Instructor to Course" << std::endl;
    std::cout << "\n--- GRADES ---" << std::endl;
    std::cout << "13. Add Grade" << std::endl;
    std::cout << "14. Update Grade" << std::endl;
    std::cout << "15. Display Student Grades" << std::endl;
    std::cout << "16. Display Course Grades" << std::endl;
    std::cout << "\n--- STATISTICS ---" << std::endl;
    std::cout << "17. Display System Statistics" << std::endl;
    std::cout << "18. Display Course Statistics" << std::endl;
    std::cout << "19. Display Top Students" << std::endl;
    std::cout << "\n0. Exit" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    CourseManager manager;
    int choice;
    
    // Add sample data
    manager.addCourse("CS101", "Introduction to Programming", 3, 30);
    manager.addCourse("CS201", "Data Structures", 4, 25);
    manager.addCourse("MATH101", "Calculus I", 4, 35);
    
    manager.addStudent(1001, "Alice Johnson", "alice@university.edu");
    manager.addStudent(1002, "Bob Smith", "bob@university.edu");
    manager.addStudent(1003, "Carol White", "carol@university.edu");
    manager.addStudent(1004, "David Brown", "david@university.edu");
    
    manager.addInstructor("I001", "Prof. Anderson", "Computer Science", 
                         "anderson@university.edu", "Room 101");
    manager.addInstructor("I002", "Prof. Miller", "Mathematics", 
                         "miller@university.edu", "Room 205");
    
    // Enroll students
    manager.enrollStudentInCourse(1001, "CS101");
    manager.enrollStudentInCourse(1001, "MATH101");
    manager.enrollStudentInCourse(1002, "CS101");
    manager.enrollStudentInCourse(1003, "CS201");
    manager.enrollStudentInCourse(1004, "CS101");
    manager.enrollStudentInCourse(1004, "MATH101");
    
    // Assign instructors
    manager.assignInstructorToCourse("I001", "CS101");
    manager.assignInstructorToCourse("I001", "CS201");
    manager.assignInstructorToCourse("I002", "MATH101");
    
    // Add grades
    manager.addGrade(1001, "CS101", 92.5);
    manager.addGrade(1001, "MATH101", 88.0);
    manager.addGrade(1002, "CS101", 85.5);
    manager.addGrade(1003, "CS201", 90.0);
    manager.addGrade(1004, "CS101", 78.5);
    manager.addGrade(1004, "MATH101", 82.0);
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                std::string code, name;
                int credits, capacity;
                
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, code);
                std::cout << "Enter Course Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Credits: ";
                std::cin >> credits;
                std::cout << "Enter Max Capacity: ";
                std::cin >> capacity;
                
                manager.addCourse(code, name, credits, capacity);
                break;
            }
            
            case 2:
                manager.displayAllCourses();
                break;
            
            case 3: {
                std::string code;
                std::cout << "Enter Course Code to remove: ";
                std::getline(std::cin, code);
                
                if (manager.removeCourse(code)) {
                    std::cout << "Course removed successfully!" << std::endl;
                } else {
                    std::cout << "Course not found!" << std::endl;
                }
                break;
            }
            
            case 4: {
                int id;
                std::string name, email;
                
                std::cout << "Enter Student ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Email: ";
                std::getline(std::cin, email);
                
                manager.addStudent(id, name, email);
                break;
            }
            
            case 5:
                manager.displayAllStudents();
                break;
            
            case 6: {
                int id;
                std::cout << "Enter Student ID to remove: ";
                std::cin >> id;
                
                if (manager.removeStudent(id)) {
                    std::cout << "Student removed successfully!" << std::endl;
                } else {
                    std::cout << "Student not found!" << std::endl;
                }
                break;
            }
            
            case 7: {
                std::string id, name, dept, email, office;
                
                std::cin.ignore();
                std::cout << "Enter Instructor ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Instructor Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Department: ";
                std::getline(std::cin, dept);
                std::cout << "Enter Email: ";
                std::getline(std::cin, email);
                std::cout << "Enter Office Location: ";
                std::getline(std::cin, office);
                
                manager.addInstructor(id, name, dept, email, office);
                break;
            }
            
            case 8:
                manager.displayAllInstructors();
                break;
            
            case 9: {
                std::string id;
                std::cout << "Enter Instructor ID to remove: ";
                std::getline(std::cin, id);
                
                if (manager.removeInstructor(id)) {
                    std::cout << "Instructor removed successfully!" << std::endl;
                } else {
                    std::cout << "Instructor not found!" << std::endl;
                }
                break;
            }
            
            case 10: {
                int studentId;
                std::string courseCode;
                
                std::cout << "Enter Student ID: ";
                std::cin >> studentId;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                
                if (manager.enrollStudentInCourse(studentId, courseCode)) {
                    std::cout << "Student enrolled successfully!" << std::endl;
                } else {
                    std::cout << "Enrollment failed! Course may be full or student already enrolled." << std::endl;
                }
                break;
            }
            
            case 11: {
                int studentId;
                std::string courseCode;
                
                std::cout << "Enter Student ID: ";
                std::cin >> studentId;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                
                if (manager.removeStudentFromCourse(studentId, courseCode)) {
                    std::cout << "Student removed from course!" << std::endl;
                } else {
                    std::cout << "Remove failed!" << std::endl;
                }
                break;
            }
            
            case 12: {
                std::string instructorId, courseCode;
                
                std::cout << "Enter Instructor ID: ";
                std::getline(std::cin, instructorId);
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                
                if (manager.assignInstructorToCourse(instructorId, courseCode)) {
                    std::cout << "Instructor assigned successfully!" << std::endl;
                } else {
                    std::cout << "Assignment failed!" << std::endl;
                }
                break;
            }
            
            case 13: {
                int studentId;
                std::string courseCode;
                double marks;
                
                std::cout << "Enter Student ID: ";
                std::cin >> studentId;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                std::cout << "Enter Marks (0-100): ";
                std::cin >> marks;
                
                manager.addGrade(studentId, courseCode, marks);
                break;
            }
            
            case 14: {
                int studentId;
                std::string courseCode;
                double marks;
                
                std::cout << "Enter Student ID: ";
                std::cin >> studentId;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                std::cout << "Enter New Marks (0-100): ";
                std::cin >> marks;
                
                manager.updateGrade(studentId, courseCode, marks);
                break;
            }
            
            case 15: {
                int studentId;
                std::cout << "Enter Student ID: ";
                std::cin >> studentId;
                
                manager.displayStudentGrades(studentId);
                break;
            }
            
            case 16: {
                std::string courseCode;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                
                manager.displayCourseGrades(courseCode);
                break;
            }
            
            case 17: {
                std::cout << "\n=== System Statistics ===" << std::endl;
                std::cout << "Total Courses: " << manager.getTotalCourses() << std::endl;
                std::cout << "Total Students: " << manager.getTotalStudents() << std::endl;
                std::cout << "Total Instructors: " << manager.getTotalInstructors() << std::endl;
                break;
            }
            
            case 18: {
                std::string courseCode;
                std::cin.ignore();
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                
                manager.displayCourseStatistics(courseCode);
                break;
            }
            
            case 19: {
                int count;
                std::cout << "Enter number of top students to display: ";
                std::cin >> count;
                
                manager.displayTopStudents(count);
                break;
            }
            
            case 0:
                std::cout << "Exiting... Thank you!" << std::endl;
                return 0;
            
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}
