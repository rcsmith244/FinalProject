#ifndef SALESINTERFACE_H
#define SALESINTERFACE_H

#include "Management.h"
#include "Sales.h"
#include "Categories/Categories.h"
#include "CurrentSale.h"
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
        Management manager;
        FileIO file;
	public:
		SalesInterface();
		~SalesInterface();
		void orderMenu(vector<Categories*>& items,const string& categoryName);
		void categoryMenu(vector<Categories*>& items, const string& categoryName);
		void createItem();
		void mainMenu();
		void managementMenu();
		void checkOut();
		void viewCart();
};

#endif