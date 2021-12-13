#ifndef FINALPROJECT_FILEIO_H
#define FINALPROJECT_FILEIO_H

#include "Categories/Categories.h"
#include "Categories/Beverages.h"
#include "Categories/Bread.h"
#include "Categories/Breakfast.h"
#include "Categories/Snacks.h"
#include "Categories/Dairy.h"
#include "Categories/Produce.h"
#include "Categories/Grains.h"
#include "Categories/Meats.h"
#include "Categories/Misc.h"
#include "Categories/Paper.h"
#include "Categories/PetCare.h"
#include "Categories/Pharmacy.h"
#include "Sales.h"
#include "Orders.h"
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#pragma warning(disable : 4996)
using namespace std;

class FileIO {
public:
    void readFile(const string& fileName, vector<Categories*> & items);
    void writeFile(const string& fileName, vector<Categories*> & items);
    void writeToSalesFile(Sales sales);
    void readSalesFile(vector<Sales>& sales);
    void writeToOrdersFile(string orderNumber, string supName, string supAddress, string supEmail, string itemCata, string itemName, string dateOfSale, string deliveryDate, double costOfItem, int quantity);
    void readOrdersFile(vector<Orders>& orders);
};


#endif //FINALPROJECT_FILEIO_H
