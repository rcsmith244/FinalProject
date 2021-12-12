#ifndef BEVERAGES_H
#define BEVERAGES_H
#include "Categories.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Beverages : public Categories
{
	private:
		const string catName = "Beverages";
		string itemName;
	public:
		Beverages(string itemName, int itemID, double itemPrice, int itemCount, string measurement);
		Beverages();
		~Beverages();
        void print();
};

#endif // !BEVERAGES_H