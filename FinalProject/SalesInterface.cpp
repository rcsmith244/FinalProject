#include "SalesInterface.h"

SalesInterface::SalesInterface() {

    bool quit = false;
    int menuSelect;
    // Loops to pull in all data from the category files into the items array of vectors
    for (int i = 0; i < 12; i++) {
        file.readFile("Inventory/" + fileNames[i] + ".txt", items[i]);
    }
    // Populates a sales vector using the sales file
    file.readSalesFile(sales);

    while (!quit) {
        system("CLS");
        // Displays the main menu
        mainMenu();
        cin >> menuSelect;

        // Menu to select which category to buy from or other ordering/managerial options
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
            case 13:
                createItem();
                break;
            case 14:
                checkOut();
                break;
            case 15:
                viewCart();
                break;
            case 16:
                currentSale.clear();
                break;
            case 17:
                managementMenu();
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

}
SalesInterface::~SalesInterface() {

}

void SalesInterface::orderMenu(vector<Categories*>& items, const string& categoryName) {

    cout << setw(16) << "Cat Name"
         << setw(14) << "Item Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count"
         << setw(14) << "Item Measure" << endl;

    // Prints out each item in the category
    int count = 1;
    for (auto& i : items) {
        cout << count << ".";
        i->print();
        count++;
    }
    cout << endl;
    cout << "Which item do you want?" << endl;
    int menuOption;
    cin >> menuOption;
    menuOption = menuOption - 1;
    // Error checking for out of bounds inputs
    if (menuOption > items.size() || menuOption < -1) {
        cout << "Item not found..." << endl;
    } else if (menuOption + 1 == 0) {
        cout << "Going back..." << endl;
    } else {
        // If the input is valid, it asks for order info
        int buyCount;
        cout << "How many " << items[menuOption]->getMeasurement()
            << " of " << items[menuOption]->getItemName()
            << " would you like to buy?" << endl;
        cin >> buyCount;

        // "Orders" the item by removing the amount out of the inventory
        items[menuOption]->orderItem(buyCount);

        // Adds the sale to the current "shopping cart"
        currentSale.emplace_back(items[menuOption]->getItemName(), categoryName, items[menuOption]->getItemPrice(), buyCount);
    }
}



void SalesInterface::categoryMenu(vector<Categories*>& items, const string& categoryName) {

    system("CLS");

    bool quitMenu = false;
    int menuOption;

    // Menu Options for displaying what's in each category
    cout << setw(14) << "Cat Name"
         << setw(14) << "Item Name"
         << setw(14) << "Item ID"
         << setw(14) << "Item Price"
         << setw(14) << "Item Count"
         << setw(14) << "Item Measure" << endl;

    // Prints each item in the category
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

        // Opens up the ordering menu for the category or just closes it
        switch (menuOption) {
        case 1:
            orderMenu(items, categoryName);
            break;
        case 0:
        default:
            cout << "Going back..." << endl;
            quitMenu = true;
            break;
        }

    }

}

void SalesInterface::createItem() {

    system("CLS");
    string newItemName;
    string name;
    string phoneNumber;
    string itemCata = "Custom";
    double price;
    int amount;

    cout << "Enter the name of the item you which to purchase: ";
    cin >> newItemName;

    cout << endl << "Enter the price of the item: ";
    cin >> price;

    cout << endl << "How many " << newItemName << " would you like to purchase ? ";
    cin >> amount;

    cout << newItemName << "Has been added to your cart" << endl;

    currentSale.emplace_back(newItemName, itemCata, price, amount);

    system("pause");

}

void SalesInterface::mainMenu() {

    // Displays all options for ordering items or opening the management submenu
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
    cout << "13. Create a new item." << endl;
    cout << "14. Check Out / Complete Sale" << endl;
    cout << "15. View Cart" << endl;
    cout << "16. Clear Cart" << endl;
    cout << "17. Management Menu" << endl;
    cout << "0. Quit" << endl;
    cout << endl;
}

void SalesInterface::managementMenu() {

    int menuSelect;

    system("CLS");
    bool exit = false;

    do {

        cout << "Select a management option (push 1, 2, 3, etc. to select)" << endl;
        cout << "1. View Current Inventory Status / Order Items" << endl;
        cout << "2. Print Total Sales by Date" << endl;
        cout << "3. Print Balance Sheet" << endl;
        cout << "4. Pay Debts to Suppliers" << endl;
        cout << "5. View current orders" << endl;
        cout << "0. Return to previous menu" << endl;
        cout << endl;

        cin >> menuSelect;

        switch (menuSelect) {
        case 1:
            system("CLS");
            manager.restock(items);
            cout << endl;
            break;
        case 2:
            system("CLS");
            manager.printTotalSalesByDate(sales);
            break;
        case 3:
            system("CLS");
            manager.printBalanceSheet(sales);
            break;
        case 4:
            system("CLS");
            manager.paySuppliers();
            break;
        case 5:
            system("CLS");
            manager.printSupOrders();
        case 0:
        default:
            exit = true;
            break;
        }
    } while (!exit);
}

void SalesInterface::checkOut() {

    system("CLS");

    string name = "";
    string phoneNumber = "";
    double subTotal = 0;
    int completePurchase = 0;
    double amountToPay = 0;

    cout << "Items in Cart" << endl;
    cout << "Item Name - Price - Amount to Purchase" << endl;
    int count = 1;
    for (int i = 0; i < currentSale.size(); i++) {
        cout << count << ". " << currentSale[i].getItemName() << " " << currentSale[i].getAmount() << " " << currentSale[i].getItemPrice() << endl;
        count++;
        subTotal = subTotal + (currentSale[i].getItemPrice() * currentSale[i].getAmount());
    }
    cout << endl << "Your order total is: $" << subTotal << endl;

    cin.ignore();
    cout << "Please enter your name: ";
    // TODO: Check for numbers: only letters
    getline(cin, name);

    cout << "Please enter your phone number: ";
    getline(cin, phoneNumber);

    cout << "Do you wish to complete your purchase? (1 = Yes, 2 = No) ";
    cin >> completePurchase;
    if (completePurchase == 1) {
        for (int i = 0; i < currentSale.size(); i++) {
            sales.emplace_back(name, phoneNumber, currentSale[i].getItemCat(), currentSale[i].getItemName(), currentSale[i].getAmount(), currentSale[i].getItemPrice());
            file.writeToSalesFile(sales[i]);

        }
        currentSale.clear();
    }

    do {
        cout << endl << "Please enter the dollar amount to pay: $" << "you owe $" << subTotal << endl;
        cin >> amountToPay;
        subTotal = subTotal - amountToPay;
    } while (subTotal > 0);

    cout << "Thank you for your purchase!" << endl;
    system("pause");

}

void SalesInterface::viewCart() {

    system("CLS");
    double subTotal = 0;
    int count = 1;

    cout << "Items in Cart" << endl;
    cout << "Item Name - Price - Amount to Purchase" << endl;

    for (int i = 0; i < currentSale.size(); i++) {
        cout << count << ". " << currentSale[i].getItemName() << " " << currentSale[i].getAmount() << " " << currentSale[i].getItemPrice() << endl;
        count++;
        subTotal = subTotal + (currentSale[i].getItemPrice() * currentSale[i].getAmount());
    }

    cout << endl << "Your order total is: $" << subTotal << endl;

    system("Pause");
}
