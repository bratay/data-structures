#include "biSearchTree.h"
#include "binaryNode.h"
#include "queue.h"
#include <string>
#include <iostream>

using namespace std;

BiSearchTree::BiSearchTree()
{

}

BiSearchTree::~BiSearchTree()
{
	delete root;
}

void BiSearchTree::insert(string element)
{
  if(root == nullptr)
  {
		BinaryNode<string>* newNode = new BinaryNode<string>(element);
    root = newNode;
    return;
  }

  insertHelp(root, element);
}

//level order traversal till a left or right child is nullptr then insert
void BiSearchTree::insertHelp(BinaryNode<string>* curNode, string newData)
{
	if(curNode == nullptr){
		BinaryNode<string>* newNode = new BinaryNode<string>(newData);
		curNode = newNode;
	}else if(curNode->getItem() >= newData){
		if(curNode->getLeftChildPtr() == nullptr){
			BinaryNode<string>* newNode = new BinaryNode<string>(newData);
			curNode->setLeftChildPtr(newNode);
			return;
		}
		insertHelp(curNode->getLeftChildPtr(), newData);
	}else{
		if(curNode->getRightChildPtr() == nullptr){
			BinaryNode<string>* newNode = new BinaryNode<string>(newData);
			curNode->setRightChildPtr(newNode);
			return;
		}
		insertHelp(curNode->getRightChildPtr(), newData);
	}
}

bool BiSearchTree::deleteNode(string element)
{
  BinaryNode<string>* nodeToDelete = find(element);

  if(nodeToDelete == nullptr)
    return false;

	BinaryNode<string>* swapNode = deleteHelp(nodeToDelete->getRightChildPtr());

	nodeToDelete->setItem( swapNode->getItem() );

  return true;
}

//returns left most node in right subtree
BinaryNode<string>* BiSearchTree::deleteHelp(BinaryNode<string>* curNode)
{
	if(curNode == nullptr)
		return nullptr;

	if(curNode->getLeftChildPtr() != nullptr)
	{
		return deleteHelp(curNode->getRightChildPtr());
	}

	BinaryNode<string>* temp = curNode;
	curNode = deleteHelp(curNode->getRightChildPtr());

	return temp;
}

BinaryNode<string>* BiSearchTree::find(string element)
{
  return findHelp(root, element);
}

BinaryNode<string>* BiSearchTree::findHelp(BinaryNode<string>* curNode, string element)
{
	if(curNode == nullptr)
		return nullptr;
	else if(curNode->getItem() == element){
		return curNode;
	}
	BinaryNode<string>* result = findHelp(curNode->getLeftChildPtr(), element);

	return (result != nullptr ) ? result :  findHelp(curNode->getRightChildPtr(), element);
}

bool BiSearchTree::isLeaf(BinaryNode<string>* curNode)
{
  if(curNode == nullptr)
		return false;

  return (curNode->getLeftChildPtr() == nullptr && curNode->getRightChildPtr() == nullptr);
}

bool BiSearchTree::isLeaf(string element)
{
	BinaryNode<string>* curNode = find(element);

  if(curNode == nullptr)
		return false;

  return (curNode->getLeftChildPtr() == nullptr && curNode->getRightChildPtr() == nullptr);
}

void BiSearchTree::printLeafs()
{
	if( root != nullptr )
		printHelp(root);
}

void BiSearchTree::printHelp(BinaryNode<string>* curNode)
{
	if( curNode == nullptr )
		return;

	if( isLeaf(curNode) )
		cout<<curNode->getItem()<<", ";

	printHelp(curNode->getLeftChildPtr());
	printHelp(curNode->getRightChildPtr());
}

int BiSearchTree::getTreeHeight()
{
  if(root == nullptr)
    return 0;

  return heightHelp(root->getLeftChildPtr(), 1);
}

int BiSearchTree::heightHelp(BinaryNode<string>* curNode, int height)
{
	if(curNode == nullptr)
		return height;

	int leftHeight = heightHelp(curNode->getLeftChildPtr(), height + 1);
	int rightHeight = heightHelp(curNode->getRightChildPtr(), height + 1);

	return max(leftHeight, rightHeight);
}

void BiSearchTree::preOrderTraversal()
{
  if(root == nullptr)
    return;
  cout<<root->getItem()<<", ";
  preOrderHelp(root->getLeftChildPtr());
  preOrderHelp(root->getRightChildPtr());
}

void BiSearchTree::preOrderHelp(BinaryNode<string>* curNode)
{
  if(curNode != nullptr){
		cout<<curNode->getItem() <<", ";
		preOrderHelp(curNode->getLeftChildPtr());
		preOrderHelp(curNode->getRightChildPtr());
	}
}

void BiSearchTree::postOrderTraversal()
{
  if(root == nullptr)
    return;

  postOderHelp(root->getLeftChildPtr());
  postOderHelp(root->getRightChildPtr());
  cout<<root->getItem() <<", ";
}

void BiSearchTree::postOderHelp(BinaryNode<string>* curNode)
{
  if(curNode != nullptr){
		postOderHelp(curNode->getLeftChildPtr());
		postOderHelp(curNode->getRightChildPtr());
    cout<<curNode->getItem()<<", ";
	}
}

void BiSearchTree::inOrderTraversal()
{
  if(root == nullptr)
    return;

  inOrderHelp(root->getLeftChildPtr());
  cout<<root->getItem() <<", ";
  inOrderHelp(root->getRightChildPtr());
}

void BiSearchTree::inOrderHelp(BinaryNode<string>* curNode)
{
  if(curNode != nullptr){
		inOrderHelp(curNode->getLeftChildPtr());
    cout<<curNode->getItem() <<", ";
    inOrderHelp(curNode->getRightChildPtr());
	}
}
