#ifndef FINALPROJECT_BREAKFAST_H
#define FINALPROJECT_BREAKFAST_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Breakfast : public Categories
{
private:
    const string catName = "Breakfast";
    string itemName;
public:
    Breakfast(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Breakfast();
    ~Breakfast();
    void print() override;
};


#endif //FINALPROJECT_BREAKFAST_H
