/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "labelShape.h"
namespace sdds {
	class lineLabel : public labelShape {
		int m_length;
	public:
		lineLabel();
		lineLabel(const char* label, int length);
		void drawShape(std::ostream& os)const;
		void readShape(std::istream& is);
	};
}
#endif