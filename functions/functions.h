#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <unordered_map>
#include "../user/user.h"
using namespace std;

// Main functions declarations
bool login(const unordered_map<string, int> &accounts, string &currentUser, const string &mssv);
void postMessage(string &currentUser, const string &mssv);
void logout(string &currentUser, const string &mssv);
void exitProgram(const string &mssv);

#endif