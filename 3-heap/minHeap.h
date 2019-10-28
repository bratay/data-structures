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

	void buildHeap(int i);

	void insert(int x);

	bool removeMax();

	bool removeMin();

	void levelorder();
};
#endif