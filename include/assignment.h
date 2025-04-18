#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <vector>

class Assignment {
public:
    Assignment(const std::string& title, const std::string& dueDate);
    
    void markCompleted();
    bool isCompleted() const;
    std::string getTitle() const;
    std::string getDueDate() const;

    static std::vector<Assignment> viewPendingAssignments(const std::vector<Assignment>& assignments);

private:
    std::string title;
    std::string dueDate;
    bool completed;
};

#endif // ASSIGNMENT_H