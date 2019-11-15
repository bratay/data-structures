#include <string>
#include <queue>
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

bool MinLeftistHeap::insert(int m_value)
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

bool MinLeftistHeap::find(int val)
{
    return findHelp(root, val);
}

bool MinLeftistHeap::findHelp(LeftistNode *m_rootPtr, int val)
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

LeftistNode *MinLeftistHeap::getRoot()
{
    return root;
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

void MinLeftistHeap::Postorder()
{
    PostorderHelper(root);
}

void MinLeftistHeap::PostorderHelper(LeftistNode *m_rootPtr)
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

void MinLeftistHeap::levelorderHelper(LeftistNode* m_rootPtr)
{
    queue<int> m;
    queue<int> n;

    if (m_rootPtr != nullptr)
    {
        m.push(m_rootPtr->getValue());
        while (m.empty() == false || n.empty() == false)
        {
            while (m.empty() == false)
            {
                if (m.front() != -1)
                {
                    n.push(m.front());
                }
                if (m.front() != -1)
                {
                    n.push(m.front());
                }
                int val = m.front();
                m.pop();
                cout << to_string(val) << " ";
                // cout << m.printFront()->getValue() << " ";
            }
            cout << " " << endl;
            while (n.empty() == false)
            {
                if (n.front() != -1)
                {
                    m.push(n.front());
                }
                if (n.front() != -1)
                {
                    m.push(n.front());
                }
                int val = n.front();
                n.pop();
                cout << to_string(val) << " ";
                // cout << m.printFront()->getValue() << " ";
            }
            cout << " " << endl;
        }
    }
}

// void MinLeftistHeap::levelorderHelper(LeftistNode* m_rootPtr)
// {
//     Queue m;
//     Queue n;

//     if (m_rootPtr != nullptr)
//     {
//         m.enqueue(m_rootPtr->getValue());
//         while (m.isEmpty() == false || n.isEmpty() == false)
//         {
//             while (m.isEmpty() == false)
//             {
//                 if (m.printFront()->getItem()->getLeftChild() != nullptr)
//                 {
//                     n.enqueue(m.printFront()->getItem()->getLeftChild()->getValue());
//                 }
//                 if (m.printFront()->getItem()->getRightChild() != nullptr)
//                 {
//                     n.enqueue(m.printFront()->getItem()->getRightChild()->getValue());
//                 }
//                 cout << m.peekFront()->getItem()->getValue() << " ";
//                 // cout << m.printFront()->getValue() << " ";
//             }
//             cout << " " << endl;
//             while (n.isEmpty() == false)
//             {
//                 if (n.printFront()->getItem()->getLeftChild() != nullptr)
//                 {
//                     m.enqueue(n.printFront()->getItem()->getLeftChild()->getValue());
//                 }
//                 if (n.printFront()->getItem()->getRightChild() != nullptr)
//                 {
//                     m.enqueue(n.printFront()->getItem()->getRightChild()->getValue());
//                 }
//                 cout << n.peekFront()->getItem()->getValue() << " ";
//                 // cout << m.printFront()->getValue() << " ";
//             }
//             cout << " " << endl;
//         }
//     }
// }


