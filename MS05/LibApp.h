//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-08
//Section:OOP244NII
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <cstring>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"

namespace sdds {
    class LibApp {
        char m_fileName[256]{};
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
        int NOLP;
        int LLRN;
        Menu m_typeMenu{ "Choose the type of publication:" };
        bool m_changed = false;
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        bool confirm(const char* message);
        void load();
        void save();
        int search(int num, char type);
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
        Publication* getPub(int libRef);
    public:
        LibApp();
        LibApp(const char dataTitle[256]);
        ~LibApp();
        void run();
    };
}
#endif 




