#include <string>
#include <sstream>
#include "Sales.h"
using namespace std;
#pragma warning(disable : 4996)


Sales::Sales(string custName, string custPhone, string itemCata, string itemName, int itemCount, double itemPrice) {

	setCustName(custName);
	setCustPhone(custPhone);
	setItemCata(itemCata);
	setItemName(itemName);
	setItemCount(itemCount);
	setItemPrice(itemPrice);
	salesDate = generateDate();
	salesTotal = itemPrice * itemCount;

}
//Overloaded constructor for custom items.
Sales::Sales(string itemName, double itemPrice, int itemCount) {

	setItemName(itemName);
	setItemPrice(itemPrice);
	setItemCount(itemCount);
	salesDate = generateDate();
	salesTotal = itemPrice * itemCount;

}

Sales::Sales(string date, double salesTotal, string custName, string custPhone, string itemName, int itemCount, double itemPrice) {

    setCustName(custName);
    setCustPhone(custPhone);
    setItemCata(itemCata);
    setItemName(itemName);
    setItemCount(itemCount);
    setItemPrice(itemPrice);
    this->salesDate = date;
    this->salesTotal = salesTotal;

}

Sales::Sales() {}

Sales::~Sales() {}

double Sales::getSalesTotal() {
	return salesTotal;
}

string Sales::getItemCata() {
	return itemCata;
}
string Sales::getCustName() {
	return custName;
}
string Sales::getCustPhone() {
	return custPhone;
}
string Sales::getItemName() {
	return itemName;
}
string Sales::getSalesDate() {
	return salesDate;
}
int Sales::getItemCount() {
	return itemCount;
}
double Sales::getItemPrice() {
	return itemPrice;
}
void Sales::setCustName(string custName) {
	this->custName = custName;
}
void Sales::setCustPhone(string custPhone) {
	this->custPhone = custPhone;
}
void Sales::setItemCata(string itemCata) {
	this->itemCata = itemCata;
}
void Sales::setItemName(string itemName) {
	this->itemName = itemName;
}
void Sales::setItemCount(int itemCount) {
	this->itemCount = itemCount;
}
void Sales::setItemPrice(double itemPrice) {
	this->itemPrice = itemPrice;
}
string Sales::generateDate() {
		
		stringstream date;

		time_t now = time(0);
		tm* ltm = localtime(&now);

		int month = ltm->tm_mon + 1;
		int day = ltm->tm_mday;
		int year = 1900 + ltm->tm_year;

		date << month << "/" << day << "/" << year;

		return date.str();
	
}