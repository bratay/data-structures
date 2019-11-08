
#ifndef MINLEFTISTHEAP_H
#define MINLEFTISTHEAP_H

#include <string>

#include "LeftistNode.h"
#include "Queue.h"

using namespace std;

class MinLeftistHeap
{
public:
    MinLeftistHeap();
    ~MinLeftistHeap();

    void insert(int m_value);

    bool deletemin();
    int findmin();
    LeftistNode *concate(LeftistNode *a, LeftistNode *b);
    void adrank(LeftistNode *m_root);
    void Preorder();
    void PreorderHelper(LeftistNode *m_rootPtr);
    void Inorder();
    void InorderHelper(LeftistNode *m_rootPtr);
    void levelorder();
    void levelorderHelper(LeftistNode *m_rootPtr);

private:
    LeftistNode *root;
};
#endif
