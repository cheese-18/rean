#include "include/schedule.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Schedule::addClass(const string& name, const string& time, const string& day) {
    for (const auto& c : classes) {
        if (c.day == day && c.time == time) {
            cout << "Class conflict: " << name << " cannot be added at " << time << " on " << day << ".\n";
            return;
        }
    }
    classes.push_back({name, time, day});
    cout << "Class " << name << " added successfully.\n";
}

void Schedule::removeClass(const string& name) {
    auto it = remove_if(classes.begin(), classes.end(), [&](const Class& c) {
        return c.name == name;
    });
    if (it != classes.end()) {
        classes.erase(it, classes.end());
        cout << "Class " << name << " removed successfully.\n";
    } else {
        cout << "Class " << name << " not found.\n";
}

    }
void Schedule::viewClasses() const {
    if (classes.empty()) {
        cout << "No classes scheduled.\n";
        return;
    }
    cout << "Scheduled Classes:\n";
    for (const auto& c : classes) {
        cout << c.name << " - " << c.time << " on " << c.day << "\n";
    }
}
