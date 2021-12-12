#ifndef FINALPROJECT_MEATS_H
#define FINALPROJECT_MEATS_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Meats : public Categories
{
private:
    const string catName = "Meats";
    string itemName;
public:
    Meats(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Meats();
    ~Meats();
    void print();
};

#endif //FINALPROJECT_MEATS_H
