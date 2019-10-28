#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class MaxHeap
{

private:
	int heap[1500];
	int size;

public:
	MaxHeap();

	bool isEmpty();

	bool isMax(int val);

	void buildHeap(int i);

	void insert(int x);

	bool removeMax();

	bool removeMin();

	void deleteMax();

	void levelorder();
};
#endif