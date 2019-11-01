#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

class MinMaxHeap
{

private:
	int heap[1500];
	int size;

public:
	MinMaxHeap();

	void buildHeap(int i);

	int getMinChild(int index);

	bool contains(int val);

	bool insert(int newVal);

	bool remove(int val);

	void showHeap();

	void minTraversal();

	void maxTraversal();
};
#endif