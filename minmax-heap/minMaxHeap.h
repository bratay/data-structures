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

	bool isEmpty();

	void isMax(int val);

	void buildHeap(int i);

	void insert(int newVal);

	void remove(int val);

	void deleteMin();

	void deleteMax();

	void levelorder();
};
#endif