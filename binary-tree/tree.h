#ifndef TREE_H
#define TREE_H
#include "binaryNode.h"
#include "queue.h"
#include <string>

using namespace std;

class Tree
{

private:
	BinaryNode<int>* root = nullptr;

public:
	Tree();
	~Tree();

	bool insert(int num);
	void insertHelp(BinaryNode<int>* curNode, Queue<int>* q, int newData);

 	bool deleteNode(int num);
	BinaryNode<int>* deleteHelp(BinaryNode<int>* curNode, Queue<int>* q);

 	BinaryNode<int>* find(int num);
	BinaryNode<int>* findHelp(BinaryNode<int>* curNode, int num);

	bool isLeaf(int num);

	void printLeafs();
	void printHelp(BinaryNode<int>* curNode);


	bool isFull();

	int getTreeHeight();
	int heightHelp(BinaryNode<int>* curNode, int height);

	void preOrderTraversal();
	void preOrderHelp(BinaryNode<int>* curNode);

	void postOrderTraversal();
	void postOderHelp(BinaryNode<int>* curNode);

	void inOrderTraversal();
	void inOrderHelp(BinaryNode<int>* curNode);

	void levelOrderTraversal();
	void levelOrderHelp(BinaryNode<int>* curNode, Queue<int>* q);
};
#endif
