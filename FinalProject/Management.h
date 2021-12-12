#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "SalesInterface.h"
#include "SupplierInfo.h"
#include "Sales.h"
#include "Categories/Categories.h"
#include "Orders.h"
#include "BalanceSheet.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

class Management
{

	private:
		vector<SupplierInfo> supInfo;
		vector<Orders> orders;
		vector<BalanceSheet> balanceSheet;

	public:
		Management();
		~Management();
		void restock(vector<Categories*> items);
		void printTotalSalesByDate();
		void paySuppliers();
		void printBalanceSheet(vector<Sales> sales);
		void loadSupplierInfo();
		void printSupplierInfo();
		void writeToOrdersFile(int buyCount, double itemCost, string supplierName, string supplierAddress, string supplierPhoneNumber, string supplierEmail, string itemName);
		string generateID();
		string generateDate();
		void printSupOrders();
};

#endif