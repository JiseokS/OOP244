//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-08
//Section:OOP244NII
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
        int inputVal;
        cin >> inputVal;

        while (inputVal  < 0 || inputVal > noOfMenuItem)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> inputVal;
        }

        cin.clear(); 
        cin.ignore(80, '\n');

        return inputVal;
    }
    int Menu::operator~()
    {
        display();
        int inputVal;
        cin >> inputVal;

        while (inputVal  < 0 || inputVal > noOfMenuItem)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> inputVal;
        }

        cin.clear(); 
        cin.ignore(80, '\n');

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