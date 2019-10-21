#ifndef TABLE_H
#define TABLE_H
#include <string>

using namespace std;

struct restaurant{
	string name;
	int rating;
	string price;
};

class Table
{

protected:
	int size;
	restaurant  *container = nullptr;

public:
	Table();
	~Table();

	int getSize() const;

	bool insert(const restaurant &value);

	bool deleteValue(string value);

	int find(string value);

	string* searchByRating(int rating);

	string* searchByPrice(string price);

	virtual int hashFunction(string value) = 0;

	void printTable();
};
#endif
