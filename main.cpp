#include <iostream>
#include <limits>
#include <windows.h>
#include "include/student.h"
#include "include/schedule.h"
#include "include/assignment.h"

using namespace std;

// Clear the screen (Windows-specific)
void clearScreen() {
    system("cls");
}

// Pause and wait for Enter key
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Assignment manager menu
void manageAssignments(Student& student) {
    int subChoice;
    do {
        clearScreen();
        cout << "\nAssignment Menu:\n";
        cout << "1. Add Assignment\n";
        cout << "2. View Assignments\n";
        cout << "3. Mark Assignment as Completed\n";
        cout << "4. Remove Assignment\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> subChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean buffer

        switch (subChoice) {
            case 1: {
                string title, dueDate;
                cout << "Enter assignment title: ";
                getline(cin, title);
                cout << "Enter due date (YYYY-MM-DD): ";
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
                student.viewAssignments();
                cout << endl;
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
        pause();
    } while (subChoice != 5);
}
void manageSchedule(Schedule& schedule) {
    int scheduleChoice;
    do {
        system("cls"); // Clear screen each loop
        cout << "\nSchedule Menu:\n";
        cout << "1. Add Class\n";
        cout << "2. View Classes\n";
        cout << "3. Remove Class\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> scheduleChoice;
        cin.ignore();

        switch (scheduleChoice) {
            case 1: {
                string className, time, day;
                cout << "Enter class name: ";
                getline(cin, className);
                cout << "Enter class time: ";
                getline(cin, time);
                cout << "Enter class day: ";
                getline(cin, day);
                schedule.addClass(className, time, day);
                system("pause");
                break;
            }
            case 2:
                schedule.viewClasses();
                system("pause");
                break;
            case 3: {
                string className;
                cout << "Enter class name to remove: ";
                getline(cin, className);
                schedule.removeClass(className);
                system("pause");
                break;
            }
            case 4:
                cout << "Returning to main menu...\n";
                Sleep(1000);
                break;
            default:
                cout << "Invalid choice.\n";
                system("pause");
        }
    } while (scheduleChoice != 4);
}

// Main program
int main() {
    clearScreen();
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
        clearScreen();
        cout << "\nMain Menu:\n";
        cout << "1. Manage Assignments\n";
        cout << "2. Manage Schedule\n";
        cout << "3. View Student Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean buffer

        switch (choice) {
            case 1:
                manageAssignments(student);
                break;
            case 2:
                manageSchedule(schedule);
            case 3:
                cout << "\n=== Student Information ===\n";
                cout << "Name: " << student.name << "\n";
                cout << "Student ID: " << student.studentID << "\n";
                student.viewAssignments();
                pause();
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
                pause();
        }

    } while (choice != 4);

    return 0;
}
