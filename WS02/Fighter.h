//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       2
// Date: 2021-09-22
//==============================================
#ifndef SDDS_FIGHTER_H
#define SDDS_FIGHTER_H
namespace sdds {
	const int MAX_NAME = 50;

	struct Fighter {
		char name[MAX_NAME+1];
		int power;
	};

	struct Competition {
		Fighter* fighters;
		int numfighters;
	};

	//TODO: Declare the prototypes for the functions required as per the lab instructions
	void fighter(char* name);
	void fighter(int& power);
	void display(const Fighter& myFighter);
	void display(const Competition& mycompetition);
	void addFighter(Competition& myCompetition);
	void removeFighter(Competition& myCompetition, const Fighter& loserFighter);
	int findFighter(const Competition& mycompetition, const Fighter& theFighter);
	bool fight(const Fighter& f1, const Fighter& f2);
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2);
}
#endif /* FIGHTER_H */



