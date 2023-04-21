//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       5
// Date: 2021-10-12
//==============================================
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
using namespace std;

namespace sdds {
	const int RegularEggWieght = 50; //These wieghts are in Grams
	const int JumboEggWieght = 75;

   class EggCarton {
	   int m_size;
	   int m_noOfEggs;
	   bool m_jumbo;
	   void setBroken();
   public: 
	   EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
	   ostream& display(std::ostream& ostr) const;
	   istream& read(std::istream& istr);

	   operator bool() const;
	   operator int() const;
	   operator double() const;

	   EggCarton& operator --();    //pre-fix operators
	   EggCarton operator --(int); //post-fix operators
	   EggCarton& operator ++();
	   EggCarton operator ++(int);

	   EggCarton& operator=(int value);
	   EggCarton& operator+=(int value);
	   EggCarton& operator+=(EggCarton& right);

	   bool operator==(const EggCarton& right) const;
   };

   int operator+(int left, const EggCarton& right);
   ostream& operator<<(ostream& ostr, const EggCarton& right);
   istream& operator>>(istream& istr, EggCarton& right);

}
#endif