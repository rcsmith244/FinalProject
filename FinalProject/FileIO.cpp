#include "FileIO.h"

void FileIO::readFile(const string& fileName, vector<Categories *> &items) {
    ifstream file;
    string line;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    while (getline(file, line)) {

        // Splits the string using substrings and find
        string category = line.substr(0, line.find(',', 0));

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

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string measure = line.substr(startLocation, size);

        // TODO: Better try catches everywhere!! :D
        try {
            if (category == "Beverages") {
                items.emplace_back(new Beverages(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Bread") {
                items.emplace_back(new Bread(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Breakfast") {
                items.emplace_back(new Breakfast(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Snacks") {
                items.emplace_back(new Snacks(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Dairy") {
                items.emplace_back(new Dairy(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Produce") {
                items.emplace_back(new Produce(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Grains") {
                items.emplace_back(new Grains(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Meats") {
                items.emplace_back(new Meats(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Misc") {
                items.emplace_back(new Misc(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Paper") {
                items.emplace_back(new Paper(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "PetCare") {
                items.emplace_back(new PetCare(itemName, itemID, itemPrice, itemCount, measure));
            } else if (category == "Pharmacy") {
                items.emplace_back(new Pharmacy(itemName, itemID, itemPrice, itemCount, measure));
            } else {
                throw (runtime_error(category));
            }
        }
            // TODO: HMMM...
        catch (runtime_error& x) {
            cout << "Category not found." << endl;
        }

    }
    file.close();
}

void FileIO::writeFile(const string& fileName, vector<Categories *> &items) {
    ofstream file;
    file.open(fileName, ios::out);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }
    try {
        for (auto & i : items) {
            file << i->getCatName() << "," << i->getItemName() << "," << to_string(i->getItemId()) << ","
                 << fixed << setprecision(2) << i->getItemPrice() << "," << i->getItemCount() << ","
                 << i->getMeasurement() << "," << endl;
        }
    }
    catch (exception & e) {
        cout << "Failure in writing to files." << endl;
    }
    file.close();
}



void FileIO::writeToSalesFile(Sales sales) {

    double salesTotal = sales.getItemCount() * sales.getItemPrice();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    fstream file;
    string line;
    file.open("SalesFile.txt", ios::app);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    file << ltm->tm_mon + 1 << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << "," << salesTotal << ","
         << sales.getCustName() << "," << sales.getCustPhone() << "," << sales.getItemName() << ","
         << sales.getItemCount() << "," << sales.getItemPrice() << "," << endl;

    file.close();

}

void FileIO::readSalesFile(vector<Sales> &sales) {
    ifstream file;
    string line;
    file.open("SalesFile.txt", ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    while (getline(file, line)) {

        // Splits the string using substrings and find
        string date = line.substr(0, line.find(',', 0));

        size_t startLocation = line.find(',') + 1;
        size_t size = line.find(',', startLocation + 1) - startLocation;
        double salesTotal = stod(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string name = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string phoneNo = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string itemName = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        int itemCount = stoi(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        double itemPrice = stod(line.substr(startLocation, size));

        sales.emplace_back(date, salesTotal, name, phoneNo, itemName, itemCount, itemPrice);
    }
}

void FileIO::writeToOrdersFile(string orderNumber, string supName, string supAddress, string supEmail, string itemCata, string itemName, string dateOfSale, string deliveryDate, double costOfItem, int quantity) {

    double orderTotal = quantity * costOfItem;

    fstream file;
    string line;
    file.open("OrdersFile.txt", ios::app);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    file << dateOfSale << orderTotal << orderNumber << "," << supName << "," << supAddress << "," << supEmail << "," << itemCata << "," << itemName << "," << deliveryDate << "," << costOfItem << "," << quantity << "," << endl;

    file.close();

}

void FileIO::readOrdersFile(vector<Orders>& orders) {
    ifstream file;
    string line;
    file.open("OrdersFile.txt", ios::in);
    if (!file.is_open()) {
        cout << "File cannot be opened" << endl;
        assert(false);
    }

    while (getline(file, line)) {

        // Splits the string using substrings and find
        string dateOfSale = line.substr(0, line.find(',', 0));

        size_t startLocation = line.find(',') + 1;
        size_t size = line.find(',', startLocation + 1) - startLocation;
        double orderTotal = stod(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string orderNumber = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string supName = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string supAddress = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string supEmail = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string itemCata = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string itemName = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        string deliveryDate = line.substr(startLocation, size);

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        double costOfItem = stod(line.substr(startLocation, size));

        startLocation = line.find(',', startLocation + 1) + 1;
        size = line.find(',', startLocation + 1) - startLocation;
        int quantity = stoi(line.substr(startLocation, size));

        orders.emplace_back(dateOfSale, orderTotal, orderNumber, supName, supAddress, supEmail, itemCata, itemName, deliveryDate, costOfItem, quantity);
    }
}