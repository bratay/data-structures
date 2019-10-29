#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class MinHeap
{

private:
	int heap[1500];
	int size;

public:
	MinHeap();

	bool isEmpty();

	bool isMin(int val);

	void buildHeap();

	void insert(int x);

	int findMin();

	int findMax();

	int removeMax();

	int removeMin();

	void levelorder();
};
#endif