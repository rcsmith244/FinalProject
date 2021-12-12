#include "CurrentSale.h"

CurrentSale::CurrentSale(string itemName, string itemCat, double itemPrice, int amount) {

	setItemName(itemName);
	setItemPrice(itemPrice);
	setAmount(amount);
	setItemCat(itemCat);

}
CurrentSale::~CurrentSale() {

}
string CurrentSale::getItemName() {
	return itemName;
}
double CurrentSale::getItemPrice() {
	return itemPrice;
}
int CurrentSale::getAmount() {
	return amount;
}
string CurrentSale::getItemCat() {
	return itemCat;
}
void CurrentSale::setItemName(string itemName) {
	this->itemName = itemName;
}
void CurrentSale::setItemCat(string itemCat) {
	this->itemCat = itemCat;
}
void CurrentSale::setItemPrice(double itemPrice) {
	this->itemPrice = itemPrice;
}
void CurrentSale::setAmount(int amount) {
	this->amount = amount;
}
