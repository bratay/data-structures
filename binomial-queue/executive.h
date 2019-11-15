#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>

#include "binomialQueue.h"

using namespace std;

class Executive
{

private:
	BinomialQueue *myBiQue = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insertElement();

	void delete();

	void levelorder();
};
#endif
