#ifndef FINALPROJECT_PETCARE_H
#define FINALPROJECT_PETCARE_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class PetCare : public Categories
{
private:
    const string catName = "PetCare";
    string itemName;
public:
    PetCare(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    PetCare();
    ~PetCare();
    void print();
};

#endif //FINALPROJECT_PETCARE_H
