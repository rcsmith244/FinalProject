#ifndef FINALPROJECT_PRODUCE_H
#define FINALPROJECT_PRODUCE_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Produce : public Categories
{
private:
    const string catName = "Produce";
    string itemName;
public:
    Produce(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Produce();
    ~Produce();
    void print();
};

#endif //FINALPROJECT_PRODUCE_H
