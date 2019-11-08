
#ifndef MINLEFTISTHEAP_H
#define MINLEFTISTHEAP_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "LeftistNode.h"
#include "Queue.h"

using namespace std;

template <typename T>
class MinLeftistHeap
{
public:
    MinLeftistHeap();
    ~MinLeftistHeap();

    void buildheap(string name);

    void insert(T m_value);

    bool deletemin();
    T findmin();
    LeftistNode<T> *concate(LeftistNode<T> *a, LeftistNode<T> *b);
    void adrank(LeftistNode<T> *m_root);
    void Preorder();
    void PreorderHelper(LeftistNode<T> *m_rootPtr);
    void Inorder();
    void InorderHelper(LeftistNode<T> *m_rootPtr);
    void levelorder();
    void levelorderHelper(LeftistNode<T> *m_rootPtr);

private:
    LeftistNode<T> *root;
};
#endif
