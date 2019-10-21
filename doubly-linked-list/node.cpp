#include "node.h"

using namespace std;
template <typename T>
Node<T>::Node()
{
	nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T startingItem)
{
	nextNode = nullptr;
	item = startingItem;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
	nextNode = next;
}

template <typename T>
void Node<T>::setPrevious(Node<T> *previous)
{
	previousNode = previous;
}

template <typename T>
Node<T> *Node<T>::getNext() const
{
	return (nextNode);
}

template <typename T>
Node<T> *Node<T>::getPrevious() const
{
	return (previousNode);
}

template <typename T>
void Node<T>::setItem(T newItem)
{
	item = newItem;
}

template <typename T>
T Node<T>::getItem() const
{
	return (item);
}
