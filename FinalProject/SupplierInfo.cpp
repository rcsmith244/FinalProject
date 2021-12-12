#include <string>
using namespace std;
#include "SupplierInfo.h"

SupplierInfo::SupplierInfo(string supplierName, string supplierAddress, string supplierPhoneNumber, string supplierEmail, string itemName, double itemCost) {

	setItemCost(itemCost);
	setitemName(itemName);
	setSupplierName(supplierName);
	setSupplierAddress(supplierAddress);
	setSupplierPhoneNumber(supplierPhoneNumber);
	setSupplierEmail(supplierEmail);

}
SupplierInfo::SupplierInfo() {}

SupplierInfo::~SupplierInfo() {}

double SupplierInfo::getItemCost() {
	return itemCost;
}
string SupplierInfo::getItemName() {
	return itemName;
}
string SupplierInfo::getSupplierName() {
	return supplierName;
}
string SupplierInfo::getSupplierAddress() {
	return supplierAddress;
}
string SupplierInfo::getSupplierPhoneNumber() {
	return supplierPhoneNumber;
}
string SupplierInfo::getSupplierEmail() {
	return supplierEmail;
}
void SupplierInfo::setItemCost(double itemCost) {
	this->itemCost = itemCost;
}
void SupplierInfo::setitemName(string itemName) {
	this->itemName = itemName;
}
void SupplierInfo::setSupplierName(string supplierName) {
	this->supplierName = supplierName;
}
void SupplierInfo::setSupplierAddress(string supplierAdddress) {
	this->supplierAddress = supplierAddress;
}
void SupplierInfo::setSupplierPhoneNumber(string supplierPhoneNumber) {
	this->supplierPhoneNumber = supplierPhoneNumber;
}
void SupplierInfo::setSupplierEmail(string supplierEmail) {
	this->supplierEmail = supplierEmail;
}
