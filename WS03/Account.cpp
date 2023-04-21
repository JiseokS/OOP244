#include "Account.h"

// Declare Constants for Interest Calculation
const int interest_days = 30;
const double interest_rate = 0.285;

// Class Constructor
Account::Account()
{
    acc_no = 0;
    bal = 0;
    days = 0;
    intr = 0;
}

// Method to add account details
void Account::add(int no, double balance, int d)
{
    // Get details from user and add into class variables
    acc_no = no;
    bal = balance;
    days = d;

    // Calculating Interest using formula given
    // Check if days number is greater than 30
    if (days > interest_days)
    {
        // Generate Interest for (number of days)
        intr = (days * (interest_rate / (double)365) * bal);
    }
}