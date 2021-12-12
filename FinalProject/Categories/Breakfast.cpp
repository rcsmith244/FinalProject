#include "Breakfast.h"
#include "Categories.h"

Breakfast::Breakfast(string itemName, int itemID, double itemPrice, int itemCount, string measurement) : Categories() {
    setItemName(itemName);
    setCatName(catName);
    setItemId(itemID);
    setItemPrice(itemPrice);
    setItemCount(itemCount);
    setMeasurement(measurement);
}
Breakfast::Breakfast() {

}

Breakfast::~Breakfast() {}

void Breakfast::print() {
    cout << setw(14) << getCatName()
         << setw(14) << getItemName()
         << setw(14) << getItemId()
         << setw(14) << fixed << setprecision(2) << getItemPrice()
         << setw(14) << getItemCount()
         << setw(14) << getMeasurement() << endl;
}