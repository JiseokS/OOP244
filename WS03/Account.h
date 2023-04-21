#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    // All members are private
private:
    int acc_no;
    double bal;
    int days;
    double intr;

    // All Methods are public
public:
    Account();

    // Method to add account details
    void add(int no, double balance, int d);

    // Method to Return Class Variables
    int getAcc() { return acc_no; }
    double getBal() { return bal; }
    int getDays() { return days; }
    double getInt() { return intr; }
};

#endif