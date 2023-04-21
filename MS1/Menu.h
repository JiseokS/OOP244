// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Jiseok Shim
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jiseok Shim        2021/11/16		   Preliminary release
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
//#include "Utils.h"

namespace sdds
{
    class Menu;
    class MenuItem
    {
        char* menuItem{};
        MenuItem();
        MenuItem(const char* item);
        ~MenuItem();
        operator bool() const;
        //operator const char* () const;
        void display() const;

        friend class Menu;
    };

    const unsigned int MAX_MENU_ITEM = 20;

    class Menu
    {
        char* menuTitle{};
        MenuItem* m_items[MAX_MENU_ITEM] = {};
        int noOfMenuItem = 0;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        void printMenu() const;
        int run() const;
        int operator~ ();
        Menu& operator << (const char* menuitemConent);
        operator bool() const;
        operator unsigned int() const;
        //operator int() const;
        char* operator[] (int index) const;
        std::ostream& write(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Menu& M);
}

#endif