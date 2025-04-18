#include "include/assignment.h"
#include <iostream>
#include <vector>
#include <string>
#pragma <once>

Assignment::Assignment(const std::string& title, const std::string& dueDate)
    : title(title), dueDate(dueDate), completed(false) {}

void Assignment::markCompleted() {
    completed = true;
}

bool Assignment::isCompleted() const {
    return completed;
}

std::string Assignment::getTitle() const {
    return title;
}

std::string Assignment::getDueDate() const {
    return dueDate;
}

std::vector<Assignment> Assignment::viewPendingAssignments(const std::vector<Assignment>& assignments) {
    std::vector<Assignment> pending;
    for (const auto& assignment : assignments) {
        if (!assignment.isCompleted()) {
            pending.push_back(assignment);
        }
    }
    return pending;
}
