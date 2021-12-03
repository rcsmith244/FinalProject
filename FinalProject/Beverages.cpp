#include "Beverages.h"
#include "Categories.h"

Beverages::Beverages(string itemName, int itemID, double itemPrice, int itemCount) : Categories("Beverages", "ct") {
	setItemName(itemName);
	setItemId(itemID);
	setItemPrice(itemPrice);
	setItemCount(itemCount);
}
Beverages::Beverages() {

}

Beverages::~Beverages() {}

void Beverages::print() {
    cout << setw(14) << getCatName()
         << setw(14) << getItemName()
         << setw(14) << getItemId()
         << setw(14) << fixed << setprecision(2) << getItemPrice()
         << setw(14) << getItemCount() << endl;
}

//string Beverages::getItemName() {
//	return itemName;
//}

//int Beverages::getItemID() {
//	return itemID;
//}

//int Beverages::getItemCount() {
//	return itemCount;
//}
//double Beverages::getItemPrice() {
//	return itemPrice;
//}
//void Beverages::setItemName(string itemName) {
//	this->itemName = itemName;
//}
//void Beverages::setItemID(int itemID) {
//	this->itemID = itemID;
//}
//void Beverages::setItemPrice(double itemPrice) {
//	this->itemPrice = itemPrice;
//}
//void Beverages::setItemCount(int itemCount) {
//	this->itemCount = itemCount;
//}