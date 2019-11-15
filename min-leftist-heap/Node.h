#ifndef Node_H
#define Node_H

class Node
{
private:
  int n_value;
  Node *n_next;
  
public:
  Node();
  ~Node();

  void setItem(int value);

  int getItem();

  void setNext(Node *n_next);

  Node *getNext();
};
#include "Node.cpp"
#endif
