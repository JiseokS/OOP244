//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        NII
// Workshop:       Workshop1 part1
// Date:           2021-09-14
//==============================================
#include <iostream>
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;

int main() {
    bool done = false;
    loadDrinks();
    cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done) {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }
    drinkMenu();
    cout << "\nThank you and come again" << endl;
    return 0;
}
