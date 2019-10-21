#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "table.h"
#include <string>

using namespace std;

class Executive
{

private:
	Table *myTable = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insert();

	void deleteElement();

	void find();

};
#endif
