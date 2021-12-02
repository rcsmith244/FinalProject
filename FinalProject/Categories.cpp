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
    if (count <= getItemCount()) {
        setItemCount(getItemCount() - count);
    } else {
        cout << "Not enough items" << endl;
    }
}

string Categories::getMeasurement() const {
    return measurement;
}

void Categories::print() {
    cout << setw(14) << getCatName()
         << setw(14) << getItemName()
         << setw(14) << getItemId()
         << setw(14) << fixed << setprecision(2) << getItemPrice()
         << setw(14) << getItemCount() << endl;

}
