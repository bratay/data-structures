#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>

#include "MinLeftistHeap.h"

using namespace std;

class Executive
{

private:
	MinLeftistHeap *myHeap = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insertElement();

	void deleteElement();

	void findMinElement();

	void merge();

	void preorder();

	void inorder();

	void postorder();

	void levelorder();
};
#endif
