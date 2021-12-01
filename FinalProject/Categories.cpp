#include "Categories.h"
using namespace std;

Categories::Categories(string catName, string measurement) : catName(catName), measurement(measurement) {
}

Categories::Categories() {

}

Categories::~Categories() {}

void Categories::setCatName(string catName) {
	this->catName = catName;
}

string Categories::getCatName() const {
	return catName;
}
int Categories::getThresholdCount() {
	return thresholdCount;
}

int Categories::getReorderAmount() {
	return reorderAmount;
}

int Categories::getItemId() const {
    return itemID;
}

void Categories::setItemId(int itemId) {
    this->itemID = itemId;
}

double Categories::getItemPrice() const {
    return itemPrice;
}

void Categories::setItemPrice(double itemPrice) {
    this->itemPrice = itemPrice;
}

int Categories::getItemCount() const {
    return itemCount;
}

void Categories::setItemCount(int itemCount) {
    this->itemCount = itemCount;
}

bool Categories::getReorderItem() const {
    return reorderItem;
}

void Categories::setReorderItem(bool reorderItem) {
    this->reorderItem = reorderItem;
}

string Categories::getItemName() const {
    return itemName;
}

void Categories::setItemName(string itemName) {
    this->itemName = itemName;
}

void Categories::orderItem(int count) {
    setItemCount(getItemCount() - count);
}

string Categories::getMeasurement() const {
    return measurement;
}
