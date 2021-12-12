#ifndef SALESINTERFACE_H
#define SALESINTERFACE_H

#include "Sales.h"
#include "Categories/Categories.h"
#include "CurrentSale.h"
#include "Management.h"
#include "CurrentSale.h"
#include "FileIO.h"
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <cassert>
#pragma warning(disable : 4996)
using namespace std;


class SalesInterface
{
	protected:
	string fileNames[12] = {"Beverages", "Bread", "Breakfast", "Snacks", "Dairy", "Produce",
							"Grains", "Meats", "Misc", "Paper", "PetCare", "Pharmacy"};
		vector<Categories*> items[12];
		vector<Sales> sales;
		vector<CurrentSale> currentSale;
	public:
		SalesInterface();
		~SalesInterface();
		void writeToSalesFile(string name, string phoneNumber, string itemName, int buyCount, double itemPrice);
		void orderMenu(vector<Categories*>& items,const string& categoryName);
		void categoryMenu(vector<Categories*>& items, const string& categoryName);
		void createItem();
		void mainMenu();
		void managementMenu(vector<Categories*> items);
		void checkOut();
		void viewCart();
};

#endif