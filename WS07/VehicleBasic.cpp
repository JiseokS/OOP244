/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-11
Section:OOP244NII
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	VehicleBasic::VehicleBasic(const char* plate, int year) {
		m_year = year;
		strcpy(m_licensePlate, plate);
		strcpy(m_currentAddress, "Factory");
	}
	void VehicleBasic::NewAddress(const char* address) {
		if (strcmp(m_currentAddress, address) !=0)
		{
			cout << "|" << right << setw(8) << m_licensePlate << "| |";
			cout << right << setw(20) << m_currentAddress << " ---> ";
			cout << left << setw(20) << address << "|\n";
			strcpy(m_currentAddress, address);
			
		}
	}
	std::istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_licensePlate;
		cout << "Current location: ";
		in >> m_currentAddress;
		return in;
	}
	std::ostream& VehicleBasic::write(std::ostream& os) const {
		os << "| " << m_year << " | " << m_licensePlate << " | " << m_currentAddress;
		return os;
	}

	std::istream& operator >> (std::istream& in, VehicleBasic& v) {
		return v.read(in);
	}
	std::ostream& operator << (std::ostream& os, const VehicleBasic& v) {
		return v.write(os);
	}
	
	
	
}
