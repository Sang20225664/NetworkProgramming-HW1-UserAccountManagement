#include <bits/stdc++.h>
#include "logger/logger.h"
#include "user/user.h"
#include "functions/functions.h"

using namespace std;

int main()
{
    string mssv = "20225664";
    string filename = "account.txt";

    // Load user accounts from file
    vector<User> users = loadAccounts(filename);

    // Create a map for quick lookup
    unordered_map<string, int> accounts;

    for (const auto &user : users)
    {
        accounts[user.name] = user.status;
    }

    string currentUser = "";

    // while (true)
    // {
    //     cout << "1. Login\n2. Post Message\n3. Logout\n4. Exit\n";
    //     int choice;

    //     // Check if input is valid
    //     // Alert if input is not an integer
    //     // clean the input buffer
    //     if (!(cin >> choice))
    //     {
    //         cout << "Invalid input. Please enter a number between 1 and 4.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         continue;
    //     }

    //     if (choice == 1)
    //     {
    //         login(accounts, currentUser, mssv);
    //     }
    //     }
}