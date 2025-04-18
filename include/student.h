#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "assignment.h"

class Student {
public:
    std::string name;
    std::string studentID;
    std::vector<Assignment> assignments;

public:
    Student(const std::string& name, const std::string& studentID);

    void addAssignment(const Assignment& assignment);
    void removeAssignment(const std::string& assignmentTitle);
    void viewAssignments() const;
};

#endif // STUDENT_H
