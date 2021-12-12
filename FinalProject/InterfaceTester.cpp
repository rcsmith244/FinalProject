#include <iostream>
#include "Categories/Categories.h"
#include "FileIO.h"
#include <vector>
#include <iomanip>
using namespace std;

void orderMenu(vector<Categories*> & items) {
    cout << setw(16) << "Cat Name"
         << setw(14) << "Item Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count"
         << setw(14) << "Item Measure" << endl;

    int count = 1;
    for (auto & i : items) {
            cout << count << ".";
            i->print();
        count++;
    }
    cout << endl;
    cout << "Which item do you want? (0 to go back)" << endl;
    int menuOption;
    cin >> menuOption;
    menuOption -= 1;
    if (menuOption >= items.size()) {
        cout << "Item not found..." << endl;
    } else if (menuOption == 0) {
        cout << "Going back..." << endl;
    } else {
        int buyCount;
        cout << "How many " << items[menuOption]->getMeasurement()
        << " of " << items[menuOption]->getItemName()
        << " would you like to buy?" << endl;
        cin >> buyCount;
        items[menuOption]->orderItem(buyCount);
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
         << setw(14) << "Item Count"
         << setw(14) << "Item Measure" << endl;

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
    cout << "3. Breakfast" << endl;
    cout << "4. Snacks" << endl;
    cout << "5. Dairy" << endl;
    cout << "6. Produce" << endl;
    cout << "7. Grains" << endl;
    cout << "8. Meats" << endl;
    cout << "9. Miscellaneous" << endl;
    cout << "10. Paper" << endl;
    cout << "11. Pet Care" << endl;
    cout << "12. Pharmacy" << endl;
    cout << "0. Quit" << endl;
    cout << endl;
}

int main() {

	bool quit = false;
	int menuSelect;
    string fileNames[12] = {"Beverages", "Bread", "Breakfast", "Snacks", "Dairy", "Produce",
                            "Grains", "Meats", "Misc", "Paper", "PetCare", "Pharmacy"};
	vector<Categories*> items[12];
    // TODO: Switch 2 to 11 once all classes are added
    FileIO file;
    for (int i = 0; i < 12; i++) {
        file.readFile("Inventory/" + fileNames[i] + ".txt", items[i]);
    }

	while (!quit) {
        system("CLS");
		mainMenu();
		cin >> menuSelect;

        switch (menuSelect) {
			case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                categoryMenu(items[menuSelect - 1], fileNames[menuSelect - 1]);
                break;
			case 0:
            default:
                cout << "Thank you for using the Inventory Software" << endl;
                for (int i = 0; i < 12; i++) {
                    file.writeFile("Inventory/" + fileNames[i] + ".txt", items[i]);
                }
                cout << "Files written on exit" << endl;
                quit = true;
                break;
		}

	}

	return 0;
}