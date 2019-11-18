#ifndef MINSKEWHEAP_H
#define MINSKEWHEAP_H

#include <string>

#include "SkewNode.h"
#include "Queue.h"

using namespace std;

class MinSkewHeap
{
public:
    MinSkewHeap();
    ~MinSkewHeap();

    SkewNode* getRoot();

    bool find(int val);
    bool findHelp(SkewNode *m_rootPtr, int val);
    bool insert(int m_value);
    bool deletemin();
    int findmin();
    SkewNode *concate(SkewNode *h1, SkewNode *h2);
    void adrank(SkewNode *m_root);
    void Preorder();
    void PreorderHelper(SkewNode *m_rootPtr);
    void Postorder();
    void PostorderHelper(SkewNode *m_rootPtr);
    void Inorder();
    void InorderHelper(SkewNode *m_rootPtr);
    void levelorder();
    void levelorderHelper(SkewNode *m_rootPtr);

private:
    SkewNode *root;
};
#endif
