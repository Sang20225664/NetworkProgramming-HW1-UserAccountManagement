#include "functions.h"
#include "../logger/logger.h"
#include <iostream>
using namespace std;

/**
 * Hàm login
 * - Input: map accounts (username → status), currentUser, MSSV
 * - If currentUser not empty → give alert, log -ERR
 * - If username not exist → give alert, log -ERR
 * - If username banned → give alert, log -ERR
 * - Else → set currentUser, log +OK
 */
bool login(const unordered_map<string, int> &accounts, string &currentUser, const string &mssv)
{
    string name;
    getline(cin, name);

    if (!currentUser.empty())
    {
        cout << "You have already logged in." << endl;
        writeLog(mssv, 1, name, false);
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

/**
 * Hàm postMessage
 * - Input: currentUser, MSSV
 * - If not logged in → give alert, log -ERR
 * - If logged in → input message, log +OK
 */
void postMessage(string &currentUser, const string &mssv)
{
    if (currentUser.empty())
    {
        cout << "You have not logged in." << endl;
        writeLog(mssv, 2, "", false);
        return;
    }

    cout << "Post message: ";
    string message;
    getline(cin, message);

    cout << "Successful post" << endl;
    writeLog(mssv, 2, message, true);
}

/**
 * Function logout
 * - Input: currentUser, MSSV
 * - If not logged in → give alert, log -ERR
 * - If logged in → log +OK, clear currentUser
 */
void logout(string &currentUser, const string &mssv)
{
    if (currentUser.empty())
    {
        cout << "You have not logged in." << endl;
        writeLog(mssv, 3, "", false);
        return;
    }

    cout << "Successful log out" << endl;
    writeLog(mssv, 3, currentUser, true);
    currentUser.clear();
}

/**
 * Function exitProgram
 * - Input: MSSV
 * - Write log +OK
 */
void exitProgram(const string &mssv)
{
    writeLog(mssv, 4, "", true);
}
