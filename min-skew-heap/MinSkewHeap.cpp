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
    {
        deletemin();
    }
}

bool MinSkewHeap::insert(int m_value)
{
    if (find(m_value))
        return false;

    LeftistNode *newnode = new LeftistNode(m_value);
    if (root == nullptr)
    {
        root = newnode;
    }
    else
    {
        root = concate(root, newnode);
    }

    return true;
}

bool MinSkewHeap::find(int val)
{
    return findHelp(root, val);
}

bool MinSkewHeap::findHelp(LeftistNode *m_rootPtr, int val)
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
    {
        return false;
    }
    else
    {
        LeftistNode *newroot = concate(root->getLeftChild(), root->getRightChild());
        delete root;
        root = newroot;
        return true;
    }
}

int MinSkewHeap::findmin()
{
    if (root == nullptr)
    {
        return -1;
    }
    else
    {
        return root->getValue();
    }
}

LeftistNode *MinSkewHeap::getRoot()
{
    return root;
}

LeftistNode *MinSkewHeap::concate(LeftistNode *a, LeftistNode *b)
{
    if (a == nullptr)
    {
        return b;
    }
    else if (b == nullptr)
    {
        return a;
    }
    else if (a->getValue() > b->getValue())
    {
        swap(a, b);
    }
    a->setRightChild(concate(a->getRightChild(), b));
    adrank(a);
    if (a->getLeftChild() != nullptr)
    {
        if (a->getLeftChild()->getRank() < a->getRightChild()->getRank())
        {
            LeftistNode *temp = a->getLeftChild();
            a->setLeftChild(a->getRightChild());
            a->setRightChild(temp);
            temp = nullptr;
        }
    }
    else
    {
        LeftistNode *temp = a->getLeftChild();
        a->setLeftChild(a->getRightChild());
        a->setRightChild(temp);
        temp = nullptr;
    }
    return a;
}

void MinSkewHeap::adrank(LeftistNode *m_root)
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

void MinSkewHeap::PreorderHelper(LeftistNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        cout << m_rootPtr->getValue() << " ";
        PreorderHelper(m_rootPtr->getLeftChild());
        PreorderHelper(m_rootPtr->getRightChild());
    }
    else
    {
    }
}

void MinSkewHeap::Postorder()
{
    PostorderHelper(root);
}

void MinSkewHeap::PostorderHelper(LeftistNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        PostorderHelper(m_rootPtr->getLeftChild());
        PostorderHelper(m_rootPtr->getRightChild());
        cout << m_rootPtr->getValue() << " ";
    }
    else
    {
    }
}

void MinSkewHeap::Inorder()
{
    InorderHelper(root);
}

void MinSkewHeap::InorderHelper(LeftistNode *m_rootPtr)
{
    if (m_rootPtr != nullptr)
    {
        InorderHelper(m_rootPtr->getLeftChild());
        cout << m_rootPtr->getValue() << " ";
        InorderHelper(m_rootPtr->getRightChild());
    }
    else
    {
    }
}

void MinSkewHeap::levelorder()
{
    levelorderHelper(root);
    cout << "" << endl;
}

void MinSkewHeap::levelorderHelper(LeftistNode *m_rootPtr)
{
    Queue<LeftistNode *> m;
    Queue<LeftistNode *> n;

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