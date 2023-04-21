//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-11-28
//Section:OOP244NII
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"Publication.h"
#include"Streamable.h"
#include"Lib.h"
#include"Date.h"
using namespace std;
namespace sdds {
	Publication::Publication() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}
	Publication::Publication(const Publication& publication) {
		if (publication) {
			this->set(publication.m_title, publication.m_shelfId, publication.m_membership, publication.m_libRef, publication.m_date);
		}
	}
	Publication::~Publication() {
		delete[] m_title;
	}
	void Publication::extractChar(std::istream& istr, char ch)const {
		if (istr.peek() == ch) istr.get();
		else  istr.setstate(ios::failbit);
	}
	void Publication::set(int member_id) {
		if (member_id > 9999 && member_id <= 99999) m_membership = member_id;
		else m_membership = 0;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date.setToToday();
	}
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return m_membership != 0;
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		bool trueFalse = false;
		if (strstr(m_title, title) != NULL) {
			trueFalse = true;
		}
		return trueFalse;
	}
	Publication::operator const char* () const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}
	bool Publication::conIO(ios& ios) const {
		return &ios == &cin || &ios == &cout;
	}
	ostream& Publication::write(ostream& os) const {
		if (conIO(os)) {
			if (*this) {
				os << "| " << setw(SDDS_SHELF_ID_LEN) << left << setfill(' ') << m_shelfId;
				os << " | " << setw(SDDS_TITLE_WIDTH) << left << setfill('.') << m_title << " | ";
				if (m_membership == 0)
				{
					os << " N/A ";
				}
				else os << m_membership;
				os << " | " << m_date << " |";
			}
		}
		else {
			if (*this) {
				os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
			}
		}
		return os;
	}
	istream& Publication::read(istream& istr) {
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		onLoan();
		set(0);
		setRef(-1);
		resetDate();
		char* title = nullptr;
		title = new char[SDDS_TITLE_WIDTH + 1];
		char shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int member = 0;
		int libRef = -1;
		Date date;
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(title, SDDS_TITLE_WIDTH + 1, '\n');
			cout << "Date: ";
			istr >> date;
			if (date.bad()) istr.setstate(ios::failbit);
		}
		else {
			istr >> libRef;
			extractChar(istr, '\t');
			istr >> shelfId;
			extractChar(istr, '\t');
			if (shelfId[0] == '\0') istr.setstate(ios::failbit);
			istr.getline(title, SDDS_TITLE_WIDTH + 1, '\t');
			if (title == nullptr || title[0] == '\0') istr.setstate(ios::failbit);
			if (istr.good()) {
				istr >> member;
				istr >> date;
			}
		}
		if (istr.rdstate() == 0) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = member;
			m_date = date;
			m_libRef = libRef;
		}
		delete[] title;
		return istr;
	}
	Publication::operator bool() const {
		return m_title != nullptr || m_shelfId[0] != '\0';
	}
	ostream& operator<<(ostream& os, const Publication& obj) {
		obj.write(os);
		return os;
	}
	istream& operator>>(istream& is, Publication& obj) {
		obj.read(is);
		return is;
	}
	Publication& Publication::operator=(const Publication& publication) {
		if (this != &publication) {
			this->set(publication.m_title, publication.m_shelfId, publication.m_membership, publication.m_libRef, publication.m_date);
		}
		return (*this);
	}
	void Publication::set(const char* title, const char* shelfId, int membership, int libRef, Date date) {
		if (m_title != nullptr) delete[] m_title;
		m_title = nullptr;
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_libRef = libRef;
			m_date = date;
		}
		else {
			m_shelfId[0] = '\0';
			m_membership = 0;
			m_libRef = -1;
			m_date.setToToday();
		}
	}
}