//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        OOP244NII
// Workshop:       4
// Date: 2021-10-10
//==============================================
#ifndef SDDS_CHAPTER_H
#define SDDS_CHAPTER_H
#define CHAPTER_NAME_LEN 51
namespace sdds {

    class Chapter {
    private:
        char chapter_name[CHAPTER_NAME_LEN];
        int noOfPages;
        bool isValid;

    public:
        Chapter();
        Chapter(const char* chapter_name, int noOfPages);
        bool isValidChapter() const;
        void display() const;
    };
}
#endif
