#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <string>
using namespace std;

class Categories
{
	private:
		string catName;
		const int thresholdCount = 2;
		const int reorderAmount = 8;
	public:
		Categories(string catName);
		Categories();
		~Categories();
		string getCatName();
		void setCatName(string catName);
		int getThresholdCount();
		int getReorderAmount();

};

#endif // !CATEGORIES_H
