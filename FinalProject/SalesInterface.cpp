#include "SalesInterface.h"

SalesInterface::SalesInterface() {

    bool quit = false;
    int menuSelect;
    FileIO file;
    // TODO: Switch 2 to 11 once all classes are added
    for (int i = 0; i < 12; i++) {
        file.writeFile("Inventory/" + fileNames[i] + ".txt", items[i]);
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
            case 13:
                createItem();
                break;
            case 14:
                viewCart();
                break;
            case 15:

                break;
            case 16:
                managementMenu(*items);
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

void SalesInterface::writeToSalesFile(string name, string phoneNumber, string itemName, int buyCount, double itemPrice) {

    double salesTotal = buyCount * itemPrice;
    time_t now = time(0);
    tm* ltm = localtime(&now);

    fstream file;
    string line;
    file.open("SalesFile.txt", ios::app);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    file << ltm->tm_mon + 1 << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << "," << salesTotal << "," << name << "," << phoneNumber << "," << itemName << "," << buyCount << "," << itemPrice << "," << endl;

    file.close();

}

void SalesInterface::orderMenu(vector<Categories*>& items, const string& categoryName) {

    cout << setw(16) << "Cat Name"
        << setw(14) << "Item Name"
        << setw(14) << "Item ID"
        << setw(14) << "Item Price"
        << setw(14) << "Item Count" << endl;

    int count = 1;
    for (auto& i : items) {
        cout << count << ".";
        i->print();
        count++;
    }
    cout << endl;
    cout << "Which item do you want?" << endl;
    // TODO: Add option to go back with 0 key
    int menuOption;
    cin >> menuOption;
    menuOption = menuOption - 1;
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

        currentSale.emplace_back(items[menuOption]->getItemName(), categoryName, items[menuOption]->getItemPrice(), buyCount);
    }
}



void SalesInterface::categoryMenu(vector<Categories*> items, const string& categoryName) {

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
            orderMenu(items, categoryName);
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

void SalesInterface::managementMenu(vector<Categories*> items) {

    int menuSelect;
    Management* ptr;
    ptr = new Management();
    ptr->loadSupplierInfo();

    system("CLS");

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
            ptr->restock(items);
            cout << endl;
            break;
        case 2:
            system("CLS");
            ptr->printTotalSalesByDate();
            break;
        case 3:
            system("CLS");
            ptr->printBalanceSheet(sales);
            break;
        case 4:
            system("CLS");
            ptr->paySuppliers();
            break;
        case 5:
            system("CLS");
            ptr->printSupOrders();
        case 0:
            break;
        }
    } while (menuSelect != 0);
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
    cout << endl << "Your order total is: $" << subTotal;

    cin.ignore();
    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Please enter your phone number: ";
    getline(cin, phoneNumber);

    cout << "Do you wish to complete your purchase? (1 = Yes, 2 = No) ";
    if (completePurchase == 1) {
        for (int i = 0; i < currentSale.size(); i++) {
            sales.emplace_back(name, phoneNumber, currentSale[i].getItemCat(), currentSale[i].getItemName(), currentSale[i].getAmount(), currentSale[i].getItemPrice());
            writeToSalesFile(name, phoneNumber, currentSale[i].getItemName(), currentSale[i].getAmount(), currentSale[i].getItemPrice());

        }
    }

    do {
        cout << endl << "Please enter the dollar amount to pay: $" << "you owe $" << subTotal << endl;
        cin >> amountToPay;
        subTotal = subTotal - amountToPay;
    } while (subTotal > 0);

    cout << "Thank you for your purchaase!" << endl;
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

    cout << endl << "Your order total is: $" << subTotal;

    system("Pause");
}
