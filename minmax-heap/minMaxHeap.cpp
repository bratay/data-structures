#include <string>
#include "minMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

bool MinMaxHeap::isEmpty()
{
}

void MinMaxHeap::isMax(int val) {}

void MinMaxHeap::buildHeap(int i) {}

void MinMaxHeap::insert(int newVal)
{
    heap[size] = newVal;
    for (int i = size / 2; i >= 0; i--)
    {
        buildHeap(i);
    }
    size++;
}

void MinMaxHeap::remove(int val) {}

void MinMaxHeap::deleteMin() {}

void MinMaxHeap::deleteMax() {}

void MinMaxHeap::levelorder() {}