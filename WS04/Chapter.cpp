//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-10
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Chapter.h"

using namespace std;

namespace sdds
{
    Chapter::Chapter() {
        this->isValid = false;
    }
    Chapter::Chapter(const char* chapter_name, int noOfPages) {
        this->isValid = true;
        int length = (chapter_name != nullptr ? strlen(chapter_name) : 0);
        if (length < 1 || length >= CHAPTER_NAME_LEN)       
            this->isValid = false;
        if (noOfPages < 1 || noOfPages > 200)               
            this->isValid = false;
        if (this->isValid) {
            strcpy(this->chapter_name, chapter_name);
            this->noOfPages = noOfPages;
        }
    }

    bool Chapter::isValidChapter() const {
        return this->isValid;
    }

    void Chapter::display() const {
        if (isValid) {
            cout.width(50);
            cout.fill('.');
            cout.setf(ios::left);
            cout << this->chapter_name;
            cout.unsetf(ios::left);
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << this->noOfPages;
            cout.unsetf(ios::right);
        }
        else {
            cout << "Invalid Chapter";
        }
    }
}
