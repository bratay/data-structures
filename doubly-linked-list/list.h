#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class List
{

private:
	int length;
	Node<T> *head = nullptr;

public:
	List();
	~List();
	bool isEmpty() const;

	int getLength() const;

	void insert(const T &newEntry);

	bool remove(int valueToDelete); 

	void clear();

	T getEntry(int position);

	void setEntry(int position, const T &newEntry);

	Node<T> *getNode(int postion);
};
#include "list.cpp"
#endif
