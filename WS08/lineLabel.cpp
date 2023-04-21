/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#include<iostream>
#include<iomanip>
#include "lineLabel.h"
using namespace std;
namespace sdds {
	lineLabel::lineLabel() :m_length(0)
	{
		//m_length = 0;
	}
	lineLabel::lineLabel(const char* label, int length):labelShape(label)//m_length(length)
	{
		m_length = length;
	}
	void lineLabel::drawShape(std::ostream& os)const 
	{
		if (m_length > 0 && label())
		{
			os << label() << endl;
			os << setw(m_length) << setfill('=')
				<< '=';
			os.fill(' ');
		}
	}
	void lineLabel::readShape(std::istream& is) 
	{
		labelShape::readShape(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}
}
