#ifndef DHTABLE_H
#define DHTABLE_H
#include "table.h"
#include <string>

using namespace std;

class dhTable: public Table
{

private:

public:
	dhTable();
	~dhTable();

	int hashFunction(string value);
};
#endif
