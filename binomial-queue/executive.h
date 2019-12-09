#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>

#include "BinomialQueue.h"

using namespace std;

class Executive
{

private:
	BinomialQueue *myBiQue = nullptr;

public:
	Executive(string filename);
	~Executive();

	void insertItem();

	void deletemin();

	void printLevelOrder();

	void runMenu();
};
#endif
