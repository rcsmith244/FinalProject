#ifndef FINALPROJECT_BREAD_H
#define FINALPROJECT_BREAD_H

#include "Categories.h"
#include <string>


class Bread : public Categories
{
    private:
        const string catName = "Beverages";
        string itemName = "";
    public:
        Bread(string itemName, int itemID, double itemPrice, int itemCount);
        Bread();
        ~Bread();
};


#endif //FINALPROJECT_BREAD_H
