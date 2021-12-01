#include "Bread.h"
#include "Categories.h"
#include <string>
using namespace std;

Bread::Bread(string itemName, int itemID, double itemPrice, int itemCount) : Categories("Bread", "ct") {
    setItemName(itemName);
    setItemId(itemID);
    setItemPrice(itemPrice);
    setItemCount(itemCount);
}
Bread::Bread() {

}

Bread::~Bread() {}