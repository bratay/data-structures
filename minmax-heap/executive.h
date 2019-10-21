#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>

using namespace std;

class Executive
{

private:
	BiSearchTree *myHeap = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insert();

	void deleteElement();
};
#endif
