#include <string>
#include "maxHeap.h"

using namespace std;

MaxHeap::MaxHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

bool MaxHeap::isEmpty() { return (size == 0); }

bool MaxHeap::isMax(int val)
{
    return (val == heap[0]);
}

void MaxHeap::buildHeap()
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
                if (heap[small] < heap[childIndex])
                {
                    small = childIndex;
                }
                childIndex++;
            }
            if (heap[small] > heap[ParentIndex])
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
    int smallestIndex = firstIndex;
    firstIndex++;
    for (int i = firstIndex; i < size; i++)
    {
        if (heap[smallestIndex] > heap[i])
        {
            smallestIndex = i;
        }
    }
    heap[smallestIndex] = heap[size - 1];
    size--;

    return true;
}

void MaxHeap::levelorder()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ,";
    }
}