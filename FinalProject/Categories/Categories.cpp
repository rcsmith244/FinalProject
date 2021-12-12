#include "Categories.h"
using namespace std;

Categories::Categories() {

}

Categories::~Categories() {}

void Categories::setCatName(string category) {
	this->catName = category;
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
    if (count <= getItemCount() && count > 0) {
        setItemCount(getItemCount() - count);
    } else {
        cout << "Not enough " << getItemName() << " to fulfill your order." << endl;
    }
}

string Categories::getMeasurement() const {
    return measurement;
}

void Categories::setMeasurement(string measurement) {
    this->measurement = measurement;
}

void Categories::print() {
    cout << "Printing from base class..." << endl;
}
