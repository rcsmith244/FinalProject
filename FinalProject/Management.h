#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "SupplierInfo.h"
#include "Sales.h"
#include "Categories/Categories.h"
#include "Orders.h"
#include "BalanceSheet.h"
#include "FileIO.h"

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
        FileIO file;

	public:
		Management();
		~Management();
		void restock(vector<Categories*> items[12]);
		void printTotalSalesByDate(vector<Sales>& sales);
		void paySuppliers();
		void printBalanceSheet(vector<Sales>& sales);
		void loadSupplierInfo();
		void printSupplierInfo();
		string generateID();
		string generateDate();
		void printSupOrders();
};

#endif