#include <iostream>
#include "include/student.h"
#include "include/schedule.h"
#include "include/assignment.h"
void manageAssignments(Student& student) {
    int subChoice;
    do {
        std::cout << "\nAssignment Menu:\n";
        std::cout << "1. Add Assignment\n";
        std::cout << "2. View Assignments\n";
        std::cout << "3. Mark Assignment as Completed\n";
        std::cout << "4. Remove Assignment\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> subChoice;
        std::cin.ignore();

        switch (subChoice) {
            case 1: {
                std::string title, dueDate;
                std::cout << "Enter assignment title: ";
                std::getline(std::cin, title);
                std::cout << "Enter due date: ";
                std::getline(std::cin, dueDate);
                Assignment newAssignment(title, dueDate);
                student.addAssignment(newAssignment);
                break;
            }
            case 2:
                student.viewAssignments();
                break;
            case 3: {
                std::string title;
                std::cout << "Enter assignment title to mark as completed: ";
                std::getline(std::cin, title);
                for (auto& assignment : student.assignments) {
                    if (assignment.getTitle() == title) {
                        assignment.markCompleted();
                        std::cout << "Assignment marked as completed.\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                std::string title;
                std::cout << "Enter assignment title to remove: ";
                std::getline(std::cin, title);
                student.removeAssignment(title);
                break;
            }
            case 5:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (subChoice != 5);
}

int main() {
    std::cout << "Welcome to the Student Management System!" << std::endl;

    std::string name, studentID;
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter student ID: ";
    std::getline(std::cin, studentID);

    Student student(name, studentID);
    Schedule schedule;

    int choice;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Manage Assignments\n";
        std::cout << "2. Manage Schedule\n";
        std::cout << "3. View Student Information\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                manageAssignments(student);
                break;
            case 2: {
                std::string className, time, day;
                std::cout << "Enter class name: ";
                std::getline(std::cin, className);
                std::cout << "Enter class time: ";
                std::getline(std::cin, time);
                std::cout << "Enter class day: ";
                std::getline(std::cin, day);
                schedule.addClass(className, time, day);
                break;
            }
            case 3:
                std::cout << "\nStudent Name: " << student.name << "\n"
                          << "Student ID: " << student.studentID << "\n";
                student.viewAssignments();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
