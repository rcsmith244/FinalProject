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
		string itemName = "";
	public:
		Beverages(string itemName, int itemID, double itemPrice, int itemCount);
		Beverages();
		~Beverages();
        void print();
//		string getItemName();
//		int getItemID();
//		int getItemCount();
//		double getItemPrice();
//		void setItemName(string itemName);
//		void setItemID(int itemID);
//		void setItemPrice(double itemPrice);
//		void setItemCount(int itemCount);
};

#endif // !BEVERAGES_H