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
    if (size == 0)
    {
        return false;
    }
    else
    {
        cout << heap[0];
        heap[0] = heap[size - 1];
        size--;

        //swap
        int smallchild = 1, ParentIndex = 0;
        bool ischange = false;
        while (ischange == false && smallchild < size)
        {
            int childIndex = smallchild + 1;
            for (int i = 1; i < 3 && childIndex < size; i++)
            {
                if (heap[smallchild] < heap[childIndex])
                {
                    smallchild = childIndex;
                }
                childIndex++;
            }
            if (heap[smallchild] < heap[ParentIndex])
            {
                swap(heap[smallchild], heap[ParentIndex]);
                ParentIndex = smallchild;
                smallchild = 3 * ParentIndex + 1;
            }
            else
            {
                ischange = true;
            }
        }
        return true;
    }
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