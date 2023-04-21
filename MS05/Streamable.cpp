//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-04
//Section:OOP244NII

#include<iostream>
#include"Streamable.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const Streamable& obj) {
		obj.write(os);
		return os;
	}

	istream& operator>>(istream& is, Streamable& obj) {
		obj.read(is);
		return is;
	}
}