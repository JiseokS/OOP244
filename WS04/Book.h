//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-10
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#ifndef BOOK_H
#define BOOK_H
#include "Chapter.h"
namespace sdds {
    // maximum length of the book
#define BOOK_NAME_LEN 51

// The `Book` class
    class Book {
    private:
        char* book_name;
        int noOfChapters;
        Chapter* chapters;
        bool isValid;
    public:
        Book(const char* book_name, int noOfChapters, const Chapter* chapters);
        bool isEmpty() const;
        Book& addChapter(const char* chapter_name, int noOfPages);
        void display() const;
        ~Book();
    };
};

#endif