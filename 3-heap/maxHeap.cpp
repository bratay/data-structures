#include <string>
#include "maxHeap.h"

using namespace std;

MaxHeap::MaxHeap()
{
    for (int i = 0; i < 800; i++)
        heap[i] = INT_MAX;

    size = 0;
}

bool MaxHeap::isEmpty() { return (size == 0); }

bool MaxHeap::isMax(int val)
{
    return (val == heap[0]);
}

void MaxHeap::buildHeap(int i) {}

void MaxHeap::insert(int newElement)
{
    heap[size] = newElement;
    int childIndex = size, parentIndex = 0;
    bool change = false;

    while (childIndex > 0 && change == false)
    {
        parentIndex = (childIndex - 1) / 3;
        if (newElement > heap[parentIndex])
        {
            swap(heap[parentIndex], heap[childIndex]);
            childIndex = parentIndex;
        }
        else
        {
            change = true;
        }
    }
    size++;
}

bool MaxHeap::removeMax()
{
}

bool MaxHeap::removeMin()
{
}

void MaxHeap::deleteMax() {}

void MaxHeap::levelorder()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ,";
    }
}