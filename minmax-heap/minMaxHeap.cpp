#include <string>
#include <math.h>
#include "minMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

void MinMaxHeap::buildHeap(int index)
{
    int min = getMinChild(index);
    if (2 * index + 1 >= size)
        return;

    if (int(trunc(log2(index + 1))) % 2 == 0)
    {
        if (heap[min] < heap[index])
        {
            int temp = heap[index];
            heap[index] = heap[min];
            heap[min] = temp;
            buildHeap(index);
            buildHeap((min - 1) / 2);
            buildHeap(min);
        }
    }
    else
    {
        if (heap[min] > heap[index])
        {
            int temp = heap[index];
            heap[index] = heap[min];
            heap[min] = temp;
            buildHeap(index);
            buildHeap((min - 1) / 2);
            buildHeap(min);
        }
    }
}

int MinMaxHeap::getMinChild(int index)
{
    int min = 2 * index + 1;
    if (2 * index + 1 >= size)
        return 2 * index + 1;

    for (int i = 1; i <= 2; i++)
    {
        if (int(trunc(log2(index + 1))) % 2 == 0)
        {
            min = (heap[2 * index + i] < heap[min] && 2 * index + i < size) ? 2 * index + i : min;
            for (int x = 1; x <= 2; x++)
            {
                min = (heap[2 * (2 * index + i) + x] < heap[min] && 2 * (2 * index + i) + x < size) ? 2 * (2 * index + i) + x : min;
            }
        }
        else
        {
            min = (heap[2 * index + i] > heap[min] && 2 * index + i < size) ? 2 * index + i : min;
            for (int x = 1; x <= 2; x++)
            {
                min = (heap[2 * (2 * index + i) + x] > heap[min] && 2 * (2 * index + i) + x < size) ? 2 * (2 * index + i) + x : min;
            }
        }
    }
    return min;
}

bool MinMaxHeap::contains(int val)
{
    if (size == 0)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (heap[i] == val)
            return true;
    }

    return false;
}

bool MinMaxHeap::insert(int newVal)
{
    size++;
    heap[size - 1] = newVal;
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        buildHeap(i);
    }

    return true;
}

bool MinMaxHeap::remove(int val)
{
    if (!contains(val))
        return false;

    for (int i = 0; i < size; i++)
    {
        if (heap[i] == val)
        {
            if (i != size - 1)
            {
                heap[i] = heap[size - 1];
                for (int i = size; i >= 0; i--)
                {
                    buildHeap(i);
                }
            }
            else
            {
                heap[size - 1] = INT_MAX;
            }
            size--;
            return true;
        }
    }

    return false;
}

void MinMaxHeap::showHeap()
{
    if (size == 0)
        return;

    int length = 1;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        while (count < length && i < size)
        {
            cout << heap[i] << ", ";
            count++;
            i++;
        }
        i--;
        cout << "\n";
        length *= 2;
    }
}

void MinMaxHeap::minTraversal()
{
    if (size == 0)
        return;

    int length = 1;
    bool minLevel = true;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        while (count < length && i < size)
        {
            if (minLevel)
                cout << heap[i] << ", ";
            count++;
            i++;
        }
        i--;
        cout << "\n";
        length = length * 2;
        minLevel = !minLevel;
    }
}

void MinMaxHeap::maxTraversal()
{
    if (size == 0)
        return;

    int length = 1;
    bool maxLevel = false;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        while (count < length && i < size)
        {
            if (maxLevel)
                cout << heap[i] << ", ";
            count++;
            i++;
        }
        i--;
        cout << "\n";
        length *= 2;
        maxLevel = !maxLevel;
    }
}