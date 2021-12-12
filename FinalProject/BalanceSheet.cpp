#include "BalanceSheet.h"

BalanceSheet::BalanceSheet(string date, string invoiceID, double dailySales, double dailyDebt) {

	setDate(date);
	setInvoiceID(invoiceID);
	setDailySales(dailySales);
	setDailyDebt(dailyDebt);

}
BalanceSheet::~BalanceSheet() {}

string BalanceSheet::getDate() {
	return date;
}
string BalanceSheet::getInvoiceID() {
	return invoiceID;
}
double BalanceSheet::getDailySales() {
	return dailySales;
}
double BalanceSheet::getDailyDebt() {
	return dailyDebt;
}
void BalanceSheet::setInvoiceID(string invoiceID) {
	this->invoiceID = invoiceID;
}
void BalanceSheet::setDate(string date) {
	this->date = date;
}
void BalanceSheet::setDailySales(double dailySales) {
	this->dailySales = dailySales;
}
void BalanceSheet::setDailyDebt(double dailyDebt) {
	this->dailyDebt = dailyDebt;
}