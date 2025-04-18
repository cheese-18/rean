#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

// Validate if a string is a valid date in YYYY-MM-DD format
bool isValidDate(const std::string& date);

// Format a date string from YYYY-MM-DD to a more readable format (e.g., "April 18, 2025")
std::string formatDate(const std::string& date);

// Split a string by a delimiter and return a vector of substrings
std::vector<std::string> splitString(const std::string& str, char delimiter);

// Trim whitespace from both ends of a string
std::string trim(const std::string& str);

// Get the current date as a string in YYYY-MM-DD format
std::string getCurrentDate();

// Display a message and wait for user input
void waitForUserInput(const std::string& message);

#endif // HELPER_H
