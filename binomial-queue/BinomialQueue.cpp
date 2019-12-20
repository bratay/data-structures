#include <iostream>
#include "BinomialQueue.h"
#include "Queue.h"

BinomialQueue::BinomialQueue()
{

    for (int i = 0; i < SIZE; i++)
    {
        mTrees[i] = nullptr;
    }

    mCurrentSize = 0;
}

BinomialQueue::~BinomialQueue()
{

    for (int i = 0; i < SIZE; i++)
    {
        if (mTrees[i])
        {
            destroyTree(mTrees[i]);
        }
    }
}

bool BinomialQueue::isEmpty() const
{
    return mCurrentSize == 0;
}

void BinomialQueue::insert(int aKey)
{
    BinomialQueue newQueue;
    bqNode *newNode = new bqNode(aKey);
    newQueue.mTrees[0] = newNode;

    merge(newQueue);

    mCurrentSize++;
}

void BinomialQueue::deleteMin()
{
    if (isEmpty())
    {
        return;
    }

    int minIndex = -1;

    for (int i = 0; i < SIZE; i++)
    {
        if (mTrees[i])
        {
            if (minIndex == -1)
            {
                minIndex = i;
            }
            else
            {
                if (mTrees[i]->key < mTrees[minIndex]->key)
                {
                    minIndex = i;
                }
            }
        }
    }

    bqNode *remainingTree = mTrees[minIndex]->fChild;
    delete mTrees[minIndex];
    mTrees[minIndex] = nullptr;
    mCurrentSize--;

    BinomialQueue queueToMerge;

    for (int i = 0; i < minIndex; i++)
    {
        queueToMerge.mTrees[i] = remainingTree;
        if (remainingTree->rSibling)
        {
            remainingTree = remainingTree->rSibling;
        }
        queueToMerge.mTrees[i]->lSibling = queueToMerge.mTrees[i];
        queueToMerge.mTrees[i]->rSibling = nullptr;
    }

    merge(queueToMerge);
}

void BinomialQueue::levelOrderDisplay()
{
    for (int i = 0; i < SIZE; i++)
    {

        if (mTrees[i])
        {
            levelOrderDisplayByTree(mTrees[i], i);
            std::cout << "---\n";
        }
    }
}

void BinomialQueue::destroyTree(bqNode *aNode)
{
    if (aNode->rSibling)
    {
        destroyTree(aNode->rSibling);
    }

    if (aNode->fChild)
    {
        destroyTree(aNode->fChild);
    }

    delete aNode;
}

void BinomialQueue::merge(BinomialQueue &aOtherQueue)
{
    bqNode *carry = nullptr;

    for (int i = 0; i < SIZE; i++)
    {
        bqNode *t1 = mTrees[i];
        bqNode *t2 = aOtherQueue.mTrees[i];

        int mergeCase = t1 == nullptr ? 0 : 1;
        mergeCase += t2 == nullptr ? 0 : 2;
        mergeCase += carry == nullptr ? 0 : 4;

        switch (mergeCase)
        {
        case 0:
        case 1:
            break;
        case 2:
            mTrees[i] = t2;
            aOtherQueue.mTrees[i] = nullptr;
            break;
        case 3:
            carry = concateTrees(t1, t2);
            mTrees[i] = aOtherQueue.mTrees[i] = nullptr;
            break;
        case 4:
            mTrees[i] = carry;
            carry = nullptr;
            break;
        case 5:
            carry = concateTrees(t1, carry);
            mTrees[i] = nullptr;
            break;
        case 6:
            carry = concateTrees(t2, carry);
            aOtherQueue.mTrees[i] = nullptr;
            break;
        case 7:
            mTrees[i] = carry;
            carry = concateTrees(t1, t2);
            aOtherQueue.mTrees[i] = nullptr;
            break;
        }
    }
}

int BinomialQueue::nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r * 2 > n)
        r = n - r;
    if (r == 0)
        return 1;

    int result = n;
    for (int i = 2; i <= r; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

void BinomialQueue::levelOrderDisplayByTree(bqNode *aRootNode, int aOrder)
{

    int *pascalVals = new int[aOrder + 1];
    int valsDisplayed = 0;
    int pascalIndex = 0;

    for (int i = 0; i <= aOrder; i++)
    {
        pascalVals[i] = nCr(aOrder, i);
    }

    Queue<bqNode *> queue;

    queue.enqueue(aRootNode);

    while (!queue.isEmpty())
    {

        bqNode *curNode = queue.peekFront();

        while (curNode)
        {

            if (curNode->fChild)
            {
                queue.enqueue(curNode->fChild);
            }

            std::cout << curNode->key << " ";

            valsDisplayed++;
            if (valsDisplayed == pascalVals[pascalIndex])
            {
                std::cout << "\n";
                valsDisplayed = 0;
                pascalIndex++;
            }

            curNode = curNode->rSibling;
        }

        queue.dequeue();
    }

    delete[] pascalVals;
}

bqNode *BinomialQueue::concateTrees(bqNode *aT1, bqNode *aT2)
{
    if (aT1->key > aT2->key)
    {
        return concateTrees(aT2, aT1);
    }

    if (aT1->order == 0)
    {
        aT1->fChild = aT2;
        aT1->order += 1;

        return aT1;
    }

    aT2->lSibling = aT1->fChild->lSibling;
    aT2->lSibling->rSibling = aT2;
    aT1->fChild->lSibling = aT2;
    aT1->order = aT1->order + 1;

    return aT1;
}
