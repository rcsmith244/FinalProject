#include "Beverages.h"
#include "Categories.h"

Beverages::Beverages(string itemName, int itemID, double itemPrice, int itemCount, string measurement) : Categories() {
	setItemName(itemName);
    setCatName(catName);
	setItemId(itemID);
	setItemPrice(itemPrice);
	setItemCount(itemCount);
    setMeasurement(measurement);
}
Beverages::Beverages() {

}

Beverages::~Beverages() {}

void Beverages::print() {
    cout << setw(14) << getCatName()
         << setw(14) << getItemName()
         << setw(14) << getItemId()
         << setw(14) << fixed << setprecision(2) << getItemPrice()
         << setw(14) << getItemCount()
         << setw(14) << getMeasurement() << endl;
}