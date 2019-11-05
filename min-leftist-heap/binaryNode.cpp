#include "binaryNode.h"
#include <iostream>

using namespace std;

template<class ItemType>
BinaryNode<ItemType>:: BinaryNode(ItemType anItem){
	item=anItem;
	//sets left and right child to null
	leftChildPtr=nullptr;
	rightChildPtr=nullptr;
}

template<class ItemType>
BinaryNode<ItemType>:: BinaryNode(ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr){
	item=anItem;
	//sets left and right child
	leftChildPtr=leftPtr;
	rightChildPtr=rightPtr;
}

//template<class ItemType>
//BinaryNode<ItemType>:: ~BinaryNode(){}

template<class ItemType>
void BinaryNode<ItemType>:: setItem(ItemType anItem){
	item=anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>:: getItem() const{
	return(item);
}

template<class ItemType>
bool BinaryNode<ItemType>:: isLeaf() const{
	if(leftChildPtr==nullptr && rightChildPtr==nullptr){
		return(true);//true if both children are null
	}else{
		return(false);
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>:: getLeftChildPtr() const{
	return(leftChildPtr);
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>:: getRightChildPtr() const{
	return(rightChildPtr);
}

template<class ItemType>
void BinaryNode<ItemType>:: setLeftChildPtr(BinaryNode<ItemType>* leftPtr){
	leftChildPtr= leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>:: setRightChildPtr(BinaryNode<ItemType>* rightPtr){
	rightChildPtr= rightPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>:: operator=(BinaryNode<ItemType>* rightHandSide){
	this->item= rightHandSide->item;
	this->leftChildPtr= rightHandSide->leftChildPtr;
	this->rightChildPtr= rightHandSide->rigthChildPtr;
	return(this);
}

template<class ItemType>
bool BinaryNode<ItemType>:: operator ==(BinaryNode<ItemType>* rhs){
	if(this->item.getName() == rhs->item.getName()){
		return(true);
	}else{
		return(false);
	}
}

template<class ItemType>
bool BinaryNode<ItemType>:: operator <(BinaryNode<ItemType>* rhs){
    if(this->item.getName() < rhs->item.getName()){
        return(true);
    }else{
        return(false);
    }
}

template<class ItemType>
bool BinaryNode<ItemType>:: operator >(BinaryNode<ItemType>* rhs){
	if(this->item.getName() > rhs->item.getName()){
		return(true);
	}else{
		return(false);
	}
}
