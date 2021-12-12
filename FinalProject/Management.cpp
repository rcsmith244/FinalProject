#include "Management.h"

Management::Management() {

    
}
Management::~Management() {}

void Management::printSupOrders() {

    cout << setw(14) << "Order Number"
         << setw(14) << "Sup Name"
         << setw(14) << "Item Cata"
         << setw(14) << "Item Name"
         << setw(14) << "Date of Sale"
         << setw(14) << "Delivery Date"
         << setw(14) << "Total Due" << endl;

    int count = 1;
    for (int i = 0; i < orders.size(); i ++) {
        cout << count << ". ";
        cout << orders[i].getOrderNumber() <<
            setw(21) << orders[i].getSupName() <<
            setw(14) << orders[i].getItemCata() <<
            setw(14) << orders[i].getItemName() <<
            setw(14) << orders[i].getDateOfSale() <<
            setw(14) << orders[i].getDeliveryDate() <<
            setw(14) << "$" << orders[i].getOrderTotal() << endl;
        count++;
    }
    cout << endl;

}

string Management::generateID() {
   
    srand(time(0));
    int randomInt = 0;

    string const legalChars(
        "0123456789");
    string results;
    while (results.size() != 6) {
        randomInt = rand() % 10 + 1;
        results += legalChars[randomInt];
    }
    return results;
}

string Management::generateDate() {

    stringstream date;
   
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;
    
    date << month << "/" << day << "/" << year;

    return date.str();
}

void Management::restock(vector<Categories*> items) {

    cout << setw(14) << "Item Name"
         << setw(14) << "# In Stock"
         << setw(14) << "Reorder?" << endl;
 
    for (auto& i : items) {
        cout << setw(14) << i->getItemName()
             << setw(14) << i->getItemCount();
        if (i->getReorderItem()) {
            cout << setw(14) << "Yes" << endl;
        } else {
            cout << setw(14) << "No" << endl;
        }

    }
    cout << endl;
    printSupplierInfo();

    cout << endl;
    cout << "Which item do you want to restock?" << endl;
    // TODO: Add option to go back with 0 key
    int menuOption;
    cin >> menuOption;
    menuOption = menuOption - 1; //subtract the 1 here so we don't have to do it each time.
    if (menuOption >= items.size()) {
        cout << "Item not found..." << endl;
    }
    else {
        int buyCount;
        cout << "How many " << items[menuOption]->getMeasurement()
            << " of " << items[menuOption]->getItemName()
            << " would you like to buy?" <<  endl;
        cin >> buyCount;

        cout << "You purchased " << buyCount << " " << items[menuOption]->getItemName() << " @ $" << supInfo[menuOption].getItemCost() << endl;

        items[menuOption]->setItemCount(buyCount + items[menuOption]->getItemCount());

        orders.emplace_back(generateID(), supInfo[menuOption].getSupplierName(), supInfo[menuOption].getSupplierAddress(), supInfo[menuOption].getSupplierEmail(), items[menuOption]->getCatName(), items[menuOption]->getItemName(), generateDate(), generateDate(), supInfo[menuOption].getItemCost(), buyCount);

    }
}

void Management::printTotalSalesByDate() {

    fstream file;
    string line;
    string currentDate = "";
    double runningTotal = 0;
    
    file.open("SalesFile.txt", ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    cout << setw(14) << "Date"
         << setw(14) << "Total Sales" << endl;

    while (getline(file, line)) {

        // Splits the string using substrings and find
        string nextDate = line.substr(0, line.find(','));

        if (currentDate.compare("") == 0) {
            currentDate = nextDate;
        } 
        else if (currentDate.compare(nextDate) != 0) {
            cout << setw(14) << currentDate
                 << setw(14) << fixed << setprecision(2) << runningTotal << endl;
            runningTotal = 0;
            currentDate = nextDate;
        }

        size_t startLocation = line.find(',') + 1;
        size_t size = line.find(',', startLocation + 1) - startLocation;
        runningTotal+= stod(line.substr(startLocation, size));

    }

    cout << setw(14) << currentDate
         << setw(14) << fixed << setprecision(2) << runningTotal << endl;

    file.close();

}

void Management::writeToOrdersFile(int buyCount, double itemCost, string supplierName, string supplierAddress, string supplierPhoneNumber, string supplierEmail, string itemName) {

    double orderTotal = buyCount * itemCost;
    time_t now = time(0);
    tm* ltm = localtime(&now);

    fstream file;
    string line;
    file.open("OrdersFile.txt", ios::app);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    file << generateDate() << "," << orderTotal << "," << supplierName << "," << supplierAddress << "," << supplierPhoneNumber << "," << supplierEmail << "," << itemName << "," << itemCost << "," << endl;

    file.close();

}

void Management::paySuppliers() {

    printSupOrders();
    int menuOption;
    double amountToPay;
    double balance;

    cout << "Which supplier would you like to make a payment towards? ";
    cin >> menuOption;
    menuOption = menuOption - 1;

    cout << "Enter an amount to pay towards the balance: ";
    cin >> amountToPay;

    balance = orders[menuOption].getOrderTotal() - amountToPay;
    orders[menuOption].setOrderTotal(balance);
    
}

void Management::printBalanceSheet(vector<Sales>& sales) {

    string currentDate = "";
    string nextDate = orders.empty() ? "" : orders[0].getDateOfSale();
    double totalDebt = 0;
    double totalSales = 0;

    try {
        for (auto &order: orders) {  //IF NO ORDERS ARE IN PLACE IT WILL CRASH NEED ERROR CHECKING.
            if (currentDate.compare("") == 0) {
                currentDate = nextDate;
            } else if (currentDate.compare(nextDate) != 0) {
                cout << currentDate << " $" << totalDebt << endl;
            }
            totalDebt = totalDebt + order.getOrderTotal();
        }

        cout << "Date" << "     Total Debt" << endl;
        cout << currentDate << " " << totalDebt << endl;

        currentDate = "";
        nextDate = sales.empty() ? "" : sales[0].getSalesDate();

        for (int i = 0; i < sales.size(); i++) {  //IF NO Sales ARE IN PLACE IT WILL CRASH NEED ERROR CHECKING.
            if (currentDate.compare("") == 0) {
                currentDate = nextDate;
            } else if (currentDate.compare(nextDate) != 0) {
                cout << currentDate << " $" << totalSales << endl;
            }
            totalSales = totalSales + orders[i].getOrderTotal();
        }

        cout << "Date" << "     Total Sales" << endl;
        cout << currentDate << " " << totalSales << endl;
    }
    catch (exception& e) {
        cout << "Hi" << endl;
    }

    system("pause");

}

void Management::loadSupplierInfo() {

    ifstream file;
    string line;
    file.open("SupplierInfo.txt", ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    while (getline(file, line)) {

        // Splits the string using substrings and find
        int pos = line.find(',');

        string supplierName = line.substr(0, pos);

        size_t startLocation = line.find(',') + 1;
        size_t size = line.find(',', startLocation + 1) - startLocation;
        string address = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string phoneNum = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string emailAddress = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string itemName = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        double itemCost = stod(line.substr(startLocation, size));
        
        supInfo.emplace_back(supplierName, address, phoneNum, emailAddress, itemName, itemCost);

    }
    file.close();

}

void Management::printSupplierInfo() {

    cout << setw(22) << "Company Name"
         << setw(18) << "Phone Number"
         << setw(30) << "E-mail Address"
         << setw(18) << "Item Name"
         << setw(18) << "Item Cost" << endl;

    int count = 1;
    for (int i = 0; i < supInfo.size(); i++) {
        cout << count << "."
             << setw(20) << supInfo[i].getSupplierName()
             << setw(18) << supInfo[i].getSupplierPhoneNumber()
             << setw(30) << supInfo[i].getSupplierEmail()
             << setw(18) << supInfo[i].getItemName()
             << setw(18) << supInfo[i].getItemCost() << endl;
        count++;
    }
    cout << endl;

}