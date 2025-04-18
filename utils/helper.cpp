#include "helper.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <iomanip>

bool isValidDate(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return !ss.fail();
}

std::string formatDate(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) return "Invalid date";

    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%B %d, %Y", &tm); // e.g., April 18, 2025
    return std::string(buffer);
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::stringstream ss(str);
    std::vector<std::string> tokens;
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

std::string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d",
             1900 + ltm->tm_year,
             1 + ltm->tm_mon,
             ltm->tm_mday);
    return std::string(buffer);
}

void waitForUserInput(const std::string& message) {
    std::cout << message << std::endl;
    std::cin.ignore();
}

