#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

using namespace std;

// Validate if a string is a valid date in YYYY-MM-DD format
bool isValidDate(const string& date);

// Format a date string from YYYY-MM-DD to a more readable format (e.g., "April 18, 2025")
string formatDate(const string& date);

// Split a string by a delimiter and return a vector of substrings
vector<string> splitString(const string& str, char delimiter);

// Trim whitespace from both ends of a string
string trim(const string& str);

// Get the current date as a string in YYYY-MM-DD format
string getCurrentDate();

// Display a message and wait for user input
void waitForUserInput(const string& message);

#endif // HELPER_H
