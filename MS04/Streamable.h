//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-04
//Section:OOP244NII


#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

namespace sdds
{
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::ostream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable() {};

	};

	std::ostream& operator<<(std::ostream& os, const Streamable& Str);
	std::istream& operator>>(std::istream& is, Streamable& Str);
}

#endif
