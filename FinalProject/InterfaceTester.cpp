#include <iostream>
#include "Categories.h"
#include "Beverages.h"
#include "Bread.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
using namespace std;

void openFile(vector<Categories> (& items)[11]) {
    ifstream file;
    string line;
    file.open("Inventory.txt");

    while (getline(file, line)) {
        istringstream ss(line);

        string category;
        string itemName;
        int itemID = 0;
        int itemCount = 0;
        double itemPrice = 0;
        ss >> category >> itemName >> itemID >> itemPrice >> itemCount;
        if (category == "Beverages") {
            Beverages beverage(itemName, itemID, itemPrice, itemCount);
            items[0].push_back(beverage);
        } else if (category == "Bread") {
            Bread bread(itemName, itemID, itemPrice, itemCount);
            items[1].push_back(bread);
        } else {
            Beverages beverage(itemName, itemID, itemPrice, itemCount);
            items[0].push_back(beverage);
        }

    }
    file.close();
}

void orderMenu(vector<Categories> & items) {
    cout << setw(16) << "Cat Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Name"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count" << endl;

    int count = 1;
    for (auto & i : items) {
            cout << count << "."
                 << setw(14) << i.getCatName()
                 << setw(14) << i.getItemId()
                 << setw(14) << i.getItemName()
                 << setw(14) << fixed << setprecision(2) << i.getItemPrice()
                 << setw(14) << i.getItemCount() << endl;
        count++;
    }
    cout << endl;
    cout << "Which item do you want?" << endl;
    // TODO: Add option to go back with 0 key
    int menuOption;
    cin >> menuOption;
    int buyCount;
    cout << "How many " << items[menuOption - 1].getMeasurement()
         << " of " << items[menuOption - 1].getItemName()
         << " would you like to buy?" << endl;
    cin >> buyCount;
    items[menuOption - 1].orderItem(buyCount);
    // TODO: Write to file after order
    // TODO: Call a function in a class to write to order file
}

void categoryMenu(vector<Categories> items, const string & categoryName, int index) {

    system("CLS");

	bool quitMenu = false;
	int menuOption;

	cout << setw(14) << "Cat Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Name"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count" << endl;

    for (auto & i : items) {
        cout << setw(14) << i.getCatName()
             << setw(14) << i.getItemId()
             << setw(14) << i.getItemName()
             << setw(14) << fixed << setprecision(2) << i.getItemPrice()
             << setw(14) << i.getItemCount() << endl;
    }
    cout << endl;

	while (!quitMenu) {

        cout << "Select a task" << endl;
        cout << "1. Order " << categoryName << endl;
        cout << "0. Go Back" << endl;
        cout << endl;

        cin >> menuOption;

        switch (menuOption) {
            case 1:
                orderMenu(items);
                break;
            case 2:
                break;
            case 0:
            default:
                quitMenu = true;
                break;
        }

    }

}

void mainMenu() {

    cout << "Select a Category (push 1, 2, 3, etc. to select)" << endl;
    cout << "1. Beverages" << endl;
    cout << "2. Bread & Bakery" << endl;
    cout << "0. Quit" << endl;
    cout << endl;
}

int main() {

	bool quit = false;
	int menuSelect;
	vector<Categories> items[11];
    openFile(items);

	while (!quit) {
        system("CLS");
		mainMenu();
		cin >> menuSelect;

		switch (menuSelect) {
			case 1:
				categoryMenu(items[0], "Beverages", 0);
				break;
            case 2:
                categoryMenu(items[1], "Bread", 1);
                break;
			case 0:
            default:
                cout << "Thank you for using the Inventory Software";
                quit = true;
                break;
		}

	}

	return 0;
}