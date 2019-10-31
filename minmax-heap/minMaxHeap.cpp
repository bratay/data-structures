#include <string>
#include "minMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

void MinMaxHeap::buildHeap(int i) 
{
    
}

bool MinMaxHeap::contains(int val)
{
    if (size == 0)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (heap[i] == val)
            return false;
    }

    return true;
}

bool MinMaxHeap::insert(int newVal)
{
    if (contains(newVal))
        return false;

    heap[size] = newVal;
    for (int i = 0; i > size / 2; i++)
    {
        buildHeap(i);
    }

    size++;
    return true;
}

bool MinMaxHeap::remove(int val)
{
    if (size == 0)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (heap[i] == val)
        {
            if (i != size - 1)
            {
                heap[i] = heap[size - 1];
                heap[size - 1] = INT_MAX;
                for (int i = 0; i > size; i++)
                {
                    buildHeap(i);
                }
            }
            else
            {
                heap[size - 1] = INT_MAX;
            }
            size--;
            remove(val);
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
        while (count < length && i < size && minLevel)
        {
            cout << heap[i] << ", ";
            count++;
            i++;
        }
        cout << "\n";
        length *= 2;
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
        while (count < length && i < size && maxLevel)
        {
            cout << heap[i] << ", ";
            count++;
            i++;
        }
        cout << "\n";
        length *= 2;
        maxLevel = !maxLevel;
    }
}