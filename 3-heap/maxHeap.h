#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class MaxHeap {

    private:
	int heap[800];

	public:
    MaxHeap();

	bool isEmpty();

	void isMax(int val);

	void buildHeap(int i);

	void insert(int x);

	void remove(int x);

	void deleteMax();

	void levelorder();
};
#endif