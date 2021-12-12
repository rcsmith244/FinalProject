#ifndef FINALPROJECT_GRAINS_H
#define FINALPROJECT_GRAINS_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Grains : public Categories
{
private:
    const string catName = "Grains";
    string itemName;
public:
    Grains(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Grains();
    ~Grains();
    void print();
};

#endif //FINALPROJECT_GRAINS_H
