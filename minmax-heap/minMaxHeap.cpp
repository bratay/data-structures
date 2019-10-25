#include <string>
#include "minMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    for (int i = 0; i < 800; i++)
        heap[i] = INT_MAX;
}

bool MinMaxHeap::isEmpty()
{
}

void MinMaxHeap::isMax(int val) {}

void MinMaxHeap::buildHeap(int i) {}

void MinMaxHeap::insert(int x) {}

void MinMaxHeap::remove(int x) {}

void MinMaxHeap::deleteMin() {}

void MinMaxHeap::deleteMax() {}

void MinMaxHeap::levelorder() {}