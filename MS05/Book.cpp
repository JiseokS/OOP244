//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-04
//Section:OOP244NII
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>
#include"Book.h"
using namespace std;
namespace sdds {
	Book::Book() : Publication() {
		m_authorName = nullptr;
	}

	void Book::set(const char* authorname) {
		if (m_authorName != nullptr)
			delete[] m_authorName;
		m_authorName = nullptr;

		if (authorname != nullptr && authorname[0] != '\0') {
			m_authorName = new char[strlen(authorname) + 1];

			strcpy(m_authorName, authorname);
		}
	}
	Book::Book(const Book& bk) : Publication(bk) {
		if (bk.operator bool()) {
			this->set(bk.m_authorName);
		}
	}

	Book& Book::operator=(const Book& bk) {
		if (this != &bk) {
			Publication::operator=(bk);
			this->set(bk.m_authorName);
		}

		return (*this);
	}

	Book::~Book() {
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {

		Publication::write(os);
		if (m_authorName != nullptr && m_authorName[0] != '\0') {
			char temp[SDDS_AUTHOR_WIDTH + 1] = {};

			if (Publication::conIO(os)) {
				os << " ";

				if (strlen(m_authorName) > SDDS_AUTHOR_WIDTH) {

					for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
						temp[i] = m_authorName[i];
					}

					temp[SDDS_AUTHOR_WIDTH] = '\0';

					os << setw(SDDS_AUTHOR_WIDTH) << temp;
				}
				else {
					os << setw(SDDS_AUTHOR_WIDTH) << m_authorName;
				}

				os << " |";
			}
			else {
				os << '\t';

				os << m_authorName;
			}
		}

		return os;
	}

	std::istream& Book::read(std::istream& istr) {

		Publication::read(istr);

		char* authorname = nullptr;
		authorname = new char[256];

		delete[] m_authorName;

		if (Publication::conIO(istr)) {
			istr.ignore(1, '\n');
			cout << "Author: ";
			istr.getline(authorname, 256, '\n');
		}
		else {
			istr.ignore(1, '\t');
			istr.get(authorname, 256, '\n');
		}

		if (authorname[0] == '\0')
			istr.setstate(ios::failbit);

		if (istr.good()) {
			m_authorName = new char[strlen(authorname) + 1];
			strcpy(m_authorName, authorname);
		}

		delete[] authorname;
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool()const {
		return m_authorName != nullptr && m_authorName[0] != '\0'
			&& Publication::operator bool();
	}

	ostream& operator<<(ostream& os, const Book& obj) {
		obj.write(os);
		return os;
	}

	istream& operator>>(istream& is, Book& obj) {
		obj.read(is);
		return is;
	}
}

