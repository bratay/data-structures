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

    LeftistNode* getRoot();

    bool find(int val);
    bool findHelp(LeftistNode *m_rootPtr, int val);

    bool insert(int m_value);

    bool deletemin();
    int findmin();
    LeftistNode *concate(LeftistNode *a, LeftistNode *b);
    void adrank(LeftistNode *m_root);
    void Preorder();
    void PreorderHelper(LeftistNode *m_rootPtr);
    void Postorder();
    void PostorderHelper(LeftistNode *m_rootPtr);
    void Inorder();
    void InorderHelper(LeftistNode *m_rootPtr);
    void levelorder();
    void levelorderHelper(LeftistNode *m_rootPtr);

private:
    LeftistNode *root;
};
#endif
