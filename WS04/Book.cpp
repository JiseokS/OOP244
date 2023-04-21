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
#include "Book.h"

using namespace std;

namespace sdds
{
    Book::Book(const char* book_name, int noOfChapters, const Chapter* chapters) {
        this->isValid = true;
        this->book_name = nullptr;
        this->chapters = nullptr;
        this->noOfChapters = 0;
        int length = (book_name != nullptr ? strlen(book_name) : 0);
        if (length < 1)             this->isValid = false;
        if (noOfChapters < 1)       this->isValid = false;
        for (int i = 0; i < noOfChapters; i++)
            if (!chapters[i].isValidChapter())
                this->isValid = false;
        if (this->isValid) {
            this->book_name = new char[length + 1];
            strcpy(this->book_name, book_name);
            this->chapters = new Chapter[noOfChapters];
            for (int i = 0; i < noOfChapters; i++)
                this->chapters[this->noOfChapters++] = chapters[i];
        }
    }
    bool Book::isEmpty() const {
        return (isValid || this->noOfChapters == 0);
    }

    Book& Book::addChapter(const char* chapter_name, int noOfPages) {
        Chapter chapter(chapter_name, noOfPages);
        if (chapter.isValidChapter()) {
            Chapter* chapters = new Chapter[this->noOfChapters + 1];
            for (int i = 0; i < this->noOfChapters; i++)
                chapters[i] = this->chapters[i];
            chapters[this->noOfChapters++] = chapter;
            delete[] this->chapters;
            this->chapters = chapters;
        }
        return *this;
    }


    void Book::display() const {
        if (!isValid) {
            std::cout << "Invalid Book object";
            std::cout << std::endl;
        }
        else {
            std::cout << "Book Name: " << this->book_name << std::endl;
            std::cout << "No of Chapters: " << this->noOfChapters << std::endl;
            std::cout.width(50);
            std::cout << std::left;
            std::cout.fill(' ');
            std::cout << "Chapter name" << " ";
            std::cout << "Pages";
            std::cout << std::endl;
            for (int i = 0; i < noOfChapters; i++) {
                chapters[i].display();
                std::cout << std::endl;
            }
        }
    }
    Book::~Book() {
        if (book_name != nullptr)   
            delete[] book_name;
        if (chapters != nullptr)    
            delete[] chapters;
    }
}
