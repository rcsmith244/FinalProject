#ifndef FINALPROJECT_MISC_H
#define FINALPROJECT_MISC_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Misc : public Categories
{
private:
    const string catName = "Misc";
    string itemName;
public:
    Misc(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Misc();
    ~Misc();
    void print();
};

#endif //FINALPROJECT_MISC_H
