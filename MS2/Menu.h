// Final Project Milestone 2
// Date Module
// File	Menu.h
// Version 1.0
// Author	Jiseok Shim
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jiseok Shim        2021/11/22		   Preliminary release
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
    int const MAX_MENU_ITEMS = 20;
    class Menu;
    class MenuItem {
        char* menuItem{};
        MenuItem();
        MenuItem(const char* item);
        ~MenuItem();
        operator bool() const;
        void display();
        friend class Menu;
    };
    class Menu {
        char* m_title{};
        MenuItem* m_item[MAX_MENU_ITEMS] = {};
        int noOfMenuItem = 0;
    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        void display();
        int run();
        int operator~();
        Menu& operator<<(const char* menuitemConent);
        operator bool() const;
        operator int() const;
        operator unsigned int() const;
        char* operator[](int i) const;
        std::ostream& write(std::ostream& os = std::cout)const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& m);
}
#endif