#ifndef FINALPROJECT_PHARMACY_H
#define FINALPROJECT_PHARMACY_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Pharmacy : public Categories
{
private:
    const string catName = "Pharmacy";
    string itemName;
public:
    Pharmacy(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Pharmacy();
    ~Pharmacy();
    void print();
};

#endif //FINALPROJECT_PHARMACY_H
