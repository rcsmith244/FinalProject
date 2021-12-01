#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <string>
using namespace std;

class Categories
{
	private:
		string catName;
        string itemName;
		const int thresholdCount = 2;
		const int reorderAmount = 8;
        int itemID = 0;
        double itemPrice = 0;
        int itemCount = 0;
        bool reorderItem = false;
        string measurement;
	public:
		Categories(string catName, string measurement);
		Categories();
		~Categories();
		string getCatName() const;
		void setCatName(string catName);
		int getThresholdCount();
		int getReorderAmount();
        int getItemId() const;
        void setItemId(int itemId);
        double getItemPrice() const;
        void setItemPrice(double itemPrice);
        int getItemCount() const;
        void setItemCount(int itemCount);
        bool getReorderItem() const;
        void setReorderItem(bool reorderItem);
        string getItemName() const;
        void setItemName(string itemName);
        void orderItem(int count);
        string getMeasurement() const;
};

#endif // !CATEGORIES_H
