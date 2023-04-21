// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29	       Preliminary release
/////////////////////////////////////////////////////////////////

//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-11-28
//Section:OOP244NII

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int MIN_YEAR = 1500;
    const int MAX_YEAR = 2021;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1()const; 
        bool validate();             
        void errCode(int);          
                  
        int mdays()const;          
        int systemYear()const;

    public:
        Date();                      
        Date(int year, int mon, int day); 
                                        
                                        
        bool bad()const;
        void setToToday();         
        int errCode()const;       
        const char* dateStatus()const;  
        int currentYear()const;         
        bool extractChar(std::istream& istr, char ch);
        bool operator==(const Date& D) const;
        bool operator!=(const Date& D) const;
        bool operator>=(const Date& D) const;
        bool operator<=(const Date& D) const;
        bool operator<(const Date& D) const;
        bool operator>(const Date& D) const;
        int operator- (const Date& D);
        operator bool() const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout)const;

    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
}
#endif