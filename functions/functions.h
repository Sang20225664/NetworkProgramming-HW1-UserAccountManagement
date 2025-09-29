#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <unordered_map>
#include "../user/user.h"
using namespace std;

// Main functions declarations
bool login(const unordered_map<string, int> &userMap, const string &username, const string &mssv);

void postMessage(const string &username, const string &mssv);

void logout(const string &username, const string &mssv);

void exitProgram();

#endif