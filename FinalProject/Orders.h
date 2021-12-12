#ifndef ORDERS_H
#define ORDERS_H
#include <vector>
#include <string>
using namespace std;

class Orders
{
	private: 
		string orderNumber = "";
		string supName = "";
		string supAddress = "";
		string supEmail = "";
		string itemCata = "";
		string itemName = "";
		string dateOfSale = "";
		string deliveryDate = "";
		const string deliveryDes = "1253 Green Way Green Bay WI 54311";
		double costOfItem = 0;
		double orderTotal = 0;
		int quantity = 0;
	public:
		Orders(string orderNumber, string supName, string supAddress, string supEmail, string itemCata, string itemName, string dateOfSale, string deliveryDate, double costOfItem, int quantity);
		Orders();
		~Orders();
		void setOrderNumber(string orderNumber);
		void setDateOfSale(string dateOfSale);
		void setDeliveryDate(string deliveryDate);
		void setCostOfItem(double costOfItem);
		void setItemCata(string itemCata);
		void setItemName(string itemName);
		void setSupAddress(string supAddress);
		void setSupEmail(string supEmail);
		void setSupName(string supName);
		void setQuantity(int quantity);
		void setOrderTotal(double orderTotal);
		string getOrderNumber();
		string getDateOfSale();
		string getDeliveryDate();
		string getDeliveryDes();
		string getItemCata();
		string getItemName();
		double getCostOfItem();
		string getSupAddress();
		string getSupEmail();
		string getSupName();
		double getOrderTotal();
		int getQuantity();

};

#endif
