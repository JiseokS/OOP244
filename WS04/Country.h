//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-07
//==============================================
#ifndef SDDS_COUNTRY_H
#define SDDS_COUNTRY_H
#include "City.h"
namespace sdds 
{

	const int MAX_CITY = 20;
	class Country
	{
		char* m_name;
		int m_noOfCity;
		City* m_city = nullptr;
	public:
		Country();
		Country(const char* name, int noOfCity, const City* cities);
		void setName(const char* name);
		Country& addCity(const City& c);
		Country& migrate(int people);
		void setEmpty();
		bool isEmpty()const;
		~Country();
		void display()const;

	};
}
#endif 
