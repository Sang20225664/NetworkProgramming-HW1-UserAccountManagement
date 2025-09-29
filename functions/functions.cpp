#include "functions.h"
#include "../logger/logger.h"
#include <iostream>
using namespace std;

bool login(const unordered_map<string, int> &accounts, string &currentUser, const string &mssv)
{
    string name;
    getline(cin, name);

    if (!currentUser.empty())
    {
        cout << "You have already logged in." << endl;
        return false;
    }

    auto it = accounts.find(name);
    if (it == accounts.end())
    {
        cout << "Account is not exist." << endl;
        writeLog(mssv, 1, name, false);
        return false;
    }

    if (it->second == 0)
    {
        cout << "Account is banned." << endl;
        writeLog(mssv, 1, name, false);
        return false;
    }

    currentUser = name;
    cout << "Hello " << currentUser << endl;
    writeLog(mssv, 1, name, true);

    return true;
}

void postMessage(const string &username, const string &mssv)
{
    if (username.empty())
    {
        cout << "You have not logged in." << endl;
        writeLog(mssv, 2, "", false);
        return;
    }
    string message;
    getline(cin, message);
    cout << "Successful post" << endl;
    writeLog(mssv, 2, message, true);
}

void logout(const string &username, const string &mssv)
{
    if (username.empty())
    {
        cout << "You have not logged in." << endl;
        writeLog(mssv, 3, "", false);
        return;
    }
    cout << "Successful log out" << endl;
    writeLog(mssv, 3, username, true);
}

void exitProgram()
{
}