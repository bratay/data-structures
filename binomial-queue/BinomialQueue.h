

#ifndef BINOMIAL_QUEUE
#define BINOMIAL_QUEUE

struct bqNode
{
    int key;
    int order;
    bqNode *fChild;
    bqNode *lSibling;
    bqNode *rSibling;

    bqNode(int aKey) : key(aKey)
    {
        order = 0;
        fChild = nullptr;
        lSibling = this;
        rSibling = nullptr;
    }
};

class BinomialQueue
{
public:
    BinomialQueue();

    ~BinomialQueue();

    bool isEmpty() const;

    void insert(int aKey);

    void deleteMin();

    void levelOrderDisplay();

private:
    void destroyTree(bqNode *aNode);

    void merge(BinomialQueue &aOtherQueue);

    int nCr(int n, int r);

    void levelOrderDisplayByTree(bqNode *aRootNode, int aOrder);

    bqNode *concateTrees(bqNode *aT1, bqNode *aT2);

    const static int SIZE = 10;
    bqNode *mTrees[SIZE];
    int mCurrentSize;
};

#endif