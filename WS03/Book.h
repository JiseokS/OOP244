//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       3
// Date: 2021-09-30
//==============================================
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{
	class Book
	{
	private:
		char m_title[51];
		int m_SKU;
		int m_daysOnLoan;
		void setEmpty();
		double penalty() const;
	public:
		void set(const char* book_title, int SKU, int loanDays);
		bool isEmpty() const;
		bool hasPenalty() const;
		bool subTitle(const char* substr) const;
		void display() const;
	
	};

}
#endif 


