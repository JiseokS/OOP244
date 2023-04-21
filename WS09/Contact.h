/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-25
Section:OOP244NII
*/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include<iostream>
#include "Person.h"
namespace sdds 
{
	class Contact :public Person 
	{
		char* m_address{};
		char* m_city{};
		char m_province[3];
		char m_postalCode[7];
		void set(const Contact& copyFrom);
	public:
        Contact();
        Contact(const Contact& copyFrom);
        Contact& operator=(const Contact& RightOperand);
        virtual ~Contact();
        virtual std::istream& read(std::istream& istr);
        virtual std::ostream& write(std::ostream& ostr)const;
        virtual operator bool()const;
        virtual void operator~();
	};
}
#endif