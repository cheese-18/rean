#include "include/schedule.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::remove_if

void Schedule::addClass(const std::string& name, const std::string& time, const std::string& day) {
    for (const auto& c : classes) {
        if (c.day == day && c.time == time) {
            std::cout << "Class conflict: " << name << " cannot be added at " << time << " on " << day << ".\n";
            return;
        }
    }
    classes.push_back({name, time, day});
    std::cout << "Class " << name << " added successfully.\n";
}

void Schedule::removeClass(const std::string& name) {
    auto it = std::remove_if(classes.begin(), classes.end(), [&](const Class& c) {
        return c.name == name;
    });
    if (it != classes.end()) {
        classes.erase(it, classes.end());
        std::cout << "Class " << name << " removed successfully.\n";
    } else {
        std::cout << "Class " << name << " not found.\n";
}

    }
void Schedule::viewClasses() const {
    if (classes.empty()) {
        std::cout << "No classes scheduled.\n";
        return;
    }
    std::cout << "Scheduled Classes:\n";
    for (const auto& c : classes) {
        std::cout << c.name << " - " << c.time << " on " << c.day << "\n";
    }
}
