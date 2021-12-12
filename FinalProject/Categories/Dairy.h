#ifndef FINALPROJECT_DAIRY_H
#define FINALPROJECT_DAIRY_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Dairy : public Categories
{
private:
    const string catName = "Dairy";
    string itemName;
public:
    Dairy(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Dairy();
    ~Dairy();
    void print();
};
#endif //FINALPROJECT_DAIRY_H
