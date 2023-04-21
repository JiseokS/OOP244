//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       6
// Date: 2021-10-23
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;
namespace sdds {

	Contact::Contact(const char* name, int area, int exchange, int number)
	{
		set(name, area, exchange, number);
	}

	bool Contact::validPhone(int area, int exchange, int number) const {
		return area >= 100 && area <= 999 && exchange >= 100 && exchange <= 999 && number >= 0 &&
			number <= 9999;
	}

	void Contact::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
		m_exchangeCode = 0;
		m_number = 0;
		m_area = 0;
	}
	void Contact::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void Contact::extractChar(std::istream& istr, char ch) const {
		char chinput;
		chinput = istr.peek();
		if (chinput == ch) {
			ch = istr.get();
		}
		else {
			istr.setstate(ios::failbit);
		}
	}

	std::ostream& Contact::printPhoneNumber(std::ostream& ostr) const {
		ostr << "(";
		ostr << m_area;
		ostr << ") ";
		ostr << m_exchangeCode;
		ostr << "-";
		ostr.width(4);
		ostr.fill('0');
		ostr.setf(ios::left);
		ostr.unsetf(ios::left);
		ostr << m_number;

		return ostr;

	}

	void Contact::set(const char* name, int area, int exchange, int number) {
		if (name != nullptr && name[0] && validPhone(area, exchange, number)) {
			allocateAndCopy(name);
			m_area = area;
			m_exchangeCode = exchange;
			m_number = number;
		}
		else {
			setEmpty();
		}
	}

	Contact::Contact() {
		setEmpty();
	}

	Contact::Contact(const Contact& cnt) {
		if (cnt) {
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
		else {
			setEmpty();
		}
	}

	Contact& Contact::operator=(const Contact& cnt) {
		if (this != &cnt) {
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
		return *this;
	}

	Contact::~Contact() {
		delete[] m_name;
	}
	Contact::operator bool() const {
		return m_name != nullptr && m_name[0] && validPhone(m_area, m_exchangeCode, m_number);
	}

	std::ostream& Contact::print(std::ostream& ostr, bool toFile = true) const {

		if (operator bool())
		{
			if (toFile)
			{
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				printPhoneNumber(ostr);
				ostr.unsetf(ios::left);
			}
			else
			{
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				printPhoneNumber(ostr);
				ostr.unsetf(ios::left);
			}
		}
		else

			ostr << "Invalid Phone Record";
		return ostr;
	}

	std::istream& Contact::read(std::istream& istr) {
		char name[MaxNameLength];
		int area;
		int exchange;
		int number;


		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		if (istr.fail())
		{
			return istr;
		}
		extractChar(istr, '(');
		if (istr.fail())
		{
			return istr;
		}
		istr >> area;

		extractChar(istr, ')');
		if (istr.fail())
		{
			return istr;
		}
		extractChar(istr, ' ');
		istr >> exchange;
		if (istr.fail())
		{
			return istr;
		}
		extractChar(istr, '-');
		istr >> number;

		if (istr.fail())
		{
			return istr;
		}
		extractChar(istr, '\n');
		if (istr.fail())
		{
			return istr;
		}
		set(name, area, exchange, number);

		return istr;
	}


	std::ostream& operator<<(std::ostream& ostr, const Contact& cnt) {
		return cnt.print(ostr, false);

	}

	std::istream& operator>>(std::istream& istr, Contact& cnt) {
		return cnt.read(istr);
	}


}