//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        NII
// Workshop:       Workshop1 part1
// Date:           2021-09-14
//==============================================
#include <iostream>
#include "util.h"
using namespace std;


namespace sdds
{
	bool confirm() {
		char choice = cin.get();
		clearBuffer();
		return choice == 'Y';
	}

	void clearBuffer() {
		while (cin.get() != '\n');
	}


}
