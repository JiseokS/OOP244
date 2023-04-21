/*
Name:Jiseok Shim
Email:jshim13@myseneca.ca
Student ID:122758170
Data:2021-11-18
Section:OOP244NII
*/
#ifndef SDDS_LABELEDSHAPE_H
#define SDDS_LABELEDSHAPE_H
#include "baseShape.h"
namespace sdds {
	class labelShape: public baseShape {
		char* m_label = nullptr;
	protected:
		const char* label()const;
	public:
		labelShape();
		labelShape(const char* label);
		~labelShape();
		labelShape(const labelShape& )= delete;
		void operator=(const labelShape&) = delete;
		void readShape(std::istream& is);
	};
	
}
#endif