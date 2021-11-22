#include "Categories.h"
using namespace std;

Categories::Categories(string catName) {
	setCatName(catName);
}

Categories::Categories() {

}

Categories::~Categories() {}

void Categories::setCatName(string catName) {
	this->catName = catName;
}

string Categories::getCatName() {
	return catName;
}
int Categories::getThresholdCount() {
	return thresholdCount;
}

int Categories::getReorderAmount() {
	return reorderAmount;
}