#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include <bits/stdc++.h>
using namespace std;

// Bank Class stores Pointer to Array of Accounts
// Bank has members - Name of Bank (Stores Name of Bank)
// Bank has members - index (index where the next acount is to be added)
// Bank has members - max (max number of accounts possible)
// Bank has members - tot (total interest of all the accounts)
class Bank
{
    // All Members are Private
private:
    Account* arr = NULL;
    string name;
    int index;
    int max;
    double tot;

    // All Methods are Public
public:

    // Method to Initialize Bank
    void initialize(const char* bank_name, int noOfAccounts);

    // Method to add an account
    bool addAccount(int account_number, double balance, int daySinceLastPayment);

    // Method to display Account Details
    void display(bool intrestOnly)const;

    // Method to clear the Bank (Deletes all accounts)
    // Deletes Accounts by deleting array of accounts and putting pointer to NULL
    void clear();
};

#endif