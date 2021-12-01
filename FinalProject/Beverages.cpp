#include "Beverages.h"
#include "Categories.h"
#include <string>
using namespace std;

Beverages::Beverages(string itemName, int itemID, double itemPrice, int itemCount) : Categories("Beverages", "ct") {
	setItemName(itemName);
	setItemId(itemID);
	setItemPrice(itemPrice);
	setItemCount(itemCount);
}
Beverages::Beverages() {

}

Beverages::~Beverages() {}

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