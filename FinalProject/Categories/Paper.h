#ifndef FINALPROJECT_PAPER_H
#define FINALPROJECT_PAPER_H

#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Paper : public Categories
{
private:
    const string catName = "Paper";
    string itemName;
public:
    Paper(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
    Paper();
    ~Paper();
    void print();
};

#endif //FINALPROJECT_PAPER_H
