#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "qpTable.h"
#include "dhTable.h"
#include <string>

using namespace std;

class Executive
{

private:
	qpTable *myqpTable = nullptr;
	dhTable *mydhTable = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insert();

	void deleteElement();

	void findByName();

	void findByRating();

	void findByPrice();
};
#endif
