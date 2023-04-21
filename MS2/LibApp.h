// Final Project Milestone 2
// Date Module
// File	LibApp.h
// Version 1.0
// Author	Jiseok Shim
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jiseok Shim        2021/11/22		   Preliminary release
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
    class LibApp {
        bool m_changed = false;
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        bool confirm(const char* message);
        void load();
        void save();
        void search();
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        void run();
    };
}
#endif // !SDDS_LIBAPP_H