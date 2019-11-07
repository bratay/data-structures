#ifndef SKEWNODE_H
#define SKEWNODE_H

class SkewNode
{
public:
    SkewNode(int s_value);
    ~SkewNode();

    void setValue(int s_value);

    int getValue();

    void setLeftChild(SkewNode *s_leftchild);

    SkewNode *getLeftChild();

    void setRightChild(SkewNode *s_rightchild);

    SkewNode *getRightChild();

private:
    int value;
    SkewNode *leftchild;
    SkewNode *rightchild;
};
#endif
