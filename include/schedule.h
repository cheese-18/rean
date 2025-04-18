#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

class Schedule {
public:
    void addClass(const std::string& className, const std::string& time, const std::string& day);
    void removeClass(const std::string& className);
    void viewClasses() const;

private:
    struct Class {
        std::string name;
        std::string time;
        std::string day;
    };
    std::vector<Class> classes;
};

#endif // SCHEDULE_H
