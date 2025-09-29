#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using namespace std;

// Function to write logs to a file
void writeLog(const string &mssv, int option, const string &input, bool success);

#endif