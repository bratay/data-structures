#include <string>
#include "minHeap.h"

using namespace std;

MinHeap::MinHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

bool MinHeap::isEmpty() { return (size == 0); }

bool MinHeap::isMin(int val) { return (val == heap[0]); }

void MinHeap::buildHeap()
{
    int lastIndex = size - 1;
    int ParentIndex = (lastIndex - 1) / 3;
    while (ParentIndex >= 0)
    {
        int small = 3 * ParentIndex + 1;
        bool ischange = false;
        while (ischange == false && small < size)
        {
            int childIndex = small + 1;
            for (int i = 1; i < 3 && childIndex < size; i++)
            {
                if (heap[small] > heap[childIndex])
                {
                    small = childIndex;
                }
                childIndex++;
            }
            if (heap[small] < heap[ParentIndex])
            {
                swap(heap[small], heap[ParentIndex]);
                ParentIndex = small;
                small = 3 * ParentIndex + 1;
            }
            else
            {
                ischange = true;
            }
        }
        ParentIndex--;
    }
}

void MinHeap::insert(int newElement)
{
    heap[size] = newElement;
    int childIndex = size, parentIndex = 0;
    bool change = false;

    while (childIndex > 0 && change == false)
    {
        parentIndex = (childIndex - 1) / 3;
        if (newElement < heap[parentIndex])
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

bool MinHeap::removeMax()
{
    if (size == 0)
    {
        return false;
    }
    else if (size == 1)
    {
        heap[0] = -1;
        size--;
        return true;
    }

    int lastIndex = size - 1;
    int firstIndex = (lastIndex - 1) / 3 + 1;
    int biggestIndex = firstIndex;
    firstIndex++;
    for (int i = firstIndex; i < size; i++)
    {
        if (heap[biggestIndex] < heap[i])
        {
            biggestIndex = i;
        }
    }
    heap[biggestIndex] = heap[size - 1];
    size--;

    return true;
}

bool MinHeap::removeMin()
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
        int small = 1, ParentIndex = 0;
        bool ischange = false;
        while (ischange == false && small < size)
        {
            int childIndex = small + 1;
            for (int i = 1; i < 3 && childIndex < size; i++)
            {
                if (heap[small] > heap[childIndex])
                {
                    small = childIndex;
                }
                childIndex++;
            }
            if (heap[small] < heap[ParentIndex])
            {
                swap(heap[small], heap[ParentIndex]);
                ParentIndex = small;
                small = 3 * ParentIndex + 1;
            }
            else
            {
                ischange = true;
            }
        }
        return true;
    }
}

void MinHeap::levelorder()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ,";
    }
}