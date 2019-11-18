#include <string>
#include <iostream>
#include "MinSkewHeap.h"

using namespace std;

MinSkewHeap::MinSkewHeap()
{
    root = nullptr;
}

MinSkewHeap::~MinSkewHeap()
{
    while (root != nullptr)
        deletemin();
}

bool MinSkewHeap::insert(int m_value)
{
    if (find(m_value))
        return false;

    SkewNode *newnode = new SkewNode(m_value);

    if (root == nullptr)
        root = newnode;
    else
        root = concate(root, newnode);

    return true;
}

bool MinSkewHeap::find(int val)
{
    return findHelp(root, val);
}

bool MinSkewHeap::findHelp(SkewNode *m_rootPtr, int val)
{
    if (m_rootPtr != nullptr)
    {
        if (m_rootPtr->getValue() == val)
            return true;
        if (findHelp(m_rootPtr->getLeftChild(), val))
            return true;
        if (findHelp(m_rootPtr->getRightChild(), val))
            return true;
    }

    return false;
}

bool MinSkewHeap::deletemin()
{
    if (root == nullptr)
        return false;
    else
    {
        SkewNode *newroot = concate(root->getLeftChild(), root->getRightChild());
        delete root;
        root = newroot;
        return true;
    }
}

int MinSkewHeap::findmin()
{
    if (root == nullptr)
        return -1;
    else
        return root->getValue();
}

SkewNode *MinSkewHeap::getRoot()
{
    return root;
}

SkewNode *MinSkewHeap::concate(SkewNode *h1, SkewNode *h2)
{

    if (h1 == NULL)
    {
        return h2;
    }
    else if (h2 == NULL)
    {
        return h1;
    }
    else
    {
        if (h1->getValue() > h2->getValue())
        {
            SkewNode *temp;

            temp = h1;
            h1 = h2;
            h2 = temp;

            temp = nullptr;
        }

        SkewNode *temp;

        temp = h1->getRightChild();
        h1->setRightChild(h1->getLeftChild());
        h1->setLeftChild(concate(temp, h2));

        return h1;
    }
}

void MinSkewHeap::adrank(SkewNode *m_root)
{
    if (m_root->getLeftChild() == nullptr || m_root->getRightChild() == nullptr)
    {
        m_root->setRank(1);
    }
    else
    {
        if (m_root->getLeftChild()->getRank() < m_root->getRightChild()->getRank())
        {
            m_root->setRank(m_root->getLeftChild()->getRank() + 1);
        }
        else
        {
            m_root->setRank(m_root->getRightChild()->getRank() + 1);
        }
    }
}

void MinSkewHeap::Preorder()
{
    PreorderHelper(root);
}

void MinSkewHeap::PreorderHelper(SkewNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        cout << m_rootPtr->getValue() << " ";
        PreorderHelper(m_rootPtr->getLeftChild());
        PreorderHelper(m_rootPtr->getRightChild());
    }
}

void MinSkewHeap::Postorder()
{
    PostorderHelper(root);
}

void MinSkewHeap::PostorderHelper(SkewNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        PostorderHelper(m_rootPtr->getLeftChild());
        PostorderHelper(m_rootPtr->getRightChild());
        cout << m_rootPtr->getValue() << " ";
    }
}

void MinSkewHeap::Inorder()
{
    InorderHelper(root);
}

void MinSkewHeap::InorderHelper(SkewNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        InorderHelper(m_rootPtr->getLeftChild());
        cout << m_rootPtr->getValue() << " ";
        InorderHelper(m_rootPtr->getRightChild());
    }
}

void MinSkewHeap::levelorder()
{
    levelorderHelper(root);
    cout << "" << endl;
}

void MinSkewHeap::levelorderHelper(SkewNode *m_rootPtr)
{
    Queue<SkewNode *> m;
    Queue<SkewNode *> n;

    if (m_rootPtr != nullptr)
    {
        m.enqueue(m_rootPtr);
        while (m.isEmpty() == false || n.isEmpty() == false)
        {
            while (m.isEmpty() == false)
            {
                if (m.PrintFront()->getLeftChild() != nullptr)
                {
                    n.enqueue(m.PrintFront()->getLeftChild());
                }
                if (m.PrintFront()->getRightChild() != nullptr)
                {
                    n.enqueue(m.PrintFront()->getRightChild());
                }
                cout << m.peekFront()->getValue() << " ";
            }
            cout << " " << endl;
            while (n.isEmpty() == false)
            {
                if (n.PrintFront()->getLeftChild() != nullptr)
                {
                    m.enqueue(n.PrintFront()->getLeftChild());
                }
                if (n.PrintFront()->getRightChild() != nullptr)
                {
                    m.enqueue(n.PrintFront()->getRightChild());
                }
                cout << n.peekFront()->getValue() << " ";
            }
            cout << " " << endl;
        }
    }
}