#ifndef Node_H
#define Node_H

#include "LeftistNode.h"

class Node
{
private:
  LeftistNode* n_value;
  Node *n_next;
  
public:
  Node();
  Node(int value);
  ~Node();

  void setItem(LeftistNode* value);

  LeftistNode* getItem();

  void setNext(Node *n_next);

  Node *getNext();
};
// #include "Node.cpp"
#endif
