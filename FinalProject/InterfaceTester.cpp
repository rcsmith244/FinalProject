#include <iostream>
#include "Categories.h"
#include "Beverages.h"
#include "Bread.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;

void openFile(string fileName, vector<Categories*> & items) {
    ifstream file;
    string line;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    while (getline(file, line)) {

        // Splits the string using substrings and find
        string category = line.substr(0, ',');

        size_t startLocation = line.find(',') + 1;
        size_t size = line.find(',', startLocation + 1) - startLocation;
        string itemName = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        int itemID = stoi(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        double itemPrice = stod(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        int itemCount = stoi(line.substr(startLocation, size));

        if (category == "Beverages") {
            items.emplace_back(new Beverages(itemName, itemID, itemPrice, itemCount));
        } else if (category == "Bread") {
            items.emplace_back(new Bread(itemName, itemID, itemPrice, itemCount));
        } else {
            items.emplace_back(new Beverages(itemName, itemID, itemPrice, itemCount));
        }

    }
    file.close();
}

void orderMenu(vector<Categories*> & items) {
    cout << setw(16) << "Cat Name"
         << setw(14) << "Item Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count" << endl;

    int count = 1;
    for (auto & i : items) {
            cout << count << ".";
            i->print();
        count++;
    }
    cout << endl;
    cout << "Which item do you want?" << endl;
    // TODO: Add option to go back with 0 key
    int menuOption;
    cin >> menuOption;
    if (menuOption - 1 >= items.size()) {
        cout << "Item not found..." << endl;
    } else {
        int buyCount;
        cout << "How many " << items[menuOption - 1]->getMeasurement()
             << " of " << items[menuOption - 1]->getItemName()
             << " would you like to buy?" << endl;
        cin >> buyCount;
        items[menuOption - 1]->orderItem(buyCount);
    }
}

void categoryMenu(vector<Categories*> items, const string & categoryName) {

    system("CLS");

	bool quitMenu = false;
	int menuOption;

	cout << setw(14) << "Cat Name"
         << setw(14) << "Item Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count" << endl;

    for (auto & i : items) {
        i->print();
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
    string fileNames[11] = {"Beverages", "Bread"};
	vector<Categories*> items[11];
    // TODO: Switch 2 to 11 once all classes are added
    for (int i = 0; i < 2; i++) {
        openFile("Inventory/" + fileNames[i] + ".txt", items[i]);
    }

	while (!quit) {
        system("CLS");
		mainMenu();
		cin >> menuSelect;

		switch (menuSelect) {
			case 1:
				categoryMenu(items[0], "Beverages");
				break;
            case 2:
                categoryMenu(items[1], "Bread");
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