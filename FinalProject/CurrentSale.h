#ifndef CURRENTSALE_H
#define CURRENTSALE_H
#include <string>
#include <vector>
using namespace std;

class CurrentSale
{
	
	private:
		string itemName;
		string itemCat;
		double itemPrice;
		int amount;
	public:
		CurrentSale(string itemName, string itemCat, double itemPrice, int amount);
		~CurrentSale();
		string getItemCat();
		string getItemName();
		double getItemPrice();
		int getAmount();
		void setItemCat(string itemCat);
		void setItemName(string itemName);
		void setItemPrice(double itemPrice);
		void setAmount(int amount);
};


#endif
