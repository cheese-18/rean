#include "helper.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

bool isValidDate(const string& date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");
    return !ss.fail();
}

string formatDate(const string& date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) return "Invalid date";

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%B %d, %Y", &tm); // e.g., April 18, 2025
    return string(buffer);
}

vector<string> splitString(const string& str, char delimiter) {
    stringstream ss(str);
    vector<string> tokens;
    string item;
    while (getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d",
             1900 + ltm->tm_year,
             1 + ltm->tm_mon,
             ltm->tm_mday);
    return string(buffer);
}

void waitForUserInput(const string& message) {
    cout << message << endl;
    cin.ignore();
}

