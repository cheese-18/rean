#include "include/student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Student::Student(const string& name, const string& studentID)
    : name(name), studentID(studentID) {}

void Student::addAssignment(const Assignment& assignment) {
    assignments.push_back(assignment);
}

void Student::removeAssignment(const string& title) {
    assignments.erase(remove_if(assignments.begin(), assignments.end(),
        [&title](const Assignment& a) { return a.getTitle() == title; }),
        assignments.end());
}

void Student::viewAssignments() const {
    cout << "Assignments for " << name << " (ID: " << studentID << "):\n";
    for (const auto& assignment : assignments) {
        cout << "- " << assignment.getTitle() << " (Due: " << assignment.getDueDate()
                 << ") [Status: " << (assignment.isCompleted() ? "Completed" : "Pending") << "]\n";
    }
}
