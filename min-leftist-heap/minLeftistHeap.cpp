#include <string>
#include <iostream>
#include "MinLeftistHeap.h"

using namespace std;

MinLeftistHeap::MinLeftistHeap()
{
    root = nullptr;
}

MinLeftistHeap::~MinLeftistHeap()
{
    while (root != nullptr)
    {
        deletemin();
    }
}

void MinLeftistHeap::buildheap(string name)
{
    ifstream inp;
    inp.open(name);
    int num;
    while (!inp.eof())
    {
        inp >> num;
        insert(num);
    }
    inp.close();
}

void MinLeftistHeap::insert(int m_value)
{
    LeftistNode *newnode = new LeftistNode(m_value);
    if (root == nullptr)
    {
        root = newnode;
    }
    else
    {
        root = concate(root, newnode);
    }
}

bool MinLeftistHeap::deletemin()
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

int MinLeftistHeap::findmin()
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

LeftistNode *MinLeftistHeap::concate(LeftistNode *a, LeftistNode *b)
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

void MinLeftistHeap::adrank(LeftistNode *m_root)
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

void MinLeftistHeap::Preorder()
{
    PreorderHelper(root);
}

void MinLeftistHeap::PreorderHelper(LeftistNode *m_rootPtr)
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

void MinLeftistHeap::Inorder()
{
    InorderHelper(root);
}

void MinLeftistHeap::InorderHelper(LeftistNode *m_rootPtr)
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

void MinLeftistHeap::levelorder()
{
    levelorderHelper(root);
    cout << "" << endl;
}

void MinLeftistHeap::levelorderHelper(LeftistNode *m_rootPtr)
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