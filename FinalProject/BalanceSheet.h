#ifndef BALANCESHEET_H
#define BALANCESHEET_H
#include <string>
using namespace std;

class BalanceSheet
{

	private:
		string date = "";
		string invoiceID = "";
		double dailySales = 0;
		double dailyDebt = 0;
	public:
		BalanceSheet(string date, string invoiceID, double dailySales, double dailyDebt);
		~BalanceSheet();
		string getDate();
		string getInvoiceID();
		double getDailySales();
		double getDailyDebt();
		void setInvoiceID(string invoiceID);
		void setDate(string date);
		void setDailySales(double dailySales);
		void setDailyDebt(double dailyDebt);

};

#endif

