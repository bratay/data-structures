#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "tree.h"
#include "binaryNode.h"
#include <string>

using namespace std;

class Executive
{

private:
	Tree *myTree = nullptr;

public:
	Executive(string filename);
	~Executive();

	void runMenu();

	void insert();

	void deleteElement();

	void leaf();

	void printLeafs();

	void height();

	void full();

	void preorder();
	void postorder();
	void inorder();
	void levelorder();
};
#endif
