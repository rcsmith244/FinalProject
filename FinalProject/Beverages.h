#ifndef BEVERAGES_H
#define BEVERAGES_H
#include "Categories.h"
#include <string>

class Beverages : public Categories
{
	private:
		const string catName = "Beverages";
		string itemName = "";
		int itemID = 0;
		double itemPrice = 0;
		int itemCount = 0;
		bool reorderItem = false;
	public:
		Beverages(string itemName, int itemID, double itemPrice, int itemCount);
		Beverages();
		~Beverages();
		string getItemName();
		int getItemID();
		int getItemCount();
		double getItemPrice();
		void setItemName(string itemName);
		void setItemID(int itemID);
		void setItemPrice(double itemPrice);
		void setItemCount(int itemCount);
		void orderItem();
};

#endif // !BEVERAGES_H