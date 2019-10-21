#ifndef NODE_H
#define NODE_H
#include "list.h"

#include <string>

using namespace std;

template <typename T>
class Node
{

private:
	T item;
	Node<T> *nextNode;
	Node<T> *previousNode;

public:
	Node();
	Node(T startingItem);
	void setNext(Node<T> *next);
	void setPrevious(Node<T> *previous);
	Node<T> *getNext() const;
	Node<T> *getPrevious() const;
	void setItem(T newItem);
	T getItem() const;
};
#include "node.cpp"
#endif
