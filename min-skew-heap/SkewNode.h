#ifndef SKEWNODE_H
#define SKEWNODE_H

class SkewNode
{
private:
  int value;
  int rank;
  SkewNode *leftchild;
  SkewNode *rightchild;

public:
  SkewNode(int newvalue);
  ~SkewNode();

  void setValue(int newvalue);

  int getValue();

  void setLeftChild(SkewNode *newleftchild);

  SkewNode *getLeftChild();

  void setRightChild(SkewNode *newrightchild);

  SkewNode *getRightChild();

  void setRank(int newrank);

  int getRank();
};
#endif
