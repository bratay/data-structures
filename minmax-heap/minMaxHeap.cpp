#include <string>
#include "minMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap()
{
    for (int i = 0; i < 1500; i++)
        heap[i] = INT_MAX;

    size = 0;
}

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