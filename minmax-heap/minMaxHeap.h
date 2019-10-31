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

	void insert(int newVal);

	void remove(int val);

	void minTraversal();

	void maxTraversal();

	void levelorder();
};
#endif