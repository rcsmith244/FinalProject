#include <iostream>
#include "Categories.h"
#include "Beverages.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>	
#include <vector>
#include <iomanip>
using namespace std;

void mainMenu() {

	cout << "Select a Category (push 1, 2, 3, etc. to select)" << endl;
	cout << "1. Beverages" << endl;
	cout << "0. Quit" << endl;
	cout << endl;
}

void beverageMenu(vector<Categories> items) {

    system("CLS");

	bool quitMenu = false;
	int menuOption;
	ifstream BeveragesFile;
	string line;
	BeveragesFile.open("Inventory.txt");

	while (getline(BeveragesFile, line)) {
		istringstream ss(line);

        string category;
		string itemName;
		int itemID = 0;
		int itemCount = 0;
		double itemPrice = 0;
		ss >> category >> itemName >> itemID >> itemPrice >> itemCount;
        if (category == "Beverages") {
            Beverages beverage(itemName, itemID, itemPrice, itemCount);
            items.push_back(beverage);
        } else {
            Beverages beverage(itemName, itemID, itemPrice, itemCount);
            items.push_back(beverage);
        }

	}
	BeveragesFile.close();

	cout << setw(14) << "Cat Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Name"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count" << endl;
    for (auto& i : items) {
        cout << setw(14) << i.getCatName()
             << setw(14) << i.getItemId()
             << setw(14) << i.getItemName()
             << setw(14) << fixed << setprecision(2) << i.getItemPrice()
             << setw(14) << i.getItemCount() << endl;
    }

	cout << endl;


	while (!quitMenu) {

		cout << "Select a task" << endl;
		cout << "1. Order Beverage" << endl;
		cout << "0. Go Back" << endl;
		cout << endl;

		cin >> menuOption;

		switch (menuOption) {
			case 1:
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


int main() {

	bool quit = false;
	int menuSelect;
	vector<Categories> items;

	while (!quit) {
        system("CLS");
		mainMenu();
		cin >> menuSelect;

		switch (menuSelect) {
			case 1:
				beverageMenu(items);
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