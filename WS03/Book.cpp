//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       3
// Date: 2021-09-30
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds 
{
	const double PENALTY = 1.5;
	const int MAXLOAN = 15;

	void Book::setEmpty(){
		m_title[0] = '\0'; 
		m_SKU = 0;
		m_daysOnLoan = 0;
	}
	double Book::penalty() const{
		double value = 0;
		if(hasPenalty())
			value = (m_daysOnLoan - MAXLOAN) * PENALTY;
		return value;
	}
	void Book::set(const char* book_title, int SKU, int loanDays) {
		if (book_title != nullptr && book_title[0]!='\0' && SKU > 0 && loanDays > 0)
		{
			strcpy(m_title, book_title);
			m_SKU = SKU;
			m_daysOnLoan = loanDays;
		}
		else
			setEmpty();
	}
	bool Book::isEmpty() const{
		return m_title[0] == '\0' && m_SKU == 0 && m_daysOnLoan == 0;
	}
	bool Book::hasPenalty() const{
		return m_daysOnLoan > MAXLOAN;
	}
	bool Book::subTitle(const char* substr) const{
		return strstr(m_title, substr) != nullptr;

	}
	void Book::display() const{
		if (!isEmpty())
		{
			cout.width(49);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_title;
			cout.width(8);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_SKU;
			cout.width(10);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_daysOnLoan;
			if (hasPenalty())
			{
				cout.width(7);
				cout.setf(ios::fixed);
				cout.setf(ios::right);
				cout.precision(2);
				cout << penalty();
				cout.unsetf(ios::right);
			}
			cout << endl;

		}
		else
			cout << "Invalid library book" << endl;
	}
}
