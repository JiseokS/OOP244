/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<cstring>
#include "labelShape.h"

using namespace std;
namespace sdds {
	const char* labelShape::label()const {
		return m_label;
	}
	labelShape::labelShape() { }
	labelShape::labelShape(const char* label) {
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	labelShape::~labelShape() {
		delete[] m_label;
	}
	void labelShape::readShape(std::istream& is) {
		string label;
		getline(is, label, ',');
		delete[] m_label;
		m_label = new char[strlen(label.c_str()) + 1];
		strcpy(m_label, label.c_str());
	}
}