/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#include<iomanip>
#include<cstring>
#include "rectangleLabel.h"
using namespace std;
namespace sdds {
	rectangleLabel::rectangleLabel() {}
	rectangleLabel::rectangleLabel(const char* label, int width, int spaces)
		:labelShape(label),m_width(width),m_spaces(spaces) 
	{
		if (width<int(strlen(label) + spaces + 2)) m_width = 0;
	}
	void rectangleLabel::drawShape(std::ostream& os)const {
		if (m_width > 0)
		{
			//first
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-' << '+' << endl;
			//second
			os << '|';
			os << setw(m_spaces) << setfill(' ')<< ' ';
			os.width(m_width - m_spaces-2);
			os.fill(' ');
			os << left << label() << '|' << endl;
			//last
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-' << '+';
		}
	}
	void rectangleLabel::readShape(std::istream& is)
	{
		char comma;
		labelShape::readShape(is);
		is >> m_width >> comma >> m_spaces;
		is.ignore(30000, '\n');
	}
}

