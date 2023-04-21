/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "labelShape.h"
namespace sdds {
	class rectangleLabel : public labelShape {
		int m_width=0, m_spaces=0;
	public:
		rectangleLabel();
		rectangleLabel(const char* label, int width, int spaces);
		void drawShape(std::ostream& os)const;
		void readShape(std::istream& is);
	};
}
#endif