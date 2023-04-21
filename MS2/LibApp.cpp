// Final Project Milestone 2
// Date Module
// File	LibApp.cpp
// Version 1.0
// Author	Jiseok Shim
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jiseok Shim        2021/11/22     	   Preliminary release
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <cstring>
#include "LibApp.h"
using namespace std;
namespace sdds {
    bool LibApp::confirm(const char* message)
    {
        Menu item(message);
        item << "Yes";
        int input = item.run();
        return input;
    }
    void LibApp::load() {
        cout << "Loading Data\n";
    }
    void LibApp::save() {
        cout << "Saving Data\n";
    }
    void LibApp::search() {
        cout << "Searching for publication\n";
    }
    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n\n";
        m_changed = true;
    }
    void LibApp::newPublication()
    {
        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added\n";
        }
        else cout << "\n";
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed\n\n";
        }
    }
    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out\n\n";
        }
    }
    LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        load();
    }
    void LibApp::run()
    {
        while (1) {
            int inputVal = m_mainMenu.run();
            if (inputVal == 1) newPublication();
            else if (inputVal == 2) removePublication();
            else if (inputVal == 3) checkOutPub();
            else if (inputVal == 4) returnPub();
            else if (inputVal == 0)
            {
                if (m_changed)
                {
                    int selection = m_exitMenu.run();
                    if (selection == 1)
                    {
                        save();
                        break;
                    }
                    else if (selection == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?")) break;
                    }
                    else if (selection == 2) cout << "\n";
                }
                else break;
            }
        }
        cout << endl;
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";

    }


}


