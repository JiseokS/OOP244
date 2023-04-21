//Name:Jiseok Shim
//ID:122758170
//Email:jshim13@myseneca.ca
// Date:2021-12-02
//Section:OOP244NII

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
    //check
    template <typename t1, typename t2>
    bool check(t1* array, int index, t2 key)
    {
        return array[index] == key;
    }
    //search
    template <typename t1, typename t2>
    bool search(t1* array, int size, t2 key, Collection<t1>& c)
    {
        bool res = false;
        for (int i = 0; i < size; i++)
        {
            if (check(array, i, key))
            {
                c.add(array[i]);
                res = true;
            }
        }
        return res;
    }
    //listArrayElements
    template <typename T>
    void listArrayElements(const char* Title, T* array, int size)
    {
        std::cout << Title << std::endl;
        for (int i = 0; i < size; i++)
        {
            //1: 10
            std::cout << i + 1 << ": " << array[i] << std::endl;
        }
    }

    //sizeCheck
    template <typename t1>
    bool sizeCheck(Collection<t1>& c1, Collection<t1>& c2)
    {
        return c1.size() > c2.size();
    }

}
#endif // !SDDS_SEARCH_H_

