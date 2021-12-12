#ifndef SUPPLIERINFO_H
#define SUPPLIERINFO_H
#include <string>
using namespace std;

class SupplierInfo
{

	private:
		double itemCost = 0;
		string itemName = "";
		string supplierName = "";
		string supplierAddress = "";
		string supplierPhoneNumber = "";
		string supplierEmail = "";
	public:
		SupplierInfo(string supplierName, string supplierAddress, string supplierPhoneNumber, string supplierEmail, string itemName, double itemCost);
		SupplierInfo();
		~SupplierInfo();
		double getItemCost();
		string getItemName();
		string getSupplierName();
		string getSupplierAddress();
		string getSupplierPhoneNumber();
		string getSupplierEmail();
		void setItemCost(double itemCost);
		void setitemName(string itemName);
		void setSupplierName(string supplierName);
		void setSupplierAddress(string supplierAddress);
		void setSupplierPhoneNumber(string supplierPhoneNumber);
		void setSupplierEmail(string supplierEmail);
};

#endif
