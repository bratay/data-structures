#include <string>
#include "maxHeap.h"

using namespace std;

MaxHeap::MaxHeap()
{
    for (int i = 0; i < 800; i++)
        heap[i] = INT_MAX;
}

bool MaxHeap::isEmpty(){ return (size == 0); }

void MaxHeap::isMax(int val) {}

void MaxHeap::buildHeap(int i) {}

void MaxHeap::insert(int x) {}

void MaxHeap::remove(int x) {}

void MaxHeap::deleteMin() {}

void MaxHeap::deleteMax() {}

void MaxHeap::levelorder() {}