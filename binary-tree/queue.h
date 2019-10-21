#ifndef QUEUE_H
#define QUEUE_H
#include "binaryNode.h"
#include <string>

using namespace std;

template<class T>
class Queue{

private:
	int length;
	BinaryNode<T>* head= nullptr;

public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void enqueue( T newEntry);
	void dequeue();
	T peekFront() const;
	int getLength();

};
#include "queue.cpp"
#endif
