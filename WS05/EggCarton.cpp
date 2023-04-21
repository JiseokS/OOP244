//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       5
// Date: 2021-10-12
//==============================================
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds {
	void EggCarton::setBroken() {
		m_size = -1;
		m_noOfEggs = -1;
	}

	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize){
		if ((size % 6 == 0) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
		{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboSize;
		}
		else setBroken();
	}
	ostream& EggCarton::display(std::ostream& ostr) const{
		if (*this)
		{
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else
			ostr << "Broken Egg Carton!" << endl;
		return ostr;

	}
	istream& EggCarton::read(std::istream& istr){
		char type;
		istr >> type;
		if (type == 'j')m_jumbo = true; else m_jumbo = false;
		istr.ignore();
		istr >> m_size;
		istr.ignore();
		istr >> m_noOfEggs;
		if (!((m_size % 6 == 0) && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size))
			setBroken();
		return istr;
	
	}

	EggCarton::operator bool() const{
		return m_size >= 0;
	}
	EggCarton::operator int() const{
		int r = -1;
		if (*this) r = m_noOfEggs;
		return r;
	}
	EggCarton::operator double() const{
		double r = -1.0;
		if (*this) 
		{
			if (m_jumbo)
			{
				r = (m_noOfEggs * JumboEggWieght) / 1000.0;
			}
			else r = (m_noOfEggs * RegularEggWieght) / 1000.0;
		}

		return r;
	}

	EggCarton& EggCarton::operator --(){
		if (*this && m_noOfEggs > 0) m_noOfEggs--;
		return *this;
	}
	EggCarton EggCarton::operator --(int){
		EggCarton temp = *this;
		operator--();
		return temp;
	}
	EggCarton& EggCarton::operator ++(){
		if (*this) m_noOfEggs++;
		if (m_noOfEggs > m_size) setBroken();
		return *this;
	}
	EggCarton EggCarton::operator ++(int){
		EggCarton temp = *this;
		operator++();
		return temp;
	}

	EggCarton& EggCarton::operator=(int value){
		m_noOfEggs = value;
		if (m_noOfEggs > m_size) setBroken();
		return *this;
	}
	EggCarton& EggCarton::operator+=(int value){
		if(*this) m_noOfEggs += value;
		if (m_noOfEggs > m_size) setBroken();
		return *this;
	}
	EggCarton& EggCarton::operator+=(EggCarton& right){
		if (*this)
		{
			m_noOfEggs += right.m_noOfEggs;
			if (m_noOfEggs > m_size)
			{
				right.m_noOfEggs = m_noOfEggs - m_size;
				m_noOfEggs = m_size;
			}
			else right.m_noOfEggs = 0;
		}
		return *this;
	}

	bool EggCarton::operator==(const EggCarton& right) const{
		bool ret = false;
		double diff = double(*this) - double(right);
		if (diff > -0.001 && diff < 0.001) ret = true;
		return ret;
	}

	int operator+(int left, const EggCarton& right) {
		if (right) left += int(right);
		return left;
	}
	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, EggCarton& right) {
		return right.read(istr);
	}
 

 
}