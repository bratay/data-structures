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

int MaxHeap::findMin()
{
    if (size == 0)
        return -1;
    else if (size == 1)
        return heap[0];

    int smallest;
    for(int cur : heap)
    {
        if(cur > smallest)
            smallest = cur;
    }

    return smallest;
}

int MaxHeap::findMax()
{
    return (size == 0) ? -1 : heap[0];
}

int MaxHeap::removeMax()
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        cout << heap[0];
        heap[0] = heap[size - 1];
        size--;

        //swap
        int largeChild = 1, ParentIndex = 0;
        bool ischange = false;
        int result;
        while (ischange == false && largeChild < size)
        {
            int childIndex = largeChild + 1;
            for (int i = 1; i < 3 && childIndex < size; i++)
            {
                if (heap[largeChild] < heap[childIndex])
                {
                    largeChild = childIndex;
                }
                childIndex++;
            }
            if (heap[largeChild] > heap[ParentIndex])
            {
                swap(heap[largeChild], heap[ParentIndex]);
                ParentIndex = largeChild;
                largeChild = 3 * ParentIndex + 1;
            }
            else
            {
                result = heap[largeChild];
                ischange = true;
            }
        }
        return result;
    }
}

int MaxHeap::removeMin()
{
    if (size == 0)
    {
        return -1;
    }
    else if (size == 1)
    {
        int result = heap[0];
        heap[0] = -1;
        size--;
        return result;
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
    int result = heap[smallestIndex];
    heap[smallestIndex] = heap[size - 1];
    size--;

    return result;
}

void MaxHeap::levelorder()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ,";
    }
}