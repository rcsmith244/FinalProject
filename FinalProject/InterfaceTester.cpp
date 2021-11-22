#include <iostream>
#include "Categories.h"
#include "Beverages.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>	
#include <vector>
using namespace std;

void mainMenu() {

	cout << "Select a Category (push 1, 2, 3, etc. to select)" << endl;
	cout << "1. Beverages" << endl;
	cout << "Push 0 to quit" << endl;
	cout << endl;
}

void beverageMenu(vector<Beverages> beverages) {

	system("CLS");

	bool quitMenu = false;
	int menuOption;
	ifstream BeveragesFile;
	string line;
	BeveragesFile.open("Beverages.txt");

	while (getline(BeveragesFile, line)) {
		istringstream ss(line);

		string itemName = ""; 
		int itemID = 0; 
		int itemCount = 0;
		double itemPrice = 0;
		ss >> itemName >> itemID >> itemPrice >> itemCount;
		Beverages bClass(itemName, itemID, itemPrice, itemCount);
		beverages.push_back(bClass);

	}
	BeveragesFile.close();

	cout << "Cat Name \t Item ID \t Item Name \t Item Price \t Item Count" << endl;
	cout << beverages[0].getCatName() << '\t' << beverages[0].getItemID() << '\t' << beverages[0].getItemName() << '\t' << beverages[0].getItemPrice() << '\t' << beverages[0].getItemCount() << endl;
	cout << endl;


	while (quitMenu == false) {

		cout << "Select a task" << endl;
		cout << "1. Order Beverage" << endl;
		cout << "Push 0 to quit" << endl;
		cout << endl;

		cin >> menuOption;

		switch (menuOption) {
			case 1:
				break;
			case 2:
				break;
			case 0:
				quitMenu = true;
				break;
		}

	}
	

}


int main() {

	bool quit = false;
	int menuSelect;
	vector<Beverages> beverages;

	while (quit == false) {
		system("CLS");
		mainMenu();
		cin >> menuSelect;

		switch (menuSelect) {
			case 1:
				beverageMenu(beverages);
				break;
			case 0:
				cout << "Thank you for using the Inventory Software";
				quit = true;
				break;
		}


	}

	return 0;
}