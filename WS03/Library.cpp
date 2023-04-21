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
#include "Library.h"

using namespace std;
namespace sdds
{
	void Library::setEmpty() {
		m_name[0] = '\0';
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}
	bool Library::isEmpty()const {
		return m_name[0] == '\0' && m_books == nullptr &&
			m_sizeOfBooksArray == 0 && m_addedBooks == 0;
	}
	void Library::header(const char* title)const {
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
		cout << "*****  " << m_name << "  *****" << endl;
		cout << title << endl;
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;
	}
	void Library::footer()const {
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
	}
	void Library::initialize(const char* name, int noOfBooks) {
		if (name != nullptr && name[0] != '\0' && noOfBooks > 0)
		{
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			m_books = new Book[m_sizeOfBooksArray];
			m_addedBooks = 0;
		}
		else
			setEmpty();
	}
	bool Library::addBook(const char* book_title, int sku, int loanDays) {
		bool res = false;
		if (m_addedBooks < m_sizeOfBooksArray)
		{
			m_books[m_addedBooks].set(book_title, sku, loanDays);
			if (!m_books[m_addedBooks].isEmpty())
			{
				res = true;
				m_addedBooks++;
			}
		}
		return res;
	}
	void Library::clear() {
		delete[] m_books;
		m_books = nullptr;


	}
	void Library::display(const char* substr) {
		bool found = false;
		cout << ">>> Searching for: \"" << substr << "\" <<<" << endl;
		header("Substring search");
		int row = 1;
		for (int i = 0; i < m_addedBooks; i++)
		{
			if (m_books[i].subTitle(substr))
			{
				cout.width(4);
				cout.fill(' ');
				cout.setf(ios::left);
				cout << row++;
				m_books[i].display();
				found = true;

			}
		}
		if (!found)
			cout << "No book title contains \"" << substr << "\"" << endl;
		footer();
	}
	void Library::display(bool overdueOnly)const {
		if (!isEmpty())
		{
			int row = 1;
			header(overdueOnly ? "Overdue Books" : "Books on Loan");
			for (int i = 0; i < m_addedBooks; i++)
			{
				if (!overdueOnly || m_books[i].hasPenalty()) 
				{
					cout.setf(ios::left);
					cout.width(4);
					cout.fill(' ');
					cout << row++;
					cout.unsetf(ios::left);
					m_books[i].display();
				}
			}
			footer();
		}
		else
			cout << "Invalid Library" << endl;
	}
}
