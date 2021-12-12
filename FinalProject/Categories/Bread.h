#ifndef FINALPROJECT_BREAD_H
#define FINALPROJECT_BREAD_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Bread : public Categories
{
    private:
        const string catName = "Bread";
        string itemName;
    public:
        Bread(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
        Bread();
        ~Bread();
        void print();
};


#endif //FINALPROJECT_BREAD_H
