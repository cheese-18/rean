#include "include/student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::remove_if

Student::Student(const std::string& name, const std::string& studentID)
    : name(name), studentID(studentID) {}

void Student::addAssignment(const Assignment& assignment) {
    assignments.push_back(assignment);
}

void Student::removeAssignment(const std::string& title) {
    assignments.erase(std::remove_if(assignments.begin(), assignments.end(),
        [&title](const Assignment& a) { return a.getTitle() == title; }),
        assignments.end());
}

void Student::viewAssignments() const {
    std::cout << "Assignments for " << name << " (ID: " << studentID << "):\n";
    for (const auto& assignment : assignments) {
        std::cout << "- " << assignment.getTitle() << " (Due: " << assignment.getDueDate()
                 << ") [Status: " << (assignment.isCompleted() ? "Completed" : "Pending") << "]\n";
    }
}
