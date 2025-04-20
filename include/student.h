#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "assignment.h"

using namespace std;

class Student {
public:
    string name;
    string studentID;
    vector<Assignment> assignments;

public:
    Student(const string& name, const string& studentID);

    void addAssignment(const Assignment& assignment);
    void removeAssignment(const string& assignmentTitle);
    void viewAssignments() const;
};

#endif // STUDENT_H
