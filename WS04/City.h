//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-07
//==============================================
#ifndef SDDS_CITY_H
#define SDDS_CITY_H
namespace sdds {

	const int POPULATION = 20000; 
	class City
	{
	private:
		char m_cityName[31];
		int m_population;
	public:
		City();
		City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;

	};
}
#endif 
