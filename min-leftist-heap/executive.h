#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "minLeftistHeap.h"

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

	void buildHeap();

    void merge();

    void preorder();//

    void inorder();//

    void postorder();//

    void levelorder();//
};
#endif
