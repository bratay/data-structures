#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class MinMaxHeap {

    private:
	int heap[800];

	public:
    MinMaxHeap();

	bool isEmpty();

	void isMax(int val);

	void buildHeap(int i);

	void insert(int x);

	void remove(int x);

	void deleteMin();

	void deleteMax();

	void levelorder();

};
#endif