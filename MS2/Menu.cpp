// Final Project Milestone 2
// Date Module
// File	Menu.cpp
// Version 1.0
// Author	Jiseok Shim
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jiseok Shim        2021/11/22		   Preliminary release
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshopsand assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include <iomanip>
using namespace std;
namespace sdds {

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
    MenuItem::operator bool() const {
        return menuItem != nullptr;
    }
    void MenuItem::display() {
        cout << menuItem;
    }

    Menu::Menu()
    {
        m_title = nullptr;
        noOfMenuItem = 0;
    }
    Menu::Menu(const char* title)
    {
        delete[] m_title;
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }
    Menu::~Menu()
    {
        delete[] m_title;
        for (int i = 0; i < noOfMenuItem; i++) delete m_item[i];
    }
    void Menu::display()
    {
        if (m_title != nullptr)
            cout << m_title << "\n";
        for (int i = 0; i < noOfMenuItem; i++)
            cout << " " << i + 1 << "- " << m_item[i]->menuItem << endl;
        cout << " 0- Exit\n> ";
    }
    int Menu::run()
    {
        display();
        char ch;
        cin >> ch;
        int inputVal = ch - '0';
        while (inputVal  < 0 || inputVal > noOfMenuItem)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> ch;
            inputVal = ch - '0';
        }
        return inputVal;
    }
    int Menu::operator~()
    {
        display();
        char ch;
        cin >> ch;
        int inputVal = ch - '0';
        while (inputVal  < 0 || inputVal > noOfMenuItem)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> ch;
            inputVal = ch - '0';
        }
        return inputVal;
    }
    Menu& Menu::operator<<(const char* menuitemConent)
    {
        m_item[noOfMenuItem++] = new MenuItem(menuitemConent);

        return *this;
    }
    Menu::operator bool() const
    {
        return (m_title != nullptr);
    }
    Menu::operator int() const
    {
        return noOfMenuItem;
    }
    Menu::operator unsigned int() const {
        return noOfMenuItem;
    }
    char* Menu::operator[](int i) const
    {
        return m_item[i]->menuItem;
    }

    std::ostream& Menu::write(std::ostream& os)const
    {
        if (m_title != nullptr)
            os << m_title;
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Menu& m)
    {
        return m.write(os);
    }
}