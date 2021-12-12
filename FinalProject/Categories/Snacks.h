#ifndef FINALPROJECT_SNACKS_H
#define FINALPROJECT_SNACKS_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Snacks : public Categories
{
private:
    const string catName = "Snacks";
    string itemName;
public:
    Snacks(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Snacks();
    ~Snacks();
    void print();
};


#endif //FINALPROJECT_SNACKS_H
