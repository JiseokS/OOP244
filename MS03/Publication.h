//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-11-28
//Section:OOP244NII

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include"Date.h"
#include"Lib.h"
namespace sdds {
	class Publication {
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{}; 
		int m_membership = 0;
		int m_libRef = -1;
		Date m_date;
		void extractChar(std::istream& istr, char ch)const;
		void set(const char* title, const char* shelfId, int membership, int libRef, Date date);
	public:
		Publication();
		Publication(const Publication& publication);
		~Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		Publication& operator=(const Publication& publication);
	};
	std::ostream& operator<<(std::ostream& os, const Publication& obj);
	std::istream& operator>>(std::istream& is, Publication& obj);
}
#endif