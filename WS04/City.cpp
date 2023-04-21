//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-07
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "City.h"

using namespace std;

namespace sdds
{
	City::City() {
		setEmpty();
	}
	City::City(const char* name, int population) {
		if (name != nullptr && name[0] != '\0' && population >= 0)
		{
			setCityName(name);
			setPopulation(population);
		}
		else
			setEmpty();
	}
	void City::setEmpty() {
		m_cityName[0] = '\0';
		m_population = -1;
	}
	void City::setCityName(const char* name) {
		if (name != nullptr) {
			strncpy(m_cityName, name, 30);
			m_cityName[30] = '\0';
		}
		else
			m_cityName[0] = '\0';
	}
	void City::setPopulation(int population) {
		if (population <= POPULATION)
			m_population = population;
		else
			m_population = -1;
	}
	void City::addPopulation(int population) {
		if (population < POPULATION)
		{
			m_population += population;
			if (m_population > POPULATION)
				m_population = POPULATION;
		}
			
	}
	bool City::isEmpty()const {
		return m_cityName[0] == '\0' || m_cityName < 0;
	}
	int City::getPeople()const {
		return m_population;
	}
	void City::display()const {
		if (!isEmpty())
		{
			cout << "|";
			cout.width(30);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_cityName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.width(10);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << m_population;
			cout.unsetf(ios::right);
			cout << " | " << endl;
		}
		else
			cout << "invalid city" << endl;
	}
}
