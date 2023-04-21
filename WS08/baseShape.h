/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
using namespace std;
namespace sdds {
	class baseShape {
	public:
		virtual void drawShape(std::ostream& os)const=0;
		virtual void readShape(std::istream& is)=0;
		virtual ~baseShape() {};

	};
	std::ostream& operator<<(std::ostream& os, const baseShape& s);
	std::istream& operator>>(std::istream& is, baseShape& s);
}
#endif