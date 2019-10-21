#ifndef BISEARCHTREE_H
#define BISEARCHTREE_H
#include "binaryNode.h"
#include "queue.h"
#include <string>

using namespace std;

class BiSearchTree
{

private:
	BinaryNode<string>* root = nullptr;

public:
	BiSearchTree();
	~BiSearchTree();

	void insert(string element);
	void insertHelp(BinaryNode<string>* curNode, string newData);

	bool deleteNode(string element);
	BinaryNode<string>* deleteHelp(BinaryNode<string>* curNode);

 	BinaryNode<string>* find(string element);
	BinaryNode<string>* findHelp(BinaryNode<string>* curNode, string element);

	bool isLeaf(BinaryNode<string>* curNode);
	bool isLeaf(string element);

	void printLeafs();
	void printHelp(BinaryNode<string>* curNode);

	int getTreeHeight();
	int heightHelp(BinaryNode<string>* curNode, int height);

	void preOrderTraversal();
	void preOrderHelp(BinaryNode<string>* curNode);

	void postOrderTraversal();
	void postOderHelp(BinaryNode<string>* curNode);

	void inOrderTraversal();
	void inOrderHelp(BinaryNode<string>* curNode);
};
#endif
