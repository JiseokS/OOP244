//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-08
//Section:OOP244NII
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
    LibApp::LibApp()
    {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        load();
    }

    LibApp::LibApp(const char dataTitle[256])
    {
        m_mainMenu << "Add New Publication" << "Remove Publication"
            << "Checkout publication from library" << "Return publication to library";

        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        strcpy(m_fileName, dataTitle);

        NOLP = 0;
        LLRN = 0;

        m_typeMenu << "Book" << "Publication";

        load();
    }
    LibApp::~LibApp()
    {
        for (int i = 0; i < NOLP; i++)
            delete PPA[i];
    }
    bool LibApp::confirm(const char* message)
    {
        Menu item(message);
        item << "Yes";
        int input = item.run();
        return input;
    }

    void LibApp::load() {
        char type{};

        cout << "Loading Data\n";

        ifstream myFile;
        myFile.open(m_fileName);

        if (!myFile) {
            cerr << "Error: file could not be opened" << endl;
            exit(1);
        }

        for (int i = 0; myFile; i++)
        {
            myFile >> type;
            myFile.ignore();

            if (myFile)
            {
                if (type == 'P')
                    PPA[i] = new Publication;
                else if (type == 'B')
                    PPA[i] = new Book;

                if (PPA[i] && i < SDDS_LIBRARY_CAPACITY)
                {
                    myFile >> *PPA[i];
                    LLRN = PPA[i]->getRef();
                    NOLP++;
                }
            }
        }
    }

    void LibApp::save() {
        cout << "Saving Data\n";

        ofstream myFile(m_fileName);

        for (int i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() != 0)
                myFile << *PPA[i] << endl;
        }
    }
    void prnPub(Publication* p[], int size, int ref)
    {
        int i;
        for (i = 0; i < size; i++) {
            if (ref == p[i]->getRef()) {
                cout << *p[i] << endl;
                i = size; 
            }
        }
    }

    int LibApp::search(int num, char type)
    {
        char title[256]{};

       
        PublicationSelector ps("Select one of the following found matches:", 15);

        cout << "Publication Title: ";

        cin.getline(title, 256, '\n');

        if (num == 1) 
        {
            for (int i = 0; i < NOLP; i++)
            {
                if (strstr(*PPA[i], title) && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];
            }
        }
        else if (num == 2) 
        {
            for (int i = 0; i < NOLP; i++)
            {
                if (strstr(*PPA[i], title) && !PPA[i]->onLoan() && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];
            }
        }
        else if (num == 3) 
        {
            for (int i = 0; i < NOLP; i++)
            {
                if (strstr(*PPA[i], title) && PPA[i]->onLoan() && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];
            }
        }

        int refNum = 0;

        if (ps)
        {
            ps.sort();
            refNum = ps.run();

            if (refNum)
            {
                prnPub(PPA, NOLP, refNum);
            }
            else
            {
                cout << "Aborted!\n" << endl;
            }

        }
        else
        {
            cout << "No matches found!\n" << endl;
        }


        return refNum;
    }

    void LibApp::returnPub()
    {
        char type{};

        int refNum;
        cout << "Return publication to the library" << endl;

        int typeNum = m_typeMenu.run();
        if (typeNum == 1) type = 'B';
        else
            type = 'P';

        refNum = search(3, type); 

        if (refNum != 0 && confirm("Return Publication?"))
        {
            Date ckOutDate = getPub(refNum)->checkoutDate();
            Date today;

            int loanDate = today - ckOutDate;
            loanDate -= 15;

            if (loanDate > 0)
            {
                cout << std::fixed;
                cout << std::setprecision(2);
                cout << "Please pay $" << float(loanDate) * (0.5)
                    << " penalty for being " << loanDate << " days late!" << endl;
            }

            getPub(refNum)->set(0);
            cout << "Publication returned\n\n";
            m_changed = true;
        }
    }

    void LibApp::newPublication()
    {
        int type;

        if (NOLP >= SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!\n" << endl;
            return;
        }

        cout << "Adding new publication to the library\n";
        type = m_typeMenu.run();
        Publication* temp = nullptr;

        if (type == 0)
        {
            cout << "Aborted!\n" << endl;
            return;
        }
        else if (type == 1)
        {
            temp = new Book;
            std::cin >> *temp;
        }
        else if (type == 2)
        {
            temp = new Publication;
            std::cin >> *temp;
        }

        if (std::cin.fail())
        {
            std::cout << "Aborted!\n" << endl;
            exit(0);
        }

        if (confirm("Add this publication to the library?"))
        {
            m_changed = true;

            PPA[NOLP] = temp;

            LLRN++;

            PPA[NOLP]->setRef(LLRN);

            NOLP++;

            std::cout << "Publication added\n\n";
        }

        if (!*temp)
        {
            cout << "Failed to add publication!" << endl;
            delete temp;
        }

    }
    void LibApp::removePublication()
    {
        char type{};

        cout << "Removing publication from the library\n";

        int typeNum = m_typeMenu.run();

        if (typeNum == 1)
            type = 'B';
        else if (typeNum == 2)
            type = 'P';

        int refNum = search(1, type);

        if (refNum != 0 && confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            getPub(refNum)->setRef(0);
            cout << "Publication removed\n\n";
        }
    }
    void LibApp::checkOutPub()
    {
        char type;
        int typeNum;
        std::cout << "Checkout publication from the library\n";
        typeNum = m_typeMenu.run();

        if (typeNum == 1)
            type = 'B';
        else if (typeNum == 2)
            type = 'P';


        int ref = search(2, type);

        if (ref != 0 && confirm("Check out publication?"))
        {
            m_changed = true;

            int mn;

            std::cout << "Enter Membership number: ";

            bool isEnd = false;

            while (!isEnd)
            {
                std::cin >> mn;

                if (mn > 9999 && mn <= 99999)
                    isEnd = true;
                else
                    cout << "Invalid membership number, try again: ";
            }

            getPub(ref)->set(mn);

            std::cout << "Publication checked out\n\n";
        }
    }

    void LibApp::run()
    {
        while (1) {
            int mainOption = m_mainMenu.run();
            if (mainOption == 1) newPublication();
            else if (mainOption == 2) removePublication();
            else if (mainOption == 3) checkOutPub();
            else if (mainOption == 4) returnPub();
            else if (mainOption == 0)
            {
                if (m_changed)
                {
                    int exitOption = m_exitMenu.run();
                    if (exitOption == 1)
                    {
                        save();
                        break;
                    }
                    else if (exitOption == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?")) break;
                    }
                    else if (exitOption == 2) cout << "\n";
                }
                else break;
            }
        }
        cout << endl;
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";

    }

    Publication* LibApp::getPub(int libRef)
    {
        for (int i = 0; i < NOLP; i++)
        {
            if (libRef == PPA[i]->getRef())
                return PPA[i];
        }
        return nullptr;
    }
}
