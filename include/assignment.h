#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <vector>

using namespace std;

class Assignment {
public:
    Assignment(const string& title, const string& dueDate);

    void markCompleted();
    bool isCompleted() const;
    string getTitle() const;
    string getDueDate() const;

    static vector<Assignment> viewPendingAssignments(const vector<Assignment>& assignments);

private:
    string title;
    string dueDate;
    bool completed;
};

#endif // ASSIGNMENT_H
