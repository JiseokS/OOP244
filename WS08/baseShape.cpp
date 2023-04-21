/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#include<iostream>
#include "baseShape.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const baseShape& s) {
		s.drawShape(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, baseShape& s) {
		s.readShape(is);
		return is;
	}
}
