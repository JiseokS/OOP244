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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"

using namespace std;

namespace sdds
{
    MenuItem::MenuItem()
    {
        menuItem = nullptr;
    }

    MenuItem::MenuItem(const char* item)
    {
        delete[] menuItem;
        menuItem = new char[strlen(item) + 1];
        strcpy(menuItem, item);
    }

    MenuItem::~MenuItem()
    {
        delete[] menuItem;
    }

    MenuItem::operator bool() const
    {
        if (menuItem != nullptr)
            return true;

        return false;
    }

    /*   MenuItem::operator const char* () const
       {
           return menuItem;
       }*/

    void MenuItem::display() const
    {
        cout << menuItem;
    }

    Menu::Menu()
    {
        menuTitle = nullptr;
        noOfMenuItem = 0;
    }

    Menu::Menu(const char* title)
    {
        delete[] menuTitle;
        menuTitle = new char[strlen(title) + 1];
        strcpy(menuTitle, title);
    }

    Menu::~Menu()
    {
        delete[] menuTitle;
        for (int i = 0; i < noOfMenuItem; i++) delete m_items[i];
    }

    void Menu::printMenu() const
    {
        if (menuTitle != nullptr)
            cout << menuTitle << ":\n";

        for (int i = 0; i < noOfMenuItem; i++)
            cout << " " << i + 1 << "- " << m_items[i]->menuItem << "\n";

        cout << " 0- Exit\n";
        cout << "> ";
    }

    int Menu::run() const
    {

        printMenu();
        char charVal;

        cin >> charVal;

        int intVal = charVal - '0';

        while (intVal < 0 || intVal > noOfMenuItem)
        {

            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> charVal;
            intVal = charVal - '0';
        }

        return intVal;
    }

    int Menu::operator~ ()
    {
        printMenu();
        char charVal;

        cin >> charVal;

        int intVal = charVal - '0';

        while (intVal < 0 || intVal > noOfMenuItem)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> charVal;
            intVal = charVal - '0';
        }

        return intVal;
    }


    Menu& Menu::operator<<(const char* menuitemConent)
    {

        m_items[noOfMenuItem++] = new MenuItem(menuitemConent);

        return *this;
    }


    Menu::operator bool() const
    {
        if (menuTitle != nullptr)
            return true;
        return false;
    }

    Menu::operator unsigned int() const
    {
        return noOfMenuItem;
    }

    /* Menu::operator int() const
     {
         return noOfMenuItem;
     }*/

    char* Menu::operator[] (int index) const
    {
        return m_items[index]->menuItem;
    }

    std::ostream& Menu::write(std::ostream& os) const
    {
        if (menuTitle != nullptr)
            os << menuTitle;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& M)
    {
        return M.write(os);
    }
}