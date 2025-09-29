#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void writeLog(const string &mssv, int option, const string &input, bool success)
{
    string filename = "log_" + mssv + ".txt";

    // Open the log file in append mode
    ofstream logFile(filename, ios::app);
    if (!logFile.is_open())
    {
        cerr << "Error opening log file: " << filename << endl;
        return;
    }

    // Get the current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%d/%m/%Y %H:%M:%S", ltm);

    // Write the log entry
    logFile << "[" << timeStr << "] $ " << option << " $ " << input
            << " $ " << (success ? "+OK" : "-ERR") << std::endl;

    logFile.close();
}