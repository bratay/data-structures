#include "tree.h"
#include "binaryNode.h"
#include "queue.h"
#include <iostream>

using namespace std;

Tree::Tree()
{

}

Tree::~Tree()
{
	delete root;
}

bool Tree::insert(int num)
{
  if(find(num) != nullptr)
    return false;

  if(root == nullptr)
  {
		BinaryNode<int>* newNode = new BinaryNode<int>(num);
    root = newNode;
    return true;
  }
	Queue<int>* myQ = new Queue<int>();
  insertHelp(root, myQ, num);

	delete myQ;

  return true;
}

//level order traversal till a left or right child is nullptr then insert
void Tree::insertHelp(BinaryNode<int>* curNode, Queue<int>* q, int newData)
{
	if(curNode->getLeftChildPtr() == nullptr)
	{
		BinaryNode<int>* newNode = new BinaryNode<int>(newData);
		curNode->setLeftChildPtr(newNode);
		return;
	}
	q->enqueue( curNode->getLeftChildPtr()->getItem() );

	if(curNode->getRightChildPtr() == nullptr)
	{
		BinaryNode<int>* newNode = new BinaryNode<int>(newData);
		curNode->setRightChildPtr(newNode);
		return;
	}
	q->enqueue( curNode->getRightChildPtr()->getItem() );


	int nextNodeData = q->peekFront();
	q->dequeue();

	insertHelp(find(nextNodeData), q, newData);
}

bool Tree::deleteNode(int num)
{
  BinaryNode<int>* nodeToDelete = find(num);

  if(nodeToDelete == nullptr)
    return false;

	// if(nodeToDelete->getItem() == root->getItem()){
	// 	root = nullptr;
	// }

	Queue<int>* myQ = new Queue<int>();
    BinaryNode<int>* swapNode = deleteHelp(root, myQ);

	delete myQ;

	nodeToDelete->setItem( swapNode->getItem() );

	delete swapNode;

  return true;
}

//returns the last node in level Order Traversal
BinaryNode<int>* Tree::deleteHelp(BinaryNode<int>* curNode, Queue<int>* q)
{
	if(curNode->getLeftChildPtr() != nullptr)
	{
		q->enqueue( curNode->getLeftChildPtr()->getItem() );
	}

	if(curNode->getRightChildPtr() != nullptr)
	{
		q->enqueue( curNode->getRightChildPtr()->getItem() );
	}

	if(q->isEmpty())
		return curNode;

	int nextNodeData = q->peekFront();
	q->dequeue();

	BinaryNode<int>* returnNode = deleteHelp(find(nextNodeData), q);

	if(curNode->getLeftChildPtr() == returnNode)
		curNode->setLeftChildPtr(nullptr);

	if(curNode->getRightChildPtr() == returnNode)
		curNode->setRightChildPtr(nullptr);

	return returnNode;
}

BinaryNode<int>* Tree::find(int num)
{
  return findHelp(root, num);
}

BinaryNode<int>* Tree::findHelp(BinaryNode<int>* curNode, int num)
{
	if(curNode == nullptr)
		return nullptr;
	else if(curNode->getItem() == num){
		return curNode;
	}
	BinaryNode<int>* result = findHelp(curNode->getLeftChildPtr(), num);

	return (result != nullptr ) ? result :  findHelp(curNode->getRightChildPtr(), num);
}

bool Tree::isLeaf(int num)
{
  BinaryNode<int>* node = find(num);

  if(node == nullptr)
    return false;

  if(node->getLeftChildPtr() == nullptr && node->getRightChildPtr() == nullptr)
    return true;

  return false;
}

void Tree::printLeafs()
{
	if( root != nullptr )
		printHelp(root);

}

void Tree::printHelp(BinaryNode<int>* curNode)
{
	if( curNode == nullptr )
		return;

	if( curNode->getLeftChildPtr() == nullptr && curNode->getRightChildPtr() == nullptr )
		cout<<curNode->getItem()<<", ";

	printHelp(curNode->getLeftChildPtr());
	printHelp(curNode->getRightChildPtr());
}

bool Tree::isFull()
{
	if(root == nullptr)
		return false;

	int leftHeight = 1;
	BinaryNode<int>* curNode = root;
	while(curNode->getLeftChildPtr() != nullptr)
	{
		curNode = curNode->getLeftChildPtr();
		leftHeight++;
	}

	int rightHeight = 1;
	BinaryNode<int>* curRightNode = root;
	while(curRightNode->getRightChildPtr() != nullptr)
	{
		curRightNode = curRightNode->getRightChildPtr();
		rightHeight++;
	}

	curRightNode = nullptr;
	curNode = nullptr;

	delete curNode;
	delete curRightNode;
	return (rightHeight == leftHeight);
}


int Tree::getTreeHeight()
{
  if(root == nullptr)
    return 0;

  return heightHelp(root->getLeftChildPtr(), 1);
}

int Tree::heightHelp(BinaryNode<int>* curNode, int height)
{
	if(curNode == nullptr)
		return height;
	else
		return heightHelp(curNode->getLeftChildPtr(), height + 1);
}

void Tree::preOrderTraversal()
{
  if(root == nullptr)
    return;
  cout<<to_string(root->getItem()) <<", ";
  preOrderHelp(root->getLeftChildPtr());
  preOrderHelp(root->getRightChildPtr());
}

void Tree::preOrderHelp(BinaryNode<int>* curNode)
{
  if(curNode != nullptr){
		cout<<to_string(curNode->getItem()) <<", ";
		preOrderHelp(curNode->getLeftChildPtr());
		preOrderHelp(curNode->getRightChildPtr());
	}
}

void Tree::postOrderTraversal()
{
  if(root == nullptr)
    return;

  postOderHelp(root->getLeftChildPtr());
  postOderHelp(root->getRightChildPtr());
  cout<<to_string(root->getItem()) <<", ";
}

void Tree::postOderHelp(BinaryNode<int>* curNode)
{
  if(curNode != nullptr){
		postOderHelp(curNode->getLeftChildPtr());
		postOderHelp(curNode->getRightChildPtr());
    cout<<to_string(curNode->getItem()) <<", ";
	}
}

void Tree::inOrderTraversal()
{
  if(root == nullptr)
    return;

  inOrderHelp(root->getLeftChildPtr());
  cout<<to_string(root->getItem()) <<", ";
  inOrderHelp(root->getRightChildPtr());
}

void Tree::inOrderHelp(BinaryNode<int>* curNode)
{
  if(curNode != nullptr){
		inOrderHelp(curNode->getLeftChildPtr());
    cout<<to_string(curNode->getItem()) <<", ";
    inOrderHelp(curNode->getRightChildPtr());
	}
}

void Tree::levelOrderTraversal()
{
	if(root == nullptr)
		return;
	Queue<int> *myQueue = new Queue<int>();
	levelOrderHelp(root, myQueue);
}

void Tree::levelOrderHelp(BinaryNode<int>* curNode, Queue<int>* q)
{
	cout<<curNode->getItem() <<", ";

	if(curNode->getLeftChildPtr() != nullptr)
	{
		q->enqueue( curNode->getLeftChildPtr()->getItem() );
	}

	if(curNode->getRightChildPtr() != nullptr)
	{
		q->enqueue( curNode->getRightChildPtr()->getItem() );
	}

	if(q->isEmpty())
		return;

	int nextNodeData = q->peekFront();
	q->dequeue();

	levelOrderHelp(find(nextNodeData), q);
}
