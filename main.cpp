#include <iostream>
#include "include/student.h"
#include "include/schedule.h"
#include "include/assignment.h"
#include <windows.h>
using namespace std;

void manageAssignments(Student& student) {
    int subChoice;
    do {
        cout << "\nAssignment Menu:\n";
        cout << "1. Add Assignment\n";
        cout << "2. View Assignments\n";
        cout << "3. Mark Assignment as Completed\n";
        cout << "4. Remove Assignment\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> subChoice;
        cin.ignore();


        switch (subChoice) {
            case 1: {
                string title, dueDate;
                cout << "Enter assignment title: ";
                getline(cin, title);
                cout << "Enter due date: ";
                getline(cin, dueDate);
                Assignment newAssignment(title, dueDate);
                student.addAssignment(newAssignment);
                break;
            }
            case 2:
                student.viewAssignments();
                break;
            case 3: {
                string title;
                cout << "Enter assignment title to mark as completed: ";
                getline(cin, title);
                for (auto& assignment : student.assignments) {
                    if (assignment.getTitle() == title) {
                        assignment.markCompleted();
                        cout << "Assignment marked as completed.\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                string title;
                cout << "Enter assignment title to remove: ";
                getline(cin, title);
                student.removeAssignment(title);
                break;
            }
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
        system("cls");
    } while (subChoice != 5);
}


int main() {
    cout << "Welcome to the Student Management System!" << endl;

    string name, studentID;
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    getline(cin, studentID);

    Student student(name, studentID);
    Schedule schedule;

    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Manage Assignments\n";
        cout << "2. Manage Schedule\n";
        cout << "3. View Student Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                manageAssignments(student);
                break;
            case 2: {
                string className, time, day;
                cout << "Enter class name: ";
                getline(cin, className);
                cout << "Enter class time: ";
                getline(cin, time);
                cout << "Enter class day: ";
                getline(cin, day);
                schedule.addClass(className, time, day);
                break;
            }
            case 3:
                cout << "\nStudent Name: " << student.name << "\n"
                          << "Student ID: " << student.studentID << "\n";
                student.viewAssignments();
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
