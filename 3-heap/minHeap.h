#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class MinHeap {

    private:
	int heap[800];

	public:
    MinHeap();

	bool isEmpty();

	void isMax(int val);

	void buildHeap(int i);

	void insert(int x);

	void remove(int x);

	void deleteMin();

	void levelorder();

};
#endif