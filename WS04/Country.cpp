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
#include "Country.h"

using namespace std;

namespace sdds
{
	Country::Country(){
		setEmpty();
	}
	Country::Country(const char* name, int noOfCity, const City* cities){
		setEmpty();
		if (name != nullptr && name[0] != '\0' && cities != nullptr && noOfCity < MAX_CITY && noOfCity>0)
		{
			setName(name);
			m_noOfCity = noOfCity;
			m_city = new City[m_noOfCity];
			for (int i = 0; i < m_noOfCity; i++)
				m_city[i] = cities[i];
		}
	}
	void Country::setName(const char* name){
		delete[] m_name;
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else
		{
			delete[] m_city;
			setEmpty();
		}
	}
    Country& Country::addCity(const City& c){
		if (!c.isEmpty())
		{
			City* temp = new City[m_noOfCity + 1];
			for (int i = 0; i < m_noOfCity; i++)
				temp[i] = m_city[i];
			delete[] m_city;
			temp[m_noOfCity] = c;
			m_noOfCity++;
			m_city = temp;
		}
		return *this;
	}
	Country& Country::migrate(int people){
		for (int i = 0; i < m_noOfCity; i++)
		{
			if (m_city[i].getPeople() < POPULATION)
			{
				m_city[i].addPopulation(people);
			}
		}
		return *this;
	}
	void Country::setEmpty(){
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}
	bool Country::isEmpty()const{
		return m_name == nullptr;
	}
	Country::~Country(){
		delete[] m_name;
		delete[] m_city;
		m_name = nullptr;
		m_city = nullptr;
	}
	void Country::display()const{
		if (!isEmpty())
		{
			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout.width(32); 
			cout.setf(ios::left);
			cout << "City name" << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
				m_city[i].display();
		}
		else
			cout << "Invalid country object" << endl;
	}
}
