#include <string>
#include "Orders.h"

Orders::Orders(string orderNumber, string supName, string supAddress, string supEmail, string itemCata, string itemName, string dateOfSale, string deliveryDate, double costOfItem, int quantity) {

	setOrderNumber(orderNumber);
	setDateOfSale(dateOfSale);
	setDeliveryDate(deliveryDate);
	setCostOfItem(costOfItem);
	setItemCata(itemCata);
	setItemName(itemName);
	setSupAddress(supAddress);
	setSupEmail(supEmail);
	setSupName(supName);
	setQuantity(quantity);

	orderTotal = getQuantity() * getCostOfItem();

}

Orders::Orders() {}

Orders::~Orders() {}

void Orders::setOrderNumber(string orderNumber) {
	this->orderNumber = orderNumber;
}
void Orders::setDateOfSale(string dateOfSale) {
	this->dateOfSale = dateOfSale;
}
void Orders::setDeliveryDate(string deliveryDate) {
	this->deliveryDate = deliveryDate;
}
void Orders::setCostOfItem(double costOfItem) {
	this->costOfItem = costOfItem;
}
string Orders::getOrderNumber() {
	return orderNumber;
}
string Orders::getDateOfSale() {
	return dateOfSale;
}
string Orders::getDeliveryDate() {
	return deliveryDate;
}
string Orders::getDeliveryDes() {
	return deliveryDate;
}
double Orders::getCostOfItem() {
	return costOfItem;
}

void Orders::setItemCata(string itemCata) {
	this->itemCata = itemCata;
}

void Orders::setItemName(string itemName) {
	this->itemName = itemName;
}

string Orders::getItemCata() {
	return itemCata;
}
string Orders::getItemName() {
	return itemName;
}

void Orders::setSupAddress(string supAddress) {
	this->supAddress = supAddress;
}
void Orders::setSupEmail(string supEmail) {
	this->supEmail = supEmail;
}
void Orders::setSupName(string supName) {
	this->supName = supName;
}

string Orders::getSupAddress() {
	return supAddress;
}
string Orders::getSupEmail() {
	return supEmail;
}
string Orders::getSupName() {
	return supName;
}
double Orders::getOrderTotal() {
	return orderTotal;
}

void Orders::setOrderTotal(double orderTotal) {
	this->orderTotal = orderTotal;
}

int Orders::getQuantity() {
	return quantity;
}

void Orders::setQuantity(int quantity){
	this->quantity = quantity;
}