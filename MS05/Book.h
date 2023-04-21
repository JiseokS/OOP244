//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-04
//Section:OOP244NII
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include"Publication.h"
namespace sdds {
	class Book : public Publication {
		char* m_authorName{};
	private:
		void set(const char* authorname);
	public:
		Book();
		Book(const Book& bk);
		Book& operator=(const Book& bk);
		~Book();

		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool()const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& obj);
	std::istream& operator>>(std::istream& is, Book& obj);
}


#endif