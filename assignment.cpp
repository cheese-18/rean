#include "include/assignment.h"
#include <iostream>
#include <vector>
#include <string>
#pragma <once>

using namespace std;

Assignment::Assignment(const string& title, const string& dueDate)
    : title(title), dueDate(dueDate), completed(false) {}

void Assignment::markCompleted() {
    completed = true;
}

bool Assignment::isCompleted() const {
    return completed;
}

string Assignment::getTitle() const {
    return title;
}

string Assignment::getDueDate() const {
    return dueDate;
}

vector<Assignment> Assignment::viewPendingAssignments(const vector<Assignment>& assignments) {
    vector<Assignment> pending;
    for (const auto& assignment : assignments) {
        if (!assignment.isCompleted()) {
            pending.push_back(assignment);
        }
    }
    return pending;
}
