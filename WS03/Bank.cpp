// Include Bank.h
#include "Bank.h"
using namespace std;

// Method to Initialize Bank
void Bank::initialize(const char* bank_name, int noOfAccounts)
{
    // Check if the given paramteres are valid
    if (noOfAccounts > 0)
    {
        if (bank_name == nullptr || strcmp(bank_name, "") == 0) { name = "Invalid Bank"; }

        // If check passes, point to pointer to array of class Accounts (Size = number of accounts)
        else
        {
            arr = new Account[noOfAccounts];

            // Initialize other variables too
            name = bank_name;
            index = -1;
            max = noOfAccounts - 1;
            tot = 0;
        }
    }

    // If any parameter is invalid, bank is invalid
    else { name = "Invalid Bank"; }
}

// Method to add an account
bool Bank::addAccount(int account_number, double balance, int daySinceLastPayment)
{
    // If index is less than max and parameters are valid
    if (index <= max && balance > 0 && daySinceLastPayment > 0)
    {
        // Increment paramter and put values into Account at Array[index]
        index++;
        arr[index].add(account_number, balance, daySinceLastPayment);

        // Cummulative Sum of Interest of Added Accounts
        tot += arr[index].getInt();
        return true;
    }

    // If cant add account, return false
    else { return false; }
}

// Method to display Account Details
void Bank::display(bool intrestOnly = false)const
{
    // If flag (interest-only) is True, Show only accounts with interest generated
    if (intrestOnly == true)
    {
        // If name is invalid, cout invalid
        if (name == "Invalid Bank") { cout << name << endl; }
        else
        {
            // Print Details of Bank
            cout << "INTEREST ONLY LIST!\n";
            cout << "-----------------------------------------\n";
            cout << ">>> " << name << " <<<\n";
            cout << "-----------------------------------------\n";
            cout << left << setw(4) << setfill(' ') << "Row";
            cout << left << setw(11) << setfill(' ') << "Accnt No";
            cout << left << setw(13) << setfill(' ') << "Balance";
            cout << left << setw(5) << setfill(' ') << "Days";
            cout << left << setw(10) << setfill(' ') << "Interest" << endl;
            cout << "--- ---------- ------------ ---- --------\n";

            // Iterate over Accounts and check if accout has interest
            int row = 1;
            for (int i = 0; i <= max; i++)
            {
                if (arr[i].getInt() != 0)
                {
                    // Print Details of Accounts
                    cout << left << setw(4) << setfill(' ') << (row);
                    cout << left << setw(11) << setfill(' ') << arr[i].getAcc();
                    cout << left << fixed << setprecision(2) << setw(13) << setfill(' ') << arr[i].getBal();
                    cout << left << setw(5) << setfill(' ') << arr[i].getDays();
                    cout << left << fixed << setprecision(2) << setw(10) << setfill(' ') << arr[i].getInt() << endl;
                    row++;
                }
            }
            cout << "-----------------------------------------\n";
            cout << right << setw(32) << setprecision(2) << "Total Interest: " << tot << endl << endl;
        }
    }
    // If flag (interest-only) is False, Show all account details
    else
    {
        if (name == "Invalid Bank") { cout << name << endl; }
        else
        {
            // Print details of Bank
            cout << "------------------------------\n";
            cout << ">>> " << name << " <<<\n";
            cout << "------------------------------\n";
            cout << left << setw(4) << setfill(' ') << "Row";
            cout << left << setw(11) << setfill(' ') << "Accnt No";
            cout << left << setw(13) << setfill(' ') << "Balance";
            cout << left << setw(5) << setfill(' ') << "Days";
            cout << left << setw(10) << setfill(' ') << "Interest" << endl;
            cout << "--- ---------- ------------ ---- --------\n";

            // Iterate over all Accounts and Print their Details
            for (int i = 0; i <= max; i++)
            {
                cout << left << setw(4) << setfill(' ') << (i + 1);
                cout << left << setw(11) << setfill(' ') << arr[i].getAcc();
                cout << left << fixed << setprecision(2) << setw(13) << setfill(' ') << arr[i].getBal();
                cout << left << setw(5) << setfill(' ') << arr[i].getDays();
                if (arr[i].getInt() == 0) { cout << "" << endl; }
                else { cout << left << fixed << setprecision(2) << setw(10) << setfill(' ') << arr[i].getInt() << endl; }
            }
            cout << "-----------------------------------------\n";
            cout << right << setw(32) << setprecision(2) << "Total Interest: " << tot << endl << endl;
        }
    }
}

// Method to clear the Bank (Deletes all accounts)
// Deletes Accounts by deleting array of accounts and putting pointer to NULL
void Bank::clear()
{
    delete[] arr;
    arr = NULL;
}