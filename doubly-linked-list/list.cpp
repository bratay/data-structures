#include "list.h"
#include "node.h"
#include <iostream>
#include <exception>
#include <string>

using namespace std;

template <typename T>
List<T>::List()
{
	head = nullptr;
	length = 0;
}

template <class T>
List<T>::~List()
{
	for (int x = length; x >= 1; x -= 1)
	{
		delete getNode(x);
	}
}

template <class T>
bool List<T>::isEmpty() const
{
	bool empty = false;
	if (length == 0)
	{
		empty = true;
	}
	return (empty);
}

template <class T>
int List<T>::getLength() const
{
	return (length);
}

template <class T>
void List<T>::insert(const T &newEntry)
{
	Node<T> *newNode = new Node<T>(newEntry);

	if(length == 0)
	{
		head = newNode;
		length++;
		return;
	}

	Node<T> *prevPtr = getNode(length);
	prevPtr->setNext(newNode);

	length++;
}

template <class T>
bool List<T>::remove(int valueToDelete)
{
	if(getNode(1)->getItem() == valueToDelete){
		Node<T> *oldHead = head;
		head = head->getNext();
		delete oldHead;
		length--;
		return true;
	}

	bool found = false;
	for (int x = 2; x <= length; x++)
	{
		if (getNode(x)->getItem() == valueToDelete)
		{
			found = true;
			Node<T> *pre = getNode(x - 1); // points the the node behid the ask for node
			Node<T> *temp = getNode(x);	//points the the asked for node
			pre->setNext(temp->getNext());
			temp->setNext(nullptr);
			delete temp;
			length -= 1;
		}
		if(found)
			break;
	}
	return found;
}

template <class T>
void List<T>::clear()
{
	Node<T> *temp = new Node<T>();
	//goes through evey link and deletes it
	for (int x = 1; x <= getLength(); x += 1)
	{
		temp = getNode(x);
		delete temp;
	}
}

template <class T>
T List<T>::getEntry(int position)
{
	//checks if node postion is valid
	if (isEmpty() == false && position <= length && position >= 1)
	{
		Node<T> *tempNode = getNode(position);
		return tempNode->getItem();
	}
	else
	{
		throw runtime_error("ERROR_invalid postion in getEntry");
	}
}

template <class T>
void List<T>::setEntry(int position, const T &newEntry)
{

	if (isEmpty() == false && position <= length && position >= 1)
	{
		getNode(position)->setItem(newEntry); //getting the node them sets there
	}
	else
	{
		throw runtime_error("ERROR_invalid postion in setEntry");
	}
}

template <class T>
Node<T> *List<T>::getNode(int position)
{
	//checks if node postion is valid
	if (isEmpty() == false && position <= length && position >= 1)
	{
		Node<T> *nodeToReturn = head; //creates new the node to return, starts at head

		if (position == 1)
		{
			return (nodeToReturn); //return the head
		}
		else
		{
			//loops till nodeToReturn is the right node
			for (int x = 1; x < position; x += 1)
			{
				nodeToReturn = nodeToReturn->getNext();
			}
			return (nodeToReturn);
		}
	}
	else
	{
		throw runtime_error("ERROR_invalid postion in getNode");
	}
}
