//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        NII
// Workshop:       Workshop1 part1
// Date:           2021-09-14
//==============================================
#ifndef SDDS_DRINK_H
#define SDDS_DRINK_H

namespace sdds
{

	struct Drink {
		char name[10];
		int volume;
		double price;
		int quantity;
	};


	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}
#endif
