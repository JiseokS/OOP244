//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       6
// Date: 2021-10-23
//==============================================
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>

namespace sdds {
	const int MaxNameLength = 55;
	class Contact {
		char* m_name{}; 
		int m_area; 
		int m_exchangeCode; 
		int m_number; 
		void setEmpty();
		void allocateAndCopy(const char* name);
		bool validPhone(int area, int exchange, int number) const; //return true
		void extractChar(std::istream& istr, char ch) const;
		std::ostream& printPhoneNumber(std::ostream& ostr) const;
		void set(const char* name, int area, int exchange, int number);
	public:
		Contact();
		Contact(const char* name, int area, int exchange, int number);
		Contact(const Contact& cnt);
		Contact& operator=(const Contact& cnt);
		~Contact();
		operator bool() const;
		std::ostream& print(std::ostream& ostr, bool) const;

		std::istream& read(std::istream& istr);

	};

	std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);

	std::istream& operator>>(std::istream& istr, Contact& cnt);


}
#endif // !SDDS_CONTACT_H

