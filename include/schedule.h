#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

using namespace std;

class Schedule {
public:
    void addClass(const string& className, const string& time, const string& day);
    void removeClass(const string& className);
    void viewClasses() const;

private:
    struct Class {
        string name;
        string time;
        string day;
    };
    vector<Class> classes;
};

#endif // SCHEDULE_H
