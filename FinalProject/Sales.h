#ifndef SALES_H
#define SALES_H
#include <string>
using namespace std;

class Sales
{
	private:
		string itemCata = "";
		string custName = "";
		string custPhone = "";
		string itemName = "";
		string salesDate = "";
		int itemCount = 0;
		double itemPrice = 0;
		double salesTotal = 0;
	public:
		Sales(string custName, string custPhone, string itemCata, string itemName, int itemCount, double itemPrice);
		Sales(string itemName, double itemPrice, int itemCount);
		Sales();
		~Sales();
		string getItemCata();
		string getCustName();
		string getCustPhone();
		string getItemName();
		string getSalesDate();
		int getItemCount();
		double getItemPrice();
		double getSalesTotal();
		string generateDate();
		void setCustName(string custName);
		void setCustPhone(string custPhone);
		void setItemCata(string itemCata);
		void setItemName(string itemName);
		void setItemCount(int itemCount);
		void setItemPrice(double itemPrice);
		
};

#endif
