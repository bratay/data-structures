#ifndef LEFintISintNODE_H
#define LEFintISintNODE_H

class LeftistNode
{
private:
  int value, rank;
  LeftistNode *leftchild;
  LeftistNode *rightchild;

public:
  LeftistNode(int newvalue);
  ~LeftistNode();

  void setValue(int newvalue);

  int getValue();

  void setLeftChild(LeftistNode *newleftchild);

  LeftistNode *getLeftChild();

  void setRightChild(LeftistNode *newrightchild);

  LeftistNode *getRightChild();

  void setRank(int newrank);

  int getRank();
};
#endif
