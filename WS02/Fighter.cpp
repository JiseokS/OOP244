//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       2
// Date: 2021-09-22
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Fighter.h"
using namespace std;
namespace sdds {
    void fighter(char* name) {
		cout << "Enter Fighter Name: ";
		cin >> name;
	}
	void fighter(int& power) {
		cout << "Enter Fighter Power: ";
		cin >> power;
	}
	void display(const Fighter& myFighter) {
		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;
	}
	void display(const Competition& mycompetition) {
		for (int i = 0; i < mycompetition.numfighters; i++)
			display(mycompetition.fighters[i]);
	}
	void addFighter(Competition& myCompetition) {
		Fighter* temp = new Fighter[myCompetition.numfighters + 1];
		
		for (int i = 0; i < myCompetition.numfighters; i++)
			temp[i] = myCompetition.fighters[i];

		cout << "Information of the new fighter:" << endl;
		fighter(temp[myCompetition.numfighters].name);
		fighter(temp[myCompetition.numfighters].power);

		delete[] myCompetition.fighters;
		myCompetition.fighters = temp;
		myCompetition.numfighters++;
	}
	void removeFighter(Competition& myCompetition, const Fighter& loserFighter) {
		int foundIndex = findFighter(myCompetition, loserFighter);
		
		if (foundIndex != -1)
		{
			Fighter* temp = new Fighter[myCompetition.numfighters - 1];
			int i = 0, j = 0;
			while (i < myCompetition.numfighters)
			{
				if (i != foundIndex)
					temp[j++] = myCompetition.fighters[i];
				i++;
			}
			myCompetition.numfighters--;
			delete[] myCompetition.fighters;
			myCompetition.fighters = temp;
		}
		
	}
	int findFighter(const Competition& mycompetition, const Fighter& theFighter) {
		int found = -1;
		for (int i = 0; i < mycompetition.numfighters && found == -1; i++)
			if (strcmp(mycompetition.fighters[i].name, theFighter.name) == 0)
				found = i;
		return found;
	}
	bool fight(const Fighter& f1, const Fighter& f2) {
		return f1.power > f2.power;
	}
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		cout << "    The winner => ";
		if (fight(f1, f2))
		{
			display(f1);
			removeFighter(mycompetition, f2);
		}
		else
		{
			display(f2);
			removeFighter(mycompetition, f1);
		}
	}

}